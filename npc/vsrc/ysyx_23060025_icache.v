/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
 /* verilator lint_off WIDTHEXPAND */
module ysyx_23060025_icache #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32, CACHE_LINE_ADDR_W = 4, CACHE_LINE_OFF_ADDR_W = 5)(
	input         		clock,
	input         		reset,
	// IFU
	input  [31:0] 		in_paddr,	// IFU fetch inst addr
	input         		in_psel,	// IFU sel icache
	output reg        	in_pready,	// icache read data ready
	output reg [31:0] 	in_prdata,	// icache read data

	// icache access DRAM
	output     [31:0]	out_araddr	,
	output reg         	out_arvalid	,
	input           	out_arready	,
	output reg  [7:0]  	out_arlen	,
	output reg  [2:0]   out_arsize	,
	output reg  [1:0]   out_arburst	,
	input        		out_rvalid	,
	input           	out_rlast	,
	input   	[31:0] 	out_rdata	,
	output reg         	out_rready	
);
	localparam	[2:0]	STATE_IDLE = 3'b00, STATE_CHECK = 3'b01, STATE_ADDR_HAND_SHAK = 3'b10, STATE_LOAD = 3'b11, STATE_UPDATE_REG = 3'b101, STATE_PASS = 3'b100;
	parameter	CACHE_LINE_W = (2 ** CACHE_LINE_OFF_ADDR_W)*8;
	parameter	CACHE_LINE_NUM = 2 ** CACHE_LINE_ADDR_W;
	parameter	TAG_W = ADDR_WIDTH-CACHE_LINE_ADDR_W-CACHE_LINE_OFF_ADDR_W;
	parameter	PASS_TIMES = (2 ** CACHE_LINE_OFF_ADDR_W) / 4;
	// parameter	PASS_TIMES_W = $clog2(PASS_TIMES);
	

	reg	[2:0] con_state;
	reg	[2:0] next_state;

	reg	[CACHE_LINE_W-1:0]	cache_reg	[CACHE_LINE_NUM-1:0];
	reg	[TAG_W-1:0]			cache_tag	[CACHE_LINE_NUM-1:0];

	wire [TAG_W-1:0]					addr_tag	= in_paddr[ADDR_WIDTH-1:CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W];
	wire [CACHE_LINE_ADDR_W-1:0]		addr_index	= in_paddr[CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W-1:CACHE_LINE_OFF_ADDR_W];
	wire [CACHE_LINE_OFF_ADDR_W-1:0]	addr_off	= in_paddr[CACHE_LINE_OFF_ADDR_W-1:0];

	wire check_hit 					= (addr_tag == cache_tag[addr_index]);

	wire [CACHE_LINE_W-1:0] cache_line_data	= cache_reg[addr_index] >> ({addr_off, 3'b0});
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
			if (con_state == STATE_CHECK && next_state == STATE_PASS) begin
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
				end
			end
			STATE_CHECK: begin
				if(check_hit) begin
					next_state = STATE_PASS;
				end else begin
					next_state = STATE_ADDR_HAND_SHAK;
				end
			end
			STATE_ADDR_HAND_SHAK: begin
				// hand shake, get data!
				if(out_arready) begin
					next_state = STATE_LOAD;
				end
			end
			STATE_LOAD: begin
				// get data over
				if(out_rvalid && out_rlast) begin
					next_state = STATE_UPDATE_REG;
				// not get enough data and finish this time
				end 
			end
			STATE_UPDATE_REG: begin
				next_state = STATE_PASS;
			end
			STATE_PASS: begin
				next_state = STATE_IDLE;
			end
			default: begin
				
			end
		endcase
	end

	integer i, j;
	always @(posedge clock) begin
		if (reset) begin
			for (i = 0; i < CACHE_LINE_NUM; i = i + 1) begin
				cache_reg[i] <= 0; // 使用非阻塞赋值
			end
		end if(con_state == STATE_LOAD && out_rvalid) begin
			cache_reg[addr_index] <= cache_reg[addr_index] >> 32 | {out_rdata, {(CACHE_LINE_W-32){1'b0}}};
		end
	end

	always @(posedge clock) begin
		if (reset) begin
			for (j = 0; j < CACHE_LINE_NUM; j = j + 1) begin
				cache_tag[j] <= 0; // 使用非阻塞赋值
			end
		end if(next_state == STATE_UPDATE_REG) begin
			cache_tag[addr_index] <= addr_tag;
		end
	end

	// output
	always @(posedge clock) begin
		if (reset) begin
			in_pready	<=		0;
			in_prdata	<=		0;
			// out_araddr	<=		0;
			out_arvalid	<=		0;
			out_rready	<=		0;
			out_arsize	<=		0;
			out_arlen	<=		0;
		end
		case (next_state)
			STATE_IDLE:  begin
				in_pready	<=		0;
				in_prdata	<=		0;
				// out_araddr	<=		0;
				out_arvalid	<=		0;
				out_rready	<=		0;
				out_arsize	<=		0;
				out_arlen	<=		0;
			end
			STATE_PASS:  begin
				in_pready	<=		1'b1;
				in_prdata	<=		prdata;
			end
			STATE_ADDR_HAND_SHAK:  begin
				out_arvalid	<=		1;
				out_arsize	<=		load_rsize;
				out_arlen	<=		load_rlen;
				out_arburst <=		`AXI_ADDR_BURST_INCR;
				out_rready	<=		0;
			end
			STATE_LOAD:  begin
				out_arvalid	<=		0;
				out_rready	<=		1'b1;
			end
			default:  begin
			end
		endcase
	end

	assign out_araddr = load_raddr;

endmodule
/* verilator lint_on WIDTHEXPAND */
