/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
module ysyx_23060025_CSR #(parameter DATA_WIDTH = 32)(
	input								clock		,
	input								reset		,
	input	    [11:0]					csr_raddr,	// 要读的csr
	input	    [11:0]					csr_waddr,	// 要读的csr
	input		[DATA_WIDTH - 1:0]		wdata	,	// 要写入csr的数据	
	input		[2:0]					csr_type_i,
	// input		[DATA_WIDTH - 1:0]		csr_mepc_i	,
	input		[DATA_WIDTH - 1:0]		csr_mcause_i	,
	// output		[DATA_WIDTH - 1:0]		csr_mtvec_pc_o	,
	// output		[DATA_WIDTH - 1:0]		csr_mepc_pc_o	,
	output		[DATA_WIDTH - 1:0]		r_data	
);
	wire csr_wen = ^csr_type_i;
	wire csr_ecall = csr_type_i == `CSR_ECALL;

	assign r_data = csr_raddr_mcause 	 	? mcause_r : 
					csr_raddr_mstatus 	 	? mstatus_r : 
					csr_raddr_mepc 	 		? mepc_r : 
					csr_raddr_mtvec 	 	? mtvec_r : 
					csr_raddr_mvendorid 	? mvendorid_r : 
					csr_raddr_marchid 	 	? marchid_r : 0;

	wire csr_raddr_mcause 		= (csr_raddr == `CSR_MCAUSE_ADDR);
	wire csr_raddr_mstatus 		= (csr_raddr == `CSR_MSTATUS_ADDR);
	wire csr_raddr_mepc 		= (csr_raddr == `CSR_MEPC_ADDR);
	wire csr_raddr_mtvec 		= (csr_raddr == `CSR_MTVEC_ADDR);
	wire csr_raddr_mvendorid 	= (csr_raddr == `CSR_MVENDORID_ADDR);
	wire csr_raddr_marchid 		= (csr_raddr == `CSR_MARCHID_ADDR);

	wire csr_waddr_mcause 		= 	(csr_waddr == `CSR_MCAUSE_ADDR);
	wire csr_waddr_mstatus 		= 	(csr_waddr == `CSR_MSTATUS_ADDR);
	wire csr_waddr_mepc 		= 	(csr_waddr == `CSR_MEPC_ADDR);
	wire csr_waddr_mtvec 		= 	(csr_waddr == `CSR_MTVEC_ADDR);
	wire csr_waddr_mvendorid 	= 	(csr_waddr == `CSR_MVENDORID_ADDR);
	wire csr_waddr_marchid 		= 	(csr_waddr == `CSR_MARCHID_ADDR);

	wire mcause_ena 	 	= (csr_ecall | csr_waddr_mcause) & csr_wen;
	wire mstatus_ena		= csr_waddr_mstatus  	& csr_wen;
	wire mepc_ena			= csr_waddr_mepc 	 	& csr_wen;
	wire mtvec_ena			= csr_waddr_mtvec 	 	& csr_wen;
	wire mvendorid_ena		= csr_waddr_mvendorid 	& csr_wen;
	wire marchid_ena		= csr_waddr_marchid 	& csr_wen;

	wire [31:0] mcause_nxt = csr_ecall ? wdata : csr_mcause_i;
	wire [31:0] mcause_r;

	ysyx_23060025_Reg #(32,0)
	csr_mcause(
		.clk  	( clock   ),
		.rst  	( reset   ),
		.din  	( mcause_nxt   ),
		.dout 	( mcause_r  ),
		.wen  	( mcause_ena   )
	);
	wire [31:0] mstatus_nxt = wdata;
	wire [31:0] mstatus_r;

	ysyx_23060025_Reg #(32,32'h1800)
	csr_mstatus(
		.clk  	( clock   ),
		.rst  	( reset   ),
		.din  	( mstatus_nxt   ),
		.dout 	( mstatus_r  ),
		.wen  	( mstatus_ena   )
	);

	wire [31:0] mepc_nxt = wdata;
	wire [31:0] mepc_r;

	ysyx_23060025_Reg #(32,0)
	csr_mepc(
		.clk  	( clock   ),
		.rst  	( reset   ),
		.din  	( mepc_nxt   ),
		.dout 	( mepc_r  ),
		.wen  	( mepc_ena   )
	);

	wire [31:0] mtvec_nxt = wdata;
	wire [31:0] mtvec_r;
	ysyx_23060025_Reg #(32,0)
	csr_mtvec(
		.clk  	( clock   ),
		.rst  	( reset   ),
		.din  	( mtvec_nxt   ),
		.dout 	( mtvec_r  ),
		.wen  	( mtvec_ena   )
	);
	wire [31:0] mvendorid_nxt = wdata;
	wire [31:0] mvendorid_r;
	ysyx_23060025_Reg #(32,32'h79737978)
	csr_mvendorid(
		.clk  	( clock   ),
		.rst  	( reset   ),
		.din  	( mvendorid_nxt   ),
		.dout 	( mvendorid_r  ),
		.wen  	( mvendorid_ena   )
	);
	wire [31:0] marchid_nxt = wdata;
	wire [31:0] marchid_r;

	ysyx_23060025_Reg #(32,32'd23060025)
	csr_marchid(
		.clk  	( clock   ),
		.rst  	( reset   ),
		.din  	( marchid_nxt   ),
		.dout 	( marchid_r  ),
		.wen  	( marchid_ena   )
	);

	// assign csr_mtvec_pc_o = csr[`CSR_MTVEC_IDX];
	// assign csr_mepc_pc_o = csr[`CSR_MEPC_IDX];
	
	// assign r_data = csr[csr_ridx];

	// always @(*) begin
	// 	$display("MTVEC = [%x] csr_idx = [%b]  wdata = [%b] csr_pc_o = [%x] csr_type_i = [%b]",csr[`CSR_MTVEC_IDX],csr_idx,wdata, csr_pc_o, csr_type_i);
	// end

	// always @(posedge clock) begin
	// 	if(reset) begin
	// 		csr[`CSR_MSTATUS_IDX] <= 32'h1800;
	// 		csr[`CSR_MVENDORID_IDX] <= 32'h79737978;
	// 		csr[`CSR_MARCHID_IDX] <= 32'd23060025;
	// 	end
	// 	else if (^csr_type_i) 
	// 		csr[csr_widx] <= wdata;
	// 	else if(csr_type_i == `CSR_ECALL) begin
	// 		csr[`CSR_MCAUSE_IDX] <= csr_mcause_i;
	// 		// TODO: change it to wdata
	// 		csr[`CSR_MEPC_IDX] <= wdata;
	// 	end
	// end


endmodule
