`include "ysyx_23060025_define.v"
module ysyx_23060025_cpu #(parameter DATA_LEN = 32,ADDR_LEN = 32) (
	input								clock 		,
	input								reset 		,

	// IFU-AXI
	// Addr Read
	output		[ADDR_LEN - 1:0]		inst_addr_r_addr_o,
	output		                		inst_addr_r_valid_o,
	input		       					inst_addr_rready_i,
	output		[1:0]  					inst_addr_rburst_i,

	output		[7:0]  					inst_addr_rlen_o	,
	output		[2:0]  					inst_addr_rsize_o	,
	// input		                		inst_addr_r_ready_i,

	// Read data
	// input		[DATA_LEN - 1:0]		inst_r_data_i	,
	// input		[1:0]					inst_r_resp_i	,	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	input		                		inst_r_valid_i	,
	output		                		inst_r_ready_o	,
	input		       					inst_r_last_i	,

	// data AXI
	 //Addr Read
	output		[ADDR_LEN - 1:0]		data_addr_r_addr_o,
	output		                		data_addr_r_valid_o,
	input		                		data_addr_r_ready_i,
	output		[2:0]                	data_addr_r_size_o,



	// Read data
`ifdef DIFFTEST
	input								diff_skip_flag_i	,
`endif
	input		[DATA_LEN - 1:0]		data_r_data_i	,
	input		[1:0]					data_r_resp_i	,	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	input		                		data_r_valid_i	,
	output		                		data_r_ready_o	,

	// Addr Write
	output		[ADDR_LEN - 1:0]		data_addr_w_addr_o,	// 写地址
	output		                		data_addr_w_valid_o,	// 主设备给出的地址和相关控制信号有效
	input		                		data_addr_w_ready_i, // 从设备已准备好接收地址和相关的控制信号
	output		[2:0]                	data_addr_w_size_o,

	// Write data
	output		[DATA_LEN - 1:0]		data_w_data_o	,	// 写出的数据
	output		[3:0]					data_w_strb_o	,	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	output		                		data_w_valid_o	,	// 主设备给出的数据和字节选通信号有效
	input		                		data_w_ready_i	,	// 从设备已准备好接收数据选通信号

	// Backward
	input		[1:0]					data_bkwd_resp_i,	// 写回复信号，写操作是否成功
	input		                		data_bkwd_valid_i,	// 从设备给出的写回复信号是否有效
	output		                		data_bkwd_ready_o,	// 主设备已准备好接收写回复信号

	input	        [DATA_LEN - 1:0]    inst_i		
	// output			[ADDR_LEN - 1:0]	pc			,
	// output								invalid		,
	// output								finish
);
	// //registerFile
	// wire								reg_re1_i		;
	wire			[4:0]				reg_raddr1_i	;
	// wire								reg_re2_i		;
	wire			[4:0]				reg_raddr2_i	;
	wire								reg_wen_i		;
	wire			[4:0]				reg_waddr_i		;
	wire	        [DATA_LEN - 1:0]    reg_wdata_i		;

	//my_IFU
	// wire								idu_ready_o	;
	wire			[ADDR_LEN - 1:0]	if_branch_target_i;
	wire								if_branch_type_i;
	wire								if_branch_request_i;	
	wire			[ADDR_LEN - 1:0]	if_jmp_target_i;
	wire								if_jmp_flag_i;	
	// wire			[ADDR_LEN - 1:0]	csr_mtvec_pc_o;
	// wire			[ADDR_LEN - 1:0]	csr_mepc_pc_o;
	// wire			[ADDR_LEN - 1:0]	pcPlus		;
	// wire			[ADDR_LEN - 1:0]	pcBranch	;
	// wire			[1:0]				pcSrc		;

	//my_decoder
	wire								ifu_valid_o		;
	// wire								exu_ready_o		;
	// wire								idu_valid_o		;
	wire			[ADDR_LEN - 1:0]	ifu_pc_o			;
	wire			[ADDR_LEN - 1:0]	ifu_inst_o		;
	wire			[ADDR_LEN - 1:0]	id_reg1_data_i	;
	wire			[ADDR_LEN - 1:0]	id_reg2_data_i	;


	// execute
	wire			[3:0]				idu_aluop_o		;
	wire			[3:0]				idu_alusel_o		;
	wire			[DATA_LEN - 1:0]	idu_reg1_o		;
	wire			[DATA_LEN - 1:0]	idu_reg2_o		;
	wire			[DATA_LEN - 1:0]	idu_imm_o		;
	wire			[ADDR_LEN - 1:0]	idu_pc_o			;
	wire								idu_wd_o			;
	wire			[4:0]				idu_wreg_o		;
	wire			[1:0]				idu_store_type_o	;
	wire			[2:0]				idu_load_type_o	;
	wire			[2:0]				idu_csr_flag_o	;


	wire			[31:0]				csr_rdata_i	;

	// csr Unit
	wire			[11:0]				csr_raddr_i	;
	wire			[11:0]				csr_waddr_i	;
	wire			[DATA_LEN - 1:0]	csr_wdata_i		;
	wire			[2:0]				csr_type_i		;
	// wire	        [DATA_LEN - 1:0]    csr_mepc_i		;
	wire	        [DATA_LEN - 1:0]    csr_mcause_i	;

	// lsu
	wire								ex_wd_o			;
	wire			[4:0]				ex_wreg_o		;
	wire			[DATA_LEN - 1:0]	ex_alu_result_o	;
	wire								ex_mem_wen_o	;
	wire			[DATA_LEN - 1:0]	ex_mem_wdata_o	;
	wire			[2:0]				ex_load_type_o	;
	wire			[1:0]				ex_store_type_o	;
	wire			[DATA_LEN - 1:0]	ex_csr_wdata_o	;
	wire			[2:0]				ex_csr_type_o	;


	// wb Unit
	wire								lsu_reg_wen_o		;
	wire			[4:0]				lsu_wreg_o			;
	wire			[DATA_LEN - 1:0]	lsu_reg_wdata_o		;
	wire			[DATA_LEN - 1:0]	lsu_csr_wdata_o		;
	wire			[11:0]				lsu_csr_waddr_o		;
	wire			[2:0]				lsu_csr_type_o		;
	// wire								lsu_memory_inst_o	;

	
	// assign pc = ifu_pc_o;
	// assign finish = if_last_finish_i;
	
	// always @(*) begin
	// 	$display("pc: [%h] inst: [%b] invalid: [%h] reset: [%b] clock[%b]",pc, ifu_inst_o, invalid, reset, clock);
	// end
`ifdef YSYXSOC_TRACE_DEVICE
	always @(*) begin
		if (data_addr_w_valid_o & data_addr_w_ready_i & data_w_ready_i & data_w_valid_o) begin
			if (data_addr_w_addr_o >= `DEVICE_CLINT_ADDR_L && data_addr_w_addr_o <= `DEVICE_CLINT_ADDR_H) begin
				$display("[DTRACE]------[CLINT: %x ~ %x]------[w_addr: %x]------[w_data: %x]---[PC: %x]", `DEVICE_CLINT_ADDR_L, `DEVICE_CLINT_ADDR_H, data_addr_w_addr_o, data_w_data_o, ifu_pc_o);
			end else if (data_addr_w_addr_o >= `DEVICE_SRAM_ADDR_L && data_addr_w_addr_o <= `DEVICE_SRAM_ADDR_H) begin
				$display("[DTRACE]------[SRAM: %x ~ %x]------[w_addr: %x]------[w_data: %x]---[PC: %x]", `DEVICE_SRAM_ADDR_L, `DEVICE_SRAM_ADDR_H, data_addr_w_addr_o, data_w_data_o, ifu_pc_o);
			end else if (data_addr_w_addr_o >= `DEVICE_UART16550_ADDR_L && data_addr_w_addr_o <= `DEVICE_UART16550_ADDR_H) begin
				$display("[DTRACE]------[UART16550: %x ~ %x]------[w_addr: %x]------[w_data: %x]---[PC: %x]", `DEVICE_UART16550_ADDR_L, `DEVICE_UART16550_ADDR_H, data_addr_w_addr_o, data_w_data_o, ifu_pc_o);
			end else if (data_addr_w_addr_o >= `DEVICE_SPI_ADDR_L && data_addr_w_addr_o <= `DEVICE_SPI_ADDR_H) begin
				$display("[DTRACE]------[SPI: %x ~ %x]------[w_addr: %x]------[w_data: %x]---[PC: %x]", `DEVICE_SPI_ADDR_L, `DEVICE_SPI_ADDR_H, data_addr_w_addr_o, data_w_data_o, ifu_pc_o);
			end else if (data_addr_w_addr_o >= `DEVICE_MROM_ADDR_L && data_addr_w_addr_o <= `DEVICE_MROM_ADDR_H) begin
				$display("[DTRACE]------[MROM: %x ~ %x]------[w_addr: %x]------[w_data: %x]---[PC: %x]", `DEVICE_MROM_ADDR_L, `DEVICE_MROM_ADDR_H, data_addr_w_addr_o, data_w_data_o, ifu_pc_o);
			end else begin
				
			end
		end else begin		
		end
	end
	
	always @(*) begin
		if (data_addr_r_valid_o & data_addr_r_ready_i) begin
			if (data_addr_r_addr_o >= `DEVICE_CLINT_ADDR_L && data_addr_r_addr_o <= `DEVICE_CLINT_ADDR_H) begin
				$display("[DTRACE-READ]------[CLINT: %x ~ %x]------[r_addr: %x]---[PC: %x]", `DEVICE_CLINT_ADDR_L, `DEVICE_CLINT_ADDR_H, data_addr_r_addr_o, ifu_pc_o);
			end else if (data_addr_r_addr_o >= `DEVICE_SRAM_ADDR_L && data_addr_r_addr_o <= `DEVICE_SRAM_ADDR_H) begin
				$display("[DTRACE-READ]------[SRAM: %x ~ %x]------[r_addr: %x]---[PC: %x]", `DEVICE_SRAM_ADDR_L, `DEVICE_SRAM_ADDR_H, data_addr_r_addr_o, ifu_pc_o);
			end else if (data_addr_r_addr_o >= `DEVICE_UART16550_ADDR_L && data_addr_r_addr_o <= `DEVICE_UART16550_ADDR_H) begin
				$display("[DTRACE-READ]------[UART16550: %x ~ %x]------[r_addr: %x]---[PC: %x]", `DEVICE_UART16550_ADDR_L, `DEVICE_UART16550_ADDR_H, data_addr_r_addr_o, ifu_pc_o);
			end else if (data_addr_r_addr_o >= `DEVICE_SPI_ADDR_L && data_addr_r_addr_o <= `DEVICE_SPI_ADDR_H) begin
				$display("[DTRACE-READ]------[SPI: %x ~ %x]------[r_addr: %x]---[PC: %x]", `DEVICE_SPI_ADDR_L, `DEVICE_SPI_ADDR_H, data_addr_r_addr_o, ifu_pc_o);
			end else if (data_addr_r_addr_o >= `DEVICE_MROM_ADDR_L && data_addr_r_addr_o <= `DEVICE_MROM_ADDR_H) begin
				$display("[DTRACE-READ]------[MROM: %x ~ %x]------[r_addr: %x]---[PC: %x]", `DEVICE_MROM_ADDR_L, `DEVICE_MROM_ADDR_H, data_addr_r_addr_o, ifu_pc_o);
			end else begin
				
			end
		end else begin		
		end
	end
`endif 

	// outports wire
	wire [DATA_LEN-1:0] 	icache_r_data;
	wire [ADDR_LEN-1:0] 	icache_addr_r_addr;
	wire                  	icache_addr_r_sel;
	wire                  	icache_r_ready;

	ysyx_23060025_ifu_stage #(
		.ADDR_WIDTH       ( 32 ),
    	.DATA_WIDTH       ( 32 ))
	u_ysyx_23060025_IFU(
		.clock            	( clock             ),
		.reset            	( reset             ),

		// ifu ifu_valid_o
		.fs_to_ds_valid_o           	( ifu_valid_o             ),
		.ds_allowin_i           	( idu_ready_o            ),
		.idu_valid_i           	( idu_valid_o            ),


		.branch_request_i ( if_branch_request_i ),
		.branch_target_i  ( if_branch_target_i  ),
		.branch_flag_i    ( if_branch_type_i    ),
		.ebreak_flag_i    ( idu_ebreak_flag_o    ),
		.jmp_flag_i  	  ( if_jmp_flag_i  ),
		.jmp_target_i     ( if_jmp_target_i    ),
		.csr_jmp_i     	  (idu_csr_flag_o[1]   ),
		// .csr_jmp_i     	  ( ex_csr_flag_i[2]  ),
		.csr_pc_i         ( idu_csr_rdata_o      ),
		// .csr_mepc_pc_i         ( csr_mepc_pc_o      ),

		.if_inst_o        	( ifu_inst_o         ),
		.if_pc_o               	( ifu_pc_o           ),

		.out_paddr    		( icache_addr_r_addr     ),
		.out_psel   		( icache_addr_r_sel    ),
		.out_pready   		( icache_r_ready    ),
		.out_prdata         ( icache_r_data          )
	);

	// ysyx_23060025_IFU #(
	// 	.ADDR_WIDTH       ( 32 ),
    // 	.DATA_WIDTH       ( 32 ))
	// u_ysyx_23060025_IFU(
	// 	.clock            	( clock             ),
	// 	.reset            	( reset             ),

	// 	// ifu ifu_valid_o
	// 	.fs_to_ds_valid_o           	( ifu_valid_o             ),
	// 	.idu_ready_i           	( idu_ready_o            ),
	// 	.idu_valid_i           	( idu_valid_o            ),


	// 	.branch_request_i ( if_branch_request_i ),
	// 	.branch_target_i  ( if_branch_target_i  ),
	// 	.branch_flag_i    ( if_branch_type_i    ),
	// 	.ebreak_flag_i    ( idu_ebreak_flag_o    ),
	// 	.jmp_flag_i  	  ( if_jmp_flag_i  ),
	// 	.jmp_target_i     ( if_jmp_target_i    ),
	// 	.csr_jmp_i     	  (idu_csr_flag_o[1]   ),
	// 	// .csr_jmp_i     	  ( ex_csr_flag_i[2]  ),
	// 	.csr_pc_i         ( idu_csr_rdata_o      ),
	// 	// .csr_mepc_pc_i         ( csr_mepc_pc_o      ),

	// 	.if_inst_o        	( ifu_inst_o         ),
	// 	.if_pc_o               	( ifu_pc_o           ),

	// 	.out_paddr    		( icache_addr_r_addr     ),
	// 	.out_psel   		( icache_addr_r_sel    ),
	// 	.out_pready   		( icache_r_ready    ),
	// 	.out_prdata         ( icache_r_data          )
	// );

	wire icache_fencei_flag;
	wire idu_ebreak_flag_o;

	ysyx_23060025_icache u_ysyx_23060025_icache(
		.clock       	( clock        ),
		.reset       	( reset        ),
		.in_paddr    	( icache_addr_r_addr     ),
		.in_psel     	( icache_addr_r_sel      ),
		.in_pready   	( icache_r_ready    ),
		.in_prdata   	( icache_r_data    ),

		.in_fence_flag   	( icache_fencei_flag    ),

		.out_araddr  	( inst_addr_r_addr_o   ),
		.out_arvalid 	( inst_addr_r_valid_o  ),
		.out_rlast  	( inst_r_last_i   ),
		.out_arready  	( inst_addr_rready_i   ),
		.out_arburst  	( inst_addr_rburst_i   ),
		.out_arlen   	( inst_addr_rlen_o    ),
		.out_arsize  	( inst_addr_rsize_o   ),
		.out_rvalid  	( inst_r_valid_i   ),
		.out_rdata   	( inst_i    ),
		.out_rready  	( inst_r_ready_o   )
	);

	// output declaration of module ysyx_23060025_if_id

	wire [DATA_LEN-1:0] t_id_inst_o;
	wire [ADDR_LEN-1:0] t_id_pc_o;
	
	ysyx_23060025_if_id #(
		.ADDR_WIDTH 	(32  ),
		.DATA_WIDTH 	(32  ))
	u_ysyx_23060025_if_id(
		.clock       	(clock        ),
		.reset       	(reset        ),
		.f_if_inst_i 	(ifu_inst_o  ),
		.f_if_pc_i   	(ifu_pc_o    ),
		.f_if_valid_i   	(ifu_valid_o    ),
		.f_id_ready_i   	(idu_ready_o    ),
		.t_id_inst_o 	(t_id_inst_o  ),
		.t_id_pc_o   	(t_id_pc_o    )	
	);
	
	ysyx_23060025_RegisterFile ysyx_23060025_RegisterFile(
		.clock		(clock),
		.wdata		(reg_wdata_i),
		.rd			(reg_waddr_i),
		.rsc1		(reg_raddr1_i),
		.rsc2		(reg_raddr2_i),
		.reset		(reset)		 ,
		.regWrite	(reg_wen_i),
		.r_data1	(id_reg1_data_i),
		.r_data2	(id_reg2_data_i)
	);

	wire 					conflict_id_nop_o      ;
	wire 	[31:0]			conflict_reg_bypass_data_o ;
	wire 	[31:0]			conflict_csr_bypass_data_o ;
	wire 					conflict_csr_o        ;
	wire 					conflict_reg0_o        ;
	wire 					conflict_reg1_o        ;
	wire 					conflict_reg1_ren_i       ;
	wire 					conflict_reg2_ren_i       ;

	wire 	[31:0]			idu_csr_rdata_o ;
	wire 					ds_busy ;

	 wire  [`ES_TO_DS_FORWARD_BUS -1:0]             es_to_ds_forward_bus;
    wire  [`MS_TO_DS_FORWARD_BUS -1:0]             ms_to_ds_forward_bus;
	ysyx_23060025_id_stage ysyx_23060025_decoder(
		.clock              				( clock              ),
		.reset              				( reset              ),
		.inst_i							(t_id_inst_o),
		.reg1_data_i					(id_reg1_data_i),
		.reg2_data_i					(id_reg2_data_i),
		.csr_rdata_i					(csr_rdata_i		),
		.pc_i       					(t_id_pc_o),	

		.reg1_ren_o					(conflict_reg1_ren_i),
		.reg2_ren_o					(conflict_reg2_ren_i),

		.fencei_flag_o    					(icache_fencei_flag),	
		.ebreak_flag_o    					(idu_ebreak_flag_o),

		.es_to_ds_forward_bus           	( es_to_ds_forward_bus             ),
		.ms_to_ds_forward_bus           	(ms_to_ds_forward_bus              ),	
		.ws_to_ds_forward_bus           	({reg_wen_i, reg_waddr_i, reg_wdata_i,wb_csr_waddr_o,csr_wdata_i, csr_type_i}),	

		// ifu_idu
		.fs_to_ds_valid_i           	( ifu_valid_o             ),
		.ds_allowin_o           	(idu_ready_o              ),

		// .conflict_id_nop_i      				(conflict_id_nop_o     ),
		// .conflict_reg_bypass_data_i 				(conflict_reg_bypass_data_o),
		// .conflict_csr_bypass_data_i 				(conflict_csr_bypass_data_o),
		// .conflict_reg0_i        				(conflict_reg0_o       ),
		// .conflict_reg1_i        				(conflict_reg1_o       ),
		// .conflict_csr_i        					(conflict_csr_o       ),

		.conflict_id_nop_i      				(0     ),
		.conflict_reg_bypass_data_i 				(0),
		.conflict_csr_bypass_data_i 				(0),
		.conflict_reg0_i        				(0       ),
		.conflict_reg1_i        				(0       ),
		.conflict_csr_i        					(0       ),

		// idu_exu
		.ds_to_ex_valid_o           ( idu_valid_o             ),
		.es_allowin_i           	(exu_ready_o              ),
		.ds_valid_o           		(ds_busy         ),
		.ds_ready_go_o           	(             ),

		// .exu_ready   					(exu_ready_o),
		// .idu_ready_o       				(idu_ready_o),
		// .idu_valid_o     				(idu_valid_o),

		.aluop_o    					(idu_aluop_o		),	
		.alusel_o   					(idu_alusel_o		),
		.pc_o       					(idu_pc_o			),
		.reg1_o     					(idu_reg1_o			),
		.reg2_o     					(idu_reg2_o			),
		.wd_o       					(idu_wd_o			),
		.wreg_o     					(idu_wreg_o			),
		.imm_o      					(idu_imm_o			),
		.csr_flag_o						(idu_csr_flag_o		),
		.csr_rdata_o					(idu_csr_rdata_o		),
		.store_type_o					(idu_store_type_o	),
		.load_type_o					(idu_load_type_o	),

		.reg1_addr_o					(reg_raddr1_i),
		.reg2_addr_o					(reg_raddr2_i),
		.branch_flag_o					(if_branch_request_i),
		.branch_type_o					(if_branch_type_i),
		.branch_target_o				(if_branch_target_i),
		.jmp_flag_o						(if_jmp_flag_i),
		.jmp_target_o					(if_jmp_target_i),
		
		.csr_raddr_o						(csr_raddr_i),
		.csr_waddr_o						(csr_waddr_i)
		  
		
	);

	// ysyx_23060025_decoder ysyx_23060025_decoder(
	// 	.clock              				( clock              ),
	// 	.reset              				( reset              ),
	// 	.inst_i							(t_id_inst_o),
	// 	.reg1_data_i					(id_reg1_data_i),
	// 	.reg2_data_i					(id_reg2_data_i),
	// 	.csr_rdata_i					(csr_rdata_i		),
	// 	.pc_i       					(t_id_pc_o),	

	// 	.reg1_ren_o					(conflict_reg1_ren_i),
	// 	.reg2_ren_o					(conflict_reg2_ren_i),

	// 	.fencei_flag_o    					(icache_fencei_flag),	
	// 	.ebreak_flag_o    					(idu_ebreak_flag_o),	

	// 	// ifu_idu
	// 	.ifu_valid_i           	( ifu_valid_o             ),
	// 	.idu_ready_o           	(idu_ready_o              ),

	// 	.conflict_id_nop_i      				(conflict_id_nop_o     ),
	// 	.conflict_reg_bypass_data_i 				(conflict_reg_bypass_data_o),
	// 	.conflict_csr_bypass_data_i 				(conflict_csr_bypass_data_o),
	// 	.conflict_reg0_i        				(conflict_reg0_o       ),
	// 	.conflict_reg1_i        				(conflict_reg1_o       ),
	// 	.conflict_csr_i        					(conflict_csr_o       ),

	// 	// idu_exu
	// 	.idu_valid_o           	( idu_valid_o             ),
	// 	.exu_ready_i           	(exu_ready_o              ),



	// 	// .exu_ready   					(exu_ready_o),
	// 	// .idu_ready_o       				(idu_ready_o),
	// 	// .idu_valid_o     				(idu_valid_o),

	// 	.aluop_o    					(idu_aluop_o		),	
	// 	.alusel_o   					(idu_alusel_o		),
	// 	.pc_o       					(idu_pc_o			),
	// 	.reg1_o     					(idu_reg1_o			),
	// 	.reg2_o     					(idu_reg2_o			),
	// 	.wd_o       					(idu_wd_o			),
	// 	.wreg_o     					(idu_wreg_o			),
	// 	.imm_o      					(idu_imm_o			),
	// 	.csr_flag_o						(idu_csr_flag_o		),
	// 	.csr_rdata_o					(idu_csr_rdata_o		),
	// 	.store_type_o					(idu_store_type_o	),
	// 	.load_type_o					(idu_load_type_o	),

	// 	.reg1_addr_o					(reg_raddr1_i),
	// 	.reg2_addr_o					(reg_raddr2_i),
	// 	.branch_flag_o					(if_branch_request_i),
	// 	.branch_type_o					(if_branch_type_i),
	// 	.branch_target_o				(if_branch_target_i),
	// 	.jmp_flag_o						(if_jmp_flag_i),
	// 	.jmp_target_o					(if_jmp_target_i),
		
	// 	.csr_raddr_o						(csr_raddr_i),
	// 	.csr_waddr_o						(csr_waddr_i)	
	// );

	
	// outports wire
	wire [DATA_LEN-1:0] 	t_ex_reg1_o;
	wire [DATA_LEN-1:0] 	t_ex_reg2_o;
	wire [ADDR_LEN-1:0] 	t_ex_pc_o;
	wire [3:0]            	t_ex_aluop_o;
	wire [3:0]            	t_ex_alusel_o;
	wire [DATA_LEN-1:0] 	t_ex_imm_o;
	wire [2:0]            	t_ex_csr_flag_o;
	wire                  	t_ex_wd_o;
	wire [1:0]            	t_ex_store_type_o;
	wire [2:0]            	t_ex_load_type_o;
	wire [4:0]            	t_ex_wreg_o;
	wire                  	t_ex_ebreak_flag_o;

	wire [DATA_LEN-1:0] 	t_ex_csr_rdata_o;
	wire [11:0] 	t_ex_csr_waddr_o;

	ysyx_23060025_id_ex #(
		.ADDR_WIDTH 	( 32  ),
		.DATA_WIDTH 	( 32  ))
	u_ysyx_23060025_id_ex(
		.clock            	( clock             ),
		.reset            	( reset             ),
		.f_id_aluop_i     	( idu_aluop_o		  ),
		.f_id_alusel_i    	( idu_alusel_o		  ),
		.f_id_pc_i        	( idu_pc_o			  ),
		.f_id_reg1_i      	( idu_reg1_o		  ),
		.f_id_reg2_i      	( idu_reg2_o		  ),
		.f_id_wd_i        	( idu_wd_o			  ),
		.f_id_wreg_i      	( idu_wreg_o		),
		.f_id_imm_i       	( idu_imm_o			  ),
		.f_id_csr_flag_i  	( idu_csr_flag_o		),
		.f_id_store_type_i  ( idu_store_type_o	  ),
		.f_id_load_type_i  	( idu_load_type_o	  ),
		.f_id_ebreak_flag_i ( idu_ebreak_flag_o	  ),
		.f_id_valid_i  		( idu_valid_o	  ),
		.f_ex_ready_i  		( exu_ready_o	  ),

		.f_csr_csr_rdata_i  	( idu_csr_rdata_o		),
		.f_csr_csr_waddr_i  	( 	csr_waddr_i	),
		.t_ex_csr_waddr_o  		( t_ex_csr_waddr_o		),
		.t_ex_csr_rdata_o  		( t_ex_csr_rdata_o		),

		

		.t_ex_reg1_o      	( t_ex_reg1_o       ),
		.t_ex_reg2_o      	( t_ex_reg2_o       ),
		.t_ex_pc_o        	( t_ex_pc_o         ),
		.t_ex_aluop_o     	( t_ex_aluop_o      ),
		.t_ex_alusel_o    	( t_ex_alusel_o     ),
		.t_ex_imm_o       	( t_ex_imm_o        ),
		.t_ex_csr_flag_o  	( t_ex_csr_flag_o   ),
		.t_ex_wd_o        	( t_ex_wd_o         ),
		.t_ex_wreg_o      	( t_ex_wreg_o       ),
		.t_ex_store_type_o  ( t_ex_store_type_o         ),
		.t_ex_load_type_o   ( t_ex_load_type_o       ),
		.t_ex_ebreak_flag_o    ( t_ex_ebreak_flag_o       )
	);

// 	ysyx_23060025_conflict #(
// 		.STATE_RUN      	( 0  ),
// 		.STATE_WAIT_LSU 	( 1  ))
// 	u_ysyx_23060025_conflict(
// 		.clock                  	( clock                   ),
// 		.reset                  	( reset                   ),
// `ifdef BYPASS_TRACE
// 		.idu_pc_i             	( idu_pc_o              ),
// `endif
// 		.idu_csr_raddr_i             	( csr_raddr_i              ),
// 		.idu_csr_ren_i             	( |idu_csr_flag_o              ),
// 		.idu_busy_i             	( ds_busy              ),
// 		.idu_ren0_i             	( conflict_reg1_ren_i              ),
// 		.idu_ren1_i             	( conflict_reg2_ren_i              ),
// 		.idu_rsc0_i             	( reg_raddr1_i              ),
// 		.idu_rsc1_i             	( reg_raddr2_i              ),

// 		.exu_csr_waddr_i            ( ex_csr_waddr_o             ),
// 		.exu_csr_type_i            	( ex_csr_type_o             ),
// 		.exu_csr_wdata_i            ( ex_csr_wdata_o             ),
// 		.exu_busy_i            	( exu_busy             ),
// 		.exu_wd_i               	( ex_wd_o                ),
// 		.exu_wreg_i             	( ex_wreg_o              ),
// 		.exu_reg_wdata_i              	( ex_alu_result_o              ),
// 		.exu_mem_to_reg_i              	( |ex_load_type_o              ),
		
// 		.lsu_csr_waddr_i       	( lsu_csr_waddr_o        ),
// 		.lsu_csr_type_i       	( lsu_csr_type_o        ),
// 		.lsu_csr_wdata_i       	( lsu_csr_wdata_o        ),
// 		.lsu_mem_to_reg_i       	( |t_lsu_load_type_o        ),
// 		.lsu_busy_i            	( lsu_busy             ),
// 		.lsu_wd_i               	( lsu_reg_wen_o                ),
// 		.lsu_valid_i            	( lsu_valid_o             ),
// 		.lsu_wreg_i             	( lsu_wreg_o              ),
// 		.lsu_reg_wdata_i        	( lsu_reg_wdata_o         ),

// 		.conflict_csr_o        		( conflict_csr_o         ),
// 		.conflict_reg0_o        	( conflict_reg0_o         ),
// 		.conflict_reg1_o        	( conflict_reg1_o         ),
// 		.conflict_id_nop_o      	( conflict_id_nop_o       ),
// 		.conflict_reg_bypass_data_o 	( conflict_reg_bypass_data_o  ),
// 		.conflict_csr_bypass_data_o 	( conflict_csr_bypass_data_o  )
// 	);


	wire exu_valid_o;
	wire exu_ready_o;
	wire idu_valid_o;
	wire idu_ready_o;
	wire lsu_valid_o;
	wire lsu_ready_o;
	wire exu_ebreak_flag_o;
	wire [11:0] ex_csr_waddr_o;
	wire exu_busy;

	ysyx_23060025_ex_stage ysyx_23060025_EXE(
		.clock              	( clock     	),
		.reset              	( reset     	),

		.reg1_i				(t_ex_reg1_o      	),
		.reg2_i				(t_ex_reg2_o      	),
		.pc_i				(t_ex_pc_o        	),
		.alu_control		(t_ex_aluop_o     	),
		.alu_sel			(t_ex_alusel_o    	),		
		.imm_i				(t_ex_imm_o       	),
		.csr_flag_i			(t_ex_csr_flag_o  	),
		.csr_waddr_i			(t_ex_csr_waddr_o  	),
		.wd_i				(t_ex_wd_o        	),	
		.wreg_i				(t_ex_wreg_o      	),
		.store_type_i		(t_ex_store_type_o	)	,	
		.load_type_i		(t_ex_load_type_o 	),

		.csr_rdata_i		(t_ex_csr_rdata_o		),
		// idu_exu
		.ds_to_ex_valid_i           ( idu_valid_o             ),
		.lsu_allowin_i           	(  lsu_ready_o            ),
		.es_valid_o           		( exu_busy        ),
		.es_ready_go_o           	(             ),
		.es_to_lsu_valid_o           	(    exu_valid_o         ),
		.es_allowin_o           	(exu_ready_o             ),

		// exu_wbu

		.ebreak_flag_i           	(      t_ex_ebreak_flag_o        ),
		.ebreak_flag_o           	(      exu_ebreak_flag_o        ),

		// .isu_ready		(lsu_ready_o),	
		// .exu_ready_o		(exu_ready_o),

		.es_to_ds_forward_bus		(es_to_ds_forward_bus),
		.es_to_ds_valid		(),
		
		.wd_o				(ex_wd_o			),	
		.wreg_o				(ex_wreg_o		),
		.alu_result_o		(ex_alu_result_o		),
		.mem_wen_o			(ex_mem_wen_o	),	
		.mem_wdata_o		(ex_mem_wdata_o		),	
		.load_type_o		(ex_load_type_o		),
		.store_type_o		(ex_store_type_o		),
		.csr_wdata_o		(ex_csr_wdata_o		),
		.csr_type_o			(ex_csr_type_o	),
		.csr_waddr_o			(ex_csr_waddr_o  	),
		.csr_mcause_o		(csr_mcause_i),
		// TODO:
		.pc_o				()
		
		
	);

	// ysyx_23060025_EXE ysyx_23060025_EXE(
	// 	.clock              	( clock     	),
	// 	.reset              	( reset     	),

	// 	.reg1_i				(t_ex_reg1_o      	),
	// 	.reg2_i				(t_ex_reg2_o      	),
	// 	.pc_i				(t_ex_pc_o        	),
	// 	.alu_control		(t_ex_aluop_o     	),
	// 	.alu_sel			(t_ex_alusel_o    	),		
	// 	.imm_i				(t_ex_imm_o       	),
	// 	.csr_flag_i			(t_ex_csr_flag_o  	),
	// 	.csr_waddr_i			(t_ex_csr_waddr_o  	),
	// 	.wd_i				(t_ex_wd_o        	),	
	// 	.wreg_i				(t_ex_wreg_o      	),
	// 	.store_type_i		(t_ex_store_type_o	)	,	
	// 	.load_type_i		(t_ex_load_type_o 	),

	// 	.csr_rdata_i		(t_ex_csr_rdata_o		),
	// 	// idu_exu
	// 	.idu_valid_i           	(      idu_valid_o        ),
	// 	.exu_ready_o           	(      exu_ready_o        ),

	// 	// exu_wbu
	// 	.exu_valid_o           	(      exu_valid_o        ),
	// 	.lsu_ready_i           	(      lsu_ready_o        ),

	// 	.ebreak_flag_i           	(      t_ex_ebreak_flag_o        ),
	// 	.ebreak_flag_o           	(      exu_ebreak_flag_o        ),

	// 	// .isu_ready		(lsu_ready_o),	
	// 	// .exu_ready_o		(exu_ready_o),
	// 	// .exu_valid_o		(exu_valid_o),
		
	// 	.wd_o				(ex_wd_o			),	
	// 	.wreg_o				(ex_wreg_o		),
	// 	.alu_result_o		(ex_alu_result_o		),
	// 	.mem_wen_o			(ex_mem_wen_o	),	
	// 	.mem_wdata_o		(ex_mem_wdata_o		),	
	// 	.load_type_o		(ex_load_type_o		),
	// 	.store_type_o		(ex_store_type_o		),
	// 	.csr_wdata_o		(ex_csr_wdata_o		),
	// 	.csr_type_o			(ex_csr_type_o	),
	// 	.csr_waddr_o			(ex_csr_waddr_o  	),
	// 	.csr_mcause_o		(csr_mcause_i),
	// 	// TODO:
	// 	.pc_o				()
		
		
	// );

	// output declaration of module ysyx_23060025_ex_lsu
	wire t_lsu_wd_o;
	wire [4:0] t_lsu_wreg_o;
	wire [DATA_LEN-1:0] t_lsu_alu_result_o;
	wire t_lsu_mem_wen_o;
	wire [DATA_LEN-1:0] t_lsu_mem_wdata_o;
	wire [2:0] t_lsu_load_type_o;
	wire [1:0] t_lsu_store_type_o;
	wire [31:0] t_lsu_csr_wdata_o;
	wire [2:0] t_lsu_csr_type_o;
	wire [11:0] t_lsu_csr_waddr_o;
	wire 	   t_lsu_ebreak_flag_o;
	
	ysyx_23060025_ex_lsu #(
		.ADDR_WIDTH 	(32  ),
		.DATA_WIDTH 	(32  ))
	u_ysyx_23060025_ex_lsu(
		.clock              	(clock               ),
		.reset              	(reset               ),
		.f_ex_wd_i          	(ex_wd_o			   ),
		.f_ex_wreg_i        	(ex_wreg_o		   ),
		.f_ex_alu_result_i  	(ex_alu_result_o	   ),
		.f_ex_mem_wen_i     	(ex_mem_wen_o	   ),
		.f_ex_mem_wdata_i   	(ex_mem_wdata_o	   ),
		.f_ex_load_type_i   	(ex_load_type_o	   ),
		.f_ex_store_type_i  	(ex_store_type_o	   ),
		.f_ex_csr_wdata_i   	(ex_csr_wdata_o	   ),
		.f_ex_csr_type_i    	(ex_csr_type_o	   ),
		.f_ex_valid_i    		(exu_valid_o	   ),
		.f_lsu_ready_i    		(lsu_ready_o	   ),

		.f_ex_ebreak_flag_i           	(      exu_ebreak_flag_o        ),
		.f_ex_csr_waddr_i  			( 	ex_csr_waddr_o	),
		.t_lsu_csr_waddr_o  		( t_lsu_csr_waddr_o		),
		.t_lsu_ebreak_flag_o           	(      t_lsu_ebreak_flag_o        ),


		.t_lsu_wd_o         	(t_lsu_wd_o          ),
		.t_lsu_wreg_o       	(t_lsu_wreg_o        ),
		.t_lsu_alu_result_o 	(t_lsu_alu_result_o  ),
		.t_lsu_mem_wen_o    	(t_lsu_mem_wen_o     ),
		.t_lsu_mem_wdata_o  	(t_lsu_mem_wdata_o   ),
		.t_lsu_load_type_o  	(t_lsu_load_type_o   ),
		.t_lsu_store_type_o 	(t_lsu_store_type_o  ),
		.t_lsu_csr_wdata_o  	(t_lsu_csr_wdata_o   ),
		.t_lsu_csr_type_o   	(t_lsu_csr_type_o    )
	);
	
	wire lsu_ebreak_flag_o;
	wire lsu_busy;
`ifdef DIFFTEST
	wire lsu_diff_skip_flag_o;
`endif

	ysyx_23060025_lsu_stage#(
		.DATA_LEN          ( 32 ),
		.ADDR_LEN          ( 32 )
	)ysyx_23060025_LSU(
		.rstn           ( ~reset           ),
		.clock           ( clock           		),

	`ifdef DIFFTEST
		.diff_skip_flag_i  ( diff_skip_flag_i           ),
		.diff_skip_flag_o  ( lsu_diff_skip_flag_o           		),
	`endif

		.wd_i          	( t_lsu_wd_o        ),
		.wreg_i   		( t_lsu_wreg_o      ),
		.alu_result_i   ( t_lsu_alu_result_o	),
		.mem_wen_i     	( t_lsu_mem_wen_o   ),
		.mem_wdata_i   	( t_lsu_mem_wdata_o ),
		.load_type_i	( t_lsu_load_type_o ),
		.store_type_i	( t_lsu_store_type_o),
		.csr_wdata_i	( t_lsu_csr_wdata_o ),
		.csr_type_i		( t_lsu_csr_type_o  ),
		.csr_waddr_i	( t_lsu_csr_waddr_o  ),

		.lsu_valid_o           	(  lsu_busy            ),
		.lsu_ready_go_o           (              ),

		.ms_to_ds_forward_bus           (   ms_to_ds_forward_bus           ),
		.ms_to_ds_valid           	(              ),

		// idu_exu
		.ex_to_lsu_valid_i           (   exu_valid_o           ),
		.lsu_allowin_o           	(    lsu_ready_o          ),

		// exu_wbu
		.lsu_to_wbu_valid_o           	(     lsu_valid_o         ),
		.wbu_allowin_i           	(    wbu_ready_o          ),


		.ebreak_flag_i   	( t_lsu_ebreak_flag_o 		),
		.ebreak_flag_o    ( lsu_ebreak_flag_o   	),

		.wd_o     		( lsu_reg_wen_o			),
		.wreg_o   		( lsu_wreg_o			),
		.wdata_o  		( lsu_reg_wdata_o		),
		.csr_type_o		( lsu_csr_type_o		),
		.csr_wdata_o    ( lsu_csr_wdata_o	 	),
		.csr_waddr_o	( lsu_csr_waddr_o  ),
		// .memory_inst_o  ( lsu_memory_inst_o ),

		.addr_r_addr_o     ( data_addr_r_addr_o     ),
		.addr_r_valid_o    ( data_addr_r_valid_o    ),
		.addr_r_ready_i    ( data_addr_r_ready_i    ),
		.addr_r_size_o	   ( data_addr_r_size_o		),
		.r_data_i          ( data_r_data_i          ),
		.r_resp_i          ( data_r_resp_i          ),
		.r_valid_i         ( data_r_valid_i         ),
		.r_ready_o         ( data_r_ready_o         ),
		.addr_w_addr_o     ( data_addr_w_addr_o     ),
		.addr_w_valid_o    ( data_addr_w_valid_o    ),
		.addr_w_ready_i    ( data_addr_w_ready_i    ),
		.addr_w_size_o	   ( data_addr_w_size_o		),
		.w_data_o          ( data_w_data_o          ),
		.w_strb_o          ( data_w_strb_o          ),
		.w_valid_o         ( data_w_valid_o         ),
		.w_ready_i         ( data_w_ready_i         ),
		.bkwd_resp_i       ( data_bkwd_resp_i       ),
		.bkwd_valid_i      ( data_bkwd_valid_i      ),
		.bkwd_ready_o      ( data_bkwd_ready_o      )
	);

	// ysyx_23060025_LSU#(
	// 	.DATA_LEN          ( 32 ),
	// 	.ADDR_LEN          ( 32 )
	// )ysyx_23060025_LSU(
	// 	.rstn           ( ~reset           ),
	// 	.clock           ( clock           		),

	// `ifdef DIFFTEST
	// 	.diff_skip_flag_i  ( diff_skip_flag_i           ),
	// 	.diff_skip_flag_o  ( lsu_diff_skip_flag_o           		),
	// `endif

	// 	.wd_i          	( t_lsu_wd_o        ),
	// 	.wreg_i   		( t_lsu_wreg_o      ),
	// 	.alu_result_i   ( t_lsu_alu_result_o	),
	// 	.mem_wen_i     	( t_lsu_mem_wen_o   ),
	// 	.mem_wdata_i   	( t_lsu_mem_wdata_o ),
	// 	.load_type_i	( t_lsu_load_type_o ),
	// 	.store_type_i	( t_lsu_store_type_o),
	// 	.csr_wdata_i	( t_lsu_csr_wdata_o ),
	// 	.csr_type_i		( t_lsu_csr_type_o  ),
	// 	.csr_waddr_i	( t_lsu_csr_waddr_o  ),

		

	// 	// idu_exu
	// 	.exu_valid_i           	(   exu_valid_o           ),
	// 	.lsu_ready_o           	(    lsu_ready_o          ),

	// 	// exu_wbu
	// 	.lsu_valid_o           	(     lsu_valid_o         ),
	// 	.wbu_ready_i           	(    wbu_ready_o          ),


	// 	.ebreak_flag_i   	( t_lsu_ebreak_flag_o 		),
	// 	.ebreak_flag_o    ( lsu_ebreak_flag_o   	),

	// 	.wd_o     		( lsu_reg_wen_o			),
	// 	.wreg_o   		( lsu_wreg_o			),
	// 	.wdata_o  		( lsu_reg_wdata_o		),
	// 	.csr_type_o		( lsu_csr_type_o		),
	// 	.csr_wdata_o    ( lsu_csr_wdata_o	 	),
	// 	.csr_waddr_o	( lsu_csr_waddr_o  ),
	// 	// .memory_inst_o  ( lsu_memory_inst_o ),

	// 	.addr_r_addr_o     ( data_addr_r_addr_o     ),
	// 	.addr_r_valid_o    ( data_addr_r_valid_o    ),
	// 	.addr_r_ready_i    ( data_addr_r_ready_i    ),
	// 	.addr_r_size_o	   ( data_addr_r_size_o		),
	// 	.r_data_i          ( data_r_data_i          ),
	// 	.r_resp_i          ( data_r_resp_i          ),
	// 	.r_valid_i         ( data_r_valid_i         ),
	// 	.r_ready_o         ( data_r_ready_o         ),
	// 	.addr_w_addr_o     ( data_addr_w_addr_o     ),
	// 	.addr_w_valid_o    ( data_addr_w_valid_o    ),
	// 	.addr_w_ready_i    ( data_addr_w_ready_i    ),
	// 	.addr_w_size_o	   ( data_addr_w_size_o		),
	// 	.w_data_o          ( data_w_data_o          ),
	// 	.w_strb_o          ( data_w_strb_o          ),
	// 	.w_valid_o         ( data_w_valid_o         ),
	// 	.w_ready_i         ( data_w_ready_i         ),
	// 	.bkwd_resp_i       ( data_bkwd_resp_i       ),
	// 	.bkwd_valid_i      ( data_bkwd_valid_i      ),
	// 	.bkwd_ready_o      ( data_bkwd_ready_o      )
	// );

//  	wire t_wb_reg_wen_o;
// 	wire [4:0] t_wb_wreg_o;
// 	wire [11:0] t_wb_csr_waddr_o;
// 	wire [DATA_LEN-1:0] t_wb_reg_wdata_o;
// 	wire [DATA_LEN-1:0] t_wb_csr_wdata_o;
// 	wire [2:0] t_wb_csr_type_o;
// 	wire t_wb_ebreak_flag_o;
// 	wire t_wb_lsu_valid_o;
// `ifdef DIFFTEST
// 	wire wb_diff_skip_flag_i;
// `endif	
// 	ysyx_23060025_lsu_wb #(
// 		.ADDR_WIDTH 	(32  ),
// 		.DATA_WIDTH 	(32  ))
// 	u_ysyx_23060025_lsu_wb(
// 		.clock               	(clock                ),
// 		.reset               	(reset                ),
// 		.f_lsu_reg_wen_i     	(lsu_reg_wen_o	  	),
// 		.f_lsu_wreg_i        	(lsu_wreg_o		  	),
// 		.f_lsu_reg_wdata_i   	(lsu_reg_wdata_o	  ),
// 		.f_lsu_csr_wdata_i   	(lsu_csr_wdata_o	  ),
// 		.f_lsu_csr_type_i    	(lsu_csr_type_o	  	),
// 		.f_lsu_valid_i 			(lsu_valid_o  			),
// 		.f_lsu_ebreak_flag_i 	(lsu_ebreak_flag_o  			),
// 		.f_wb_ready_i 			(wbu_ready_o  ),
// 		.f_lsu_csr_waddr_o  		( lsu_csr_waddr_o  ),
// `ifdef DIFFTEST
// 		.diff_skip_flag_i  ( lsu_diff_skip_flag_o           ),
// 		.diff_skip_flag_o  ( wb_diff_skip_flag_i           		),
// 	`endif

// 		.t_wb_lsu_valid_o      	(t_wb_lsu_valid_o       ),
// 		.t_wb_reg_wen_o      	(t_wb_reg_wen_o       ),
// 		.t_wb_reg_wdata_o      	(t_wb_reg_wdata_o       ),
// 		.t_wb_wreg_o         	(t_wb_wreg_o          ),
// 		.t_wb_ebreak_flag_o    	(t_wb_ebreak_flag_o     ),
// 		.t_wb_csr_wdata_o    	(t_wb_csr_wdata_o     ),
// 		.t_wb_csr_type_o     	(t_wb_csr_type_o      ),
// 		.t_wb_csr_waddr_o  		(t_wb_csr_waddr_o   )
// 	);
	
	wire wbu_ready_o;
	wire [11:0] wb_csr_waddr_o;
		ysyx_23060025_wb#(
		.DATA_LEN     ( 32 )
	)ysyx_23060025_wb(
		.reset          ( reset          ),
		.clock          ( clock          ),

		.wd_i         ( lsu_reg_wen_o	   ),
		.wreg_i       ( lsu_wreg_o		   ),
		.reg_wdata_i  ( lsu_reg_wdata_o ),
		.csr_wdata_i  ( lsu_csr_wdata_o ),
		.csr_waddr_i  ( lsu_csr_waddr_o ),
		.csr_type_i   ( lsu_csr_type_o	 ),
		// .memory_inst_i( lsu_memory_inst_o  ),
		.ebreak_flag_i(lsu_ebreak_flag_o  ),
`ifdef DIFFTEST
		.diff_skip_flag_i  ( lsu_diff_skip_flag_o           ),
`endif
		// lsu_wbu 
		.ms_to_ws_valid    ( lsu_valid_o	    ),
		.ws_allowin_o    ( wbu_ready_o    ),

		.wd_o     	  ( reg_wen_i   ),
		.wreg_o   	  ( reg_waddr_i ),
		.wdata_o  	  ( reg_wdata_i ),
		.csr_type_o   ( csr_type_i  ),
		.csr_waddr_o  ( wb_csr_waddr_o ),
		.csr_wdata_o  ( csr_wdata_i  )
	);
// 	ysyx_23060025_wb#(
// 		.DATA_LEN     ( 32 )
// 	)ysyx_23060025_wb(
// 		.reset          ( reset          ),
// 		.clock          ( clock          ),

// 		.wd_i         ( t_wb_reg_wen_o	   ),
// 		.wreg_i       ( t_wb_wreg_o		   ),
// 		.reg_wdata_i  ( t_wb_reg_wdata_o ),
// 		.csr_wdata_i  ( t_wb_csr_wdata_o ),
// 		.csr_waddr_i  ( t_wb_csr_waddr_o ),
// 		.csr_type_i   ( t_wb_csr_type_o	 ),
// 		// .memory_inst_i( lsu_memory_inst_o  ),
// 		.ebreak_flag_i( t_wb_ebreak_flag_o  ),
// `ifdef DIFFTEST
// 		.diff_skip_flag_i  ( wb_diff_skip_flag_i           ),
// `endif
// 		// lsu_wbu 
// 		.lsu_valid_i    ( t_wb_lsu_valid_o	    ),
// 		.wbu_ready_o    ( wbu_ready_o    ),

// 		.wd_o     	  ( reg_wen_i   ),
// 		.wreg_o   	  ( reg_waddr_i ),
// 		.wdata_o  	  ( reg_wdata_i ),
// 		.csr_type_o   ( csr_type_i  ),
// 		.csr_waddr_o  ( wb_csr_waddr_o ),
// 		.csr_wdata_o  ( csr_wdata_i  )
// 	);


	ysyx_23060025_CSR#(
		.DATA_WIDTH    ( 32 )
	)ysyx_23060025_CSR(
		.clock           ( clock           ),
		.reset           ( reset           ),
		.csr_raddr      ( csr_raddr_i      ),
		.csr_waddr      ( wb_csr_waddr_o      ),
		.wdata         ( csr_wdata_i         ),
		.csr_type_i    ( csr_type_i    ),
		// .csr_mepc_i    ( csr_mepc_i    ),  
		.csr_mcause_i  ( csr_mcause_i  ),
		// .csr_mtvec_pc_o     ( csr_mtvec_pc_o      ),
		// .csr_mepc_pc_o      ( csr_mepc_pc_o      ),
		.r_data        ( csr_rdata_i     )
	);

endmodule
