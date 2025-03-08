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
	//Addr Read
	input		[ADDR_LEN - 1:0]		inst_addr_r_addr_i,
	input		                		inst_addr_r_valid_i,
	input		[7:0]  					inst_addr_rlen_o	,
	input		[2:0]  					inst_addr_rsize_o	,
	// input		[3:0]                	inst_addr_r_id_i,	// 谁发出的读请求

	// Read data
	output		[DATA_LEN - 1:0]		inst_r_data_o	,
	output		                		inst_r_valid_o	,
	output		       					inst_r_last_i	,

	// data-AXI
	//Addr Read
	input		[ADDR_LEN - 1:0]		data_addr_r_addr_i,
	input		                		data_addr_r_valid_i,
	input		[2:0]                	data_addr_r_size_i,
	output		                		data_addr_r_ready_o,

	// Read data
	output		[DATA_LEN - 1:0]		data_r_data_o	,
	output		[1:0]					data_r_resp_o	,	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	output		                		data_r_valid_o	,
	input		                		data_r_ready_i	,

	// Addr Write
	input		[ADDR_LEN - 1:0]		data_addr_w_addr_i,	// 写地址
	input		[2:0]                	data_addr_w_size_i,
	input		                		data_addr_w_valid_i,	// 主设备给出的地址和相关控制信号有效
	output		                		data_addr_w_ready_o, // 从设备已准备好接收地址和相关的控制信号

	// Write data
	input		[DATA_LEN - 1:0]		data_w_data_i	,	// 写出的数据
	input		[3:0]					data_w_strb_i	,	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	input		                		data_w_valid_i	,	// 主设备给出的数据和字节选通信号有效
	output		                		data_w_ready_o	,	// 从设备已准备好接收数据选通信号

	// Backward
	output		[1:0]					data_bkwd_resp_o,	// 写回复信号，写操作是否成功
	output		                		data_bkwd_valid_o,	// 从设备给出的写回复信号是否有效
	input		                		data_bkwd_ready_i,	// 主设备已准备好接收写回复信号

    // Xbar
	output	reg 						axi_device,
    //Addr Read
	output	reg	[ADDR_LEN - 1:0]		axi_addr_r_addr_o,
	output		                		axi_addr_r_valid_o,
	input		                		axi_addr_r_ready_i,
	output		[3:0]                	axi_addr_r_id_o,	// 谁发出的读请求
	output		[7:0]                	axi_addr_r_len_o,	// 突发长度 用于一个burst中有多少个beat
	output		[2:0]                	axi_addr_r_size_o,	// 突发长度 设置1个beat的宽度，不可超过数据总线的宽度
	output		[1:0]                	axi_addr_r_burst_o,	// 突发类型

	// Read data
	input		[DATA_LEN - 1:0]		axi_r_data_i	,
	input		[1:0]					axi_r_resp_i	,	// 读操作是否成功，存储器处理读写事物时可能会发生错误
	input		                		axi_r_valid_i	,
	input		                		axi_r_last_i	,
	input		[3:0]           		axi_r_id_i		,	// 读到的数据给谁？
	output		                		axi_r_ready_o	,	// 最后一次读取到的数据

	// Addr Write
	output	reg	[ADDR_LEN - 1:0]		axi_addr_w_addr_o,	// 写地址
	output		                		axi_addr_w_valid_o,	// 主设备给出的地址和相关控制信号有效
	input		                		axi_addr_w_ready_i, // 从设备已准备好接收地址和相关的控制信号
	output		[3:0]                	axi_addr_w_id_o,	// 谁发出的写请求
	output		[7:0]                	axi_addr_w_len_o,	// 突发长度，这个字段标识每次突发传输的传输次数
	output		[2:0]                	axi_addr_w_size_o,	// 突发大小，这个字段表示每次突发传输的大小
	output		[1:0]                	axi_addr_w_burst_o,	// 突发类型，包括突发类型和突发大小信息，该字段决定了每次突发传输时地址的计算方法

	// Write data
	output	reg	[DATA_LEN - 1:0]		axi_w_data_o	,	// 写出的数据
	output	reg	[3:0]					axi_w_strb_o	,	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	output		                		axi_w_valid_o	,	// 主设备给出的数据和字节选通信号有效
	input		                		axi_w_ready_i	,	// 从设备已准备好接收数据选通信号
	output		                		axi_w_last_o	,	// 该信号用于标识当前传输是否为突发传输中的最后一次传输

	// Backward
	input		[1:0]					axi_bkwd_resp_i,	// 写回复信号，写操作是否成功
	input		                		axi_bkwd_valid_i,	// 从设备给出的写回复信号是否有效
	output		                		axi_bkwd_ready_o,	// 主设备已准备好接收写回复信号
	input		[3:0]                	axi_bkwd_id_i		// 写响应ID，该信号用于标识写响应传输
);	
	parameter [1:0] STATE_IDLE = 2'b00, AXI_CTL_BUSY_DATA = 2'b01, AXI_CTL_BUSY_INST = 2'b10;

	reg				[1:0]			        con_state	;
	reg				[1:0]		        	next_state	;

	// assign axi_addr_r_len_o = 0;
	// assign axi_addr_r_burst_o = `AXI_ADDR_BURST_FIXED;
	
	assign axi_addr_w_len_o = 0;
	assign axi_addr_w_burst_o = `AXI_ADDR_BURST_FIXED;
	assign axi_w_last_o = `AXI_W_LAST_TRUE;

`ifdef N_YOSYS_STA_CHECK
	// 访问部分设备时。跳过ref的difftest检查
	// 设备：UART
`ifdef DIFFTEST
	always @(posedge clock) begin
		if(reset) begin
			diff_skip_flag_o <= 0;
		end
		else if (data_addr_r_valid_i & ((data_addr_r_addr_i & 32'hffff_f000) == `DEVICE_UART16550_ADDR_L 
			||(data_addr_r_addr_i >= `DEVICE_GPIO_ADDR_L && data_addr_r_addr_i <= `DEVICE_GPIO_ADDR_H)
			||(data_addr_r_addr_i >= `DEVICE_CLINT_ADDR_L && data_addr_r_addr_i <= `DEVICE_CLINT_ADDR_H))) begin
				diff_skip_flag_o <= 1;
			end else if (data_addr_w_valid_i & ((data_addr_w_addr_i & 32'hffff_f000) == `DEVICE_UART16550_ADDR_L || 
			(data_addr_w_addr_i >= `DEVICE_GPIO_ADDR_L && data_addr_w_addr_i <= `DEVICE_GPIO_ADDR_H))) begin
				diff_skip_flag_o <= 1;
			end else begin if(next_state == STATE_IDLE)
				diff_skip_flag_o <= 0;
			end
	end
`endif
`endif

	wire addr_clint = (data_addr_r_addr_i & 32'hffff_0000) == `DEVICE_CLINT_ADDR_L;

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


	// always @(*) begin
	// 	$display("con_state: [%b] next_state: [%b] axi_addr_r_ready_i: [%b] inst_addr_r_valid_i: [%b] data_addr_r_valid_i[%b]",con_state, next_state, axi_addr_r_ready_i, inst_addr_r_valid_i, data_addr_r_valid_i);
	// end
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
				// sram busy
				if(data_addr_w_valid_i & data_w_valid_i) begin 
					next_state = AXI_CTL_BUSY_DATA;
				// data read
				end else if(data_addr_r_valid_i) begin
					next_state = AXI_CTL_BUSY_DATA;
				// inst read
				end else if(inst_addr_r_valid_i) begin
					next_state = AXI_CTL_BUSY_INST;
				end else begin 
					next_state = STATE_IDLE;
				end
			end
			AXI_CTL_BUSY_DATA: begin
				// finish write
				if (axi_bkwd_valid_i  & data_bkwd_ready_i) begin
					next_state = STATE_IDLE;			
				// finish read
				end else if (axi_r_valid_i & data_r_ready_i & axi_r_last_i) begin 
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
	assign {data_r_resp_o, data_r_valid_o, 
			data_bkwd_resp_o, data_bkwd_valid_o} 
			= (state_busy_data) ? {axi_r_resp_i, axi_r_valid_i,
																				axi_bkwd_resp_i, axi_bkwd_valid_i} : 
																				0;
	// finish inst read
	assign {inst_r_valid_o, inst_r_last_i} 
			= state_busy_inst ? {axi_r_valid_i, axi_r_last_i} : 
																				0;
	// finish data read or write OR finish inst read
	assign {axi_r_ready_o, axi_bkwd_ready_o} 
			= state_busy_data ? {data_r_ready_i, data_bkwd_ready_i} : 
				state_busy_inst ? {1'b1, 1'b0} : 0;
	
	// NEXT: AXI_CTL_BUSY_DATA
	assign {data_addr_r_ready_o, data_addr_w_ready_o, data_w_ready_o} 
			= state_busy_data ? {axi_addr_r_ready_i, axi_addr_w_ready_i, axi_w_ready_i} : 0;

	// NEXT: SRAM AXI_CTL_BUSY_DATA or AXI_CTL_BUSY_INST
	assign {axi_addr_r_valid_o, axi_addr_r_id_o, axi_addr_r_size_o, axi_addr_r_len_o, 
			axi_addr_w_valid_o, axi_addr_w_id_o, axi_addr_w_size_o, 
			axi_w_valid_o} 
			= state_busy_data ? { data_addr_r_valid_i, `AXI_R_ID_LSU, data_addr_r_size_i, 8'b0, 
													data_addr_w_valid_i, `AXI_W_ID_LSU, data_addr_w_size_i, 
													data_w_valid_i} : 
				state_busy_inst ? {inst_addr_r_valid_i, `AXI_R_ID_IF, inst_addr_rsize_o, inst_addr_rlen_o, 
													1'b0, 4'b0, `AXI_ADDR_SIZE_1, 
													1'b0} : 
													0;
	assign axi_addr_r_burst_o = `AXI_ADDR_BURST_INCR;
	always @(*) begin
		axi_addr_r_addr_o	= 0;
		axi_addr_w_addr_o	= 0;
		axi_w_data_o		= 0;
		axi_w_strb_o		= 0;
		case(con_state)
			AXI_CTL_BUSY_INST: begin
				axi_addr_r_addr_o	= inst_addr_r_addr_i;
			end
			AXI_CTL_BUSY_DATA: begin
				axi_addr_r_addr_o	= data_addr_r_addr_i;
				axi_addr_w_addr_o	= data_addr_w_addr_i;
				axi_w_data_o		= data_w_data_i;
				axi_w_strb_o		= data_w_strb_i;
			end
			default: begin 
			end
		endcase
	end

	assign data_r_data_o = axi_r_data_i;
	assign inst_r_data_o = axi_r_data_i;

endmodule
