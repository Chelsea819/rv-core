/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_lsu_wb #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	input									clock				,
	input									reset				,

    // from ifu
    input 									f_lsu_reg_wen_i 			,
    input 		[4:0]						f_lsu_wreg_i       		,
	input 		[DATA_WIDTH - 1:0]			f_lsu_reg_wdata_i     	,
    input 		[DATA_WIDTH - 1:0]		    f_lsu_csr_wdata_i    		,
	input 		[2:0]						f_lsu_csr_type_i  	  		,
	input 									f_lsu_memory_inst_i		,
	input 									f_lsu_valid_i		,
	input 									f_lsu_ebreak_flag_i		,
	input 									f_wb_ready_i		,

	// to idu
	output 									t_wb_reg_wen_o 			,
	output 		[4:0]						t_wb_wreg_o       			,
    output 		[DATA_WIDTH - 1:0]			t_wb_reg_wdata_o     	  	,
	output 		[DATA_WIDTH - 1:0]		    t_wb_csr_wdata_o   	 		,
    output 		[2:0]						t_wb_csr_type_o  	  	 		,
	output 									t_wb_memory_inst_o				,	
	output 									t_wb_ebreak_flag_o				,	
	output 									t_wb_lsu_valid_o					
);
	wire wen = f_lsu_valid_i & f_wb_ready_i;
	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_ebreak_flag_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_ebreak_flag_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_ebreak_flag_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_lsu_valid_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_valid_i   ),
		.wen  	(1  ),
		.dout 	(t_wb_lsu_valid_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_wd_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_reg_wen_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_reg_wen_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(5  ),
		.RESET_VAL 	(0  ))
	ex_lsu_wreg_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_wreg_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_wreg_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	ex_lsu_alu_result_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_reg_wdata_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_reg_wdata_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	ex_lsu_mem_wen_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_csr_wdata_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_csr_wdata_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(3  ),
		.RESET_VAL 	(0  ))
	ex_lsu_mem_wdata_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_csr_type_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_csr_type_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	ex_lsu_load_type_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_lsu_memory_inst_i   ),
		.wen  	(wen  ),
		.dout 	(t_wb_memory_inst_o  )
	);
	

endmodule

