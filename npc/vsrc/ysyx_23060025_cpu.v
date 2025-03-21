`include "ysyx_23060025_define.v"
module ysyx_23060025_cpu #(parameter DATA_LEN = 32,ADDR_LEN = 32) (
	input								clock 		,
	input								reset 		,

	// IFU-AXI
	// Addr Read
	output		[ADDR_LEN - 1:0]		inst_paddr_o	,
	output		                		inst_psel_o		,
	output		[7:0]  					inst_plen_o		,
	output		[2:0]  					inst_psize_o	,	
	input		                		inst_pvalid_o	,
	input		       					inst_plast_o	,

	// Read data
`ifdef DIFFTEST
	input								diff_skip_flag_i	,
`endif
	// data AXI
	 //Addr Read
	output		                		data_prsel_o  ,
	output		[ADDR_LEN - 1:0]		data_praddr_o ,
	output		[2:0]                	data_psize_o ,
	output		[7:0]                	data_prlen_o ,
	input		                		data_prlast_o  ,
	input		[DATA_LEN - 1:0]		data_prdata_o,
	input		                		data_pvalid_o,

	output		                				data_pwsel_o  ,
	output		[ADDR_LEN - 1:0]				data_pwaddr_o ,
	output		[`MACRO_CACHE_LINE_W - 1:0]		data_pwdata_o ,
	output		[3:0]							data_pwstrb_o ,
	output		[2:0]                			data_pwtype_o ,
	input		                				data_pwrdy_o  ,


	input	        [DATA_LEN - 1:0]    inst_i		
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
	wire			[ADDR_LEN - 1:0]	if_jmp_target_i;
	wire								if_jmp_flag_i;	
	// wire			[ADDR_LEN - 1:0]	csr_mtvec_pc_o;
	// wire			[ADDR_LEN - 1:0]	csr_mepc_pc_o;
	// wire			[ADDR_LEN - 1:0]	pcPlus		;
	// wire			[ADDR_LEN - 1:0]	pcBranch	;
	// wire			[1:0]				pcSrc		;

	//my_decoder
	wire								ifu_valid_o		;
	wire			[`FS_TO_DS_DATA_BUS - 1:0]	if_to_id_bqu_bus;
	wire			[`DS_TO_ES_DATA_BUS - 1:0]	ds_to_es_bus;
	wire			[`ES_TO_MS_DATA_BUS -1:0]   es_to_ms_bus;
	wire			[ADDR_LEN - 1:0]			id_reg1_data_i	;
	wire			[ADDR_LEN - 1:0]			id_reg2_data_i	;


	// execute
	wire								idu_csr_flag_o	;


	wire			[31:0]				csr_rdata_i	;

	// csr Unit
	wire			[11:0]				csr_raddr_i	;
	wire			[DATA_LEN - 1:0]	csr_wdata_i		;
	wire			[2:0]				csr_type_i		;
	// wire	        [DATA_LEN - 1:0]    csr_mepc_i		;
	wire	        [DATA_LEN - 1:0]    csr_mcause_i	;



	wire 			[`MS_TO_WS_DATA_BUS-1:0]  ms_to_ws_bus;

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


		
		.ebreak_flag_i    ( idu_ebreak_flag_o    ),
		.jmp_flag_i  	  ( if_jmp_flag_i  ),
		.jmp_target_i     ( if_jmp_target_i    ),
		.csr_jmp_i     	  (idu_csr_flag_o   ),
		// .csr_jmp_i     	  ( ex_csr_flag_i[2]  ),
		.csr_pc_i         ( idu_csr_rdata_o      ),
		.if_to_id_bqu_bus_o      ( if_to_id_bqu_bus         ),
		// .csr_mepc_pc_i         ( csr_mepc_pc_o      ),

		.idu_flush_i        	( if_flush_i        ),
		.idu_flush_pc_i         ( if_flush_pc_i           ),
		
		// .bpu_pc_o         ( if_flush_pc_i           ),
		.bpu_pc_predict_i        	( bpu_pc_predict_o        ),
		.bpu_valid_i         ( bpu_valid_o           ),

		.out_paddr    		( icache_addr_r_addr     ),
		.out_psel   		( icache_addr_r_sel    ),
		.out_pready   		( icache_r_ready    ),
		.out_prdata         ( icache_r_data          )
	);

	// output declaration of module ysyx_23060025_ifu_bpu
	wire [ADDR_LEN-1:0] bpu_pc_predict_o;
	wire bpu_valid_o;
	
	ysyx_23060025_ifu_bpu #(
		.ADDR_WIDTH 	(32  ),
		.DATA_WIDTH 	(32  ))
	u_ysyx_23060025_ifu_bpu(
		.if_to_bqu_bus		(if_to_id_bqu_bus		  ),
		.bpu_pc_predict_o 	(bpu_pc_predict_o  ),
		.bpu_valid_o      	(bpu_valid_o       )
	);
	
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

		.out_paddr  	( inst_paddr_o   ),
		.out_psel 	( inst_psel_o  ),
		.out_rlast  	( inst_plast_o   ),
		.out_arlen   	( inst_plen_o    ),
		.out_arsize  	( inst_psize_o   ),
		.out_rvalid  	( inst_pvalid_o   ),
		.out_rdata   	( inst_i    )
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


	wire 	[31:0]			idu_csr_rdata_o ;

	wire 					if_flush_i      ;
	wire 	[31:0]			if_flush_pc_i ;

	wire  [`ES_TO_DS_FORWARD_BUS -1:0]             es_to_ds_forward_bus;
    wire  [`MS_TO_DS_FORWARD_BUS -1:0]             ms_to_ds_forward_bus;
	ysyx_23060025_id_stage ysyx_23060025_decoder(
		.clock              				( clock              ),
		.reset              				( reset              ),
		.fs_to_ds_bus				(if_to_id_bqu_bus),
		.reg1_data_i					(id_reg1_data_i),
		.reg2_data_i					(id_reg2_data_i),
		.csr_rdata_i					(csr_rdata_i		),

		.fencei_flag_o    					(icache_fencei_flag),	
		.ebreak_flag_o    					(idu_ebreak_flag_o),

		.es_to_ds_forward_bus           	( es_to_ds_forward_bus             ),
		.ms_to_ds_forward_bus           	(ms_to_ds_forward_bus              ),	
		.ws_to_ds_forward_bus           	({reg_wen_i & |reg_waddr_i, 
													reg_waddr_i, 
													reg_wdata_i,
													ws_csr_waddr_o,
													csr_wdata_i, 
													csr_type_i}),	
		// ifu_idu
		.fs_to_ds_valid_i           	( ifu_valid_o             ),
		.ds_allowin_o           	(idu_ready_o              ),

		// idu_exu
		.ds_to_ex_valid_o           ( idu_valid_o             ),
		.es_allowin_i           	(exu_ready_o              ),
		.ds_valid_o           		(         ),
		.ds_to_es_bus				(ds_to_es_bus),


		
		.csr_flag_o						(idu_csr_flag_o		),
		.csr_rdata_o					(idu_csr_rdata_o		),

		.reg1_addr_o					(reg_raddr1_i),
		.reg2_addr_o					(reg_raddr2_i),
		.jmp_flag_o						(if_jmp_flag_i),
		.jmp_target_o					(if_jmp_target_i),
		.ds_to_fs_bpu_flush_o			(if_flush_i),
		.ds_to_fs_flush_pc_o			(if_flush_pc_i),
		
		.csr_raddr_o						(csr_raddr_i)
	);

	wire exu_valid_o;
	wire exu_ready_o;
	wire idu_valid_o;
	wire idu_ready_o;
	wire lsu_valid_o;
	wire lsu_ready_o;


	ysyx_23060025_ex_stage ysyx_23060025_EXE(
		.clock              	( clock     	),
		.reset              	( reset     	),

		// idu_exu
		.ds_to_es_bus				(ds_to_es_bus),
		.ds_to_ex_valid_i           ( idu_valid_o             ),
		.lsu_allowin_i           	(  lsu_ready_o            ),
		.es_valid_o           		(         ),
		.es_to_lsu_valid_o           	(    exu_valid_o         ),
		.es_allowin_o           	(exu_ready_o             ),
		// exu_wbu

		.es_to_ds_forward_bus		(es_to_ds_forward_bus),
		.es_to_ms_bus				(es_to_ms_bus)
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
		.rstn           		( ~reset           ),
		.clock           		( clock           		),

	`ifdef DIFFTEST
		.diff_skip_flag_i  		( diff_skip_flag_i           ),
		.diff_skip_flag_o  		( lsu_diff_skip_flag_o           		),
	`endif
		.lsu_valid_o           	(  lsu_busy            ),

		.ms_to_ds_forward_bus   (   ms_to_ds_forward_bus           ),
		.ms_to_ds_valid         (              ),

		// idu_exu
		.ex_to_lsu_valid_i      (   exu_valid_o           ),
		.es_to_ms_bus           (   es_to_ms_bus           ),
		.lsu_allowin_o          (    lsu_ready_o          ),

		// exu_wbu

		.lsu_to_wbu_valid_o     (     lsu_valid_o         ),
		.wbu_allowin_i          (    ws_ready_o          ),

		.ms_to_ws_bus           (ms_to_ws_bus           ),

		.out_fencei   			( lsu_fencei_o    ),
		.out_paddr   			( lsu_paddr_o    ),
		.out_psel    			( lsu_psel_o     ),
		.out_psize    			(lsu_psize_o     ),
		.out_pwrite  			( lsu_pwrite_o		),
		.out_pwdata  			( lsu_pwdata_o   ),
		.out_pwstrb  			( lsu_pwstrb_o   ),
		.out_prdata  			( lsu_prdata_o   ),
		.out_pvalid  			( lsu_pvalid_o   )
	);

	wire	[ADDR_LEN - 1:0]		lsu_paddr_o ;
	wire	                		lsu_psel_o  ;
	wire	                		lsu_pwrite_o;
	wire	[DATA_LEN - 1:0]		lsu_pwdata_o;
	wire	[3:0]					lsu_pwstrb_o;
	wire	[2:0]					lsu_psize_o;
	wire	[DATA_LEN - 1:0]		lsu_prdata_o;
	wire	                		lsu_pvalid_o;

	wire	                		lsu_fencei_o  ;

	ysyx_23060025_dcache 
	u_ysyx_23060025_dcache(
		.clock         	(clock          ),
		.reset         	(reset          ),
		.in_fencei      (lsu_fencei_o       ),
		.in_paddr      	(lsu_paddr_o       ),
		.in_pwdata     	(lsu_pwdata_o      ),
		.in_pwstrb     	(lsu_pwstrb_o      ),
		.in_pwrite     	(lsu_pwrite_o      ),
		.in_psel       	(lsu_psel_o        ),
		.in_psize       (lsu_psize_o        ),
		.in_pready     	(lsu_pvalid_o      ),
		.in_prdata     	(lsu_prdata_o      ),

		.out_pwr_req   	(data_pwsel_o    ),
		.out_pwaddr    	(data_pwaddr_o     ),
		.out_pwdata    	(data_pwdata_o     ),
		.out_pwstrb    	(data_pwstrb_o     ),
		.out_pwtype    	(data_pwtype_o     ),
		.out_pwrdy     	(data_pwrdy_o      ),

		.out_praddr    	(data_praddr_o     ),
		.out_prd_req   	(data_prsel_o    ),
		.out_prsize    	(data_psize_o     ),
		.out_prlen     	(data_prlen_o      ),
		.out_prlast    	(data_prlast_o     ),
		.out_prdata    	(data_prdata_o     ),
		.out_pvalid    	(data_pvalid_o     )
	);
	

	wire ws_ready_o;
	wire [11:0] ws_csr_waddr_o;
	wire [31:0] ws_flush_pc_o;
	wire ws_flush_sign_o;
	wire ws_flush_valid_o;
		ysyx_23060025_wb#(
		.DATA_LEN     ( 32 )
	)ysyx_23060025_wb(
		.reset          ( reset          ),
		.clock          ( clock          ),

`ifdef DIFFTEST
		.diff_skip_flag_i  	( lsu_diff_skip_flag_o           ),
`endif
		// lsu_wbu 
		.ms_to_ws_bus       ( ms_to_ws_bus	   ),
		.ms_to_ws_valid    	( lsu_valid_o	    ),
		.ws_allowin_o    	( ws_ready_o    ),

		.ws_flush_pc_o    	( ws_flush_pc_o	    ),
		.ws_flush_sign_o    ( ws_flush_sign_o    ),
		.ws_flush_valid    	( ws_flush_valid_o    ),

		.wd_o     	  	( reg_wen_i   ),
		.wreg_o   	  	( reg_waddr_i ),
		.reg_wdata_o  	( reg_wdata_i ),
		.csr_type_o   	( csr_type_i  ),
		.csr_waddr_o  	( ws_csr_waddr_o ),
		.csr_mcause_o   ( csr_mcause_i	 ),
		.csr_wdata_o  	( csr_wdata_i  )
	);


	ysyx_23060025_CSR#(
		.DATA_WIDTH    ( 32 )
	)ysyx_23060025_CSR(
		.clock           ( clock           ),
		.csr_raddr      ( csr_raddr_i      ),
		.csr_waddr      ( ws_csr_waddr_o      ),
		.wdata         ( csr_wdata_i         ),
		.csr_type_i    ( csr_type_i    ),
		// .csr_mepc_i    ( csr_mepc_i    ),  
		.csr_mcause_i  ( csr_mcause_i  ),
		// .csr_mtvec_pc_o     ( csr_mtvec_pc_o      ),
		// .csr_mepc_pc_o      ( csr_mepc_pc_o      ),
		.r_data        ( csr_rdata_i     )
	);

endmodule
