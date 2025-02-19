/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_ex_lsu #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	input									clock				,
	input									reset				,

    // from ifu
    input 									f_ex_wd_i   			,
    input 		[4:0]						f_ex_wreg_i   			,
	input 		[DATA_WIDTH - 1:0]			f_ex_alu_result_i   	,
    input 		   						    f_ex_mem_wen_i     		,
	input 		[DATA_WIDTH - 1:0]			f_ex_mem_wdata_i   		,
	input 		[2:0]						f_ex_load_type_i		,
    input 		[1:0]            			f_ex_store_type_i		,
	input 		[DATA_WIDTH - 1:0]			f_ex_csr_wdata_i			,
    input 		[2:0]            			f_ex_csr_type_i					,
	input 		                			f_ex_valid_i				,
	input 		                			f_lsu_ready_i				,
	input 		                			f_ex_ebreak_flag_i				,

	// to idu
	output 									t_lsu_wd_o   			,
	output 		[4:0]						t_lsu_wreg_o   			,
    output 		[DATA_WIDTH - 1:0]			t_lsu_alu_result_o   	,
	output 		   						    t_lsu_mem_wen_o     		,
    output 		[DATA_WIDTH - 1:0]			t_lsu_mem_wdata_o   		,
	output 		[2:0]						t_lsu_load_type_o		,
	output 		[1:0]            			t_lsu_store_type_o		,
    output 		[DATA_WIDTH - 1:0]			t_lsu_csr_wdata_o		,
	output 		[2:0]            			t_lsu_csr_type_o		,
	output 		                			t_lsu_ebreak_flag_o			
);
	wire wen = f_ex_valid_i & f_lsu_ready_i;

	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_ebreak_flag_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_ebreak_flag_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_ebreak_flag_o  )
	);

	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_wd_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_wd_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_wd_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(5  ),
		.RESET_VAL 	(0  ))
	ex_lsu_wreg_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_wreg_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_wreg_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	ex_lsu_alu_result_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_alu_result_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_alu_result_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_mem_wen_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_mem_wen_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_mem_wen_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	ex_lsu_mem_wdata_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_mem_wdata_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_mem_wdata_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(3  ),
		.RESET_VAL 	(0  ))
	ex_lsu_load_type_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_load_type_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_load_type_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(2  ),
		.RESET_VAL 	(0  ))
	ex_lsu_store_type_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_store_type_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_store_type_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	ex_lsu_csr_wdata_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_csr_wdata_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_csr_wdata_o  )
	);

	ysyx_23060025_Reg #(
		.WIDTH     	(3  ),
		.RESET_VAL 	(0  ))
	ex_lsu_csr_type_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_ex_csr_type_i   ),
		.wen  	(wen    ),
		.dout 	(t_lsu_csr_type_o  )
	);
	

endmodule

