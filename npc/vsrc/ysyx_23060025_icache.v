/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
 /* verilator lint_off WIDTHEXPAND */
module ysyx_23060025_icache #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32, CACHE_LINE_ADDR_W = 2, CACHE_WAY_ADDR_W = 1, CACHE_LINE_OFF_ADDR_W = 4)(
	input         		clock,
	input         		reset,
	// IFU
`ifdef PC_NO_2
	input  [29:0] 		in_paddr,	// IFU fetch inst addr
`else
	input  [31:0] 		in_paddr,	// IFU fetch inst addr
`endif 
	input         		in_psel,	// IFU sel icache
	output 	        	in_pready,	// icache read data ready
	output 	 [31:0] 	in_prdata,	// icache read data

	input         		in_fence_flag,	// fence.i update

	// icache access DRAM
	output     [31:0]	out_paddr	,
	output 	         	out_psel	,
	output 	  	[7:0]  	out_arlen	,
	output 	  	[2:0]   out_arsize	,
	input        		out_rvalid	,
	input           	out_rlast	,
	input   	[31:0] 	out_rdata	
);
	localparam	[1:0]	STATE_IDLE = 2'b00, STATE_CHECK = 2'b01, STATE_LOAD = 2'b10, STATE_FENCE = 2'b11;
	parameter	CACHE_LINE_W = (2 ** CACHE_LINE_OFF_ADDR_W)*8;
	parameter	CACHE_LINE_NUM = 2 ** CACHE_LINE_ADDR_W;
	parameter	TAG_W = ADDR_WIDTH-CACHE_LINE_ADDR_W-CACHE_LINE_OFF_ADDR_W;
	parameter	CACHE_VALID_W = 1;
	// parameter	TAG_W = ADDR_WIDTH-CACHE_LINE_ADDR_W-CACHE_LINE_OFF_ADDR_W;
	parameter	PASS_TIMES = (2 ** CACHE_LINE_OFF_ADDR_W) / 4;
	// parameter	PASS_TIMES_W = $clog2(PASS_TIMES);

	// wire state_idle = (con_state == STATE_IDLE);
	wire state_check = (con_state == STATE_CHECK);
	// wire state_load = (con_state == STATE_LOAD);
	// wire state_fence = (con_state == STATE_FENCE);
`ifdef PC_NO_2
	wire [29:0]  raddr     = in_paddr;
`else
	wire [31:0]  raddr     = in_paddr;
`endif 

	reg random_data;
	always @(posedge clock) begin
		if(reset) begin
			random_data <= 0;
		end else if(con_state != STATE_LOAD) begin
			random_data <= random_data ^ 1;
		end
	end

	reg	[1:0] con_state;
	reg	[1:0] next_state;

	reg	[CACHE_LINE_W-1:0]	cache_reg_way_0	[CACHE_LINE_NUM-1:0];
	reg	[CACHE_LINE_W-1:0]	cache_reg_way_1	[CACHE_LINE_NUM-1:0];

	reg	[TAG_W+CACHE_VALID_W-1:0]			cache_tag_way_0	[CACHE_LINE_NUM+CACHE_VALID_W-1:0];
	reg	[TAG_W+CACHE_VALID_W-1:0]			cache_tag_way_1	[CACHE_LINE_NUM+CACHE_VALID_W-1:0];

`ifdef PC_NO_2
	wire [TAG_W-1:0]					addr_tag	= raddr[ADDR_WIDTH-1-2:CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W-2];
	wire [CACHE_LINE_ADDR_W-1:0]		addr_index	= raddr[CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W-1-2:CACHE_LINE_OFF_ADDR_W-2];
	wire [CACHE_LINE_OFF_ADDR_W-1-2:0]	addr_off	= raddr[CACHE_LINE_OFF_ADDR_W-1-2:0];
`else
	wire [TAG_W-1:0]					addr_tag	= raddr[ADDR_WIDTH-1:CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W];
	wire [CACHE_LINE_ADDR_W-1:0]		addr_index	= raddr[CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W-1:CACHE_LINE_OFF_ADDR_W];
	wire [CACHE_LINE_OFF_ADDR_W-1:0]	addr_off	= raddr[CACHE_LINE_OFF_ADDR_W-1:0];
`endif 

	wire check_hit_0 					= (addr_tag == cache_tag_way_0[addr_index][TAG_W-1:0] && cache_tag_way_0[addr_index][TAG_W+CACHE_VALID_W-1] == 1);
	wire check_hit_1 					= (addr_tag == cache_tag_way_1[addr_index][TAG_W-1:0] && cache_tag_way_1[addr_index][TAG_W+CACHE_VALID_W-1] == 1);
	wire check_hit = check_hit_0 | check_hit_1;
`ifdef PC_NO_2
	wire [CACHE_LINE_W-1:0] cache_line_data	= check_hit_0 ? cache_reg_way_0[addr_index] >> ({addr_off, 2'b0, 3'b0}) : cache_reg_way_1[addr_index] >> ({addr_off, 2'b0, 3'b0});
`else
	wire [CACHE_LINE_W-1:0] cache_line_data	= check_hit_0 ? cache_reg_way_0[addr_index] >> ({addr_off, 3'b0}) : cache_reg_way_1[addr_index] >> ({addr_off, 3'b0});
`endif 
	wire [DATA_WIDTH-1:0] 	prdata			= cache_line_data[DATA_WIDTH-1:0];

	wire [ADDR_WIDTH-1:0] 	load_raddr = {addr_tag, addr_index, {(ADDR_WIDTH-TAG_W-CACHE_LINE_ADDR_W){1'b0}}};
	wire [2:0] 			  	load_rsize = `AXI_ADDR_SIZE_4;
	wire [7:0] 				load_rlen  = PASS_TIMES - 1;

	`ifdef N_YOSYS_STA_CHECK
		// hit_percent: total_load, hit_load, miss_load
		// access_time: 
		import "DPI-C" function void cache_cycle_statistic(byte state);
		always @(posedge clock) begin
			if (next_state != STATE_IDLE) begin
				cache_cycle_statistic({5'b0, next_state});
			end
		end

		import "DPI-C" function void cache_hit_statistic();
		always @(posedge clock) begin
			if (state_check && check_hit) begin
				cache_hit_statistic();
			end
		end

	`endif

	always @(posedge clock) begin
		if (reset) begin
			con_state <= 0;
		end else begin
			con_state <= next_state;
		end
	end

	always @(*) begin
		next_state = con_state;
		case (con_state)
			STATE_IDLE: begin
				if(in_psel) begin
					next_state = STATE_CHECK;
				end else if(in_fence_flag) begin
					next_state = STATE_FENCE;
				end
			end
			STATE_CHECK: begin
				if(check_hit) begin
					next_state = STATE_IDLE;
				end else begin
					next_state = STATE_LOAD;
				end
			end
			STATE_LOAD: begin
				// get data over
				if(out_rvalid && out_rlast) begin
					next_state = STATE_IDLE;
				// not get enough data and finish this time
				end 
			end
			STATE_FENCE: begin
				next_state = STATE_IDLE;
			end
		endcase
	end

	integer j;
	always @(posedge clock) begin
		if(out_rvalid) begin
			if(~random_data) begin
				cache_reg_way_0[addr_index] <= cache_reg_way_0[addr_index] >> 32 | {out_rdata, {(CACHE_LINE_W-32){1'b0}}};
			end else begin
				cache_reg_way_1[addr_index] <= cache_reg_way_1[addr_index] >> 32 | {out_rdata, {(CACHE_LINE_W-32){1'b0}}};
			end
		end
	end

	always @(posedge clock) begin
		// valid--1
		if(out_rvalid & out_rlast) begin
			if(~random_data) begin
				cache_tag_way_0[addr_index] <= {1'b1, addr_tag};
			end else begin
				cache_tag_way_1[addr_index] <= {1'b1, addr_tag};
			end
			
		end else if(next_state == STATE_FENCE) begin
			for (j = 0; j < CACHE_LINE_NUM; j = j + 1) begin
				cache_tag_way_0[j][TAG_W+CACHE_VALID_W-1] <= 0; // 使用非阻塞赋值
				cache_tag_way_1[j][TAG_W+CACHE_VALID_W-1] <= 0; // 使用非阻塞赋值
			end
		end
	end

	reg r_last_valid;
	always @(posedge clock) begin
		if(reset) begin
			r_last_valid <= 0;
		end else begin
			r_last_valid <= out_rvalid & out_rlast;
		end
	end

	reg psel;
	always @(posedge clock) begin
		if(reset | next_state == STATE_IDLE) begin
			psel <= 0;
		end else if(next_state == STATE_LOAD) begin
			psel <= 1;
		end
	end


	assign out_arsize = load_rsize;
	assign out_arlen = load_rlen;
	assign out_psel = psel;
	assign out_paddr = load_raddr;

	assign in_pready = r_last_valid | (state_check & check_hit);
	assign in_prdata = prdata;
	

endmodule
/* verilator lint_on WIDTHEXPAND */
