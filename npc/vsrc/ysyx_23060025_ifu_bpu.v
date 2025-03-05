/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_ifu_bpu #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	// input									clock				,
	// input									reset				,

	// from ifu to bpu
	input  		[`FS_TO_DS_DATA_BUS - 1:0]	if_to_bqu_bus,
	output  	[ADDR_WIDTH - 1:0]			bpu_pc_predict_o,
	output  								bpu_valid_o

);
	wire  		[DATA_WIDTH - 1:0]			bpu_inst_i ;
	wire  		[DATA_WIDTH - 1:0]			bpu_pc_i   ;
	assign {bpu_inst_i, bpu_pc_i} = if_to_bqu_bus;

`ifdef N_YOSYS_STA_CHECK
	`ifdef PERFORMANCE_COUNTER

	`endif
`endif
	// 简单译码
	wire   [6:0]   opcode = bpu_inst_i[6:0];
	wire opcode_1_0_11  = (opcode[1:0] == 2'b11);
	wire opcode_6_5_11  = (opcode[6:5] == 2'b11);
	wire opcode_4_2_000 = (opcode[4:2] == 3'b000);
	wire opcode_4_2_011 = (opcode[4:2] == 3'b011);
	wire opcode_4_2_001 = (opcode[4:2] == 3'b001);
	wire opcode_4_2_100 = (opcode[4:2] == 3'b100);
	wire   [2:0]   func3 = bpu_inst_i[14:12];
	wire func3_000 = (func3 == 3'b000);
	wire opcode_B_branch   = opcode_6_5_11 & opcode_4_2_000 & opcode_1_0_11;
	wire opcode_J_jal      = opcode_6_5_11 & opcode_4_2_011 & opcode_1_0_11;
	wire opcode_I_jalr     = opcode_6_5_11 & opcode_4_2_001 & opcode_1_0_11;
    wire opcode_I_system   = opcode_6_5_11 & opcode_4_2_100 & opcode_1_0_11;
	wire rv32_ecall    = opcode_I_system & func3_000 & (bpu_inst_i[31:20] == 12'b0000_0000_0000);
    wire rv32_mret     = opcode_I_system & func3_000 & (bpu_inst_i[31:20] == 12'b0011_0000_0010);
	wire [31:0]  rv32_b_imm = {
                               {19{bpu_inst_i[31]}} 
                              , bpu_inst_i[31] 
                              , bpu_inst_i[7] 
                              , bpu_inst_i[30:25] 
                              , bpu_inst_i[11:8]
                              , 1'b0
                              };
	wire [31:0]  rv32_j_imm = {
                               {11{bpu_inst_i[31]}} 
                              , bpu_inst_i[31] 
                              , bpu_inst_i[19:12] 
                              , bpu_inst_i[20] 
                              , bpu_inst_i[30:21]
                              , 1'b0
                              };
	wire [31:0] imm = opcode_B_branch ? rv32_b_imm : rv32_j_imm;
	// 1. branch指令--识别出是branch指令，得到立即数，判断立即数正负
	wire imm_b_neg = rv32_b_imm[31];
	wire bpu_branch_jmp = opcode_B_branch & imm_b_neg; 

	// 2. jal指令--识别出是jal指令，得到立即数，直接跳

	
	// 如果是jal指令或者是分支跳转 向后跳转(imm negetive)的指令，则跳转
	wire bpu_token = opcode_J_jal | bpu_branch_jmp;
	wire [31:0] bpu_op2 = bpu_token ? imm : 32'd4;
	assign bpu_pc_predict_o = bpu_pc_i + bpu_op2;

	/* bpu_valid: when J-> must jmp
					when B -> predict
					when not jmp_instr -> pc+4
					when jalr: nextpc depends on register value -> nor predict
					when ecall or mret -> nor predict
				--> if not jalr ecall mret, we can get nextpc
	*/			
	assign bpu_valid_o = ~(opcode_I_jalr | rv32_ecall | rv32_mret) ;

	
endmodule
