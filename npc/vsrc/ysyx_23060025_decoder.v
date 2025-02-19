`include "ysyx_23060025_define.v"
module ysyx_23060025_decoder(
    input									      clock				        ,
    input									      reset				        ,
    input           [31:0]                        inst_i                    ,
    input           [31:0]                        reg1_data_i               ,
    input           [31:0]                        reg2_data_i               ,
    input           [31:0]                        pc_i                      ,

    // ifu_idu
    input                                         ifu_valid_i               ,
    output                                        idu_ready_o               ,

    input                                         conflict_id_nop_i         ,
    input           [31:0]                        conflict_bypass_data_i    ,
    input                                         conflict_reg0_i           ,
    input                                         conflict_reg1_i           ,
    input                                         conflict_valid_i          ,

    // idu_exu
    output                                        idu_valid_o               ,
    input                                         exu_ready_i               ,

    // data bypass
	// from exeu
    // TODO: add exu valid logic, when exu not least one cycle
	// input		[31:0]			            exu_reg_wdata_i	,
	// // from lsu
	// input		[31:0]			            lsu_reg_wdata_i	,

    // input                                         exu_ready                 ,
    output          [3:0]                         aluop_o                   ,
    output          [3:0]                         alusel_o                  ,
    output          [31:0]                        pc_o                      ,
    output          [31:0]                        reg1_o                    ,
    output          [31:0]                        reg2_o                    ,
    output	                   		              wd_o                      ,
    output	        [4:0]		                  wreg_o                    ,
    output          [4:0]                         reg1_addr_o               ,
    output          [4:0]                         reg2_addr_o               ,
    output                                        reg1_ren_o               ,
    output                                        reg2_ren_o               ,
    output                                        branch_flag_o             ,
    output          [2:0]                         branch_type_o             ,
    output          [31:0]                        branch_target_o           ,
    output          [1:0]                         store_type_o              ,
    output          [2:0]                         load_type_o              ,
    output                                        jmp_flag_o                ,
    output                                        fencei_flag_o             ,
    output                                        ebreak_flag_o             ,
    output          [31:0]                        jmp_target_o              ,
    output          [11:0]                        csr_addr_o                ,
    output          [2:0]                         csr_flag_o                ,
    output          [31:0]                        imm_o         
);
    wire            [6:0]                          func7;
    wire            [2:0]                          func3;
    wire            [6:0]                          opcode;

    assign func3 = inst_i[14:12];
    assign func7 = inst_i[31:25];
    assign opcode = inst_i[6:0];
    assign pc_o = pc_i;

    assign reg1_o = conflict_reg0_i ? conflict_bypass_data_i : reg1_data_i;
    assign reg2_o = conflict_reg1_i ? conflict_bypass_data_i : reg2_data_i;
    assign wreg_o = inst_i[11:7];
    assign reg1_addr_o = inst_i[19:15];
    assign reg2_addr_o = inst_i[24:20];

    assign branch_target_o = pc_i + imm_o;
    assign csr_addr_o = inst_i[31:20];
   

    assign idu_valid_o = (con_state == STATE_RUN && (next_state == STATE_WAIT_IFU_VALID || next_state == STATE_WAIT_READY)) || con_state == STATE_WAIT_READY;
    assign idu_ready_o = (con_state == STATE_WAIT_IFU_VALID) ;


    reg			[1:0]			        	con_state	;
	reg			[1:0]			        	next_state	;
    parameter [1:0] STATE_WAIT_IFU_VALID = 2'b00, STATE_RUN = 2'b01, STATE_WAIT_READY = 2'b10, STATE_IS_RAW = 2'b11;
                                                                                                                                                             

	// state trans
	always @(posedge clock ) begin
		if(reset)
			con_state <= STATE_WAIT_IFU_VALID;
		else 
			con_state <= next_state;
	end
    
`ifdef N_YOSYS_STA_CHECK
    `ifdef PERFORMANCE_COUNTER
    import "DPI-C" function void idu_p_counter_update(byte opcode, byte func3);
	always @(posedge clock) begin
		if (con_state == IDU_WAIT_IDU_VALID && next_state == STATE_WAIT_EXU_READY) begin
			idu_p_counter_update({1'b0, opcode}, {5'b0, func3});
		end
	end
    `endif
`endif
	// next_state
	always @(*) begin
        next_state = con_state;
		case(con_state) 
            // 等待ifu取指，下一个时钟周期开始译码
            STATE_WAIT_IFU_VALID: begin
				if (ifu_valid_i) begin
					next_state = STATE_RUN;
				end
			end
            STATE_RUN: begin
                // 出现了数据相关
                // 一个信号标志着，空泡期
                if(conflict_id_nop_i) begin
                    next_state = STATE_RUN;
                end else if(~exu_ready_i) begin
                    next_state = STATE_WAIT_READY;
                end else begin
                    next_state = STATE_WAIT_IFU_VALID;
                end
            end
            STATE_WAIT_READY: begin 
				if (exu_ready_i) begin
					next_state = STATE_WAIT_IFU_VALID;
				end
			end
            STATE_IS_RAW: begin
                if(conflict_valid_i) begin
                    next_state = STATE_RUN;
                end
            end
            default: begin 
			end 
		endcase
	end


assign reg1_ren_o = (alusel_o[1:0] == `ALU_SEL1_REG1) | {opcode, func3} == {`TYPE_I_JALR_OPCODE, `TYPE_I_JALR_FUNC3};
assign reg2_ren_o = (alusel_o[3:2] == `ALU_SEL2_REG2) | (store_type_o != `STORE_INVALID);
    
// controller look-up lut
// inst: R-type: wd_o aluop_o alusel_o
// alu_sel  [1:0] res1/pc_o/0, [3:2] res2/imm_o/4/0
// alu_op + - 
assign {wd_o, aluop_o, alusel_o, store_type_o, load_type_o, ebreak_flag_o} = ({opcode, func3, func7}        == {`TYPE_R_OPCODE, `TYPE_R_ADD_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-add
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_SUB_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_SUB, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-sub
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_XOR_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_XOR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-xor
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_OR_FUNC})           ? {`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-or
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_AND_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_AND, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-and
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_SLL_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_LEFT_LOGIC, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-sll
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_SRL_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_RIGHT_LOGIC, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-srl
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_SRA_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_RIGHT_ARITH, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-sra
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_SLT_FUNC})          ? {`EN_REG_WRITE, `ALU_OP_LESS_SIGNED, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-slt
                                                              ({opcode, func3, func7}                       == {`TYPE_R_OPCODE, `TYPE_R_SLTU_FUNC})         ? {`EN_REG_WRITE, `ALU_OP_LESS_UNSIGNED, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-sltu
                                                              ({inst_i}                                     == {`TYPE_I_EBREAK})                          ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_ZERO,`ALU_SEL1_ZERO, `STORE_INVALID, `LOAD_INVALID}, `EBREAK_FLAG} :        // R-sltu
                                                              ({inst_i}                                     == {`TYPE_I_FENCEI})                          ? {~`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_ZERO,`ALU_SEL1_ZERO, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG} :        // R-sltu
                                                              ({inst_i}                                     == {`TYPE_I_ECALL})                           ? {~`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_ZERO,`ALU_SEL1_CSR, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :       // I-ecall
                                                              ({inst_i}                                     == {`TYPE_I_MRET})                            ? {~`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_ZERO,`ALU_SEL1_CSR, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :       // I-mret
                                                              ({opcode, func3}                              == {`TYPE_I_CSR_OPCODE, `TYPE_I_CSRRW_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_ZERO,`ALU_SEL1_CSR, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // I-csrrw
                                                              ({opcode, func3}                              == {`TYPE_I_CSR_OPCODE, `TYPE_I_CSRRS_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_ZERO,`ALU_SEL1_CSR, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // I-csrrs
                                                              ({opcode, func3}                              == {`TYPE_I_BASE_OPCODE, `TYPE_I_ADDI_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // I-addi
                                                              ({opcode, func3}                              == {`TYPE_I_BASE_OPCODE, `TYPE_I_XORI_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_XOR, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // I-xori
                                                              ({opcode, func3}                              == {`TYPE_I_BASE_OPCODE, `TYPE_I_ORI_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // I-ori
                                                              ({opcode, func3}                              == {`TYPE_I_BASE_OPCODE, `TYPE_I_ANDI_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_AND, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // I-andi
                                                              ({opcode, func3}                              == {`TYPE_I_BASE_OPCODE, `TYPE_I_SLTI_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_LESS_SIGNED, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // I-ori
                                                              ({opcode, func3}                              == {`TYPE_I_BASE_OPCODE, `TYPE_I_SLTIU_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_LESS_UNSIGNED, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // I-andi
                                                              ({opcode, func3}                              == {`TYPE_I_JALR_OPCODE, `TYPE_I_JALR_FUNC3}) ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_4,`ALU_SEL1_PC, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :            // I-jalr
                                                              ({opcode, func3, imm_o[11:5]}                 == {`TYPE_I_BASE_OPCODE, `TYPE_I_SLLI_FUNC3_IMM}) ? {`EN_REG_WRITE, `ALU_OP_LEFT_LOGIC, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // I-slli
                                                              ({opcode, func3, imm_o[11:5]}                 == {`TYPE_I_BASE_OPCODE, `TYPE_I_SRLI_FUNC3_IMM}) ? {`EN_REG_WRITE, `ALU_OP_RIGHT_LOGIC, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // I-slli
                                                              ({opcode, func3, imm_o[11:5]}                 == {`TYPE_I_BASE_OPCODE, `TYPE_I_SRAI_FUNC3_IMM}) ? {`EN_REG_WRITE, `ALU_OP_RIGHT_ARITH, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // I-slli
                                                              ({opcode, func3}                              == {`TYPE_S_OPCODE, `TYPE_S_SB_FUNC3})        ? {~`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_SB_8, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // S-sb
                                                              ({opcode, func3}                              == {`TYPE_S_OPCODE, `TYPE_S_SH_FUNC3})        ? {~`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_SH_16, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // S-sh
                                                              ({opcode, func3}                              == {`TYPE_S_OPCODE, `TYPE_S_SW_FUNC3})        ? {~`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_SW_32, `LOAD_INVALID}, ~`EBREAK_FLAG}  :        // S-sw
                                                              ({opcode, func3}                              == {`TYPE_I_LOAD_OPCODE, `TYPE_I_LB_FUNC3})        ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_LB_8}, ~`EBREAK_FLAG}  :         // L-sb
                                                              ({opcode, func3}                              == {`TYPE_I_LOAD_OPCODE, `TYPE_I_LH_FUNC3})        ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_LH_16}, ~`EBREAK_FLAG}  :        // L-sh
                                                              ({opcode, func3}                              == {`TYPE_I_LOAD_OPCODE, `TYPE_I_LW_FUNC3})        ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_LW_32}, ~`EBREAK_FLAG}  :        // L-sw
                                                              ({opcode, func3}                              == {`TYPE_I_LOAD_OPCODE, `TYPE_I_LBU_FUNC3})       ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_LBU_8}, ~`EBREAK_FLAG}  :         // L-sb
                                                              ({opcode, func3}                              == {`TYPE_I_LOAD_OPCODE, `TYPE_I_LHU_FUNC3})       ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_LHU_16}, ~`EBREAK_FLAG}  :        // L-sh
                                                              ({opcode}                                     == {`TYPE_J_JAL_OPCODE})                      ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_4,`ALU_SEL1_PC, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :            // J-jal
                                                              ({opcode, func3}                              == {`TYPE_B_OPCODE, `TYPE_B_BEQ_FUNC3})       ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}:        // B-beq
                                                              ({opcode, func3}                              == {`TYPE_B_OPCODE, `TYPE_B_BNE_FUNC3})       ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}:        // B-beq
                                                              ({opcode, func3}                              == {`TYPE_B_OPCODE, `TYPE_B_BLT_FUNC3})       ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}:        // B-beq
                                                              ({opcode, func3}                              == {`TYPE_B_OPCODE, `TYPE_B_BGE_FUNC3})       ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}:        // B-beq
                                                              ({opcode, func3}                              == {`TYPE_B_OPCODE, `TYPE_B_BLTU_FUNC3})       ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}:        // B-beq
                                                              ({opcode, func3}                              == {`TYPE_B_OPCODE, `TYPE_B_BGEU_FUNC3})       ? {~`EN_REG_WRITE, `ALU_OP_OR, {`ALU_SEL2_REG2,`ALU_SEL1_REG1, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}:        // B-beq
                                                              ({opcode}                                     == {`TYPE_U_AUIPC_OPCODE})                    ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_PC, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}    :        // U-auipc
                                                              ({opcode}                                     == {`TYPE_U_LUI_OPCODE})                      ? {`EN_REG_WRITE, `ALU_OP_ADD, {`ALU_SEL2_IMM,`ALU_SEL1_ZERO, `STORE_INVALID, `LOAD_INVALID}, ~`EBREAK_FLAG}  :         // U-lui  
                                                              0;                        

assign  {branch_type_o, jmp_target_o, jmp_flag_o, csr_flag_o} = ({opcode, func3} == {`TYPE_B_OPCODE, `TYPE_B_BEQ_FUNC3})             ? {`BRANCH_BEQ,     32'b0,             ~`EN_JMP, `CSR_INVALID}:         // B-beq
                                                                ({opcode, func3} == {`TYPE_B_OPCODE, `TYPE_B_BNE_FUNC3})             ? {`BRANCH_BNE,     32'b0,             ~`EN_JMP, `CSR_INVALID}:         // B-beq
                                                                ({opcode, func3} == {`TYPE_B_OPCODE, `TYPE_B_BLT_FUNC3})             ? {`BRANCH_BLT,     32'b0,             ~`EN_JMP, `CSR_INVALID}:         // B-beq
                                                                ({opcode, func3} == {`TYPE_B_OPCODE, `TYPE_B_BGE_FUNC3})             ? {`BRANCH_BGE,     32'b0,             ~`EN_JMP, `CSR_INVALID}:         // B-beq
                                                                ({opcode, func3} == {`TYPE_B_OPCODE, `TYPE_B_BLTU_FUNC3})            ? {`BRANCH_BLTU,    32'b0,             ~`EN_JMP, `CSR_INVALID}:         // B-beq
                                                                ({opcode, func3} == {`TYPE_B_OPCODE, `TYPE_B_BGEU_FUNC3})            ? {`BRANCH_BGEU,    32'b0,             ~`EN_JMP, `CSR_INVALID}:         // B-beq
                                                                ({opcode, func3} == {`TYPE_I_JALR_OPCODE, `TYPE_I_JALR_FUNC3})       ? {`BRANCH_INVALID, reg1_o + imm_o, `EN_JMP , `CSR_INVALID} :         // I-jalr
                                                                ({opcode}        == {`TYPE_J_JAL_OPCODE})                            ? {`BRANCH_INVALID, pc_i + imm_o,        `EN_JMP, `CSR_INVALID} :         // J-jal 
                                                                ({inst_i}        == {`TYPE_I_ECALL})                                 ? {`BRANCH_INVALID, 32'b0,             ~`EN_JMP, `CSR_ECALL}  :         // I-ecall 
                                                                ({inst_i}        == {`TYPE_I_MRET})                                  ? {`BRANCH_INVALID, 32'b0,             ~`EN_JMP, `CSR_MRET}   :         // I-mret 
                                                                ({opcode, func3} == {`TYPE_I_CSR_OPCODE, `TYPE_I_CSRRW_FUNC3})       ? {`BRANCH_INVALID, 32'b0,             ~`EN_JMP, `CSR_CSRRW}  :         // I-csrrw
                                                                ({opcode, func3} == {`TYPE_I_CSR_OPCODE, `TYPE_I_CSRRS_FUNC3})       ? {`BRANCH_INVALID, 32'b0,             ~`EN_JMP, `CSR_CSRRS}  :         // I-csrrs
                                                                0;       

ysyx_23060025_immGen my_gen (
    .inst       (inst_i),
    .imm        (imm_o)
);

// 比较逻辑
wire signed [31:0] reg1_signed = $signed(reg1_o);
wire signed [31:0] reg2_signed = $signed(reg2_o);

// 定义分支类型与比较结果的映射
wire [6:0] branch_result = {
    (reg1_o >= reg2_o),   // BRANCH_BGEU    (3'b110)
    (reg1_o < reg2_o),    // BRANCH_BLTU    (3'b101)
    (reg1_signed >= reg2_signed),   // BRANCH_BGE     (3'b100)
    (reg1_signed < reg2_signed),    // BRANCH_BLT     (3'b011)
    (reg1_o != reg2_o),   // BRANCH_BNE     (3'b010)
    (reg1_o == reg2_o),    // BRANCH_BEQ     (3'b001)
    1'b0                            // BRANCH_invalid     (3'b000)
};

assign branch_flag_o = branch_result[branch_type_o];



endmodule

