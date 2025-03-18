/*************************************************************************
	> File Name: ysyx_23060025_counter.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月05日 星期六 22时12分23秒
 ************************************************************************/
// clock reset waddr wdata wen wmask
/* 当多个master同时访问同一个slave时, 获得访问权的master将得到放行, 可以成功访问slave; 
 其他master的请求将阻塞在仲裁器, 等待获得访问权的master访问结束后, 它们才能获得接下来的访问权. */
`include "ysyx_23060025_define.v"
module ysyx_23060025_AXI_CTL #(parameter ADDR_LEN = 32, DATA_LEN = 32)(
	input								reset		,
    input		                		clock		,
`ifdef DIFFTEST
	output	reg							diff_skip_flag_o,
`endif
	// IFU--inst-AXI
	// Addr Read
	input		[ADDR_LEN - 1:0]		inst_paddr_i,
	input		                		inst_psel_i,
	input		[7:0]  					inst_plen_i	,
	input		[2:0]  					inst_psize_i	,

	// Read data
	output		[DATA_LEN - 1:0]		inst_prdata_o	,
	output		                		inst_pvalid_o	,
	output		       					inst_plast_o	,

	// lsu module
	// read
	input		[ADDR_LEN - 1:0]		data_praddr_i ,
	input		                		data_prsel_i  ,
	output		                		data_prlast_o  ,
	output		[DATA_LEN - 1:0]		data_prdata_o ,
	input		[2:0]                	data_prsize_i ,
	input		[7:0]  					data_prlen_i	,
	output		                		data_pvalid_o ,
	// write
	input		                				data_pwsel_i  ,
	input		[ADDR_LEN - 1:0]				data_pwaddr_i ,
	input		[`MACRO_CACHE_LINE_W-1:0]		data_pwdata_i ,
	input		[3:0]							data_pwstrb_i ,
	input		[2:0]							data_pwtype_i ,
	output		                				data_pwrdy_i  ,

    // Xbar
	output	reg 						axi_device,
    // Addr Read
	output	reg	[ADDR_LEN - 1:0]		axi_addr_r_addr_o,
	output		                		axi_addr_r_valid_o,
	input		                		axi_addr_r_ready_i,
	output		[7:0]                	axi_addr_r_len_o,	// 突发长度 用于一个burst中有多少个beat
	output		[2:0]                	axi_addr_r_size_o,	// 突发长度 设置1个beat的宽度，不可超过数据总线的宽度

	// Read data
	input		[DATA_LEN - 1:0]		axi_r_data_i	,
	input		                		axi_r_valid_i	,
	input		                		axi_r_last_i	,
	output		                		axi_r_ready_o	,	// 最后一次读取到的数据

	// Addr Write
	output	reg	[ADDR_LEN - 1:0]		axi_addr_w_addr_o,	// 写地址
	output		                		axi_addr_w_valid_o,	// 主设备给出的地址和相关控制信号有效
	input		                		axi_addr_w_ready_i, // 从设备已准备好接收地址和相关的控制信号
	output		[7:0]                	axi_addr_w_len_o,	// 突发长度，这个字段标识每次突发传输的传输次数
	output		[2:0]                	axi_addr_w_size_o,	// 突发大小，这个字段表示每次突发传输的大小

	// Write data
	output	reg	[DATA_LEN - 1:0]		axi_w_data_o	,	// 写出的数据
	output	reg	[3:0]					axi_w_strb_o	,	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	output		                		axi_w_valid_o	,	// 主设备给出的数据和字节选通信号有效
	input		                		axi_w_ready_i	,	// 从设备已准备好接收数据选通信号
	output		                		axi_w_last_o	,	// 该信号用于标识当前传输是否为突发传输中的最后一次传输

	// Backward
	input		                		axi_bkwd_valid_i,	// 从设备给出的写回复信号是否有效
	output		                		axi_bkwd_ready_o	// 主设备已准备好接收写回复信号
);	
	parameter [1:0] STATE_IDLE = 2'b00, AXI_CTL_BUSY_DATA = 2'b01, AXI_CTL_BUSY_INST = 2'b10;

	reg sub_state_is_data;
	reg sub_next_state;
	always @(posedge clock) begin
		if(reset) begin
			sub_state_is_data <= 0;
		end else begin
			sub_state_is_data <= sub_next_state;
		end
	end

	assign sub_next_state = (con_state == STATE_IDLE) ? 0 :
							(con_state == AXI_CTL_BUSY_DATA) ? axi_addr_r_ready_i & data_prsel_i | sub_state_is_data:
							(con_state == AXI_CTL_BUSY_INST) ? axi_addr_r_ready_i & inst_psel_i  | sub_state_is_data: 
							0;

	reg				[1:0]			        con_state	;
	reg				[1:0]		        	next_state	;

	
`ifdef N_YOSYS_STA_CHECK
	// 访问部分设备时。跳过ref的difftest检查
	// 设备：UART
`ifdef DIFFTEST
	always @(posedge clock) begin
		if(reset) begin
			diff_skip_flag_o <= 0;
		end
		else if (raddr_valid & ((data_praddr_i & 32'hffff_f000) == `DEVICE_UART16550_ADDR_L 
			||(data_praddr_i >= `DEVICE_GPIO_ADDR_L && data_praddr_i <= `DEVICE_GPIO_ADDR_H)
			||(data_praddr_i >= `DEVICE_CLINT_ADDR_L && data_praddr_i <= `DEVICE_CLINT_ADDR_H))) begin
				diff_skip_flag_o <= 1;
			end else if (waddr_valid & ((data_praddr_i & 32'hffff_f000) == `DEVICE_UART16550_ADDR_L || 
			(data_praddr_i >= `DEVICE_GPIO_ADDR_L && data_praddr_i <= `DEVICE_GPIO_ADDR_H))) begin
				diff_skip_flag_o <= 1;
			end else begin if(next_state == STATE_IDLE)
				diff_skip_flag_o <= 0;
			end
	end
`endif
`endif

	wire addr_clint = (data_praddr_i & 32'hffff_0000) == `DEVICE_CLINT_ADDR_L;

	always @(posedge clock) begin
		if (next_state == AXI_CTL_BUSY_DATA) begin
			if (addr_clint) begin
				axi_device <= `AXI_XBAR_CLINT;
			end else begin
				axi_device <= `AXI_XBAR_SOC;
			end
		end else if(next_state == STATE_IDLE) begin
			axi_device <= `AXI_XBAR_SOC;
		end
	end

	// state trans
	always @(posedge clock ) begin
		if(reset)
			con_state <= STATE_IDLE;
		else 
			con_state <= next_state;
	end

	// next_state
	always @(*) begin
		case(con_state) 
			STATE_IDLE: begin
				if(data_prsel_i) begin 
					next_state = AXI_CTL_BUSY_DATA;
				end else if(inst_psel_i) begin
					next_state = AXI_CTL_BUSY_INST;
				end else begin 
					next_state = STATE_IDLE;
				end
			end
			AXI_CTL_BUSY_DATA: begin
				// finish write
				if (axi_bkwd_valid_i) begin
					next_state = STATE_IDLE;			
				// finish read
				end else if (axi_r_valid_i & axi_r_last_i) begin 
					next_state = STATE_IDLE;
				end else begin 
					next_state = AXI_CTL_BUSY_DATA;
				end
			end
			AXI_CTL_BUSY_INST: begin				
				// finish inst read
				if (axi_r_valid_i  & axi_r_last_i) begin 
					next_state = STATE_IDLE;
				end else begin 
					next_state = AXI_CTL_BUSY_INST;
				end
			end
			default:
				next_state = 2'b11;
		endcase
	end

	wire state_busy_data = (con_state == AXI_CTL_BUSY_DATA);
	wire state_busy_inst = (con_state == AXI_CTL_BUSY_INST);

	// NEXT: AXI-CTL-IDLE
	// finish data read or write
	assign {data_pvalid_o, data_prlast_o}
			= state_busy_data ? {axi_r_valid_i, axi_r_last_i} : 0;

	// finish inst read
	assign {inst_pvalid_o, inst_plast_o} 
			= state_busy_inst ? {axi_r_valid_i, axi_r_last_i} : 
																				0;
	// finish data read or write OR finish inst read

	assign axi_r_ready_o = state_busy_data | state_busy_inst;
	
	// NEXT: SRAM AXI_CTL_BUSY_DATA or AXI_CTL_BUSY_INST
	assign {axi_addr_r_valid_o, axi_addr_r_size_o, axi_addr_r_len_o} 
			= state_busy_data ? { raddr_valid, data_prsize_i, data_prlen_i} : 
				state_busy_inst ? {~sub_state_is_data & inst_psel_i, inst_psize_i, inst_plen_i} : 
													0;
	wire raddr_valid = ~sub_state_is_data & ~data_pwsel_i & data_prsel_i;
	wire waddr_valid = ~sub_state_is_data & data_pwsel_i;

	assign axi_addr_r_addr_o = state_busy_data ? data_praddr_i : inst_paddr_i;
	assign data_prdata_o = axi_r_data_i;
	assign inst_prdata_o = axi_r_data_i;

	// outports wire
	ysyx_23060025_write_buffer 
	u_ysyx_23060025_write_buffer(
		.clock              	( clock               ),
		.reset              	( reset               ),
		.in_pwr_req         	( data_pwsel_i        ),
		.in_pwaddr          	( data_pwaddr_i       ),
		.in_pwdata          	( data_pwdata_i       ),
		.in_pwstrb          	( data_pwstrb_i       ),
		.in_pwtype          	( data_pwtype_i       ),
		.in_pwrdy           	( data_pwrdy_i        ),
		.axi_addr_w_addr_o  	( axi_addr_w_addr_o   ),
		.axi_addr_w_valid_o 	( axi_addr_w_valid_o  ),
		.axi_addr_w_ready_i 	( axi_addr_w_ready_i  ),
		.axi_addr_w_len_o   	( axi_addr_w_len_o    ),
		.axi_addr_w_size_o  	( axi_addr_w_size_o   ),
		.axi_w_data_o       	( axi_w_data_o        ),
		.axi_w_strb_o       	( axi_w_strb_o        ),
		.axi_w_valid_o      	( axi_w_valid_o       ),
		.axi_w_ready_i      	( axi_w_ready_i       ),
		.axi_w_last_o       	( axi_w_last_o        ),
		.axi_bkwd_valid_i   	( axi_bkwd_valid_i    ),
		.axi_bkwd_ready_o   	( axi_bkwd_ready_o    )
	);

endmodule
