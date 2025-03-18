/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/
`include "ysyx_23060025_define.v"
 /* verilator lint_off WIDTHEXPAND */
module ysyx_23060025_dcache #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32, CACHE_LINE_ADDR_W = `MACRO_CACHE_LINE_ADDR_W, 
									CACHE_WAY_ADDR_W = `MACRO_CACHE_WAY_ADDR_W, CACHE_LINE_OFF_ADDR_W = `MACRO_CACHE_LINE_OFF_ADDR_W)(
	input         		clock,
	input         		reset,
	// IFU
	input  [31:0] 		in_paddr,	// IFU fetch inst addr
	input  [31:0] 		in_pwdata,	// IFU fetch inst
	input  [3:0] 		in_pwstrb,	// IFU fetch inst addr
	input  [2:0] 		in_psize,	// IFU fetch inst addr
	input         		in_pwrite,	// IFU sel icache
	input         		in_psel,	// IFU sel icache
	output 	        	in_pready,	// icache read data ready
	output 	 [31:0] 	in_prdata,	// icache read data

	input         		in_fence_flag,	// fence.i update

	// icache access DRAM
	// dcache to write_buffer
	output		                		out_pwr_req	,
	output		[ADDR_WIDTH - 1:0]		out_pwaddr	,
	output		[CACHE_LINE_W-1:0]		out_pwdata	,	// 写出的数据
	output		[3:0]					out_pwstrb	,	// 仅当不是写一个cacheline时 有效
	output		[2:0]					out_pwtype	,	// 3'b000--byte, 3'b001--half word, 3'b010--word, 3'b100--cacheline
	input								out_pwrdy	,	// write_buffer empty

	// dcache to arbiter
	output		[ADDR_WIDTH - 1:0]		out_praddr	,
	output		                		out_prd_req	,
	output 	  	[2:0]   				out_prsize	,
	output 	  	[7:0]  					out_prlen	,
	input           					out_prlast	,
	input   	[31:0] 					out_prdata	,
	input        						out_pvalid	
);
	localparam	[2:0]	STATE_IDLE = 3'b000, STATE_CHECK = 3'b001, STATE_MISS = 3'b101, STATE_REPLACE = 3'b010, STATE_LOAD = 3'b011, STATE_FENCE = 3'b100;
	localparam			WRITE_STATE_IDLE = 1'b0, WRITE_STATE_WRITE = 1'b1;
	parameter	CACHE_LINE_W = (2 ** CACHE_LINE_OFF_ADDR_W)*8;
	parameter	CACHE_LINE_NUM = 2 ** CACHE_LINE_ADDR_W;
	parameter	TAG_W = ADDR_WIDTH-CACHE_LINE_ADDR_W-CACHE_LINE_OFF_ADDR_W;
	localparam	CACHE_VALID_W = 1, CACHE_DIRTY_W = 1;
	parameter	PASS_TIMES = (2 ** CACHE_LINE_OFF_ADDR_W) / 4;

	wire state_check = (con_state == STATE_CHECK);

	// uncache condition
	wire addr_uart 	= (in_paddr >= `DEVICE_UART16550_ADDR_L && in_paddr <= `DEVICE_UART16550_ADDR_H);
	wire addr_spi 	= (in_paddr >= `DEVICE_SPI_ADDR_L && in_paddr <= `DEVICE_SPI_ADDR_H);
	wire addr_gpio 	= (in_paddr >= `DEVICE_GPIO_ADDR_L && in_paddr <= `DEVICE_GPIO_ADDR_H);
	wire addr_clint = (in_paddr >= `DEVICE_CLINT_ADDR_L && in_paddr <= `DEVICE_CLINT_ADDR_H);
	wire uncache_sign = addr_uart | addr_spi | addr_gpio | addr_clint;
	wire uncache_r = uncache_sign & ~in_pwrite;
	wire uncache_w = uncache_sign & in_pwrite;

	wire [31:0]  raddr     = in_paddr;

	// random arithematic
	reg random_data;
	always @(posedge clock) begin
		if(reset) begin
			random_data <= 0;
		end else begin
			random_data <= random_data ^ 1;
		end
	end

	// store the way_addr to be replaced
	reg replace_way_addr;
	always @(posedge clock) begin
		if(next_state == STATE_MISS) begin
			replace_way_addr <= random_data;
		end
	end

	reg			w_buffer_con_state;
	reg			w_buffer_next_state;

	reg	[2:0] con_state;
	reg	[2:0] next_state;

	reg	[CACHE_LINE_W-1:0]	cache_reg_way_0	[CACHE_LINE_NUM-1:0];
	reg	[CACHE_LINE_W-1:0]	cache_reg_way_1	[CACHE_LINE_NUM-1:0];

	reg	[TAG_W+CACHE_VALID_W+CACHE_DIRTY_W-1:0]			cache_tag_way_0	[CACHE_LINE_NUM+CACHE_VALID_W-1:0];
	reg	[TAG_W+CACHE_VALID_W+CACHE_DIRTY_W-1:0]			cache_tag_way_1	[CACHE_LINE_NUM+CACHE_VALID_W-1:0];

	wire [TAG_W-1:0]					addr_tag	= raddr[ADDR_WIDTH-1:CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W];
	wire [CACHE_LINE_ADDR_W-1:0]		addr_index	= raddr[CACHE_LINE_OFF_ADDR_W+CACHE_LINE_ADDR_W-1:CACHE_LINE_OFF_ADDR_W];
	wire [CACHE_LINE_OFF_ADDR_W-1:0]	addr_off	= raddr[CACHE_LINE_OFF_ADDR_W-1:0];

	wire [CACHE_WAY_ADDR_W-1:0]			addr_way	= check_hit_0 ? 0 : 1;

	wire check_hit_0 					= (addr_tag == cache_tag_way_0[addr_index][TAG_W-1:0] && cache_tag_way_0[addr_index][TAG_W+CACHE_VALID_W-1] == 1);
	wire check_hit_1 					= (addr_tag == cache_tag_way_1[addr_index][TAG_W-1:0] && cache_tag_way_1[addr_index][TAG_W+CACHE_VALID_W-1] == 1);
	wire check_hit = check_hit_0 | check_hit_1;
	wire hit_write = check_hit & in_pwrite;
	// wire hit_dirty = check_hit & (cache_tag_way_0[addr_index][CACHE_LINE_NUM+CACHE_VALID_W-1] | cache_tag_way_1[addr_index][CACHE_LINE_NUM+CACHE_VALID_W-1]);
	wire wr_back   = replace_way_addr ? cache_tag_way_1[addr_index][TAG_W+CACHE_VALID_W+CACHE_DIRTY_W-1] : cache_tag_way_0[addr_index][TAG_W+CACHE_VALID_W+CACHE_DIRTY_W-1];

	wire [CACHE_LINE_W-1:0] cache_line_data	= check_hit_0 ? cache_reg_way_0[addr_index] >> ({addr_off, 3'b0}) : cache_reg_way_1[addr_index] >> ({addr_off, 3'b0});
	wire [DATA_WIDTH-1:0] 	prdata			= cache_line_data[DATA_WIDTH-1:0];

	wire [ADDR_WIDTH-1:0] 	load_raddr = {addr_tag, addr_index, {(ADDR_WIDTH-TAG_W-CACHE_LINE_ADDR_W){1'b0}}};

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
			w_buffer_con_state <= 0;
		end else begin
			con_state <= next_state;
			w_buffer_con_state <= w_buffer_next_state;
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
				if(uncache_sign) begin
					next_state = STATE_MISS;
				end else if(check_hit) begin
					next_state = STATE_IDLE;
				end else begin
					next_state = STATE_MISS;
				end
			end
			// get the way-addr we use immediateliy
			// if need write back(dirty), turn to STATE_REPLACE
			// if not need wirte back, turn to STATE_LOAD
			STATE_MISS: begin
				if(out_pwrdy) begin
					if(uncache_r) begin
						next_state = STATE_LOAD;
					end else if(wr_back | uncache_w) begin
						next_state = STATE_REPLACE;
					end else begin
						next_state = STATE_LOAD;
					end
					
				end
			end
			// 发出读请求，并且将要写回的数据写回
			STATE_REPLACE: begin
				if(uncache_w) begin
					next_state = STATE_IDLE;
				end else begin
					next_state = STATE_LOAD;
				end
			end
			// 等待数据读取, STATE LOAD -- STATE IDLE 变化时，
			// 对cachereg进行更新，如果是uncache的情况，则不写入cachereg
			STATE_LOAD: begin
				// get data over
				if(out_pvalid && out_prlast) begin
					next_state = STATE_IDLE;
				// not get enough data and finish this time
				end 
			end
			STATE_FENCE: begin
				next_state = STATE_IDLE;
			end
			default: begin

			end
		endcase
	end

	// hit_write: lsu has store inst and hit cache, need to write cache
	always @(*) begin
		w_buffer_next_state = w_buffer_con_state;
		case (w_buffer_con_state)
			WRITE_STATE_IDLE: begin
				if(state_check & hit_write) begin
					w_buffer_next_state = WRITE_STATE_WRITE;
				end
			end
			WRITE_STATE_WRITE: begin
				if(state_check & hit_write) begin
					w_buffer_next_state = WRITE_STATE_WRITE;
				end else begin
					w_buffer_next_state = WRITE_STATE_IDLE;
				end
			end
		endcase
	end
	wire [31:0] mask = {{8{in_pwstrb[3]}}, {8{in_pwstrb[2]}}, {8{in_pwstrb[1]}}, {8{in_pwstrb[0]}}};
	wire [31:0] pwdata = prdata & ~mask | in_pwdata & mask;

	// store wdata, replace_way_addr, addr_index, addr_off
	reg [DATA_WIDTH+CACHE_WAY_ADDR_W+CACHE_LINE_ADDR_W+CACHE_LINE_OFF_ADDR_W-3:0] write_buffer;
	always @(posedge clock) begin
		if(state_check & hit_write) begin
			write_buffer <= {pwdata, addr_way, addr_index, addr_off[CACHE_LINE_OFF_ADDR_W-1:2]};
		end
	end

	wire	[DATA_WIDTH-1:0] 			write_buffer_wdata;
	wire	[CACHE_WAY_ADDR_W-1:0] 		write_buffer_away;
	wire 	[CACHE_LINE_ADDR_W-1:0]		write_buffer_aindex;
	wire 	[CACHE_LINE_OFF_ADDR_W-3:0]	write_buffer_aoff;

	assign {write_buffer_wdata, write_buffer_away, 
			write_buffer_aindex, write_buffer_aoff} = write_buffer;

	// 计算要写入的 32 位块在 cache line 中的偏移量
	// CACHE_LINE_OFF_ADDR_W=4 时，write_buffer_aoff[3:2] 表示 4 字节对齐的块索引 (0~3)
	wire [CACHE_LINE_W-1:0] cache_dmask = ({{(CACHE_LINE_W-32){1'b0}}, {32{1'b1}}}) << {write_buffer_aoff, 5'b0};
	// 生成写掩码：目标 32 位块全 0，其他位全 1
	wire [CACHE_LINE_W-1:0] cache_wmask = ~cache_dmask;
	wire [CACHE_LINE_W-1:0] cache_wdata_1 = cache_wmask & cache_reg_way_1[addr_index] | {PASS_TIMES{write_buffer_wdata}} & cache_dmask;
	wire [CACHE_LINE_W-1:0] cache_wdata_0 = cache_wmask & cache_reg_way_0[addr_index] | {PASS_TIMES{write_buffer_wdata}} & cache_dmask;

	
	always @(posedge clock) begin
		if(out_pvalid & out_prlast & ~uncache_r) begin
			if(~replace_way_addr) begin
				cache_reg_way_0[addr_index] <= cache_update_data;
			end else begin
				cache_reg_way_1[addr_index] <= cache_update_data;
			end
		end else if(w_buffer_con_state == WRITE_STATE_WRITE) begin
			if(write_buffer_away) begin
				cache_reg_way_1[write_buffer_aindex] <= cache_wdata_1;
			end else begin
				cache_reg_way_0[write_buffer_aindex] <= cache_wdata_0;
			end
		end
	end

	wire [CACHE_LINE_W-1:0] cache_rdata = r_data[addr_index] >> 32 | {out_prdata, {(CACHE_LINE_W-32){1'b0}}};
	// 实际要写入cache的值，如果lsu read-> 直接写入从存储器中读出的值即可
	// 						lsu write-> 要写入的值覆盖存储器的值
	wire [CACHE_LINE_W-1:0] cache_rdata_after_w = ~cache_rdata_dmask & cache_rdata | {PASS_TIMES{pwdata}} & cache_rdata_dmask;
	wire [CACHE_LINE_W-1:0] cache_rdata_dmask = ({{(CACHE_LINE_W-32){1'b0}}, {32{1'b1}}}) << {addr_off[CACHE_LINE_OFF_ADDR_W-1:2], 5'b0};
	wire [CACHE_LINE_W-1:0] cache_update_data = in_pwrite ? cache_rdata_after_w : cache_rdata;
	reg [CACHE_LINE_W-1:0] r_data;
	always @(posedge clock) begin
		if(out_pvalid) begin
			r_data <= r_data >> 32 | {out_prdata, {(CACHE_LINE_W-32){1'b0}}};
		end
	end


	integer j;
	always @(posedge clock) begin
		// valid--1
		if(out_pvalid & out_prlast & ~uncache_r) begin
			if(~replace_way_addr) begin
				cache_tag_way_0[addr_index] <= {1'b0, 1'b1, addr_tag};
			end else begin
				cache_tag_way_1[addr_index] <= {1'b0, 1'b1, addr_tag};
			end
			
		end else if(next_state == STATE_FENCE) begin
			for (j = 0; j < CACHE_LINE_NUM; j = j + 1) begin
				cache_tag_way_0[j][TAG_W+CACHE_VALID_W-1] <= 0; // 使用非阻塞赋值
				cache_tag_way_1[j][TAG_W+CACHE_VALID_W-1] <= 0; // 使用非阻塞赋值
			end
		// hit_write
		end else if(w_buffer_con_state == WRITE_STATE_WRITE) begin
			if(write_buffer_away) begin
				cache_tag_way_1[j][TAG_W+CACHE_VALID_W+CACHE_DIRTY_W-1] <= 1'b1;
			end else begin
				cache_tag_way_0[j][TAG_W+CACHE_VALID_W+CACHE_DIRTY_W-1] <= 1'b1;
			end
		end
	end

	reg r_last_valid;
	// for uncache 
	reg [31:0] prdata_reg;
	always @(posedge clock) begin
		if(reset) begin
			r_last_valid <= 0;
		end else begin
			r_last_valid <= out_pvalid & out_prlast;
			// for uncache 
			prdata_reg	 <= in_prdata;
		end
	end

	assign out_prsize = uncache_r ? in_psize : `AXI_ADDR_SIZE_4;
	assign out_prlen  = uncache_r ? 0 : PASS_TIMES - 1;
	assign out_prd_req = (con_state == STATE_LOAD);
	assign out_praddr = uncache_r ? in_paddr : load_raddr;

	wire [TAG_W-1:0] replace_tag = replace_way_addr ? cache_tag_way_1[addr_index][TAG_W-1:0] : cache_tag_way_0[addr_index][TAG_W-1:0];
	assign out_pwr_req = (con_state == STATE_REPLACE);
	assign out_pwdata = uncache_w ? in_pwdata : 
						replace_way_addr ? cache_reg_way_1[addr_index] : cache_reg_way_0[addr_index];
	assign out_pwaddr = uncache_w ? in_paddr : {replace_tag, addr_index, {(ADDR_WIDTH-TAG_W-CACHE_LINE_ADDR_W){1'b0}}};
	assign out_pwstrb = uncache_w ? in_pwstrb : `AXI_W_STRB_32;
	assign out_pwtype = uncache_w ? in_psize : 3'b100 ;

	assign in_pready = r_last_valid | (state_check & check_hit);
	assign in_prdata = uncache_sign ? prdata_reg : prdata;
	

endmodule
/* verilator lint_on WIDTHEXPAND */
