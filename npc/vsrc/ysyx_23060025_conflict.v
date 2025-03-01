/*************************************************************************
	> File Name: ysyx_23060025_add.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时24分15秒
 ************************************************************************/
 `include "ysyx_23060025_define.v"
module ysyx_23060025_conflict (
	input 								clock			,
	input 								reset			,
	// decoder-read register information
`ifdef BYPASS_TRACE
	input		[31:0]					idu_pc_i		,
`endif
	input		[11:0]					idu_csr_raddr_i	,
	input								idu_csr_ren_i	,
	input								idu_busy_i		,
	input								idu_ren1_i		,
	input								idu_ren2_i		,
	input		[4:0]					idu_rsc1_i		,
	input		[4:0]					idu_rsc2_i		,

	// exeute-write register information
	input		[11:0]					exu_csr_waddr_i	,
	input		[2:0]					exu_csr_type_i	,
	input		[31:0]			        exu_csr_wdata_i	,
	input								exu_busy_i		,
	input								exu_wd_i		,
	input		[4:0]					exu_wreg_i		,
	input		[31:0]			        exu_reg_wdata_i	,
	input						        exu_mem_to_reg_i	,

	// lsu-write register information
	input		[11:0]					lsu_csr_waddr_i	,
	input		[2:0]					lsu_csr_type_i	,
	input		[31:0]			        lsu_csr_wdata_i	,
	input								lsu_busy_i		,
	input								lsu_mem_to_reg_i,
	input								lsu_wd_i		,
	input								lsu_valid_i		,
	input		[4:0]					lsu_wreg_i		,
	input		[31:0]			        lsu_reg_wdata_i	,
	

	// is raw
	output 								conflict_reg1_o	,
	output 								conflict_reg2_o	,
	output 								conflict_csr_o	,
	// 1. lsu 2. exeu+load
	output 								conflict_id_nop_o,
	output 		[31:0]					conflict_csr_bypass_data_o,
	output 		[31:0]					conflict_reg1_bypass_data_o,
	output 		[31:0]					conflict_reg2_bypass_data_o

);
	// addr confirm
	wire [4:0] idu_reg1_addr = {5{idu_ren1_i}} & idu_rsc1_i;
	wire [4:0] idu_reg2_addr = {5{idu_ren2_i}} & idu_rsc2_i;

	wire [4:0] exu_wreg_addr = {5{exu_wd_i}} & exu_wreg_i;
	wire [4:0] lsu_wreg_addr = {5{lsu_wd_i}} & lsu_wreg_i;

	wire reg1_not_0 = ~(idu_reg1_addr == 0);
	wire reg2_not_0 = ~(idu_reg2_addr == 0);

	// module state
	wire lsu_busy = lsu_busy_i;
	wire exu_busy = exu_busy_i;
	wire idu_busy = idu_busy_i;

	// if write csr register
	wire exu_csr_wen = exu_csr_type_i == `CSR_CSRRW 
						|| exu_csr_type_i == `CSR_CSRRS
						|| exu_csr_type_i == `CSR_ECALL;
	wire lsu_csr_wen = lsu_csr_type_i == `CSR_CSRRW 
						|| lsu_csr_type_i == `CSR_CSRRS
						|| lsu_csr_type_i == `CSR_ECALL;
	wire id_exu_csr_conflict = (idu_csr_raddr_i == exu_csr_waddr_i) & idu_csr_ren_i & idu_busy & exu_busy & exu_csr_wen;
	wire id_lsu_csr_conflict = (idu_csr_raddr_i == lsu_csr_waddr_i) & idu_csr_ren_i & idu_busy & lsu_busy & lsu_csr_wen;
	assign conflict_csr_o = id_exu_csr_conflict | id_lsu_csr_conflict;

	// not register[0] , not in idle state
	wire id_exu_conflict_1 = (idu_reg1_addr == exu_wreg_addr) & reg1_not_0 & exu_busy &	idu_busy;
	wire id_exu_conflict_2 = (idu_reg2_addr == exu_wreg_addr) & reg2_not_0 & exu_busy &	idu_busy;
	wire id_lsu_conflict_1 = (idu_reg1_addr == lsu_wreg_addr) & reg1_not_0 & lsu_busy &	idu_busy;
	wire id_lsu_conflict_2 = (idu_reg2_addr == lsu_wreg_addr) & reg2_not_0 & lsu_busy &	idu_busy;

	// assign id_is_raw_o = id_exu_conflict_1 | id_exu_conflict_2 | id_lsu_conflict_1 | id_lsu_conflict_2;

	// which module conflict
	wire id_exu_conflict = id_exu_conflict_1 | id_exu_conflict_2;
	wire id_lsu_conflict = id_lsu_conflict_1 | id_lsu_conflict_2;

	// which reg conflict
	assign conflict_reg1_o = id_exu_conflict_1 | id_lsu_conflict_1;
	assign conflict_reg2_o = id_exu_conflict_2 | id_lsu_conflict_2;

	assign conflict_reg1_bypass_data_o = id_exu_conflict_1_reg ? ex_wdata : lsu_reg_wdata;	
	assign conflict_reg2_bypass_data_o = id_exu_conflict_2_reg ? ex_wdata :	lsu_reg_wdata;  

	reg id_exu_conflict_1_reg;
	reg id_exu_conflict_2_reg;
	always @(posedge clock) begin
		if(reset) begin
			id_exu_conflict_1_reg	<= 0;
			id_exu_conflict_2_reg	<= 0;
		end else begin
			id_exu_conflict_1_reg	<= id_exu_conflict_1;
			id_exu_conflict_2_reg	<= id_exu_conflict_2;
		end
	end
	
	parameter 	 STATE_RUN = 1'b0, STATE_WAIT_LSU = 1'b1;
	reg 	 con_state;
	reg 	 next_state;

	always @(posedge clock) begin
		if(reset) begin
			con_state <= STATE_RUN;
		end else begin
			con_state <= next_state;
		end
	end

	always @(*) begin
		next_state = con_state;
		case (con_state)
			STATE_RUN : begin
				if(id_lsu_conflict & ~lsu_valid_i) begin	// need wait for lsu
					next_state = STATE_WAIT_LSU;
				end
			end
			STATE_WAIT_LSU: begin
				if(lsu_valid) begin
					next_state = STATE_RUN;
				end
			end 
			// STATE_DATA_PASS: begin
			// 	next_state = STATE_RUN;
			// end
		endcase
	end
`ifdef BYPASS_TRACE
	wire is_raw = id_exu_conflict_1 | id_exu_conflict_2 | id_lsu_conflict_1 | id_lsu_conflict_2;
	always @(posedge clock) begin
		if(con_state == STATE_RUN) begin
			if(is_raw) begin
				$display("Data bypass!--PC:%x", idu_pc_i);
			end
		end
	end
`endif

`ifdef N_YOSYS_STA_CHECK
    `ifdef PERFORMANCE_COUNTER
    import "DPI-C" function void data_relation_inst_update();
    import "DPI-C" function void data_relation_delay_update();
	always @(posedge clock) begin
		if (con_state == STATE_RUN && next_state == STATE_WAIT_LSU) begin
			data_relation_inst_update();
		end
	end
	always @(posedge clock) begin
		if (next_state == STATE_WAIT_LSU) begin
			data_relation_delay_update();
		end
	end
    `endif
`endif
	reg conflict_id_nop;
	always @(posedge clock) begin
		if(reset) begin
			conflict_id_nop <= 0;
		end else if((con_state == STATE_RUN && (id_exu_conflict & exu_mem_to_reg_i || id_lsu_conflict & ~lsu_valid_i))) begin
			conflict_id_nop <= 1;
		end else if((con_state == STATE_WAIT_LSU && lsu_valid_i)) begin
			conflict_id_nop <= 0;
		end
	end
	// 1. id_exu_conflict
	// 	1. mem
	// 	2. not mem: 
	// wire id_ex_not_mem_conflict_nop = (con_state == STATE_RUN && (id_exu_conflict & ~exu_mem_to_reg_i));	// not mem
	reg [31:0] ex_wdata;
	always @(posedge clock) begin
		if(reset) begin
			ex_wdata <= 0;
		end else begin
			ex_wdata <= exu_reg_wdata_i;
		end
	end

	// wire id_ex_mem_conflict_nop = (con_state == STATE_RUN && (id_exu_conflict & mem_to_reg)) & lsu_allowin_i; // wait for lsu_ok
																							
	// wire id_lsu_conflict_nop = (con_state == STATE_RUN && (id_lsu_conflict & ~lsu_valid));

	assign conflict_id_nop_o = (con_state == STATE_RUN && (id_exu_conflict || id_lsu_conflict)) ? 1 : 
								conflict_id_nop;

	reg [31:0] lsu_reg_wdata;
	reg lsu_valid;
	always @(posedge clock) begin
		if(reset) begin
			lsu_reg_wdata <= 0;
			lsu_valid <= 0;
		end else begin
			lsu_reg_wdata <= lsu_reg_wdata_i;
			lsu_valid <= lsu_valid_i;
		end
	end

	// TODO: (con_state == STATE_RUN) ? ex_wdata 这里需要更改，可能需要是lsu_wdata, 当检测时，lsuvalid i 恰好为1时候
	// assign conflict_reg_bypass_data_o = (con_state == STATE_RUN && id_exu_reg_conflict) ? ex_wdata:	// exu_not_mem
	// 									(con_state == STATE_RUN && id_lsu_reg_conflict) ? lsu_reg_wdata:	// lsu valid
	// 									lsu_reg_wdata;    // lsu-decoder data relation, not load inst
	
	assign conflict_csr_bypass_data_o = (id_exu_csr_conflict) ? exu_csr_wdata_i:  
									(id_lsu_csr_conflict) ? lsu_csr_wdata_i:  
									0;
	

endmodule
