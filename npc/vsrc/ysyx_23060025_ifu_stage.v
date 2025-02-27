/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_ifu_stage #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	input									clock				,
	input									reset				,
    // hand signal

	// ifu ifu_valid_o
	// output									ifu_valid_o	        ,
	// input									idu_ready_i	        ,
	input									idu_valid_i	        ,
	input									ds_allowin_i	    ,
	output									fs_to_ds_valid_o	,
	

    // refresh if_pc_o
	input									branch_request_i,	
	input		[ADDR_WIDTH - 1:0]			branch_target_i	,
	input									branch_flag_i	,
	input									ebreak_flag_i	,
	input                                   jmp_flag_i      ,
    input       [31:0]                   	jmp_target_i    ,
	input									csr_jmp_i	    ,
	input		[ADDR_WIDTH - 1:0]			csr_pc_i	    ,

    // get instruction
    output 		[DATA_WIDTH - 1:0]			if_inst_o	,
	output 		[ADDR_WIDTH - 1:0]			if_pc_o			,

	// IFU-AXI
	// Addr Read
	output	reg	 [ADDR_WIDTH - 1:0]			out_paddr,
	output			                		out_psel,

	// Read data
	input		                		out_pready	,	// icache read data ready
	input	[31:0]	                	out_prdata	// icache read data
);
	wire		[ADDR_WIDTH - 1:0]	        pc_plus_4	;
	// reg 		[DATA_WIDTH - 1:0]			out_prdata	;

`ifdef N_YOSYS_STA_CHECK

	import "DPI-C" function void pc_node_init(int pc, int dnpc);
	always @(posedge clock) begin
		if(reset)begin
		end
		else if(next_state_fs && ~con_state_fs) begin
			pc_node_init(fs_pc, nextpc);
		end else if(ebreak_flag_i) begin
			pc_node_init(fs_pc, nextpc);
		end
			
	end
	// 检测到ebreak
    // import "DPI-C" function void ifebreak_func(int inst);
    // always @(*)
    //     ifebreak_func(out_prdata);

	// TODO: 目前只有 lui I-addi/slti/sltiu/xori/ori/andi/slli/srli/srai R 
	wire	inst_invalid = ~((out_prdata[6:0] == `TYPE_U_LUI_OPCODE) | // lui
					(out_prdata[6:0] == `TYPE_U_AUIPC_OPCODE) | //U-auipc 
					(out_prdata[6:0] == `TYPE_J_JAL_OPCODE) | 	 					     //jal
					({out_prdata[14:12], out_prdata[6:0]} == {`TYPE_I_JALR_FUNC3, `TYPE_I_JALR_OPCODE}) |			 //I-jalr
					({out_prdata[6:0]} == `TYPE_B_OPCODE) |			 //B-beq
					((out_prdata[6:0] == `TYPE_I_LOAD_OPCODE) & (out_prdata[14:12] == `TYPE_I_LB_FUNC3 | out_prdata[14:12] == `TYPE_I_LH_FUNC3 | out_prdata[14:12] == `TYPE_I_LW_FUNC3 | out_prdata[14:12] == `TYPE_I_LBU_FUNC3 | out_prdata[14:12] == `TYPE_I_LHU_FUNC3)) |	 //I-lb lh lw lbu lhu
					((out_prdata[6:0] == `TYPE_I_CSR_OPCODE) & (out_prdata[14:12] == `TYPE_I_CSRRW_FUNC3 | out_prdata[14:12] == `TYPE_I_CSRRS_FUNC3)) |	 //I-csrrw csrrs
					((out_prdata[6:0] == `TYPE_S_OPCODE) & (out_prdata[14:12] == `TYPE_S_SB_FUNC3 | out_prdata[14:12] == `TYPE_S_SH_FUNC3 | out_prdata[14:12] == `TYPE_S_SW_FUNC3))	|		//S-sb sh sw
					((out_prdata[6:0] == `TYPE_I_BASE_OPCODE) & (out_prdata[14:12] == `TYPE_I_SLTI_FUNC3 || out_prdata[14:12] == `TYPE_I_SLTIU_FUNC3 || out_prdata[14:12] == `TYPE_I_ADDI_FUNC3 || out_prdata[14:12] == `TYPE_I_XORI_FUNC3 || out_prdata[14:12] == `TYPE_I_ORI_FUNC3 || out_prdata[14:12] == `TYPE_I_ANDI_FUNC3 || 
														{out_prdata[14:12], out_prdata[31:25]} == `TYPE_I_SLLI_FUNC3_IMM || {out_prdata[14:12], out_prdata[31:25]} == `TYPE_I_SRLI_FUNC3_IMM || {out_prdata[14:12], out_prdata[31:25]} == `TYPE_I_SRAI_FUNC3_IMM)) |	 //I-addi slli srli srai xori ori andi
					(out_prdata[6:0] == `TYPE_R_OPCODE) | //R
					(out_prdata == `TYPE_I_ECALL) | 
					(out_prdata == `TYPE_I_MRET)  | 
					(out_prdata == `TYPE_I_FENCEI)  | 
					(out_prdata == `TYPE_I_EBREAK));

	import "DPI-C" function void inst_invalid_get(byte invalid, int pc);
		always @(posedge clock) begin
			if(out_pready)
				inst_invalid_get({7'b0, inst_invalid}, fs_pc);
		end
	`ifdef PERFORMANCE_COUNTER
	import "DPI-C" function void ifu_p_counter_update();
	import "DPI-C" function void pre_ifu_counter_update();
	always @(posedge clock) begin
		if(reset) begin
			
		end else if (next_state_fs && ~con_state_fs) begin
			ifu_p_counter_update();
		end
	end
	always @(posedge clock) begin
		if(reset) begin
			
		end else if (~ebreak_flag_i && ~next_state_fs) begin
			pre_ifu_counter_update();
		end
	end
	`endif
`endif

	// pre IFU stage

	// assign out_psel = (fs_allowin && !pfs_excp && !tlb_excp_lock_pc || flush_sign || btb_pre_error_flush) && !(idle_flush || idle_lock);

	reg con_state_fs;	// 0-pre, 1-ifu
	reg next_state_fs;
	always @(posedge clock) begin
		if(reset) begin
			con_state_fs <= 1'b0;
		end else begin
			con_state_fs <= next_state_fs;
		end
	end

	assign next_state_fs = con_state_fs ? ~fs_allowin : to_fs_valid & ~ebreak_flag_i;
	
	assign out_psel = con_state_fs && next_state_fs && ~fs_ready_go;	// 选中icache
	// assign out_paddr = nextpc;

	always @(posedge clock) begin
		if(reset) begin
			out_paddr <= 0;
		end else if(~con_state_fs && next_state_fs) begin
			out_paddr <= nextpc;
		end
	end

	// id得到结果 or id not busy
	wire to_fs_valid = idu_valid_i | ds_allowin_i;

	assign pc_plus_4 = fs_pc + 32'b100;
	wire [31:0] nextpc = (branch_flag_i & branch_request_i) ? branch_target_i : 
							jmp_flag_i 						? jmp_target_i : 
							csr_jmp_i 						? csr_pc_i : 
							pc_plus_4;

	// IFU stage
	// 1. 握手相关的信号
	reg [31:0] fs_pc;
	
	// wire fs_ready_go    = out_pready || inst_buff_enable;
	wire fs_ready_go    = out_pready || inst_buff_enable;			// 当前指令准备好传递，inst第一个有效周期开始拉高
	wire fs_allowin     = fs_ready_go && ds_allowin_i;	// 当前无指令执行或者当前指令处理完毕 下一周期就会传递
	assign fs_to_ds_valid_o =  fs_ready_go;

	always @(posedge clock) begin
		if (reset) begin
			fs_pc        <= `PC_RESET_VAL - 4;  //trick: to make nextpc be 0x1c000000 during reset 
		end
		else if (~con_state_fs && to_fs_valid) begin
			fs_pc        <= nextpc;
		end
	end

	// 2. 指令相关的存储
	reg inst_buff_enable;
	reg  [31:0] inst_rd_buff;
	wire [31:0]  fs_inst     = inst_buff_enable ? inst_rd_buff : out_prdata;
	// wire n_ds_update = out_pready && !ds_allowin_i;
	// wire ds_update = inst_buff_enable && ds_allowin_i;

	//inst read buffer  use for stall situation
	always @(posedge clock) begin
		// fs_ready_go && ds_allowin -> inst往下一级传递，无需buffer
		if (reset || inst_buff_enable && ds_allowin_i) begin	
			inst_buff_enable  <= 1'b0;
		end
		// 下一级还没准备好接受数据，需要先存到buffer中
		else if (out_pready && !ds_allowin_i) begin
			inst_rd_buff <= out_prdata;
			inst_buff_enable  <= 1'b1;
		end
	end

	// 给下一级使用的寄存器：inst/pc
	assign if_inst_o = fs_inst;
	assign if_pc_o = fs_pc;

endmodule
