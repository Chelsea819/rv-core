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
	reg 	[DATA_WIDTH - 1:0] 		csr [5:0]	;
	wire 	[2:0]  					csr_ridx		;
	wire 	[2:0]  					csr_widx		;

	assign csr_ridx = (csr_raddr == `CSR_MCAUSE_ADDR)	? `CSR_MCAUSE_IDX :
					 (csr_raddr == `CSR_MSTATUS_ADDR)? `CSR_MSTATUS_IDX :
					 (csr_raddr == `CSR_MEPC_ADDR)	? `CSR_MEPC_IDX :
					 (csr_raddr == `CSR_MTVEC_ADDR)	? `CSR_MTVEC_IDX :
					 (csr_raddr == `CSR_MVENDORID_ADDR)	? `CSR_MVENDORID_IDX :
					 (csr_raddr == `CSR_MARCHID_ADDR)	? `CSR_MARCHID_IDX :
					 `CSR_MTVEC_IDX ;
	assign csr_widx = (csr_waddr == `CSR_MCAUSE_ADDR)	? `CSR_MCAUSE_IDX :
					 (csr_waddr == `CSR_MSTATUS_ADDR)? `CSR_MSTATUS_IDX :
					 (csr_waddr == `CSR_MEPC_ADDR)	? `CSR_MEPC_IDX :
					 (csr_waddr == `CSR_MTVEC_ADDR)	? `CSR_MTVEC_IDX :
					 (csr_waddr == `CSR_MVENDORID_ADDR)	? `CSR_MVENDORID_IDX :
					 (csr_waddr == `CSR_MARCHID_ADDR)	? `CSR_MARCHID_IDX :
					 `CSR_MTVEC_IDX ;

	// assign csr_mtvec_pc_o = csr[`CSR_MTVEC_IDX];
	// assign csr_mepc_pc_o = csr[`CSR_MEPC_IDX];
	
	assign r_data = csr[csr_ridx];

	// always @(*) begin
	// 	$display("MTVEC = [%x] csr_idx = [%b]  wdata = [%b] csr_pc_o = [%x] csr_type_i = [%b]",csr[`CSR_MTVEC_IDX],csr_idx,wdata, csr_pc_o, csr_type_i);
	// end

	always @(posedge clock) begin
		if(reset) begin
			csr[`CSR_MSTATUS_IDX] <= 32'h1800;
			csr[`CSR_MVENDORID_IDX] <= 32'h79737978;
			csr[`CSR_MARCHID_IDX] <= 32'd23060025;
		end
		else if (^csr_type_i == 1'b1) 
			csr[csr_widx] <= wdata;
		else if(csr_type_i == `CSR_ECALL) begin
			csr[`CSR_MCAUSE_IDX] <= csr_mcause_i;
			// TODO: change it to wdata
			csr[`CSR_MEPC_IDX] <= wdata;
		end
	end


endmodule
