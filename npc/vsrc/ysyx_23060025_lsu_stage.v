/*************************************************************************
	> File Name: ysyx_23060025_counter.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月05日 星期六 22时12分23秒
 ************************************************************************/
// clock rstn waddr wdata wen wmask
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"
module ysyx_23060025_lsu_stage #(parameter DATA_LEN = 32,ADDR_LEN = 32)(
	input								rstn			,
	input		                		clock			,
`ifdef DIFFTEST
	input								diff_skip_flag_i,
	output								diff_skip_flag_o,
`endif	
`ifdef DEBUG
	input     [31:0]                      pc_i               ,
	output reg   [31:0]                   pc_o               ,
`endif
    
    
    input  [`ES_TO_MS_DATA_BUS-1:0] 	es_to_ms_bus,

	//to ds forward path 
    output [`MS_TO_DS_FORWARD_BUS-1:0] ms_to_ds_forward_bus,
    output                             ms_to_ds_valid,
	
	output	reg							          lsu_valid_o	        ,

	// exu_lsu
    input                                         ex_to_lsu_valid_i               ,
	output                                        lsu_allowin_o               ,

    // lsu_wbu
    output                                        lsu_to_wbu_valid_o               ,
    input                                         wbu_allowin_i               ,

	output                                        ebreak_flag_o               ,

    
    output	   	                		wd_o		,
    output	   	[4:0]		            wreg_o		,
	output     [DATA_LEN - 1:0]		    wdata_o,
    output      [DATA_LEN - 1:0]        csr_wdata_o	,
    output      [2:0]                   csr_type_o	,
	output       [11:0]        			csr_waddr_o	,
	output       [31:0]        			csr_mcause_o	,

	output		[ADDR_LEN - 1:0]		out_paddr	,
	output		                		out_psel	,
	output		                		out_pwrite	,
	output		[2:0]                	out_psize	,
	output		[DATA_LEN - 1:0]		out_pwdata	,	// 写出的数据
	output		[3:0]					out_pwstrb	,	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	input		[DATA_LEN - 1:0]		out_prdata	,
	input		                		out_pvalid	
    
);	
    wire [31:0] mem_rdata;
	wire								lsu_ready_go_o	        ;
	wire	 [DATA_LEN - 1:0]    		mem_rdata_unaligned	;
	wire 		 				 		aligned_store	;
    wire		[DATA_LEN - 1:0]		alu_result_i ;
    wire		                		mem_wen_i	 ;
	wire		[DATA_LEN - 1:0]		mem_wdata_i	 ;
    wire       [2:0]                    load_type_i 	; 
    wire       [1:0]                    store_type_i	; 
    wire       [11:0]       			csr_waddr_i	 ;
    wire                                ebreak_flag_i;
    // reg  [7:0]  mem_rmask;
    wire        					mem_to_reg;
	wire	[3:0]					w_strb	;	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	wire	[DATA_LEN - 1:0]		w_data	;	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit

	`ifdef DEBUG
		always @(posedge clock) begin
			if(~rstn) begin
				pc_o <= 0;
			end else if(ex_to_lsu_valid_i & lsu_allowin_o) begin
				pc_o <= pc_i;
			end
		end
	`endif
	
	reg [`ES_TO_MS_DATA_BUS -1:0]       es_to_ms_bus_reg;
	always @(posedge clock) begin
		if(~rstn) begin
			es_to_ms_bus_reg <= 0;
		end else if(ex_to_lsu_valid_i & lsu_allowin_o) begin
			es_to_ms_bus_reg <= es_to_ms_bus;
		end
	end

	assign ebreak_flag_o = ebreak_flag_i;
	assign csr_waddr_o = csr_waddr_i;
`ifdef DIFFTEST
	assign diff_skip_flag_o = diff_skip_flag_i;
`endif

	wire lsu_csr_wen = csr_type_o == `CSR_CSRRW 
						|| csr_type_o == `CSR_CSRRS
						|| csr_type_o == `CSR_ECALL;

	assign ms_to_ds_valid = lsu_valid_o;
	wire dest_zero            = (wreg_o == 5'b0);
	wire forward_enable       = wd_o & ~dest_zero & lsu_valid_o;
	wire csr_forward_enable       = lsu_csr_wen & lsu_valid_o;
	wire dep_need_stall       = 1;
	assign ms_to_ds_forward_bus = {dep_need_stall,  //38:38
								forward_enable,  //37:37
								wreg_o       ,  //36:32
								wdata  , //31:0
								csr_forward_enable,
								csr_waddr_i,
								csr_wdata_o,
								csr_type_o
								};
	assign {	wd_o		 ,
				wreg_o		 ,
				alu_result_i ,
				mem_wen_i	 ,
				mem_wdata_i	 ,
				load_type_i  ,
				store_type_i ,
				csr_wdata_o	 ,
				csr_type_o	 ,
				csr_waddr_i	 ,
				csr_mcause_o ,
				ebreak_flag_i } = es_to_ms_bus_reg;

	assign lsu_allowin_o    = !lsu_valid_o || lsu_ready_go_o && wbu_allowin_i;
    assign lsu_ready_go_o   = ~(mem_to_reg | mem_wen_i) || out_pvalid;
    assign lsu_to_wbu_valid_o = lsu_valid_o && lsu_ready_go_o;

    always @(posedge clock) begin   //bug1 no reset; branch no delay slot
        if (~rstn) begin
            lsu_valid_o <= 1'b0;
        end
        else begin 
            if (lsu_allowin_o) begin   //bug2 ??
                lsu_valid_o <= ex_to_lsu_valid_i;
            end
        end

    end

	wire [31:0] r_data = out_prdata;

	assign out_psel = (mem_to_reg | mem_wen_i) & lsu_valid_o;
	assign out_pwrite = mem_wen_i & lsu_valid_o;


    // 写寄存器的信息
    wire		[DATA_LEN - 1:0]		    wdata       ;
    assign wdata = mem_to_reg ? mem_rdata : alu_result_i;

	assign out_paddr = alu_result_i;

	assign w_strb = (store_type_i == `STORE_SB_8)? `AXI_W_STRB_8 :
                    (store_type_i == `STORE_SH_16) ? `AXI_W_STRB_16 :
                    (store_type_i == `STORE_SW_32) ? `AXI_W_STRB_32 : 
                    0;
	assign w_data = mem_wdata_i;

	assign out_psize = mem_to_reg ? addr_r_size : addr_w_size;
	
	wire [2:0] addr_r_size = (load_type_i == `LOAD_LB_8)  ? `AXI_ADDR_SIZE_1 : 
							(load_type_i == `LOAD_LH_16) ? `AXI_ADDR_SIZE_2: 
							(load_type_i == `LOAD_LBU_8) ? `AXI_ADDR_SIZE_1: 
							(load_type_i == `LOAD_LHU_16) ? `AXI_ADDR_SIZE_2: 
							// (load_type_i == `LOAD_LW_32) ? `AXI_ADDR_SIZE_4: 
							`AXI_ADDR_SIZE_4;
							
	wire [2:0] addr_w_size = (store_type_i == `STORE_SB_8)? `AXI_ADDR_SIZE_1 :
							(store_type_i == `STORE_SH_16) ? `AXI_ADDR_SIZE_2 :
							// (store_type_i == `STORE_SW_32) ? `AXI_ADDR_SIZE_4 : 
							`AXI_ADDR_SIZE_4;


`ifdef N_YOSYS_STA_CHECK
	// import "DPI-C" function void dtrace_func(int addr);
    // always @(*)
	// 	dtrace_func(addr_w_addr_o);
`ifdef PERFORMANCE_COUNTER
	import "DPI-C" function void lsu_p_counter_update();
	always @(posedge clock) begin
		if (lsu_to_wbu_valid_o & wbu_allowin_i) begin
			lsu_p_counter_update();
		end
	end

	import "DPI-C" function void lsu_delay_counter_update();
	always @(posedge clock) begin
		if ((lsu_valid_o & (mem_to_reg | mem_wen_i))) begin
			lsu_delay_counter_update();
		end
	end
	`endif
`endif


	wire n_aligned_store = ~aligned_store;

	assign {out_pwstrb, out_pwdata} = alu_result_i[1:0] == 2'b00 || n_aligned_store ? {w_strb, w_data} :
					alu_result_i[1:0] == 2'b01 ? {{w_strb[2:0], 1'b0}, {w_data[23:0], 8'b0}} :
					alu_result_i[1:0] == 2'b10 ? {{w_strb[1:0], 2'b0}, {w_data[15:0], 16'b0}} :
					alu_result_i[1:0] == 2'b11 ? {{w_strb[0], 3'b0}, {w_data[7:0], 24'b0}} : 0;
	
	assign wdata_o = wdata;



	wire addr_sram = (alu_result_i >= `DEVICE_SRAM_ADDR_L && alu_result_i <= `DEVICE_SRAM_ADDR_H);
	wire addr_flash = (alu_result_i >= `DEVICE_FLASH_ADDR_L && alu_result_i <= `DEVICE_FLASH_ADDR_H);
	wire addr_sdram = (alu_result_i >= `DEVICE_SDRAM_ADDR_L && alu_result_i <= `DEVICE_SDRAM_ADDR_H);
	wire addr_psram = (alu_result_i >= `DEVICE_PSRAM_ADDR_L && alu_result_i <= `DEVICE_PSRAM_ADDR_H);
	wire addr_uart = (alu_result_i >= `DEVICE_UART16550_ADDR_L && alu_result_i <= `DEVICE_UART16550_ADDR_H);

	assign aligned_store = addr_sram | addr_flash | addr_sdram | addr_psram | addr_uart;

    assign  mem_to_reg = |load_type_i;

    // assign mem_ren_o = mem_to_reg;
    
    // load
	/*
		addr_unaligned--访存地址的后两位
		对于mem 地址0x80000010【0-3】-- 内容【00_01_02_03】
		PSRAM->CPU 00_01_02_03
		0x80000011 addr_unaligned[1:0] == 2'b01---- 【00_01_02_03】--[01_02_03_00]
		0x80000012 addr_unaligned[1:0] == 2'b10---- 【00_01_02_03】--[02_03_00_00]  
		0x80000013 addr_unaligned[1:0] == 2'b11---- 【00_01_02_03】--[03_00_00_00]
	*/

	assign mem_rdata_unaligned = (alu_result_i[1:0] == 2'b00 || n_aligned_store) ? {r_data} :
								alu_result_i[1:0] == 2'b01 ? {8'b0, {r_data[31:8]}} :
								alu_result_i[1:0] == 2'b10 ? {16'b0, {r_data[31:16]}} :
								alu_result_i[1:0] == 2'b11 ? {{24'b0, r_data[31:24]}} : 0;

								
    assign mem_rdata = (load_type_i == `LOAD_LB_8)  ? {{24{mem_rdata_unaligned[7]}}, mem_rdata_unaligned[7:0]} : 
                    (load_type_i == `LOAD_LH_16) ? {{16{mem_rdata_unaligned[15]}}, mem_rdata_unaligned[15:0]}: 
                    (load_type_i == `LOAD_LBU_8) ? {{24{1'b0}}, mem_rdata_unaligned[7:0]}: 
                    (load_type_i == `LOAD_LHU_16) ? {{16{1'b0}}, mem_rdata_unaligned[15:0]}: 
                    mem_rdata_unaligned;


endmodule

