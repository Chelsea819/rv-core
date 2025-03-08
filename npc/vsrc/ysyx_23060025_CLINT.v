/*************************************************************************
	> File Name: ysyx_23060025_counter.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月05日 星期六 22时12分23秒
 ************************************************************************/
// clock reset waddr wdata wen wmask
`include "ysyx_23060025_define.v"
`include "ysyx_23060025_define_delay.v"
module ysyx_23060025_CLINT #(parameter ADDR_LEN = 32, DATA_LEN = 32)(
	input								rstn		,
    input		                		clock			,

	//Addr Read
	input		[ADDR_LEN - 1:0]		addr_r_addr_i,
	input		                		addr_r_valid_i,
	output		                		addr_r_ready_o,

	// Read data
	output	reg	[DATA_LEN - 1:0]		r_data_o	,
	output		[1:0]					r_resp_o	,	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	output		                		r_valid_o	,
	output		                		r_last_o	,
	input		                		r_ready_i	

);	
	// addr 
	parameter 	 WAIT_ADDR = 1'b0, WAIT_DATA_GET = 1'b1;
	reg								        con_state	;
	reg							        	next_state	;
	// wire						        	mem_ren	;
	wire			[DATA_LEN - 1:0]	    r_data  ;
	
	reg 			[63:0] 					mtime;
	wire									bit_sel; // 0 低位； 1 高位
	
	assign addr_r_ready_o = (con_state == WAIT_ADDR) && rstn;

	assign r_resp_o = 2'b0;

	assign bit_sel = addr_r_addr_i[2];
	assign r_data = bit_sel ? mtime[63:DATA_LEN] : mtime[DATA_LEN - 1:0];



	always @(posedge clock ) begin
		if(rstn)
			mtime <= mtime + 64'b1;
		else
			mtime <= 0;
	end

	assign r_valid_o = (con_state == WAIT_DATA_GET);
	assign r_last_o = 1;


	// state trans
	always @(posedge clock ) begin
		if(rstn)
			con_state <= next_state;
		else 
			con_state <= WAIT_ADDR;
	end

	// next_state
	always @(*) begin
		case(con_state) 
			WAIT_ADDR: begin
				if (addr_r_valid_i) begin
					next_state = WAIT_DATA_GET;
				end else begin 
					next_state = WAIT_ADDR;
				end
			end
			WAIT_DATA_GET: begin
				if (r_ready_i) begin
					next_state = WAIT_ADDR;
				end else begin 
					next_state = WAIT_DATA_GET;
				end
			end
		endcase
	end

	always @(posedge clock) begin
		if(~rstn) begin
			r_data_o <= 0;
		end else if(con_state == WAIT_ADDR && next_state == WAIT_DATA_GET) begin
			r_data_o <= r_data;
		end
	end

	
endmodule
