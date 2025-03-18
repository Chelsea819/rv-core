`include "ysyx_23060025_define.v"
module ysyx_23060025_write_buffer #(parameter ADDR_WIDTH = 32, DATA_WIDTH = 32, CACHE_LINE_OFF_ADDR_W = `MACRO_CACHE_LINE_OFF_ADDR_W)(
    input         		                clock,
	input         		                reset,    
    input		                		in_pwr_req	,
	input		[ADDR_WIDTH - 1:0]		in_pwaddr	,
	input		[CACHE_LINE_W-1:0]		in_pwdata	,	// 写出的数据
	input		[3:0]					in_pwstrb	,	// 仅当不是写一个cacheline时 有效
	input		[2:0]					in_pwtype	,	// 3'b000--byte, 3'b001--half word, 3'b010--word, 3'b100--cacheline
	output								in_pwrdy    ,		// write_buffer empty
	output								in_pwvalid    ,		// write_buffer empty

    // Addr Write
	output		[DATA_WIDTH - 1:0]		axi_addr_w_addr_o   ,	// 写地址
	output		                		axi_addr_w_valid_o  ,	// 主设备给出的地址和相关控制信号有效
	input		                		axi_addr_w_ready_i  , // 从设备已准备好接收地址和相关的控制信号
	output		[7:0]                	axi_addr_w_len_o    ,	// 突发长度，这个字段标识每次突发传输的传输次数
	output		[2:0]                	axi_addr_w_size_o   ,	// 突发大小，这个字段表示每次突发传输的大小

	// Write data
	output		[DATA_WIDTH - 1:0]		axi_w_data_o	,	// 写出的数据
	output		[3:0]					axi_w_strb_o	,	// wmask 	数据的字节选通，数据中每8bit对应这里的1bit
	output		                		axi_w_valid_o	,	// 主设备给出的数据和字节选通信号有效
	input		                		axi_w_ready_i	,	// 从设备已准备好接收数据选通信号
	output		                		axi_w_last_o	,	// 该信号用于标识当前传输是否为突发传输中的最后一次传输
	// Backward
	input		                		axi_bkwd_valid_i,	// 从设备给出的写回复信号是否有效
	output		                		axi_bkwd_ready_o	// 主设备已准备好接收写回复信号

);
    parameter	CACHE_LINE_W = (2 ** CACHE_LINE_OFF_ADDR_W) * 8;
    parameter	PASS_LEN = (2 ** CACHE_LINE_OFF_ADDR_W) / 4 - 1;
	parameter	PASS_TIMES = (2 ** CACHE_LINE_OFF_ADDR_W) / 4;

    localparam [1:0] STATE_IDLE = 2'b0, STATE_WAIT_AXI_READY = 2'b01, STATE_WRITE = 2'b10, STATE_BKWD = 2'b11;

    reg [1:0] con_state;
    reg [1:0] next_state;

    reg [ADDR_WIDTH+CACHE_LINE_W+4+3-1:0] write_buff_reg;
    always @(posedge clock) begin
        if(in_pwr_req) begin
            write_buff_reg <= { in_pwaddr	,
                                in_pwdata	,
                                in_pwstrb	,
                                in_pwtype	};
        end
    end

    wire		[ADDR_WIDTH - 1:0]		pwaddr	;
    wire		[CACHE_LINE_W-1:0]		pwdata	;	
    wire		[3:0]					pwstrb	;	
    wire		[2:0]					pwtype	;	
    
    assign {pwaddr	,
            pwdata	,
            pwstrb	,
            pwtype	} = write_buff_reg;

    // state machine
    always @(posedge clock) begin
        if(reset) begin
            con_state <= STATE_IDLE;
        end else begin
            con_state <= next_state;
        end
    end

    always @(*) begin
        next_state = con_state;
        case (con_state)
            STATE_IDLE: begin
                if(in_pwr_req) begin
                    next_state = STATE_WAIT_AXI_READY;
                end
            end
            STATE_WAIT_AXI_READY: begin
                if(axi_addr_w_ready_i) begin
                    next_state = STATE_WRITE;
                end
            end
            STATE_WRITE: begin
                if(axi_w_last_o & axi_w_ready_i) begin
                    next_state = STATE_BKWD;
                end
            end
            STATE_BKWD: begin
                if(axi_bkwd_valid_i) begin
                    next_state = STATE_IDLE;
                end
            end
            default: begin
            end
        endcase
    end

    // 用于突发传输中的传输次数计数
    reg [2:0] counter;
    always @(posedge clock) begin
        // 每轮复位一次
        if(next_state == STATE_WAIT_AXI_READY) begin
            counter <= 0;
        end else if(axi_w_valid_o & axi_w_ready_i) begin
            counter <= counter + 1;
        end
    end

    assign in_pwrdy = (next_state == STATE_IDLE);
    assign in_pwvalid = axi_bkwd_valid_i;

    assign axi_addr_w_addr_o  = pwaddr;
    assign axi_addr_w_valid_o = (con_state == STATE_WAIT_AXI_READY);
    assign axi_addr_w_len_o   = pwtype == 3'b100 ? PASS_LEN : 
                                0;
    assign axi_addr_w_size_o  = pwtype == 3'b001 ?  `AXI_ADDR_SIZE_2:
                                pwtype == 3'b000 ?  `AXI_ADDR_SIZE_1: 
                                `AXI_ADDR_SIZE_4;

    wire [CACHE_LINE_W-1:0] wdata_off = pwdata >> {counter, 5'b0};
    assign axi_w_data_o  = wdata_off[31:0];
    assign axi_w_strb_o  = pwtype == 3'b100 ?  `AXI_W_STRB_32:
                            pwstrb;
    assign axi_w_valid_o = (con_state == STATE_WRITE);
    assign axi_w_last_o  = counter == PASS_TIMES;

    assign axi_bkwd_ready_o = 1;

endmodule
