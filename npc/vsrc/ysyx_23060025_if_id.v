/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_if_id (
	input									clock				,
	input									reset				,

    // from ifu
    input 		[`FS_TO_DS_DATA_BUS - 1:0]	f_if_to_id_bus_i			,
    input 									f_if_valid_i			,
	input 									f_id_ready_i			,

	// to idu
	output		[`FS_TO_DS_DATA_BUS - 1:0]	t_id_bus_o		
);
	wire wen = f_if_valid_i & f_id_ready_i;

	ysyx_23060025_Reg #(
		.WIDTH     	(`FS_TO_DS_DATA_BUS  ),
		.RESET_VAL 	(0  ))
	if_id_inst_reg(
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_if_to_id_bus_i   ),
		.wen  	(wen  ),
		.dout 	(t_id_bus_o  )
	);

	

endmodule

