/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_id_ex #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	input									clock				,
	input									reset				,

    // from ifu
    input 		[DATA_WIDTH - 1:0]			f_id_reg1_i				,
	input 		[DATA_WIDTH - 1:0]			f_id_reg2_i				,
    input 		[ADDR_WIDTH - 1:0]			f_id_pc_i				,
	input 		[3:0]						f_id_aluop_i			,
    input 		[3:0]						f_id_alusel_i			,
	input 		[DATA_WIDTH - 1:0]			f_id_imm_i				,
	input 		[2:0]						f_id_csr_flag_i			,
    input 		                			f_id_wd_i				,
	input 		[1:0]						f_id_store_type_i			,
    input 		[2:0]            			f_id_load_type_i				,
	input 		[4:0]		    			f_id_wreg_i				,
	input 		                			f_id_ebreak_flag_i				,
	input 		                			f_id_valid_i				,
	input 		                			f_ex_ready_i				,

	input 		[DATA_WIDTH - 1:0]			f_csr_csr_rdata_i				,
	input 		[11:0]						f_csr_csr_waddr_i				,
	output 		[11:0]						t_ex_csr_waddr_o				,
	output 		[DATA_WIDTH - 1:0]			t_ex_csr_rdata_o				,

	// to idu
	output 		[DATA_WIDTH - 1:0]			t_ex_reg1_o				,
	output 		[DATA_WIDTH - 1:0]			t_ex_reg2_o				,
    output 		[ADDR_WIDTH - 1:0]			t_ex_pc_o				,
	output 		[3:0]						t_ex_aluop_o			,
    output 		[3:0]						t_ex_alusel_o			,
	output 		[DATA_WIDTH - 1:0]			t_ex_imm_o				,
	output 		[2:0]						t_ex_csr_flag_o			,
    output 		                			t_ex_wd_o				,
	output 		[1:0]						t_ex_store_type_o			,
    output 		[2:0]            			t_ex_load_type_o				,
	output 		[4:0]		    			t_ex_wreg_o				,
	output 		                			t_ex_ebreak_flag_o				

);
	wire wen = f_ex_ready_i & f_id_valid_i;

	ysyx_23060025_Reg #(
		.WIDTH     	(12  ),
		.RESET_VAL 	(0  ))
	id_ex_csr_waddr_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_csr_csr_waddr_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_csr_waddr_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	id_ex_csr_rdata_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_csr_csr_rdata_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_csr_rdata_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	id_ex_ebreak_flag_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_ebreak_flag_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_ebreak_flag_o  )
	);

	ysyx_23060025_Reg #(
		.WIDTH     	(2  ),
		.RESET_VAL 	(0  ))
	id_ex_store_type_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_store_type_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_store_type_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(3  ),
		.RESET_VAL 	(0  ))
	id_ex_load_type_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_load_type_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_load_type_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	id_ex_reg1_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_reg1_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_reg1_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	id_ex_reg2_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_reg2_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_reg2_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(ADDR_WIDTH  ),
		.RESET_VAL 	(0  ))
	id_ex_pc_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_pc_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_pc_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(4  ),
		.RESET_VAL 	(0  ))
	id_ex_aluop_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_aluop_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_aluop_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(4  ),
		.RESET_VAL 	(0  ))
	id_ex_alusel_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_alusel_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_alusel_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(DATA_WIDTH  ),
		.RESET_VAL 	(0  ))
	id_ex_imm_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_imm_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_imm_o  )
	);

	ysyx_23060025_Reg #(
		.WIDTH     	(3  ),
		.RESET_VAL 	(0  ))
	id_ex_csr_flag_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_csr_flag_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_csr_flag_o  )
	);

	ysyx_23060025_Reg #(
		.WIDTH     	(1  ),
		.RESET_VAL 	(0  ))
	id_ex_wd_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_wd_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_wd_o  )
	);
	ysyx_23060025_Reg #(
		.WIDTH     	(5  ),
		.RESET_VAL 	(0  ))
	id_ex_wreg_reg (
		.clk  	(clock   ),
		.rst  	(reset   ),
		.din  	(f_id_wreg_i   ),
		.wen  	(wen   ),
		.dout 	(t_ex_wreg_o  )
	);
	

endmodule

