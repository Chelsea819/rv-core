/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_if_id #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	input									clock				,
	input									reset				,

    // from ifu
    input 		[DATA_WIDTH - 1:0]			f_if_inst_i			,
	input 		[ADDR_WIDTH - 1:0]			f_if_pc_i			,
    input 									f_if_valid_i			,
	input 									f_id_ready_i			,

	// to idu
	output		[DATA_WIDTH - 1:0]			t_id_inst_o			,	
	output		[ADDR_WIDTH - 1:0]      	t_id_pc_o			
);
	wire wen = f_if_valid_i & f_id_ready_i;

	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	if_id_inst_reg(
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_if_inst_i   ),
		.wen  	(wen  ),
		.dout 	(t_id_inst_o  )
	);

	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	if_id_pc_reg(
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_if_pc_i   ),
		.wen  	(wen  ),
		.dout 	(t_id_pc_o  )
	);
	

endmodule

