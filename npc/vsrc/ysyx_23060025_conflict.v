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
	input								idu_ready_i		,
	input								idu_ren0_i		,
	input								idu_ren1_i		,
	input		[4:0]					idu_rsc0_i		,
	input		[4:0]					idu_rsc1_i		,

	// exeute-write register information
	input		[11:0]					exu_csr_waddr_i	,
	input		[2:0]					exu_csr_type_i	,
	input		[31:0]			        exu_csr_wdata_i	,
	input								exu_ready_i		,
	input								exu_mem_to_reg_i,
	input								exu_wd_i		,
	input		[4:0]					exu_wreg_i		,
	input		[31:0]			        exu_reg_wdata_i	,

	// lsu-write register information
	input		[11:0]					lsu_csr_waddr_i	,
	input		[2:0]					lsu_csr_type_i	,
	input		[31:0]			        lsu_csr_wdata_i	,
	input								lsu_ready_i		,
	input								lsu_mem_to_reg_i,
	input								lsu_wd_i		,
	input								lsu_valid_i		,
	input		[4:0]					lsu_wreg_i		,
	input		[31:0]			        lsu_reg_wdata_i	,
	

	// is raw
	output 								conflict_reg0_o	,
	output 								conflict_reg1_o	,
	output 								conflict_csr_o	,
	// 1. lsu 2. exeu+load
	output 	reg							conflict_id_nop_o,
	output 		[31:0]					conflict_csr_bypass_data_o,
	output 		[31:0]					conflict_reg_bypass_data_o

);
	wire [4:0] idu_reg0_addr = {5{idu_ren0_i}} & idu_rsc0_i;
	wire [4:0] idu_reg1_addr = {5{idu_ren1_i}} & idu_rsc1_i;

	wire [4:0] exu_wreg_addr = {5{exu_wd_i}} & exu_wreg_i;
	wire [4:0] lsu_wreg_addr = {5{lsu_wd_i}} & lsu_wreg_i;

	wire reg0_not_0 = ~(idu_reg0_addr == 0);
	wire reg1_not_0 = ~(idu_reg1_addr == 0);

	wire lsu_busy = ~lsu_ready_i;
	wire exu_busy = ~exu_ready_i;
	wire idu_busy = ~idu_ready_i;

	wire exu_csr_wen = exu_csr_type_i == `CSR_CSRRW 
						|| exu_csr_type_i == `CSR_CSRRS
						|| exu_csr_type_i == `CSR_ECALL;
	wire lsu_csr_wen = lsu_csr_type_i == `CSR_CSRRW 
						|| lsu_csr_type_i == `CSR_CSRRS
						|| lsu_csr_type_i == `CSR_ECALL;

	// not register[0] , not in idle state
	wire id_exu_conflict_0 = (idu_reg0_addr == exu_wreg_addr) & reg0_not_0 & exu_busy &	idu_busy;
	wire id_exu_conflict_1 = (idu_reg1_addr == exu_wreg_addr) & reg1_not_0 & exu_busy &	idu_busy;
	wire id_lsu_conflict_0 = (idu_reg0_addr == lsu_wreg_addr) & reg0_not_0 & lsu_busy &	idu_busy;
	wire id_lsu_conflict_1 = (idu_reg1_addr == lsu_wreg_addr) & reg1_not_0 & lsu_busy &	idu_busy;

	// assign id_is_raw_o = id_exu_conflict_0 | id_exu_conflict_1 | id_lsu_conflict_0 | id_lsu_conflict_1;

	wire id_exu_conflict = id_exu_conflict_0 | id_exu_conflict_1;
	wire id_lsu_conflict = id_lsu_conflict_0 | id_lsu_conflict_1;


	assign conflict_reg0_o = id_exu_conflict_0 | id_lsu_conflict_0;
	assign conflict_reg1_o = id_exu_conflict_1 | id_lsu_conflict_1;

	// assign conflict_valid_o = (con_state == STATE_RUN && next_state == STATE_RUN) || (con_state == STATE_WAIT_LSU && next_state == STATE_RUN);

	wire id_exu_csr_conflict = (idu_csr_raddr_i == exu_csr_waddr_i) & idu_csr_ren_i & idu_busy & exu_busy & exu_csr_wen;
	wire id_lsu_csr_conflict = (idu_csr_raddr_i == lsu_csr_waddr_i) & idu_csr_ren_i & idu_busy & lsu_busy & lsu_csr_wen;
	assign conflict_csr_o = id_exu_csr_conflict | id_lsu_csr_conflict;
	
	
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
				// need wait for exeu inst finish lsu
				// if(id_exu_conflict & exu_mem_to_reg_i) begin
				// 	next_state = STATE_RUN;
				// else if(id_exu_conflict & exu_mem_to_reg_i) begin
				// 	next_state = STATE_RUN; 
				// end else 
				if(id_lsu_conflict & ~lsu_valid_i & lsu_mem_to_reg_i) begin	// need wait for lsu
					next_state = STATE_WAIT_LSU;
				end
			end
			STATE_WAIT_LSU: begin
				if(lsu_valid_i) begin
					next_state = STATE_RUN;
				end
			end 
		endcase
	end
`ifdef BYPASS_TRACE
	wire is_raw = id_exu_conflict_0 | id_exu_conflict_1 | id_lsu_conflict_0 | id_lsu_conflict_1;
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

	assign conflict_id_nop_o = (con_state == STATE_RUN && (id_exu_conflict & exu_mem_to_reg_i || id_lsu_conflict & ~lsu_valid_i)) ? 1 : conflict_id_nop;

	reg [31:0] lsu_wreg_data;
	always @(posedge clock) begin
		if(reset) begin
			lsu_wreg_data <= 0;
		end else if(con_state == STATE_WAIT_LSU && lsu_valid_i || con_state == STATE_RUN && lsu_valid_i & id_lsu_conflict) begin
			lsu_wreg_data <= lsu_reg_wdata_i;
		end 
	end

	assign conflict_reg_bypass_data_o = (id_exu_conflict & ~exu_mem_to_reg_i) ? exu_reg_wdata_i:    // exeute-decoder data relation
									(id_lsu_conflict & ~lsu_mem_to_reg_i) ? lsu_reg_wdata_i:    // lsu-decoder data relation, not load inst
									// 当时刚好lsu_valid 
									(con_state == STATE_RUN & id_lsu_conflict) ? lsu_reg_wdata_i: lsu_wreg_data;
	
	assign conflict_csr_bypass_data_o = (id_exu_csr_conflict) ? exu_csr_wdata_i:  
									(id_lsu_csr_conflict) ? lsu_csr_wdata_i:  
									0;
	

endmodule
