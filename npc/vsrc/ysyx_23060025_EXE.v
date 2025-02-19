/*************************************************************************
	> File Name: ysyx_23060025_add.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时24分15秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
module ysyx_23060025_EXE #(parameter DATA_LEN = 32)(
	input									      clock				        ,
    input									      reset				        ,
	input		[DATA_LEN - 1:0]		reg1_i		,
	input		[DATA_LEN - 1:0]		reg2_i		,
	input		[DATA_LEN - 1:0]		pc_i		,
    // input		[DATA_LEN - 1:0]		inst		,
	input 		[3:0]					alu_control	,
    input 		[3:0]					alu_sel		, // choose source number
	input       [DATA_LEN - 1:0]        imm_i		,
	input       [DATA_LEN - 1:0]        csr_rdata_i	,
	input  	    [11:0]     	csr_waddr_i		,
	input 		[2:0]					csr_flag_i	,
	input		                		wd_i		,
    input		[4:0]		            wreg_i		,
	input		[1:0]					store_type_i,
	input       [2:0]                   load_type_i ,
	input                                        ebreak_flag_i             ,


	// idu_exu
    input                                         idu_valid_i               ,
    output                                        exu_ready_o               ,

    // exu_lsu
    output                                        exu_valid_o               ,
    input                                         lsu_ready_i               ,

	output                                        ebreak_flag_o             ,

    // input                                         isu_ready                 ,
    // output                                        exu_ready_o                 ,
	output  	    [2:0]                load_type_o 	,
	output  	    [1:0]				store_type_o	,
    output			                		mem_wen_o		,
	output			[DATA_LEN - 1:0]		mem_wdata_o		,
    output			                		wd_o			,
    output		   [4:0]		            wreg_o			,
	output  	   [DATA_LEN - 1:0]     csr_wdata_o		,
	output  	    [11:0]     csr_waddr_o		,
	output  	    [2:0]			    csr_type_o		,
	output  	    [DATA_LEN - 1:0]     csr_mcause_o	,
	output			[DATA_LEN - 1:0]		pc_o			,
    output			[DATA_LEN - 1:0]		alu_result_o
);

	wire [31:0] src1;
	wire [31:0] src2;
	assign wd_o  = wd_i;
	assign wreg_o  = wreg_i;
	assign csr_waddr_o = csr_waddr_i;
	assign mem_wen_o  = |store_type_i;
	assign mem_wdata_o  = reg2_i;
	assign load_type_o  = load_type_i;
	assign store_type_o  = store_type_i;
	assign pc_o  = pc_i;
	assign csr_mcause_o  = 32'hb;

	assign ebreak_flag_o = ebreak_flag_i;

`ifdef N_YOSYS_STA_CHECK
	`ifdef PERFORMANCE_COUNTER
	import "DPI-C" function void exu_p_counter_update();
	always @(posedge clock) begin
		if (con_state == STATE_WAIT_LSU_READY) begin
			exu_p_counter_update();
		end
	end
	`endif
`endif

	reg			[1:0]			        	con_state	;
	reg			[1:0]			        	next_state	;
    parameter [1:0] STATE_WAIT_IDU_VALID = 2'b00, STATE_RUN = 2'b01, STATE_WAIT_LSU_READY = 2'b10;


	// state trans
	always @(posedge clock ) begin
		if(reset)
			con_state <= STATE_WAIT_IDU_VALID;
		else 
			con_state <= next_state;
	end

	// next_state
	always @(*) begin
		next_state = con_state;
		case(con_state) 
            // 等待idu完成译码
			STATE_WAIT_IDU_VALID: begin
				if(idu_valid_i) 
					next_state = STATE_RUN;
			end
            // 等待idu完成译码
			STATE_RUN: begin
				if(~lsu_ready_i) begin
					next_state = STATE_WAIT_LSU_READY;
				end else begin
					next_state = STATE_WAIT_IDU_VALID;
				end
				// else if(~idu_valid_i) begin
				// 	next_state = STATE_WAIT_IDU_VALID;
				// end
			end
            // 等待exu空闲，下个时钟周期传递信息
            STATE_WAIT_LSU_READY: begin 
				if (lsu_ready_i) begin
					next_state = STATE_WAIT_IDU_VALID;
				end
			end
            default: begin 
				next_state = 2'b11;
			end
		endcase
	end
	assign exu_valid_o = (con_state == STATE_RUN || con_state == STATE_WAIT_LSU_READY);
	assign exu_ready_o = (con_state == STATE_WAIT_IDU_VALID);

	// ysyx_23060025_MuxKeyWithDefault #(6,3,1) branch_request_mux (branch_request_o , branch_type_i, 1'b0, {
	// 	`BRANCH_BEQ, alu_zero,
	// 	`BRANCH_BNE, ~alu_zero,
	// 	`BRANCH_BLT, alu_less,
	// 	`BRANCH_BGE, ~alu_less,
	// 	`BRANCH_BLTU, alu_less,
	// 	`BRANCH_BGEU, ~alu_less
	// });

	ysyx_23060025_MuxKeyWithDefault #(2,3,32) csr_wdata_choose (csr_wdata_o , csr_flag_i, 32'b0, {
		`CSR_CSRRW, reg1_i,
		`CSR_CSRRS, reg1_i | csr_rdata_i
	});

	assign csr_type_o = csr_flag_i;

	ysyx_23060025_ALU my_alu(
		.src1				(src1),
		.src2				(src2),
		.alu_control		(alu_control),
		.result				(alu_result_o )
	);

	ysyx_23060025_MuxKeyWithDefault #(4,2,32) src1_choose (src1, alu_sel[1:0], 32'b0, {
		`ALU_SEL1_ZERO, 32'b0,
		`ALU_SEL1_REG1, reg1_i,
		`ALU_SEL1_PC,   pc_i,
		`ALU_SEL1_CSR,  csr_rdata_i
	});

	ysyx_23060025_MuxKeyWithDefault #(4,2,32) src2_choose (src2, alu_sel[3:2], 32'b0, {
		`ALU_SEL1_ZERO, 32'b0,
		`ALU_SEL2_REG2, reg2_i,
		`ALU_SEL2_IMM, 	imm_i,
		`ALU_SEL2_4, 	32'b100
	});


endmodule

