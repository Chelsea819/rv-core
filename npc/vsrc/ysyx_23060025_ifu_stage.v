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

	// flush path
	input                                   fencei_flush_sign_i           ,
	input                                   fencei_flush_valid_i          ,	// hint: 由wb模块的逻辑易知valid仅维持一周期
	input		[ADDR_WIDTH - 1:0]			fencei_flush_pc_i  			  ,

	// ifu and idu interface
	input									idu_valid_i	        ,
	input									ds_allowin_i	    ,
	output									fs_to_ds_valid_o	,
	

    // from idu to ifu
	input									ebreak_flag_i	,
	input                                   jmp_flag_i      ,
    input       [31:0]                   	jmp_target_i    ,
	input									csr_jmp_i	    ,
	input		[ADDR_WIDTH - 1:0]			csr_pc_i	    ,
	input									idu_flush_i	    ,
	input		[ADDR_WIDTH - 1:0]			idu_flush_pc_i  ,

    // from ifu to idu
	output 		[`FS_TO_DS_DATA_BUS - 1:0]	if_to_id_bqu_bus_o,

	// from ifu to bpu
	// output 		[DATA_WIDTH - 1:0]			bpu_inst_o,
	// output 		[ADDR_WIDTH - 1:0]			bpu_pc_o,
	input 		[ADDR_WIDTH - 1:0]			bpu_pc_predict_i,
	input 									bpu_valid_i,

	// from ifu to cache
	output	reg	 [ADDR_WIDTH - 1:0]			out_paddr,
	output			                		out_psel,
	input		                			out_pready	,	// icache read data ready
	input		[31:0]	                	out_prdata	// icache read data
);

	// valid idu_flush
	wire idu_flush = idu_flush_i & idu_valid_i;

	// 处理flush
	// flush时，to_next_valid -> 0
	// 		   xx_valid -> 0, allowin -> 1
	wire fencei_flush_sign = fencei_flush_sign_i & fencei_flush_valid_i;

	wire flush_sign = fencei_flush_sign | idu_flush;

`ifdef N_YOSYS_STA_CHECK
	reg [31:0] history_pc;
	always @(posedge clock) begin
		if(reset) begin
			history_pc <= 0;
		end else if(fs_to_ds_valid_o & ds_allowin_i) begin
			history_pc <= fs_pc;
		end
	end

	import "DPI-C" function void pc_node_init(int pc, int dnpc);
	import "DPI-C" function void pc_node_cancel();
	import "DPI-C" function void cache_hit_cancel_statistic();
	always @(posedge clock) begin
		if(reset)begin
		end
		// 1. pre ifu flush --(ok)--> ifu -> ok
		// 2. pre -> ifu flush(cancel and init) ----> pre ifu --(ok)--> ifu -> ok
		else if(to_fs_valid & fs_allowin & idu_flush & ~idu_solved) begin
			pc_node_cancel();
			pc_node_init(history_pc, nextpc);
		end  else if(to_fs_valid & fs_allowin) begin
			pc_node_init(fs_pc, nextpc);
		end  else if(ebreak_flag_i) begin
			pc_node_init(fs_pc, nextpc);
		end
	end

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
			
		end else if (to_fs_valid & fs_allowin) begin
			ifu_p_counter_update();
		end
	end
	import "DPI-C" function void bqu_wrong_counter_update();
	always @(posedge clock) begin
		if(reset) begin
			
		end else if (idu_flush & ~idu_solved & to_fs_valid & fs_allowin) begin
			bqu_wrong_counter_update();
		end
	end
	`endif
`endif
	/******************************************************************************
	* **************************************************************
	* ************************** Pre_IFU **************************
	* **************************************************************
	******************************************************************************/
	// 1. BPU生成预测的pc
	// 2. 向icache发出取指请求
	// PRE_IFU -> IFU 握手信号
	// id得到结果 or id not busy
	assign out_psel = to_fs_valid & fs_allowin;
	wire pfs_ready_go = bpu_valid_i || (jmp_flag_i & idu_valid_i) || flush_sign;
	wire to_fs_valid = pfs_ready_go & ~reset;

	// 来自idu的flush or jmp信号是否已经处理完毕，避免重复处理（主要是nextpc的逻辑）
	reg idu_solved;
	always @(posedge clock) begin
		if(reset) begin
			idu_solved <= 0;
		// enter ifu, finish solving
		end else if(~idu_solved & to_fs_valid & fs_allowin & idu_valid_i) begin
			idu_solved <= jmp_flag_i | idu_flush;
		end else if(idu_solved & fs_to_ds_valid_o & ds_allowin_i) begin
			idu_solved <= 0;
		end
	end

	
	// idu_flush-》 pre刚好碰到valid flush
	// flush_state_is_busy -》 ifu->pre ifu->ifu
	// preifu阶段的nextpc值
	wire [31:0] nextpc = fencei_flush_sign	  	  ? fencei_flush_pc_i :
						 idu_flush & ~idu_solved  ? idu_flush_pc_i : // 一个周期出结果 idu_flush_i & valid
						 csr_jmp_i & ~idu_solved	? csr_pc_i : 
						 jmp_flag_i & ~idu_solved ? jmp_target_i : 
						bpu_pc_predict_i;

	/******************************************************************************
	* **************************************************************
	* ************************** IFU **************************
	* **************************************************************
	******************************************************************************/
	assign fs_to_ds_valid_o =  fs_valid && ~(idu_flush & ~idu_solved) && fs_ready_go && ~fencei_flush_sign;
	wire fs_ready_go    = out_pready || inst_buff_enable;			// 当前指令准备好传递，inst第一个有效周期开始拉高
	wire fs_allowin     = (fs_ready_go && ds_allowin_i) || ~fs_valid || (idu_flush & ~idu_solved);	// 当前无指令执行或者当前指令处理完毕 下一周期就会传递
	reg fs_valid;
	always @(posedge clock) begin
    if (reset || fencei_flush_sign) begin
        fs_valid <= 1'b0;
    end
    else if (fs_allowin) begin
        fs_valid <= to_fs_valid;
    end
end
	assign if_to_id_bqu_bus_o = {fs_inst, fs_pc};

	// IFU stage
	// 1. 握手相关的信号
	reg [31:0] fs_pc;
	always @(posedge clock) begin
		if (reset) begin
			fs_pc        <= `PC_RESET_VAL_SUB_4;  //trickd: to make nextpc be 0x1c000000 during reset 
		end
		else if (fs_allowin && to_fs_valid) begin
			fs_pc        <= nextpc;
		end
		
	end
	assign out_paddr = fs_pc;

	// 2. 指令相关的存储
	reg inst_buff_enable;
	reg  [31:0] inst_rd_buff;
	wire [31:0]  fs_inst     = inst_buff_enable ? inst_rd_buff : out_prdata;


	// inst read buffer  use for stall situation
	always @(posedge clock) begin
		// fs_ready_go && ds_allowin_i -> inst往下一级传递，无需buffer
		if (reset || (fs_ready_go && ds_allowin_i) || (idu_flush & ~idu_solved)) begin	
			inst_buff_enable  <= 1'b0;
		end
		// 下一级还没准备好接受数据，需要先存到buffer中
		else if (out_pready & ~(idu_flush & ~idu_solved)) begin
			inst_rd_buff <= out_prdata;
			inst_buff_enable  <= 1'b1;
		end
	end

	


endmodule
