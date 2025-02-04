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
	input									last_finish		,
	output	reg								valid	        ,

    // refresh pc
	input									branch_request_i,	
	input		[ADDR_WIDTH - 1:0]			branch_target_i	,
	input									branch_flag_i	,
	input                                   jmp_flag_i      ,
    input       [31:0]                   	jmp_target_i    ,
	input									csr_jmp_i	    ,
	input		[ADDR_WIDTH - 1:0]			csr_pc_i	    ,

    // get instruction
    input		[DATA_WIDTH - 1:0]			addr_r_data_i	,
    output 		[DATA_WIDTH - 1:0]			id_inst_i	,
	output reg	[ADDR_WIDTH - 1:0]			pc			,

	// IFU-AXI
	// Addr Read
	output	reg	[ADDR_WIDTH - 1:0]		addr_r_addr_o,
	output		                		addr_r_valid_o,
	input		                		addr_r_ready_i,

	// Read data
	input		[1:0]					r_resp_i	,	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	input		                		r_valid_i	,
	output		                		r_ready_o	
);
	wire		[ADDR_WIDTH - 1:0]	        pc_plus_4	;
	reg			[1:0]				        con_state	;
	reg			[1:0]			        	next_state	;
	wire									inst_invalid;
	reg 		[DATA_WIDTH - 1:0]			inst_reg	;

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
			else if((con_state == IFU_WAIT_FINISH && next_state == STATE_IDLE) || (con_state == STATE_IDLE && next_state == STATE_READ))
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

	// assign addr_r_valid_o = (con_state == STATE_IDLE) & ~reset & (addr_r_valid_delay == RANDOM_DELAY);
	assign addr_r_valid_o = (con_state == STATE_IDLE) & ~reset;
	assign r_ready_o = (con_state == STATE_READ) & (r_ready_delay == RANDOM_DELAY);

	// r addr delay
	always @(posedge clock ) begin
		if (next_state == STATE_IDLE && (addr_r_valid_delay != RANDOM_DELAY || addr_r_valid_delay == 0))
			addr_r_valid_delay <= addr_r_valid_delay + 1;
		else if(next_state == STATE_IDLE && addr_r_valid_delay == RANDOM_DELAY)
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
	assign addr_r_valid_o = (con_state == STATE_IDLE) & ~reset;
	assign r_ready_o = (con_state == STATE_READ);
`endif
	assign valid = (con_state == STATE_READ && next_state == IFU_WAIT_READY);

	assign inst_invalid = ~((inst_reg[6:0] == `TYPE_U_LUI_OPCODE) | (inst_reg[6:0] == `TYPE_U_AUIPC_OPCODE) | //U-auipc lui
					 (inst_reg[6:0] == `TYPE_J_JAL_OPCODE) | 	 					     //jal
				     ({inst_reg[14:12], inst_reg[6:0]} == {`TYPE_I_JALR_FUNC3, `TYPE_I_JALR_OPCODE}) |			 //I-jalr
					 ({inst_reg[6:0]} == `TYPE_B_OPCODE) |			 //B-beq
					 ((inst_reg[6:0] == `TYPE_I_LOAD_OPCODE) & (inst_reg[14:12] == `TYPE_I_LB_FUNC3 | inst_reg[14:12] == `TYPE_I_LH_FUNC3 | inst_reg[14:12] == `TYPE_I_LW_FUNC3 | inst_reg[14:12] == `TYPE_I_LBU_FUNC3 | inst_reg[14:12] == `TYPE_I_LHU_FUNC3)) |	 //I-lb lh lw lbu lhu
					 ((inst_reg[6:0] == `TYPE_I_CSR_OPCODE) & (inst_reg[14:12] == `TYPE_I_CSRRW_FUNC3 | inst_reg[14:12] == `TYPE_I_CSRRS_FUNC3)) |	 //I-csrrw csrrs
					 ((inst_reg[6:0] == `TYPE_S_OPCODE) & (inst_reg[14:12] == `TYPE_S_SB_FUNC3 | inst_reg[14:12] == `TYPE_S_SH_FUNC3 | inst_reg[14:12] == `TYPE_S_SW_FUNC3))	|		//S-sb sh sw
					 ((inst_reg[6:0] == `TYPE_I_BASE_OPCODE) & (inst_reg[14:12] == `TYPE_I_SLTI_FUNC3 || inst_reg[14:12] == `TYPE_I_SLTIU_FUNC3 || inst_reg[14:12] == `TYPE_I_ADDI_FUNC3 || inst_reg[14:12] == `TYPE_I_XORI_FUNC3 || inst_reg[14:12] == `TYPE_I_ORI_FUNC3 || inst_reg[14:12] == `TYPE_I_ANDI_FUNC3 || 
					 										{inst_reg[14:12], inst_reg[31:25]} == `TYPE_I_SLLI_FUNC3_IMM || {inst_reg[14:12], inst_reg[31:25]} == `TYPE_I_SRLI_FUNC3_IMM || {inst_reg[14:12], inst_reg[31:25]} == `TYPE_I_SRAI_FUNC3_IMM)) |	 //I-addi slli srli srai xori ori andi
					 (inst_reg[6:0] == `TYPE_R_OPCODE) | //R
					 (inst_reg == `TYPE_I_ECALL) | 
					 (inst_reg == `TYPE_I_MRET)  | 
					 (inst_reg == `TYPE_I_EBREAK));

`ifdef N_YOSYS_STA_CHECK
	// 检测到ebreak
    import "DPI-C" function void ifebreak_func(int inst);
    always @(*)
        ifebreak_func(inst_reg);

	import "DPI-C" function void inst_invalid_get(byte invalid);
		always @(*) begin
			// $display("pc = %x dpc = %x\n",pc,pc_next);
			inst_invalid_get({7'b0, inst_invalid});
		end

	import "DPI-C" function void ifu_p_counter_update();
	always @(posedge clock) begin
		if (con_state == IFU_WAIT_READY) begin
			ifu_p_counter_update();
		end
	end
`endif

	parameter [1:0] STATE_IDLE = 2'b00, IFU_WAIT_READY = 2'b01, IFU_WAIT_FINISH = 2'b10, STATE_READ = 2'b11;

	// state trans
	always @(posedge clock ) begin
		if(reset)
			con_state <= STATE_IDLE;
		else 
			con_state <= next_state;
	end

	// next_state
	always @(*) begin
		next_state = con_state;
		case(con_state) 
			STATE_IDLE: begin
				if (addr_r_ready_i == 1'b1) begin
					next_state = STATE_READ;
				end
			end
			// TODO: 这里的设计很不优雅，由于r_ready_o依赖于STATE_READ，如果进行delay测试，结果应该为：
			// STATE_READ: begin
			// 	if (r_ready_delay == RANDOM_DELAY) && r_valid_i == 1'b1 && r_resp_i == 2'b00) begin
			// 		next_state = IFU_WAIT_READY;
			// 	end 
			// end
			STATE_READ: begin
				if (r_valid_i == 1'b1 && r_resp_i == 2'b00) begin
					next_state = IFU_WAIT_READY;
				end 
			end
			IFU_WAIT_READY: begin 
				next_state = IFU_WAIT_FINISH;
			end
			IFU_WAIT_FINISH: begin 
				if (last_finish == 1'b0) begin
					next_state = IFU_WAIT_FINISH;
				end else begin 
					next_state = STATE_IDLE;
				end
			end
			default:
				next_state = 2'b0;
		endcase
	end

    // get new pc
    ysyx_23060025_counter#(
        .ADDR_LEN         ( 32 )
    )u_ysyx_23060025_counter(
        .clock              ( clock              ),
        .reset              ( reset              ),
        .branch_request_i ( branch_request_i ),
        .branch_target_i  ( branch_target_i  ),
        .branch_flag_i    ( branch_flag_i    ),
        .pc_plus_4        ( pc_plus_4        ),
        .jmp_flag_i       ( jmp_flag_i       ),
        .jmp_target_i     ( jmp_target_i     ),
        .csr_jmp_i        ( csr_jmp_i        ),
        .csr_pc_i         ( csr_pc_i         ),
		.con_state        ( con_state        ),
        .pc               ( pc               )
    );


	always @(posedge clock) begin
		if(reset) begin
			inst_reg <= 0;
		end else if(next_state == IFU_WAIT_READY) begin
			inst_reg <= addr_r_data_i;
		end
	end

	assign pc_plus_4 = pc + 32'b100;
	assign addr_r_addr_o = pc;
	assign id_inst_i = inst_reg;


endmodule
