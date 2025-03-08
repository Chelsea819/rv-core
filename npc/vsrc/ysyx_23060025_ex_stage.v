/*************************************************************************
	> File Name: ysyx_23060025_add.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时24分15秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
module ysyx_23060025_ex_stage #(parameter DATA_LEN = 32)(
	input									      clock				        ,
    input									      reset				        ,

		//to ds forward path
    output [`ES_TO_DS_FORWARD_BUS -1:0] 		 es_to_ds_forward_bus,
	input [`DS_TO_ES_DATA_BUS -1:0]              ds_to_es_bus,
	output [`ES_TO_MS_DATA_BUS -1:0]             es_to_ms_bus,

	// idu_exu
    input                                         ds_to_ex_valid_i           ,
    output                                        es_allowin_o               ,
`ifdef DEBUG
	output     [31:0]                                   pc_o               ,
`endif 
	output	reg							          es_valid_o	        ,
    // exu_lsu
    output                                        es_to_lsu_valid_o          ,
    input                                         lsu_allowin_i               
    // input                                         isu_ready                 ,
    // output                                        es_allowin_o                 ,    	
);
	wire			[DATA_LEN - 1:0]		alu_result_o;
	wire  	    	[DATA_LEN - 1:0]     	csr_wdata_o	;
	wire es_ready_go_o;
	wire		[DATA_LEN - 1:0]		reg1_i			;
	wire		[DATA_LEN - 1:0]		reg2_i			;
	wire		[DATA_LEN - 1:0]		pc_i			;
	wire 		[3:0]					alu_control		;
    wire 		[3:0]					alu_sel			; // choose source number
	wire        [DATA_LEN - 1:0]        imm_i			;
	wire 		[2:0]					csr_flag_i		;
	wire		                		wd_i			;
    wire		[4:0]		            wreg_i			;
	wire		[1:0]					store_type_i	;
	wire        [2:0]                   load_type_i 	;
	wire                                ebreak_flag_i 	;

	wire        [DATA_LEN - 1:0]        csr_rdata_i		;
	wire  	    [11:0]     				csr_waddr_i		;

	`ifdef DEBUG
		assign pc_o = pc_i;
	`endif
	reg [`DS_TO_ES_DATA_BUS -1:0]       ds_to_es_bus_reg;
	always @(posedge clock) begin
		if(reset) begin
			ds_to_es_bus_reg <= 0;
		end else if(ds_to_ex_valid_i & es_allowin_o) begin
			ds_to_es_bus_reg <= ds_to_es_bus;
		end
	end

	assign { reg1_i		  ,     
			reg2_i			,
			pc_i			,
			alu_control		,
			alu_sel			,
			imm_i			,
			csr_flag_i		,
			csr_rdata_i		,
			csr_waddr_i		,
			wd_i			,
			wreg_i			,
			store_type_i	,
			load_type_i 	,
			ebreak_flag_i 	} = ds_to_es_bus_reg;
	
	assign es_to_ms_bus = {
					wd_i, 
					wreg_i,
					alu_result_o,
					|store_type_i,
					reg2_i,
					load_type_i,
					store_type_i,
					csr_wdata_o,
					csr_flag_i,
					csr_waddr_i,
					csr_mcause_o,
					ebreak_flag_i
							};


	wire [31:0] src1;
	wire [31:0] src2;
	wire [31:0] csr_mcause_o  = 32'hb;

`ifdef N_YOSYS_STA_CHECK
	`ifdef PERFORMANCE_COUNTER
	import "DPI-C" function void exu_p_counter_update();
	always @(posedge clock) begin
		if (es_allowin_o & es_to_lsu_valid_o) begin
			exu_p_counter_update();
		end
	end
	`endif
`endif

	wire es_csr_wen = csr_flag_i == `CSR_CSRRW 
						|| csr_flag_i == `CSR_CSRRS
						|| csr_flag_i == `CSR_ECALL;

	//forward path
	wire dest_zero            = (wreg_i == 5'b0); 
	wire forward_enable       = wd_i & ~dest_zero & es_valid_o;
	wire csr_forward_enable       = es_csr_wen & es_valid_o;
	wire dep_need_stall       = 1;
	assign es_to_ds_forward_bus = {dep_need_stall ,  //38:38
                               forward_enable ,  //37:37
                               wreg_i        ,  //36:32
                               alu_result_o ,        //31:0
							   csr_forward_enable,
							   csr_waddr_i ,
							   csr_wdata_o ,
							   csr_flag_i
                              };

	assign es_allowin_o    = !es_valid_o || es_ready_go_o && lsu_allowin_i;
    assign es_ready_go_o   = 1;
    assign es_to_lsu_valid_o = es_valid_o && es_ready_go_o;
    always @(posedge clock) begin   //bug1 no reset; branch no delay slot
        if (reset) begin
            es_valid_o <= 1'b0;
        end
        else begin 
            if (es_allowin_o) begin   //bug2 ??
                es_valid_o <= ds_to_ex_valid_i;
            end
        end
        // if (fs_to_ds_valid && ds_allowin) begin
        //     fs_to_ds_bus_r <= fs_to_ds_bus;
        // end
    end

	wire csr_cssrw = csr_flag_i == `CSR_CSRRW;
	wire csr_cssrs = csr_flag_i == `CSR_CSRRS;
	wire csr_ecall = csr_flag_i == `CSR_ECALL;

	wire [31:0] csr_csrrs_res = reg1_i | csr_rdata_i;
	
	assign csr_wdata_o = {32{csr_cssrw}} & reg1_i 
				| {32{csr_cssrs}} & csr_csrrs_res  
				| {32{csr_ecall}} & pc_i;

	ysyx_23060025_ALU my_alu(
		.src1						(src1),
		.src2						(src2),
		.alu_op_sel_add				(alu_op_sel_add),
		.alu_op_sel_sub				(alu_op_sel_sub),
		.alu_op_sel_xor				(alu_op_sel_xor),
		.alu_op_sel_or				(alu_op_sel_or),
		.alu_op_sel_and				(alu_op_sel_and),
		.alu_op_sel_right_logic		(alu_op_sel_right_logic),
		.alu_op_sel_right_arithe	(alu_op_sel_right_arithe),
		.alu_op_sel_less_unsigned	(alu_op_sel_less_unsigned),
		.alu_op_sel_less_signed		(alu_op_sel_less_signed),
		.alu_op_sel_left_logic		(alu_op_sel_left_logic ),
		.result						(alu_result_o )
	);

	wire aluop1_sel_zero = alu_sel[1:0] == `ALU_SEL1_ZERO;
	wire aluop1_sel_reg1 = alu_sel[1:0] == `ALU_SEL1_REG1;
	wire aluop1_sel_pc = alu_sel[1:0] == `ALU_SEL1_PC;
	wire aluop1_sel_csr = alu_sel[1:0] == `ALU_SEL1_CSR;

	wire aluop2_sel_zero 	= alu_sel[3:2] == `ALU_SEL2_ZERO;
	wire aluop2_sel_reg2 	= alu_sel[3:2] == `ALU_SEL2_REG2;
	wire aluop2_sel_imm 	= alu_sel[3:2] == `ALU_SEL2_IMM;
	wire aluop2_sel_4 		= alu_sel[3:2] == `ALU_SEL2_4;

	assign src1 = {32{aluop1_sel_zero}} & 32'b0 
				| {32{aluop1_sel_reg1}} & reg1_i 
				| {32{aluop1_sel_pc}} & pc_i 
				| {32{aluop1_sel_csr}} & csr_rdata_i ;

	assign src2 = {32{aluop2_sel_zero}} & 32'b0 
				| {32{aluop2_sel_reg2}} & reg2_i 
				| {32{aluop2_sel_imm}} & imm_i 
				| {32{aluop2_sel_4}} & 32'b100 ;

	wire alu_op_sel_add = (alu_control == `ALU_OP_ADD);

    wire alu_op_sel_sub = (alu_control == `ALU_OP_SUB);
    wire alu_op_sel_xor = (alu_control == `ALU_OP_XOR);
    wire alu_op_sel_or  = (alu_control == `ALU_OP_OR);

    wire alu_op_sel_and				= (alu_control == `ALU_OP_AND);
    wire alu_op_sel_right_logic 	= (alu_control == `ALU_OP_RIGHT_LOGIC);
    wire alu_op_sel_right_arithe 	= (alu_control == `ALU_OP_RIGHT_ARITH);
    wire alu_op_sel_left_logic 		= (alu_control == `ALU_OP_LEFT_LOGIC);
    wire alu_op_sel_less_unsigned 	= (alu_control == `ALU_OP_LESS_UNSIGNED);
    wire alu_op_sel_less_signed 	= (alu_control == `ALU_OP_LESS_SIGNED);


endmodule

