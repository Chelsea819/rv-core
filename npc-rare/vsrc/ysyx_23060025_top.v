`include "ysyx_23060025_define.v"

module ysyx_23060025_top #(parameter DATA_LEN = 32,ADDR_LEN = 32) (
	input								clock 		,
	input								reset
);
    wire                               io_master_awready;
    wire                               io_master_wready;
    wire                               io_master_bvalid;
    wire        [1:0]                  io_master_bresp;
    wire        [3:0]                  io_master_bid;
    wire                               io_master_arready;
    wire                               io_master_rvalid;
    wire        [1:0]                  io_master_rresp;
    wire        [DATA_LEN-1:0]         io_master_rdata;
    wire                               io_master_rlast;
    wire        [3:0]                  io_master_rid;
    
    
    // output declaration of module ysyx_23060025
    wire                               io_master_awvalid;
    wire        [ADDR_LEN-1:0]         io_master_awaddr;
    wire        [3:0]                  io_master_awid;
    wire        [7:0]                  io_master_awlen;
    wire        [2:0]                  io_master_awsize;
    wire        [1:0]                  io_master_awburst;
    wire                               io_master_wvalid;
    wire        [DATA_LEN-1:0]         io_master_wdata;
    wire        [3:0]                  io_master_wstrb;
    wire                               io_master_wlast;
    wire                               io_master_bready;
    wire                               io_master_arvalid;
    wire        [ADDR_LEN-1:0]         io_master_araddr;
    wire        [3:0]                  io_master_arid;
    wire        [7:0]                  io_master_arlen;
    wire        [2:0]                  io_master_arsize;
    wire        [1:0]                  io_master_arburst;
    wire                               io_master_rready;

    
    ysyx_23060025 #(
        .DATA_LEN 	(32  ),
        .ADDR_LEN 	(32  ))
    u_ysyx_23060025(
        .clock             	(clock              ),
        .reset             	(reset              ),
        .io_interrupt      	(       ),
        .io_master_awready 	(io_master_awready  ),
        .io_master_awvalid 	(io_master_awvalid  ),
        .io_master_awaddr  	(io_master_awaddr   ),
        .io_master_awid    	(io_master_awid     ),
        .io_master_awlen   	(io_master_awlen    ),
        .io_master_awsize  	(io_master_awsize   ),
        .io_master_awburst 	(io_master_awburst  ),
        .io_master_wready  	(io_master_wready   ),
        .io_master_wvalid  	(io_master_wvalid   ),
        .io_master_wdata   	(io_master_wdata    ),
        .io_master_wstrb   	(io_master_wstrb    ),
        .io_master_wlast   	(io_master_wlast    ),
        .io_master_bready  	(io_master_bready   ),
        .io_master_bvalid  	(io_master_bvalid   ),
        .io_master_bresp   	(io_master_bresp    ),
        .io_master_bid     	(io_master_bid      ),
        .io_master_arready 	(io_master_arready  ),
        .io_master_arvalid 	(io_master_arvalid  ),
        .io_master_araddr  	(io_master_araddr   ),
        .io_master_arid    	(io_master_arid     ),
        .io_master_arlen   	(io_master_arlen    ),
        .io_master_arsize  	(io_master_arsize   ),
        .io_master_arburst 	(io_master_arburst  ),
        .io_master_rready  	(io_master_rready   ),
        .io_master_rvalid  	(io_master_rvalid   ),
        .io_master_rresp   	(io_master_rresp    ),
        .io_master_rdata   	(io_master_rdata    ),
        .io_master_rlast   	(io_master_rlast    ),
        .io_master_rid     	(io_master_rid      ),
        .io_slave_awready  	(   ),
        .io_slave_awvalid  	(   ),
        .io_slave_awaddr   	(   ),
        .io_slave_awid     	(   ),
        .io_slave_awlen    	(   ),
        .io_slave_awsize   	(   ),
        .io_slave_awburst  	(   ),
        .io_slave_wready   	(   ),
        .io_slave_wvalid   	(   ),
        .io_slave_wdata    	(   ),
        .io_slave_wstrb    	(   ),
        .io_slave_wlast    	(   ),
        .io_slave_bready   	(   ),
        .io_slave_bvalid   	(   ),
        .io_slave_bresp    	(   ),
        .io_slave_bid      	(   ),
        .io_slave_arready  	(   ),
        .io_slave_arvalid  	(   ),
        .io_slave_araddr   	(   ),
        .io_slave_arid     	(   ),
        .io_slave_arlen    	(   ),
        .io_slave_arsize   	(   ),
        .io_slave_arburst  	(   ),
        .io_slave_rready   	(   ),
        .io_slave_rvalid   	(   ),
        .io_slave_rresp    	(   ),
        .io_slave_rdata    	(   ),
        .io_slave_rlast    	(   ),
        .io_slave_rid      	(   )
    );

	ysyx_23060025_AXI_SRAM#(
		.ADDR_LEN       ( 32 ),
		.DATA_LEN       ( 32 )
	)u_ysyx_23060025_AXI_SRAM(
		.rstn            ( ~reset               ),
		.clk            ( clock                        ),
		.addr_r_addr_i  ( io_master_araddr      ),
		.addr_r_valid_i ( io_master_arvalid     ),
		.addr_r_ready_o ( io_master_arready     ),
		.r_data_o  		( io_master_rdata       ),
		.r_resp_o 		( io_master_rresp       ),
		.r_valid_o      ( io_master_rvalid      ),
		.r_ready_i      ( io_master_rready      ),
		.r_last_o      ( io_master_rlast      ),

		.addr_w_addr_i  ( io_master_awaddr  ),
		.addr_w_valid_i ( io_master_awvalid ),
		.addr_w_ready_o ( io_master_awready ),
		.w_data_i       ( io_master_wdata   ),
		.w_strb_i       ( io_master_wstrb   ),
		.w_valid_i      ( io_master_wvalid  ),
		.w_ready_o      ( io_master_wready  ),
		.bkwd_resp_o    ( io_master_bresp   ),
		.bkwd_valid_o   ( io_master_bvalid  ),
		.bkwd_ready_i   ( io_master_bready  )
	);

endmodule
