/*************************************************************************
	> File Name: ysyx_23060025_add.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时24分15秒
 ************************************************************************/
 `include "ysyx_23060025_define.v"
module ysyx_23060025_ALU #(parameter DATA_LEN = 32)(
	input		[DATA_LEN - 1:0]		src1		,
	input		[DATA_LEN - 1:0]		src2		,
	input 								alu_op_sel_add	,
	input 								alu_op_sel_sub	,
	input 								alu_op_sel_xor	,
	input 								alu_op_sel_or	,
	input 								alu_op_sel_and	,
	input 								alu_op_sel_right_logic	,
	input 								alu_op_sel_right_arithe	,
	input 								alu_op_sel_less_unsigned	,
	input 								alu_op_sel_less_signed	,
	input 								alu_op_sel_left_logic	,
	output		[DATA_LEN - 1:0]		result
);
	// always @(*) begin
	// 	$display("src1 = [%b], src2 = [%b] alu_zero_o = [%b]  alu_less = [%b]",src1, src2, alu_zero_o, alu_less_o);
	// 	$display("src1 = [%h], src2 = [%h] sub_result = [%b] s_compare_result = [%b] u_compare_result = [%b]",src1, src2, sub_result, s_compare_result, u_compare_result);
	// end

	wire signed [31:0] src1_signed = $signed(src1);
	wire signed [31:0] src2_signed = $signed(src2);

	wire [31:0] add_res 		= src1 + src2				;
	wire [31:0] sub_res 		= src1 - src2				;
	wire [31:0] xor_res 		= src1 ^ src2				;
	wire [31:0] or_res 			= src1 | src2				;
	wire [31:0] and_res 		= src1 & src2				;
	wire [31:0] right_logic_res = src1 >> src2[4:0]			;
	wire [31:0] right_arithme 	= $signed(src1) >>> src2[4:0];
	wire [31:0] left_logic 		= src1 << src2[4:0]			;
	wire [31:0] less_signed 	= {31'b0, (src1_signed < src2_signed)}			;
	wire [31:0] less_unsigned 	= {31'b0, (src1 < src2)}			;
	

	/* 比较两数大小，查看a-b相关标志位
	有符号整数：当OF = SF时，a > b; OF != SF时，a >= b
	无符号整数：当CF = 1时，即产生借位，此时a < b; CF = 0时，a > b
	SF：符号位，即结果最高位
	OF：(有符号数溢出判断)溢出判断位，OF=C(n) ^ C(n-1)最高位进位异或次高位进位
	CF：进位/借位判断位，CF = Cout ^ Cin, Cin = Sub
	Sub = 1 表示减法运算，此时CF = ~Cout
	Sub = 0 表示加法运算，此时CF = Cout
	 */

	assign result = {32{alu_op_sel_add}} 			& add_res 		
					| {32{alu_op_sel_sub}} 			& sub_res 		
					| {32{alu_op_sel_xor}} 			& xor_res 		
					| {32{alu_op_sel_or}} 			& or_res 			
					| {32{alu_op_sel_and}} 			& and_res 		
					| {32{alu_op_sel_right_logic}} 	& right_logic_res 
					| {32{alu_op_sel_right_arithe}} & right_arithme 	
					| {32{alu_op_sel_less_unsigned}}& less_unsigned 		
					| {32{alu_op_sel_less_signed}} 	& less_signed 	
					| {32{alu_op_sel_left_logic}} 	& left_logic ;	
	

endmodule
