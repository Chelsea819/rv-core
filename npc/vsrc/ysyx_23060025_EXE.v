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
	input  	    [11:0]     				csr_waddr_i		,
	input 		[2:0]					csr_flag_i	,
	input		                		wd_i		,
    input		[4:0]		            wreg_i		,
	input		[1:0]					store_type_i,
	input       [2:0]                   load_type_i ,
	input                               ebreak_flag_i        ,


	// idu_exu
    input                                         idu_valid_i               ,
    output                                        exu_ready_o               ,

    // exu_lsu
    output                                        exu_valid_o               ,
    input                                         lsu_ready_i               ,

	output                                        ebreak_flag_o             ,

    // input                                         isu_ready                 ,
    // output                                        exu_ready_o                 ,
	output  	    [2:0]                	load_type_o 	,
	output  	    [1:0]					store_type_o	,
    output			                		mem_wen_o		,
	output			[DATA_LEN - 1:0]		mem_wdata_o		,
    output			                		wd_o			,
    output		    [4:0]		            wreg_o			,
	output  	    [DATA_LEN - 1:0]     	csr_wdata_o		,
	output  	    [11:0]     				csr_waddr_o		,
	output  	    [2:0]			    	csr_type_o		,
	output  	    [DATA_LEN - 1:0]     	csr_mcause_o	,
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
		if (con_state == STATE_WAIT_IDU_VALID && next_state == STATE_RUN) begin
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

	wire csr_cssrw = csr_flag_i == `CSR_CSRRW;
	wire csr_cssrs = csr_flag_i == `CSR_CSRRS;
	wire csr_ecall = csr_flag_i == `CSR_ECALL;

	wire [31:0] csr_csrrs_res = reg1_i | csr_rdata_i;
	
	assign csr_wdata_o = {32{csr_cssrw}} & reg1_i 
				| {32{csr_cssrs}} & pc_i 
				| {32{csr_ecall}} & csr_csrrs_res ;

	assign csr_type_o = csr_flag_i;

	ysyx_23060025_ALU my_alu(
		.src1						(src1),
		.src2						(src2),
		.alu_op_sel_add				(alu_op_sel_add),
		.alu_op_sel_sub				(alu_op_sel_sub),
		.alu_op_sel_xor				(alu_op_sel_xor),
		.alu_op_sel_or				(alu_op_sel_or),
		.alu_op_sel_and				(alu_op_sel_and),
		.alu_op_sel_right_logic		(alu_op_sel_right_logic),
		.alu_op_sel_right_arithe	(alu_op_sel_right_arithe),
		.alu_op_sel_less_unsigned	(alu_op_sel_less_unsigned),
		.alu_op_sel_less_signed		(alu_op_sel_less_signed),
		.alu_op_sel_left_logic		(alu_op_sel_left_logic ),
		.result						(alu_result_o )
	);

	wire aluop1_sel_zero = alu_sel[1:0] == `ALU_SEL1_ZERO;
	wire aluop1_sel_reg1 = alu_sel[1:0] == `ALU_SEL1_REG1;
	wire aluop1_sel_pc = alu_sel[1:0] == `ALU_SEL1_PC;
	wire aluop1_sel_csr = alu_sel[1:0] == `ALU_SEL1_CSR;

	wire aluop2_sel_zero 	= alu_sel[3:2] == `ALU_SEL2_ZERO;
	wire aluop2_sel_reg2 	= alu_sel[3:2] == `ALU_SEL2_REG2;
	wire aluop2_sel_imm 	= alu_sel[3:2] == `ALU_SEL2_IMM;
	wire aluop2_sel_4 		= alu_sel[3:2] == `ALU_SEL2_4;

	assign src1 = {32{aluop1_sel_zero}} & 32'b0 
				| {32{aluop1_sel_reg1}} & reg1_i 
				| {32{aluop1_sel_pc}} & pc_i 
				| {32{aluop1_sel_csr}} & csr_rdata_i ;

	assign src2 = {32{aluop2_sel_zero}} & 32'b0 
				| {32{aluop2_sel_reg2}} & reg2_i 
				| {32{aluop2_sel_imm}} & imm_i 
				| {32{aluop2_sel_4}} & 32'b100 ;

	wire alu_op_sel_add = (alu_control == `ALU_OP_ADD);

    wire alu_op_sel_sub = (alu_control == `ALU_OP_SUB);
    wire alu_op_sel_xor = (alu_control == `ALU_OP_XOR);
    wire alu_op_sel_or  = (alu_control == `ALU_OP_OR);

    wire alu_op_sel_and				= (alu_control == `ALU_OP_AND);
    wire alu_op_sel_right_logic 	= (alu_control == `ALU_OP_RIGHT_LOGIC);
    wire alu_op_sel_right_arithe 	= (alu_control == `ALU_OP_RIGHT_ARITH);
    wire alu_op_sel_left_logic 		= (alu_control == `ALU_OP_LEFT_LOGIC);
    wire alu_op_sel_less_unsigned 	= (alu_control == `ALU_OP_LESS_UNSIGNED);
    wire alu_op_sel_less_signed 	= (alu_control == `ALU_OP_LESS_SIGNED);


endmodule

