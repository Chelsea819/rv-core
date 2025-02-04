/*************************************************************************
	> File Name: ysyx_23060025_counter.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月05日 星期六 22时12分23秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
module ysyx_23060025_counter #(parameter ADDR_LEN = 32)(
	input									clock				,
	input									reset				,
	input									branch_request_i,	
	input		[ADDR_LEN - 1:0]			branch_target_i	,
	input									branch_flag_i	,
	input	    [ADDR_LEN - 1:0]			pc_plus_4		,
	input                                   jmp_flag_i      ,
    input       [31:0]                   	jmp_target_i,
	input									csr_jmp_i	,
	input		[ADDR_LEN - 1:0]			csr_pc_i	,
	input		[1:0]						con_state	,
	// input	[ADDR_LEN - 1:0]			ce		,
	output reg	[ADDR_LEN - 1:0]			pc
);	
	wire 		[ADDR_LEN - 1:0]			pc_next;

	parameter IFU_WAIT_READY = 2'b01;

	// always @(*) begin
	// 	$display("csr_jmp_i = [%b] ",csr_jmp_i);
	// 	$display("csr_pc_i = [%b]\n",csr_pc_i);
	// end

	assign pc_next = (branch_flag_i & branch_request_i) ? branch_target_i : 
					 jmp_flag_i 						? jmp_target_i : 
					 csr_jmp_i 							? csr_pc_i : 
					 pc_plus_4;
	
	always @ (posedge clock) begin
		if(reset)
			pc <= `PC_RESET_VAL;
		else if (con_state == IFU_WAIT_READY) 
			pc <= pc_next;
	end
	
`ifdef N_YOSYS_STA_CHECK
	import "DPI-C" function void pc_get(int pc, int dnpc);
	always @(*) begin
		// $display("pc = %x dpc = %x",pc,pc_next);
		pc_get(pc, pc_next);
	end
`endif	
	
endmodule
