`include "ysyx_23060025_define.v"
module ysyx_23060025 #(parameter DATA_LEN = 32,ADDR_LEN = 32) (
	input								clock 				,
	input								reset 				,
	input								io_interrupt		,
	// Adddr Write
	input								io_master_awready	,
	output								io_master_awvalid	,
	output			[ADDR_LEN - 1:0]	io_master_awaddr	,
	output			[3:0]				io_master_awid	,
	output			[7:0]				io_master_awlen	,
	output			[2:0]				io_master_awsize	,
	output			[1:0]				io_master_awburst	,

	// Write Data
	input								io_master_wready	,
	output								io_master_wvalid	,
	output			[DATA_LEN - 1:0]	io_master_wdata	,
	output			[3:0]				io_master_wstrb	,
	output								io_master_wlast	,

	// Write backward
	output								io_master_bready	,
	input								io_master_bvalid	,
	input			[1:0]				io_master_bresp	,
	input			[3:0]				io_master_bid	,

	// Read Addr 
	input								io_master_arready	,
	output								io_master_arvalid	,
	output			[ADDR_LEN - 1:0]	io_master_araddr	,
	output			[3:0]				io_master_arid	,
	output			[7:0]				io_master_arlen	,
	output			[2:0]				io_master_arsize	,
	output			[1:0]				io_master_arburst	,

	// Read Data
	output								io_master_rready	,
	input								io_master_rvalid	,
	input			[1:0]				io_master_rresp	,
	input			[DATA_LEN - 1:0]	io_master_rdata	,
	input								io_master_rlast	,
	input			[3:0]				io_master_rid	,


	// Adddr Write
	output								io_slave_awready	,
	input								io_slave_awvalid	,
	input			[ADDR_LEN - 1:0]	io_slave_awaddr	,
	input			[3:0]				io_slave_awid	,
	input			[7:0]				io_slave_awlen	,
	input			[2:0]				io_slave_awsize	,
	input			[1:0]				io_slave_awburst	,

	// Write Data
	output								io_slave_wready	,
	input								io_slave_wvalid	,
	input			[DATA_LEN - 1:0]	io_slave_wdata	,
	input			[3:0]				io_slave_wstrb	,
	input								io_slave_wlast	,

	// Write backward
	input								io_slave_bready	,
	output								io_slave_bvalid	,
	output			[1:0]				io_slave_bresp	,
	output			[3:0]				io_slave_bid	,

	// Read Addr 
	output								io_slave_arready	,
	input								io_slave_arvalid	,
	input			[ADDR_LEN - 1:0]	io_slave_araddr	,
	input			[3:0]				io_slave_arid	,
	input			[7:0]				io_slave_arlen	,
	input			[2:0]				io_slave_arsize	,
	input			[1:0]				io_slave_arburst	,

	// Read Data
	input								io_slave_rready	,
	output								io_slave_rvalid	,
	output			[1:0]				io_slave_rresp	,
	output			[DATA_LEN - 1:0]	io_slave_rdata	,
	output								io_slave_rlast	,
	output			[3:0]				io_slave_rid		

);
	wire			[DATA_LEN - 1:0]	inst		;

	// 检测到ebreak
    // import "DPI-C" function void clk_cycle_plus();
    // always @(posedge clock)
    //     clk_cycle_plus();

	// Xbar
    //Addr Read
	wire									axi_device		;
	wire			[ADDR_LEN - 1:0]		xbar_addr_r_addr_o	;
	wire		                		xbar_addr_r_valid_o	;
	wire		                		xbar_addr_r_ready_i	;
	wire			[7:0]				xbar_addr_r_len_o	;
	wire			[2:0]				xbar_addr_r_size_o	;

	// Read data
	wire		[DATA_LEN - 1:0]		xbar_r_data_i		;
	wire		                		xbar_r_valid_i		;
	wire		                		xbar_r_ready_o		;
	wire								xbar_r_last_i		;

	// Addr Write
	wire			[ADDR_LEN - 1:0]		xbar_addr_w_addr_o	;	// 写地址
	wire		                		xbar_addr_w_valid_o	;	// 主设备给出的地址和相关控制信号有效
	wire		                		xbar_addr_w_ready_i	; // 从设备已准备好接收地址和相关的控制信号
	wire			[7:0]				xbar_addr_w_len_o	;
	wire			[2:0]				xbar_addr_w_size_o	;

	// Write data
	wire			[DATA_LEN - 1:0]		xbar_w_data_o	;	// 写出的数据
	wire			[3:0]					xbar_w_strb_o	;	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	wire		                		xbar_w_valid_o	;	// 主设备给出的数据和字节选通信号有效
	wire		                		xbar_w_ready_i	;	// 从设备已准备好接收数据选通信号
	wire								xbar_w_last_o	;
	// Backward
	wire		                		xbar_bkwd_valid_i	;	// 从设备给出的写回复信号是否有效
	wire		                		xbar_bkwd_ready_o	;// 主设备已准备好接收写回复信号

	// CLINT
	wire	[ADDR_LEN - 1:0]		clint_addr_r_addr_o	;
	wire	                		clint_addr_r_valid_o	;
	wire	                		clint_addr_r_ready_i	;


	// Read data
	wire		[DATA_LEN - 1:0]	clint_r_data_i	;
	wire		[1:0]				clint_r_resp_i	;	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	wire		                	clint_r_valid_i	;
	wire		                	clint_r_last_i;
	wire		                	clint_r_ready_o	;
`ifdef N_YOSYS_STA_CHECK

	// 检测resp
	import "DPI-C" function void resp_check(byte resp);
	always @(*)
		resp_check({6'b0, io_master_rresp});

	always @(*)
		resp_check({6'b0, io_master_bresp});
	
	
	// 为ITRACE提供指令
    import "DPI-C" function void inst_get(int inst);
    always @(*) begin
        inst_get(inst);
		// $display("io_master_awaddr = %x",io_master_awaddr);
	end
`endif

	// outports wire
	`ifdef DIFFTEST
	wire                	diff_skip_flag;
	`endif
	

	wire	[ADDR_LEN - 1:0]		inst_paddr_o	;
	wire	                		inst_psel_o		;
	wire	[7:0]  					inst_plen_o		;
	wire	[2:0]  					inst_psize_o	;	
	wire	                		inst_pvalid_o	;
	wire	       					inst_plast_o	;

	wire		                		data_prsel_o  	;
	wire		[ADDR_LEN - 1:0]		data_praddr_o 	;
	wire		[2:0]                	data_psize_o 	;
	wire		[7:0]                	data_prlen_o 	;
	wire		                		data_prlast_o  	;
	wire		[DATA_LEN - 1:0]		data_prdata_o	;
	wire		                		data_prvalid_o	;

	wire		                				data_pwsel_o  ;
	wire		[ADDR_LEN - 1:0]				data_pwaddr_o ;
	wire		[`MACRO_CACHE_LINE_W - 1:0]		data_pwdata_o ;
	wire		[3:0]							data_pwstrb_o ;
	wire		[2:0]                			data_pwtype_o ;
	wire		                				data_pwrdy_o  ;
	wire		                				data_pwalid_o	;

	ysyx_23060025_cpu #(
		.DATA_LEN 	( 32  ),
		.ADDR_LEN 	( 32  ))
	ysyx_23060025_cpu(
		.clock               	( clock                ),
		.reset               	( reset                ),
		.inst_paddr_o	 		( inst_paddr_o	  ),
		.inst_psel_o		 	( inst_psel_o		 ),
		.inst_plen_o			( inst_plen_o			),
		.inst_psize_o	 		( inst_psize_o	  ),
		.inst_pvalid_o	 		( inst_pvalid_o		),
		.inst_plast_o	 		( inst_plast_o		)	,
`ifdef DIFFTEST
		.diff_skip_flag_i  	( diff_skip_flag   ),
`endif
		.data_prsel_o 		 	( data_prsel_o ),
		.data_praddr_o		 	( data_praddr_o),
		.data_psize_o 		 	( data_psize_o ),
		.data_prlen_o 		 	( data_prlen_o ),
		.data_prlast_o		 	( data_prlast_o),
		.data_prdata_o		 	( data_prdata_o),
		.data_pvalid_o		 	( data_prvalid_o),
		
		.data_pwsel_o 		 	( data_pwsel_o     ),
		.data_pwaddr_o		 	( data_pwaddr_o),
		.data_pwdata_o		 	( data_pwdata_o),
		.data_pwstrb_o		 	( data_pwstrb_o),
		.data_pwtype_o		 	( data_pwtype_o),
		.data_pwrdy_o 		 	( data_pwrdy_o ),

		.inst_i              	( inst		           )
	);


	ysyx_23060025_AXI_CTL#(
		.ADDR_LEN            ( 32 ),
		.DATA_LEN            ( 32 )
	)u_ysyx_23060025_AXI_CTL(
		.reset               ( reset                ),
		.clock               ( clock                 ),
		.inst_paddr_i	 		( inst_paddr_o	  ),
		.inst_psel_i		 	( inst_psel_o		 ),
		.inst_plen_i			( inst_plen_o			),
		.inst_psize_i	 		( inst_psize_o	  ),
		.inst_pvalid_o	 		( inst_pvalid_o		),
		.inst_plast_o	 		( inst_plast_o		)	,
		.inst_prdata_o       ( inst       		   ),
`ifdef DIFFTEST
		.diff_skip_flag_o       ( diff_skip_flag       		   ),
`endif
		.data_prsel_i 		 	( data_prsel_o ),
		.data_praddr_i		 	( data_praddr_o),
		.data_prsize_i		 	( data_psize_o ),
		.data_prlen_i		 	( data_prlen_o     ),
		.data_prlast_o		 	( data_prlast_o),
		.data_prdata_o		 	( data_prdata_o    ),
		.data_prvalid_o		 	( data_prvalid_o),
		
		.data_pwsel_i 		 	( data_pwsel_o ),
		.data_pwaddr_i		 	( data_pwaddr_o),
		.data_pwdata_i		 	( data_pwdata_o),
		.data_pwstrb_i		 	( data_pwstrb_o),
		.data_pwtype_i		 	( data_pwtype_o),
		.data_pwrdy_i 		 	( data_pwrdy_o ),
		.data_pwvalid_i 		( data_pwalid_o ),

		.axi_device		 	 ( axi_device 		   ),
		// Read Addr 
		.axi_addr_r_addr_o  ( xbar_addr_r_addr_o    ),
		.axi_addr_r_valid_o ( xbar_addr_r_valid_o 	),
		.axi_addr_r_ready_i ( xbar_addr_r_ready_i 	),
		.axi_addr_r_len_o   ( xbar_addr_r_len_o    ),
		.axi_addr_r_size_o  ( xbar_addr_r_size_o   ),

		// Read Data
		.axi_r_data_i       ( xbar_r_data_i       ),
		.axi_r_valid_i      ( xbar_r_valid_i      ),
		.axi_r_last_i       ( xbar_r_last_i        ),
		.axi_r_ready_o      ( xbar_r_ready_o      ),

		// Adddr Write
		.axi_addr_w_addr_o  ( xbar_addr_w_addr_o  ),
		.axi_addr_w_valid_o ( xbar_addr_w_valid_o ),
		.axi_addr_w_ready_i ( xbar_addr_w_ready_i ),
		.axi_addr_w_len_o   ( xbar_addr_w_len_o    ),
		.axi_addr_w_size_o  ( xbar_addr_w_size_o   ),

		// Write Data
		.axi_w_data_o       ( xbar_w_data_o       ),
		.axi_w_strb_o       ( xbar_w_strb_o       ),
		.axi_w_valid_o      ( xbar_w_valid_o      ),
		.axi_w_ready_i      ( xbar_w_ready_i      ),
		.axi_w_last_o       ( xbar_w_last_o        ),

		// Write backward
		.axi_bkwd_valid_i   ( xbar_bkwd_valid_i   ),
		.axi_bkwd_ready_o   ( xbar_bkwd_ready_o   )	);

	assign io_master_arid = 0;
	assign io_master_awid = 0;
	assign io_master_awburst = `AXI_ADDR_BURST_INCR;
	assign io_master_arburst = `AXI_ADDR_BURST_INCR;

	ysyx_23060025_xbar#(
		.ADDR_LEN               ( 32 ),
		.DATA_LEN 		        ( 32 )
	)u_ysyx_23060025_xbar(
		.rstn                   ( ~reset                   ),
		.clock                    ( clock                    ),
		.axi_device				( axi_device			 ),
		.axi_ctl_addr_r_addr_i  ( xbar_addr_r_addr_o	),
		.axi_ctl_addr_r_valid_i ( xbar_addr_r_valid_o ),
		.axi_ctl_addr_r_ready_o ( xbar_addr_r_ready_i ),
		.axi_ctl_addr_r_len_i   ( xbar_addr_r_len_o    ),
		.axi_ctl_addr_r_size_i  ( xbar_addr_r_size_o   ),
		
		.axi_ctl_r_data_o       ( xbar_r_data_i       ),
		.axi_ctl_r_valid_o      ( xbar_r_valid_i      ),
		.axi_ctl_r_ready_i      ( xbar_r_ready_o      ),
		.axi_ctl_r_last_o       ( xbar_r_last_i        ),

		.axi_ctl_addr_w_addr_i  ( xbar_addr_w_addr_o  ),
		.axi_ctl_addr_w_valid_i ( xbar_addr_w_valid_o ),
		.axi_ctl_addr_w_ready_o ( xbar_addr_w_ready_i ),
		.axi_ctl_addr_w_len_i   ( xbar_addr_w_len_o    ),
		.axi_ctl_addr_w_size_i  ( xbar_addr_w_size_o   ),

		.axi_ctl_w_data_i       ( xbar_w_data_o       ),
		.axi_ctl_w_strb_i       ( xbar_w_strb_o       ),
		.axi_ctl_w_valid_i      ( xbar_w_valid_o      ),
		.axi_ctl_w_ready_o      ( xbar_w_ready_i      ),
		.axi_ctl_w_last_i       ( xbar_w_last_o        ),

		.axi_ctl_bkwd_valid_o   ( xbar_bkwd_valid_i   ),
		.axi_ctl_bkwd_ready_i   ( xbar_bkwd_ready_o   ),

		// Read Addr
		.axi_addr_r_addr_o  ( io_master_araddr    ),
		.axi_addr_r_valid_o ( io_master_arvalid 	),
		.axi_addr_r_ready_i ( io_master_arready 	),
		.axi_addr_r_len_o   ( io_master_arlen    ),
		.axi_addr_r_size_o  ( io_master_arsize   ),

		// Read Data
		.axi_r_data_i       ( io_master_rdata       ),
		.axi_r_valid_i      ( io_master_rvalid      ),
		.axi_r_last_i       ( io_master_rlast        ),
		.axi_r_ready_o      ( io_master_rready      ),

		// Adddr Write
		.axi_addr_w_addr_o  ( io_master_awaddr  ),
		.axi_addr_w_valid_o ( io_master_awvalid ),
		.axi_addr_w_ready_i ( io_master_awready ),
		.axi_addr_w_len_o   ( io_master_awlen    ),
		.axi_addr_w_size_o  ( io_master_awsize   ),

		// Write Data
		.axi_w_data_o       ( io_master_wdata       ),
		.axi_w_strb_o       ( io_master_wstrb       ),
		.axi_w_valid_o      ( io_master_wvalid      ),
		.axi_w_ready_i      ( io_master_wready      ),
		.axi_w_last_o       ( io_master_wlast        ),

		// Write backward
		.axi_bkwd_valid_i   ( io_master_bvalid   ),
		.axi_bkwd_ready_o   ( io_master_bready   ),

		.clint_addr_r_addr_i    ( clint_addr_r_addr_o    ),
		.clint_addr_r_valid_i   ( clint_addr_r_valid_o   ),
		.clint_addr_r_ready_o   ( clint_addr_r_ready_i   ),
		.clint_r_data_o         ( clint_r_data_i         ),
		.clint_r_valid_o        ( clint_r_valid_i        ),
		.clint_r_last_o        ( clint_r_last_i        ),
		.clint_r_ready_i        ( clint_r_ready_o        )
	);

	ysyx_23060025_CLINT#(
		.ADDR_LEN       ( 32 ),
		.DATA_LEN 	    ( 32 )
	)u_ysyx_23060025_CLINT(
		.rstn           ( ~reset           ),
		.clock          ( clock            ),
		.addr_r_addr_i  ( clint_addr_r_addr_o  ),
		.addr_r_valid_i ( clint_addr_r_valid_o ),
		.addr_r_ready_o ( clint_addr_r_ready_i ),
		.r_data_o       ( clint_r_data_i       ),
		.r_resp_o       ( clint_r_resp_i       ),
		.r_valid_o      ( clint_r_valid_i      ),
		.r_last_o      (  clint_r_last_i      ),
		.r_ready_i      ( clint_r_ready_o      )
	);


	

endmodule
