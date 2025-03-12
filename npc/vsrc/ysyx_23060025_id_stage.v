`include "ysyx_23060025_define.v"

module ysyx_23060025_id_stage(
    input									      clock				        ,
    input									      reset				        ,
    
    input           [31:0]                        reg1_data_i               ,
    input           [31:0]                        reg2_data_i               ,
    input           [31:0]                        csr_rdata_i	            ,
    
    // ifu_idu
    input                                         fs_to_ds_valid_i               ,
	output	reg							          ds_valid_o	        ,
	output									      ds_allowin_o	        ,
	output									      ds_to_ex_valid_o	        ,
    output                                        ds_to_ex_bpu_flush_o,
    output           [31:0]                       ds_to_ex_flush_pc_o,

    //from es forward path
    input  [`ES_TO_DS_FORWARD_BUS -1:0]             es_to_ds_forward_bus,
    input  [`MS_TO_DS_FORWARD_BUS -1:0]             ms_to_ds_forward_bus,
    input  [`WS_TO_DS_FORWARD_BUS -1:0]             ws_to_ds_forward_bus,
    input  [`FS_TO_DS_DATA_BUS -1:0]                fs_to_ds_bus,
    output [`DS_TO_ES_DATA_BUS -1:0]                ds_to_es_bus,

    // idu_exu
    input                                         es_allowin_i               ,

    // data bypass
	// from exeu
    // TODO: add exu valid logic, when exu not least one cycle
	// input		[31:0]			            exu_reg_wdata_i	,
	// // from lsu
	// input		[31:0]			            lsu_reg_wdata_i	,

    // input                                         exu_ready                 ,
    output          [4:0]                         reg1_addr_o               ,
    output          [4:0]                         reg2_addr_o               ,
    
    
    output                                        jmp_flag_o                ,
    output                                        fencei_flag_o             ,
    output                                        ebreak_flag_o             ,
    output          [31:0]                        jmp_target_o              ,
    output          [31:0]                        csr_rdata_o	            ,
    output          [11:0]                        csr_raddr_o                ,
    output                                        csr_flag_o                
);
    wire  [31:0]   pc_i   ;
    wire  [31:0]   inst_i ;
    wire  [3:0]                         aluop_o                   ;
    wire  [3:0]                         alusel_o                  ;
    
    wire  [31:0]                        reg1_o                    ;
    wire  [31:0]                        reg2_o                    ;
    wire  [31:0]                        imm_o                     ;
    wire             		            wd_o                      ;
    wire  [4:0]		                    wreg_o                    ;
    wire  [1:0]                         store_type_o              ;
    wire  [2:0]                         load_type_o               ;
    wire  [11:0]                        csr_waddr_o               ;
    
    wire [2:0] csr_flag;
    assign csr_flag_o = csr_flag[1];
    assign ds_to_es_bus = { reg1_o        ,     
                            reg2_o      ,
                            pc_o        ,
                            aluop_o     ,
                            alusel_o    ,
                            imm_o       ,
                            csr_flag  ,
                            csr_rdata_o ,
                            csr_waddr_o ,
                            wd_o        ,
                            wreg_o      ,
                            store_type_o ,
                            load_type_o  ,
                            ebreak_flag_o};


    reg  [`FS_TO_DS_DATA_BUS -1:0]   fs_to_ds_forward_bus_reg ;
    always @(posedge clock) begin
        if(reset) begin
            fs_to_ds_forward_bus_reg <= 0;
        end else if(ds_allowin_o & fs_to_ds_valid_i) begin
            fs_to_ds_forward_bus_reg <= fs_to_ds_bus;
        end
    end

    `ifdef PC_NO_2
        //ifdef
        assign {inst_i, pc_i} = {fs_to_ds_forward_bus_reg, 2'b0};
    `else
    //else
        assign {inst_i, pc_i} = fs_to_ds_forward_bus_reg;
    `endif

    
    wire     reg1_ren  ;
    wire     reg2_ren  ;
    // 1. opcode match
    //  1.1 bit match
    //      1.1.1 opcode_1_0
    wire   [6:0]   opcode = inst_i[6:0];
    wire opcode_1_0_11  = (opcode[1:0] == 2'b11);
    //      1.1.2 opcode_4_2
    wire opcode_4_2_000 = (opcode[4:2] == 3'b000);
    wire opcode_4_2_001 = (opcode[4:2] == 3'b001);
    wire opcode_4_2_010 = (opcode[4:2] == 3'b010);
    wire opcode_4_2_011 = (opcode[4:2] == 3'b011);
    wire opcode_4_2_100 = (opcode[4:2] == 3'b100);
    wire opcode_4_2_101 = (opcode[4:2] == 3'b101);
    wire opcode_4_2_110 = (opcode[4:2] == 3'b110);
    wire opcode_4_2_111 = (opcode[4:2] == 3'b111);
    //      1.1.2 opcode_6_5
    wire opcode_6_5_00  = (opcode[6:5] == 2'b00);
    wire opcode_6_5_01  = (opcode[6:5] == 2'b01);
    wire opcode_6_5_10  = (opcode[6:5] == 2'b10);
    wire opcode_6_5_11  = (opcode[6:5] == 2'b11);

    //      1.1.3 func3
    wire   [2:0]   func3 = inst_i[14:12];
    wire func3_000 = (func3 == 3'b000);
    wire func3_001 = (func3 == 3'b001);
    wire func3_010 = (func3 == 3'b010);
    wire func3_011 = (func3 == 3'b011);
    wire func3_100 = (func3 == 3'b100);
    wire func3_101 = (func3 == 3'b101);
    wire func3_110 = (func3 == 3'b110);
    wire func3_111 = (func3 == 3'b111);


    //      1.1.4 func7
    wire   [6:0]   func7 = inst_i[31:25];
    wire func7_0000000 = (func7 == 7'b0000000);
    wire func7_0100000 = (func7 == 7'b0100000);
    // wire func7_0000001 = (func7 == 7'b0000001);
    // wire func7_0000101 = (func7 == 7'b0000101);
    // wire func7_0001001 = (func7 == 7'b0001001);
    // wire func7_0001101 = (func7 == 7'b0001101);
    // wire func7_0010101 = (func7 == 7'b0010101);
    // wire func7_0100001 = (func7 == 7'b0100001);
    // wire func7_0010001 = (func7 == 7'b0010001);
    // wire func7_0101101 = (func7 == 7'b0101101);
    // wire func7_1111111 = (func7 == 7'b1111111);
    // wire func7_0000100 = (func7 == 7'b0000100); 
    // wire func7_0001000 = (func7 == 7'b0001000); 
    // wire func7_0001100 = (func7 == 7'b0001100); 
    // wire func7_0101100 = (func7 == 7'b0101100); 
    // wire func7_0010000 = (func7 == 7'b0010000); 
    // wire func7_0010100 = (func7 == 7'b0010100); 
    // wire func7_1100000 = (func7 == 7'b1100000); 
    // wire func7_1110000 = (func7 == 7'b1110000); 
    // wire func7_1010000 = (func7 == 7'b1010000); 
    // wire func7_1101000 = (func7 == 7'b1101000); 
    // wire func7_1111000 = (func7 == 7'b1111000); 
    // wire func7_1010001 = (func7 == 7'b1010001);  
    // wire func7_1110001 = (func7 == 7'b1110001);  
    // wire func7_1100001 = (func7 == 7'b1100001);  
    // wire func7_1101001 = (func7 == 7'b1101001);

    //  1.2 opcode match
    /*
        TYPE_I_LOAD_OPCODE 7'b0000011
        TYPE_S_OPCODE      7'b0100011
        TYPE_B_OPCODE      7'b1100011
        TYPE_I_JALR_OPCODE 7'b1100111
        TYPE_J_JAL_OPCODE 7'b1101111
        TYPE_I_BASE_OPCODE 7'b0010011
        TYPE_R_OPCODE     7'b0110011
        TYPE_U_LUI_OPCODE   7'b0110111
        TYPE_U_AUIPC_OPCODE 7'b0010111
    */
    wire opcode_I_load     = opcode_6_5_00 & opcode_4_2_000 & opcode_1_0_11; 
    wire opcode_S_store    = opcode_6_5_01 & opcode_4_2_000 & opcode_1_0_11; 
    wire opcode_B_branch   = opcode_6_5_11 & opcode_4_2_000 & opcode_1_0_11; 
    wire opcode_I_jalr     = opcode_6_5_11 & opcode_4_2_001 & opcode_1_0_11;
    wire opcode_J_jal      = opcode_6_5_11 & opcode_4_2_011 & opcode_1_0_11;
    wire opcode_I_op_imm   = opcode_6_5_00 & opcode_4_2_100 & opcode_1_0_11; 
    wire opcode_R_op       = opcode_6_5_01 & opcode_4_2_100 & opcode_1_0_11; 
    wire opcode_I_system   = opcode_6_5_11 & opcode_4_2_100 & opcode_1_0_11;
    wire opcode_U_auipc    = opcode_6_5_00 & opcode_4_2_101 & opcode_1_0_11; 
    wire opcode_U_lui      = opcode_6_5_01 & opcode_4_2_101 & opcode_1_0_11; 
    wire opcode_I_fence    = opcode_6_5_00 & opcode_4_2_011 & opcode_1_0_11;
    //  1.3 addr
    assign wreg_o = inst_i[11:7];
    assign reg1_addr_o = inst_i[19:15];
    assign reg2_addr_o = inst_i[24:20];
    wire [11:0] csr_addr = inst_i[31:20];


    // 2. instruction match (21+3+6+1+10+2=43)
    //  2.1 I-type (5+1+9+5+1=21)
    //      2.1.1 I-load (5)
    wire rv32_lb       = opcode_I_load   & func3_000;
    wire rv32_lh       = opcode_I_load   & func3_001;
    wire rv32_lw       = opcode_I_load   & func3_010;
    wire rv32_lbu      = opcode_I_load   & func3_100;
    wire rv32_lhu      = opcode_I_load   & func3_101;
    //      2.1.2 I_jalr (1)
    wire rv32_jalr     = opcode_I_jalr   & func3_000;  
    //      2.1.3 I_op_imm (6+3)
    wire rv32_addi     = opcode_I_op_imm & func3_000;
    wire rv32_slti     = opcode_I_op_imm & func3_010;
    wire rv32_sltiu    = opcode_I_op_imm & func3_011;
    wire rv32_xori     = opcode_I_op_imm & func3_100;
    wire rv32_ori      = opcode_I_op_imm & func3_110;
    wire rv32_andi     = opcode_I_op_imm & func3_111;

    wire rv32_slli     = opcode_I_op_imm & func3_001 & (inst_i[31:26] == 6'b000000);
    wire rv32_srli     = opcode_I_op_imm & func3_101 & (inst_i[31:26] == 6'b000000);
    wire rv32_srai     = opcode_I_op_imm & func3_101 & (inst_i[31:26] == 6'b010000);

    wire rv32_sxxi_shamt_legl = (inst_i[25] == 1'b0); //shamt[5] must be zero for RV32I
    wire rv32_sxxi_shamt_ilgl =  (rv32_slli | rv32_srli | rv32_srai) & (~rv32_sxxi_shamt_legl);
    //      2.1.4 I_system (3+2)
    wire rv32_ecall    = opcode_I_system & func3_000 & (inst_i[31:20] == 12'b0000_0000_0000);
    wire rv32_ebreak   = opcode_I_system & func3_000 & (inst_i[31:20] == 12'b0000_0000_0001);
    wire rv32_mret     = opcode_I_system & func3_000 & (inst_i[31:20] == 12'b0011_0000_0010);
    wire rv32_csrrw    = opcode_I_system & func3_001; 
    wire rv32_csrrs    = opcode_I_system & func3_010; 
    // wire rv32_csrrc    = opcode_I_system & func3_011; 
    // wire rv32_csrrwi   = opcode_I_system & func3_101; 
    // wire rv32_csrrsi   = opcode_I_system & func3_110; 
    // wire rv32_csrrci   = opcode_I_system & func3_111;

    //      2.1.1 I-fence (1)
    wire rv32_fence    = opcode_I_fence & func3_000;
    // wire rv32_fence_i  = opcode_I_fence & func3_001;

    wire rv32_fence_fencei  = opcode_I_fence;

    //  2.2 S-type (3)
    wire rv32_sb       = opcode_S_store  & func3_000;
    wire rv32_sh       = opcode_S_store  & func3_001;
    wire rv32_sw       = opcode_S_store  & func3_010;

    //  2.3 B_branch (6)
    wire rv32_beq      = opcode_B_branch & func3_000;
    wire rv32_bne      = opcode_B_branch & func3_001;
    wire rv32_blt      = opcode_B_branch & func3_100;
    wire rv32_bge      = opcode_B_branch & func3_101;
    wire rv32_bltu     = opcode_B_branch & func3_110;
    wire rv32_bgeu     = opcode_B_branch & func3_111;

    //  2.4 J-jal (1)
    wire rv32_jal      = opcode_J_jal; 

    //  2.5 R_op (10)
    wire rv32_add      = opcode_R_op     & func3_000 & func7_0000000;
    wire rv32_sub      = opcode_R_op     & func3_000 & func7_0100000;
    wire rv32_sll      = opcode_R_op     & func3_001 & func7_0000000;
    wire rv32_slt      = opcode_R_op     & func3_010 & func7_0000000;
    wire rv32_sltu     = opcode_R_op     & func3_011 & func7_0000000;
    wire rv32_xor      = opcode_R_op     & func3_100 & func7_0000000;
    wire rv32_srl      = opcode_R_op     & func3_101 & func7_0000000;
    wire rv32_sra      = opcode_R_op     & func3_101 & func7_0100000;
    wire rv32_or       = opcode_R_op     & func3_110 & func7_0000000;
    wire rv32_and      = opcode_R_op     & func3_111 & func7_0000000;

    //  2.6 U_type (2)
    wire rv32_auipc    = opcode_6_5_00 & opcode_4_2_101 & opcode_1_0_11; 
    wire rv32_lui      = opcode_6_5_01 & opcode_4_2_101 & opcode_1_0_11;


    // 3. imm
                // It will select i-type immediate when
            //    * opcode_I_op_imm
            //    * opcode_J_jalr
            //    * opcode_I_load
    wire rv32_imm_sel_i = opcode_I_op_imm | opcode_I_jalr | opcode_I_load;

                // It will select u-type immediate when
                //    * rv32_lui, rv32_auipc 
    wire rv32_imm_sel_u = rv32_auipc | rv32_lui;

                // It will select j-type immediate when
                //    * opcode_J_jal
    wire rv32_imm_sel_j = opcode_J_jal;

                // It will select b-type immediate when
                //    * opcode_B_branch
    wire rv32_imm_sel_b = opcode_B_branch;
                   
                // It will select s-type immediate when
                //    * opcode_S_store
    wire rv32_imm_sel_s = opcode_S_store;

    wire [31:0]  rv32_i_imm = { 
                               {20{inst_i[31]}} 
                              , inst_i[31:20]
                             };

    wire [31:0]  rv32_s_imm = {
                               {20{inst_i[31]}} 
                              , inst_i[31:25] 
                              , inst_i[11:7]
                             };


    wire [31:0]  rv32_b_imm = {
                               {19{inst_i[31]}} 
                              , inst_i[31] 
                              , inst_i[7] 
                              , inst_i[30:25] 
                              , inst_i[11:8]
                              , 1'b0
                              };

    wire [31:0]  rv32_u_imm = {inst_i[31:12],12'b0};

    wire [31:0]  rv32_j_imm = {
                               {11{inst_i[31]}} 
                              , inst_i[31] 
                              , inst_i[19:12] 
                              , inst_i[20] 
                              , inst_i[30:21]
                              , 1'b0
                              };
    wire [31:0]  rv32_imm = 
                     ({32{rv32_imm_sel_i}} & rv32_i_imm)
                   | ({32{rv32_imm_sel_s}} & rv32_s_imm)
                   | ({32{rv32_imm_sel_b}} & rv32_b_imm)
                   | ({32{rv32_imm_sel_u}} & rv32_u_imm)
                   | ({32{rv32_imm_sel_j}} & rv32_j_imm)
                   ;

    assign imm_o = rv32_imm;
    // 4. control signal
    // write register
    assign wd_o = opcode_I_jalr | opcode_I_load | opcode_I_op_imm
                    | opcode_R_op
                    | opcode_J_jal
                    | opcode_U_auipc | opcode_U_lui | rv32_csrrs | rv32_csrrw;

    assign store_type_o = {2{rv32_sb}} & `STORE_SB_8
                            | {2{rv32_sh}} & `STORE_SH_16
                            | {2{rv32_sw}} & `STORE_SW_32;

    assign load_type_o = {3{rv32_lb}} & `LOAD_LB_8
                            | {3{rv32_lbu}} & `LOAD_LBU_8
                            | {3{rv32_lh}} & `LOAD_LH_16
                            | {3{rv32_lhu}} & `LOAD_LHU_16
                            | {3{rv32_lw}} & `LOAD_LW_32;

    wire alu_op_sel_add = rv32_add 
                        | rv32_csrrs | rv32_csrrw | rv32_ecall
                        | rv32_addi | rv32_jalr
                        | opcode_S_store
                        | opcode_I_load
                        | opcode_J_jal 
                        | opcode_U_auipc | opcode_U_lui;

    wire alu_op_sel_sub = rv32_sub;
    wire alu_op_sel_xor = rv32_xor | rv32_xori;
    wire alu_op_sel_or  = rv32_or | rv32_ori;

    wire alu_op_sel_and = rv32_and | rv32_andi;
    wire alu_op_sel_right_logic = rv32_srl | rv32_srli;
    wire alu_op_sel_right_arithe = rv32_sra | rv32_srai;
    wire alu_op_sel_left_logic = rv32_sll | rv32_slli;
    wire alu_op_sel_less_unsigned = rv32_sltu | rv32_sltiu;
    wire alu_op_sel_less_signed = rv32_slt | rv32_slti;


    assign aluop_o = {4{alu_op_sel_sub}} & `ALU_OP_SUB
                    | {4{alu_op_sel_add}} & `ALU_OP_ADD
                    | {4{alu_op_sel_xor}} & `ALU_OP_XOR
                    | {4{alu_op_sel_or}} & `ALU_OP_OR
                    | {4{alu_op_sel_and}} & `ALU_OP_AND
                    | {4{alu_op_sel_right_logic}} & `ALU_OP_RIGHT_LOGIC
                    | {4{alu_op_sel_right_arithe}} & `ALU_OP_RIGHT_ARITH
                    | {4{alu_op_sel_left_logic}} & `ALU_OP_LEFT_LOGIC
                    | {4{alu_op_sel_less_signed}} & `ALU_OP_LESS_SIGNED
                    | {4{alu_op_sel_less_unsigned}} & `ALU_OP_LESS_UNSIGNED;

    wire aluop1_sel_zero = opcode_U_lui;

    wire aluop1_sel_reg1 = opcode_R_op 
                        | opcode_I_op_imm
                        | opcode_S_store
                        | opcode_I_load;
    wire aluop1_sel_pc = opcode_J_jal 
                        | opcode_I_jalr | opcode_U_auipc;

    wire aluop1_sel_csr = opcode_I_system;

    wire aluop2_sel_zero = opcode_I_system;
    wire aluop2_sel_reg2 = opcode_R_op;
    wire aluop2_sel_imm = opcode_I_op_imm | opcode_U_lui | opcode_U_auipc | opcode_I_load | opcode_S_store;
    wire aluop2_sel_4 = opcode_I_jalr | opcode_J_jal;

    assign alusel_o[1:0] = {2{aluop1_sel_zero}} & `ALU_SEL1_ZERO
                        | {2{aluop1_sel_reg1}} & `ALU_SEL1_REG1
                        | {2{aluop1_sel_pc}} & `ALU_SEL1_PC
                        | {2{aluop1_sel_csr}} & `ALU_SEL1_CSR;

    assign alusel_o[3:2] = {2{aluop2_sel_zero}} & `ALU_SEL2_ZERO
                        | {2{aluop2_sel_reg2}} & `ALU_SEL2_REG2
                        | {2{aluop2_sel_imm}} & `ALU_SEL2_IMM
                        | {2{aluop2_sel_4}} & `ALU_SEL2_4;

    wire [31:0] trans_src1 = rv32_jalr ? reg1_o : pc_i;
    wire [31:0] trans_src2 = opcode_B_branch & ~branch_flag ? 32'd4 : imm_o;

    wire [31:0] trans_target_o = trans_src1 + trans_src2;
    assign jmp_target_o = trans_target_o;
    assign ds_to_ex_flush_pc_o = trans_target_o;
    // output 
    wire  [31:0]                        pc_o                      ;
    assign pc_o = pc_i;
    

    assign jmp_flag_o = rv32_jalr;
    

    assign csr_flag = {3{rv32_ecall}} & `CSR_ECALL
                        | {3{rv32_mret}} & `CSR_MRET
                        | {3{rv32_csrrw}} & `CSR_CSRRW
                        | {3{rv32_csrrs}} & `CSR_CSRRS;

    assign ebreak_flag_o = rv32_ebreak;
    

    wire        ms_csr_forward_enable;
    wire        es_csr_forward_enable;
    wire        ws_csr_forward_enable;
    wire        ms_forward_enable;
    wire [ 4:0] ms_forward_reg;
    wire [31:0] ms_forward_data;
    wire        ms_dep_need_stall;
    wire [ 2:0] ms_csr_type;
    wire [ 11:0] ms_csr_waddr;
    wire [31:0] ms_csr_wdata;
    wire        es_dep_need_stall;
    wire        es_forward_enable;
    wire [ 4:0] es_forward_reg;
    wire [31:0] es_forward_data;
    wire [ 2:0] es_csr_type;
    wire [ 11:0] es_csr_waddr;
    wire [31:0] es_csr_wdata;
    wire        ws_forward_enable;
    wire [ 4:0] ws_forward_reg;
    wire [31:0] ws_forward_data;
    wire [ 2:0] ws_csr_type;
    wire [ 11:0] ws_csr_waddr;
    wire [31:0] ws_csr_wdata;
    wire        rf1_forward_stall;
    wire        rf2_forward_stall;

    assign {es_dep_need_stall,
        es_forward_enable, 
        es_forward_reg   ,
        es_forward_data ,
        es_csr_forward_enable ,
        es_csr_waddr     ,
        es_csr_wdata     ,
        es_csr_type     
       } = es_to_ds_forward_bus;

    assign {ms_dep_need_stall,
        ms_forward_enable, 
        ms_forward_reg   ,
        ms_forward_data ,
        ms_csr_forward_enable ,
        ms_csr_waddr     ,
        ms_csr_wdata     ,
        ms_csr_type
       } = ms_to_ds_forward_bus;

    assign {ws_forward_enable, 
        ws_forward_reg   ,
        ws_forward_data  ,
        ws_csr_waddr     ,
        ws_csr_wdata     ,
        ws_csr_type
       } = ws_to_ds_forward_bus;

        wire id_csr_ren = csr_flag == `CSR_CSRRW 
                    || csr_flag == `CSR_CSRRS
                    || csr_flag == `CSR_MRET;


        wire ws_csr_wen = ws_csr_type == `CSR_CSRRW 
                            || ws_csr_type == `CSR_CSRRS
                            || ws_csr_type == `CSR_ECALL;


    // data relation
    // assign csr_rdata_o = conflict_csr_i ? conflict_csr_bypass_data_i : csr_rdata_i;
    assign {csr_rdata_o} = ((csr_raddr_o == es_csr_waddr) && {es_csr_forward_enable} && id_csr_ren) ? es_csr_wdata :
                                        ((csr_raddr_o == ms_csr_waddr) && {ms_csr_forward_enable} && id_csr_ren) ? ms_csr_wdata :
                                        ((csr_raddr_o == ws_csr_waddr) && ws_csr_wen && id_csr_ren) ? ws_csr_wdata :
                                                                                                                csr_rdata_i;

    assign {rf1_forward_stall, reg1_o} = ((reg1_addr_o == es_forward_reg) && {es_forward_enable} && reg1_ren) ? {es_dep_need_stall, es_forward_data} :
                                        ((reg1_addr_o == ms_forward_reg) && {ms_forward_enable} && reg1_ren) ? {{ms_dep_need_stall}, ms_forward_data} :
                                        ((reg1_addr_o == ws_forward_reg) && ws_forward_enable && reg1_ren) ? {1'b0, ws_forward_data} :
                                                                                                                {1'b0, reg1_data_i}; 

    assign {rf2_forward_stall, reg2_o} = ((reg2_addr_o == es_forward_reg) && {es_forward_enable} && reg2_ren) ? {es_dep_need_stall, es_forward_data} :
                                        ((reg2_addr_o == ms_forward_reg) && {ms_forward_enable} && reg2_ren) ? {{ms_dep_need_stall}, ms_forward_data} :
                                        ((reg2_addr_o == ws_forward_reg) && ws_forward_enable && reg2_ren) ? {1'b0, ws_forward_data} :
                                                                                                                {1'b0, reg2_data_i};

    
    
    assign csr_waddr_o = (rv32_ecall ? `CSR_MEPC_ADDR : csr_addr);
    assign csr_raddr_o = (rv32_ecall ? `CSR_MTVEC_ADDR : rv32_mret ? `CSR_MEPC_ADDR : csr_addr);
   

    assign reg1_ren = aluop1_sel_reg1 | opcode_I_jalr | opcode_B_branch | rv32_csrrs | rv32_csrrw;
    assign reg2_ren = aluop2_sel_reg2 | opcode_S_store | opcode_B_branch;
    
// controller look-up lut
// inst: R-type: wd_o aluop_o alusel_o
// alu_sel  [1:0] res1/pc_o/0, [3:2] res2/imm_o/4/0
// alu_op + - 

// 比较逻辑
wire signed [31:0] reg1_signed = $signed(reg1_o);
wire signed [31:0] reg2_signed = $signed(reg2_o);



wire branch_flag = rv32_beq ? reg1_o == reg2_o :
                    rv32_bne    ? reg1_o != reg2_o  :   
                    rv32_blt    ? reg1_signed < reg2_signed  :   
                    rv32_bge    ? reg1_signed >= reg2_signed  :   
                    rv32_bltu   ? reg1_o < reg2_o :       
                    rv32_bgeu   ? reg1_o >= reg2_o : 0;
// guess wrong
assign ds_to_ex_bpu_flush_o = opcode_B_branch & (branch_flag ^ rv32_b_imm[31]);



`ifdef N_YOSYS_STA_CHECK
    `ifdef PERFORMANCE_COUNTER
    import "DPI-C" function void idu_p_counter_update(byte opcode, byte func3);
	always @(posedge clock) begin
		if (ds_to_ex_valid_o && es_allowin_i) begin
			idu_p_counter_update({1'b0, opcode}, {5'b0, func3});
		end
	end
    `endif
`endif

    assign ds_allowin_o    = !ds_valid_o || ds_ready_go_o && es_allowin_i;
    wire ds_ready_go_o   = ~rf1_forward_stall & ~rf2_forward_stall;
    assign ds_to_ex_valid_o = ds_valid_o && ds_ready_go_o;
    always @(posedge clock) begin   //bug1 no reset; branch no delay slot
        if (reset) begin
            ds_valid_o <= 1'b0;
        end
        else begin 
            if (ds_allowin_o) begin   //bug2 ??
                ds_valid_o <= fs_to_ds_valid_i;
            end
        end

        // if (fs_to_ds_valid && ds_allowin) begin
        //     fs_to_ds_bus_r <= fs_to_ds_bus;
        // end
    end

    // idu deal with bpu result 


endmodule

