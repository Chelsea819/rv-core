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
	input		[DATA_LEN - 1:0]		reg1_i		,
	input		[DATA_LEN - 1:0]		reg2_i		,
	input		[DATA_LEN - 1:0]		pc_i		,
    // input		[DATA_LEN - 1:0]		inst		,
	input 		[3:0]					alu_control	,
    input 		[3:0]					alu_sel		, // choose source number
	input       [DATA_LEN - 1:0]        imm_i		,
	input       [DATA_LEN - 1:0]        csr_rdata_i	,
	input  	    [11:0]     				csr_waddr_i		,
	input 		[2:0]					csr_flag_i	,
	input		                		wd_i		,
    input		[4:0]		            wreg_i		,
	input		[1:0]					store_type_i,
	input       [2:0]                   load_type_i ,
	input                               ebreak_flag_i             ,

		//to ds forward path
    output [`ES_TO_DS_FORWARD_BUS -1:0] es_to_ds_forward_bus,
    output                              es_to_ds_valid      ,

	// idu_exu
    input                                         ds_to_ex_valid_i           ,
    output                                        es_allowin_o               ,

	output	reg							          es_valid_o	        ,
	output									      es_ready_go_o	        ,
    // exu_lsu
    output                                        es_to_lsu_valid_o          ,
    input                                         lsu_allowin_i               ,

	output                                        ebreak_flag_o             ,

    // input                                         isu_ready                 ,
    // output                                        es_allowin_o                 ,
	output  	    [2:0]                	load_type_o 	,
	output  	    [1:0]					store_type_o	,
    output			                		mem_wen_o		,
	output			[DATA_LEN - 1:0]		mem_wdata_o		,
    output			                		wd_o			,
    output		    [4:0]		            wreg_o			,
	output  	    [DATA_LEN - 1:0]     	csr_wdata_o		,
	output  	    [11:0]     				csr_waddr_o		,
	output  	    [2:0]			    	csr_type_o		,
	output  	    [DATA_LEN - 1:0]     	csr_mcause_o	,
	output			[DATA_LEN - 1:0]		pc_o			,
    output			[DATA_LEN - 1:0]		alu_result_o
);

	wire [31:0] src1;
	wire [31:0] src2;
	assign wd_o  = wd_i;
	assign wreg_o  = wreg_i;
	assign csr_waddr_o = csr_waddr_i;
	assign mem_wen_o  = |store_type_i;
	assign mem_wdata_o  = reg2_i;
	assign load_type_o  = load_type_i;
	assign store_type_o  = store_type_i;
	assign pc_o  = pc_i;
	assign csr_mcause_o  = 32'hb;

	assign ebreak_flag_o = ebreak_flag_i;

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
	assign es_to_ds_valid = es_valid_o;


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

	assign csr_type_o = csr_flag_i;

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

