/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"

module ysyx_23060025_IFU #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32)(
	input									clock				,
	input									reset				,
    // hand signal

	// ifu ifu_valid_o
	output									ifu_valid_o	        ,
	input									idu_ready_i	        ,
	input									idu_valid_i	        ,

    // refresh if_pc_o
	input									branch_request_i,	
	input		[ADDR_WIDTH - 1:0]			branch_target_i	,
	input									branch_flag_i	,
	input                                   jmp_flag_i      ,
    input       [31:0]                   	jmp_target_i    ,
	input									csr_jmp_i	    ,
	input		[ADDR_WIDTH - 1:0]			csr_pc_i	    ,

    // get instruction
    output 		[DATA_WIDTH - 1:0]			if_inst_o	,
	output reg	[ADDR_WIDTH - 1:0]			if_pc_o			,

	// IFU-AXI
	// Addr Read
	output	reg [ADDR_WIDTH - 1:0]		out_paddr,
	output	reg	                		out_psel,

	// Read data
	input		                		out_pready	,	// icache read data ready
	input	[31:0]	                	out_prdata	// icache read data
);
	wire		[ADDR_WIDTH - 1:0]	        pc_plus_4	;
	reg			[1:0]				        con_state	;
	reg			[1:0]			        	next_state	;
	// reg 		[DATA_WIDTH - 1:0]			out_prdata	;

	// delay test
`ifdef DELAY_TEST
	// random delay
	`ifdef RAN_DELAY
		reg				[3:0]		        	RANDOM_DELAY;
		wire			[3:0]		        	delay_num;

		ysyx_23060025_LFSR u_LFSR(
			.clock          ( clock          ),
			.rstn         ( ~reset         ),
			.initial_var  ( 4'b1  		 ),
			.result       ( delay_num    )
		);
		
		always @(posedge clock ) begin
			if (reset) 
				RANDOM_DELAY <= 4'b1;
			else if((con_state == STATE_WAIT_INST_FINISH && next_state == STATE_RUN) || (con_state == STATE_RUN && next_state == STATE_READ))
				RANDOM_DELAY <= delay_num;
		end

	// fixed var delay
	`elsif VAR_DELAY
		// 当 RAN_DELAY 未定义，但 VAR_DELAY 被定义时，编译这段代码
		wire				[3:0]		        	RANDOM_DELAY;
		assign RANDOM_DELAY = `VAR_DELAY;
	`endif

	reg			[3:0]		addr_r_valid_delay;
	reg			[3:0]		r_ready_delay;

	// assign out_psel = (con_state == STATE_RUN) & ~reset & (addr_r_valid_delay == RANDOM_DELAY);
	assign out_psel = (con_state == STATE_RUN) & ~reset;
	assign out_prdata = (con_state == STATE_READ) & (r_ready_delay == RANDOM_DELAY);

	// r addr delay
	always @(posedge clock ) begin
		if (next_state == STATE_RUN && (addr_r_valid_delay != RANDOM_DELAY || addr_r_valid_delay == 0))
			addr_r_valid_delay <= addr_r_valid_delay + 1;
		else if(next_state == STATE_RUN && addr_r_valid_delay == RANDOM_DELAY)
			addr_r_valid_delay <= addr_r_valid_delay;
		else 
			addr_r_valid_delay <= 4'b0;
	end

	always @(posedge clock ) begin
		if (next_state == STATE_READ && ((r_ready_delay != RANDOM_DELAY || r_ready_delay == 0)))
			r_ready_delay <= r_ready_delay + 1;
		else if(next_state == STATE_READ && r_ready_delay == RANDOM_DELAY)
			r_ready_delay <= r_ready_delay;
		else  
			r_ready_delay <= 4'b0;
	end
// no delay
`else
	// assign out_psel = (next_state == STATE_RUN) & ~reset;
`endif
	assign ifu_valid_o = (out_pready || con_state == STATE_WAIT_IDU_READY);

`ifdef N_YOSYS_STA_CHECK

	import "DPI-C" function void pc_node_init(int pc, int dnpc);
	always @(posedge clock) begin
		if(reset)begin
		end
		else if(con_state == STATE_PRE_IFU && next_state == STATE_RUN)
			pc_node_init(pc, pc_next);
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
					// ((out_prdata[6:0] == `TYPE_I_CSR_OPCODE) & (out_prdata[14:12] == `TYPE_I_CSRRW_FUNC3 | out_prdata[14:12] == `TYPE_I_CSRRS_FUNC3)) |	 //I-csrrw csrrs
					((out_prdata[6:0] == `TYPE_S_OPCODE) & (out_prdata[14:12] == `TYPE_S_SB_FUNC3 | out_prdata[14:12] == `TYPE_S_SH_FUNC3 | out_prdata[14:12] == `TYPE_S_SW_FUNC3))	|		//S-sb sh sw
					((out_prdata[6:0] == `TYPE_I_BASE_OPCODE) & (out_prdata[14:12] == `TYPE_I_SLTI_FUNC3 || out_prdata[14:12] == `TYPE_I_SLTIU_FUNC3 || out_prdata[14:12] == `TYPE_I_ADDI_FUNC3 || out_prdata[14:12] == `TYPE_I_XORI_FUNC3 || out_prdata[14:12] == `TYPE_I_ORI_FUNC3 || out_prdata[14:12] == `TYPE_I_ANDI_FUNC3 || 
														{out_prdata[14:12], out_prdata[31:25]} == `TYPE_I_SLLI_FUNC3_IMM || {out_prdata[14:12], out_prdata[31:25]} == `TYPE_I_SRLI_FUNC3_IMM || {out_prdata[14:12], out_prdata[31:25]} == `TYPE_I_SRAI_FUNC3_IMM)) |	 //I-addi slli srli srai xori ori andi
					(out_prdata[6:0] == `TYPE_R_OPCODE) | //R
					// (out_prdata == `TYPE_I_ECALL) | 
					// (out_prdata == `TYPE_I_MRET)  | 
					// (out_prdata == `TYPE_I_FENCEI)  | 
					(out_prdata == `TYPE_I_EBREAK));

	import "DPI-C" function void inst_invalid_get(byte invalid, int pc);
		always @(posedge clock) begin
			if(out_pready)
				inst_invalid_get({7'b0, inst_invalid}, pc);
		end
	`ifdef PERFORMANCE_COUNTER
	import "DPI-C" function void ifu_p_counter_update();
	always @(posedge clock) begin
		if (con_state == STATE_RUN) begin
			ifu_p_counter_update();
		end
	end
	`endif
`endif

	parameter [1:0] STATE_PRE_IFU = 2'b00, STATE_RUN = 2'b01, STATE_WAIT_IDU_READY = 2'b11, STATE_STOP = 2'b10;

	// state trans
	always @(posedge clock ) begin
		if(reset)
			con_state <= STATE_PRE_IFU;
		else 
			con_state <= next_state;
	end

	// next_state
	always @(*) begin
		next_state = con_state;
		case(con_state) 
			// get jmp branch pc from decoder
			STATE_PRE_IFU: begin
				if(idu_valid_i | idu_ready_i) begin
					next_state = STATE_RUN;
				end
			end
			STATE_RUN: begin
				if (out_pready & out_prdata == `TYPE_I_EBREAK) begin
					next_state = STATE_STOP;
				// idu busy
				end else if (out_pready & ~idu_ready_i) begin
					next_state = STATE_WAIT_IDU_READY;
				end else if (out_pready)  begin
					next_state = STATE_PRE_IFU;
				end
			end
			STATE_WAIT_IDU_READY: begin 
				if(idu_ready_i) begin
					next_state = STATE_PRE_IFU;
				end
			end
			default: begin
				
			end
				
		endcase
	end
	
	// 访问cache
	reg [31:0] pc;
	assign pc_plus_4 = pc + 32'b100;

	wire [31:0] pc_next = (branch_flag_i & branch_request_i) ? branch_target_i : 
							jmp_flag_i 						? jmp_target_i : 
							csr_jmp_i 						? csr_pc_i : 
							pc_plus_4;

	// CSR_ECALL       3'b110
	// CSR_MRET        3'b011
	// wire [31:0] csr_pc = csr_jmp_i[0] ? csr_mepc_pc_i : csr_mtvec_pc_i;

	always @(posedge clock) begin
		if(reset) begin
			pc <= `PC_RESET_VAL - 4;
		// only when STATE_PRE_IFU has just one cycle
		end else if(con_state == STATE_PRE_IFU && next_state == STATE_RUN) begin
			pc <= pc_next;
		end
	end
	// assign out_paddr = pc_next;

	always @(posedge clock) begin
		if(reset) begin
			out_paddr <= 0;
		end else if(con_state == STATE_PRE_IFU && next_state == STATE_RUN) begin
			out_paddr <= pc_next;
		end
	end

	assign out_psel = (con_state == STATE_RUN && next_state == STATE_RUN) & ~reset;

	// 给下一级使用的寄存器：inst/pc
	assign if_inst_o = out_prdata;
	assign if_pc_o = pc;



endmodule
