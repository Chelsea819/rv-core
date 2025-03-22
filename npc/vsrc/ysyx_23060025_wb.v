`include "ysyx_23060025_define.v"
`define MS_TO_WS_BUS_WD 493
module ysyx_23060025_wb #(parameter DATA_LEN = 32, ADDR_LEN = 32)(
    input								reset,
    input		                		clock		    ,


    //to fs fencei flush path 
    output [`WS_TO_XX_FLUSH_BUS-1:0]    ws_to_xx_flush_bus,
    output                              ws_to_xx_valid,


`ifdef DIFFTEST
	input								diff_skip_flag_i,
`endif
    // lsu_wbu
    input       [`MS_TO_WS_BUS-1:0]    	ms_to_ws_bus    ,
    input                               ms_to_ws_valid  ,
    output                              ws_allowin_o  ,

    output	    	                	    wd_o		,
    output	   	    [4:0]		            wreg_o		,
    output          [DATA_LEN - 1:0]        csr_mcause_o,
    output          [DATA_LEN - 1:0]        csr_wdata_o	,
    output          [11:0]		            csr_waddr_o	,
    output          [2:0]		            csr_type_o	,

    output	    	[DATA_LEN - 1:0]		reg_wdata_o
);
    wire		                		    wd_i		    ;
    wire            [2:0]		            csr_type_i	    ;
    wire                                    fencei_sign_i	;
    wire                                    ebreak_flag_i	;

    // wire ws_ready_go = 1;
    assign ws_allowin_o  = 1;
    reg ws_valid;
    always @(posedge clock) begin
        if (reset) begin
            ws_valid <= 1'b0;
        end
        else if (ws_allowin_o) begin
            ws_valid <= ms_to_ws_valid;
        end
    end

    reg [`ES_TO_MS_DATA_BUS -1:0]       ms_to_ws_bus_reg;
	always @(posedge clock) begin
		if(reset) begin
			ms_to_ws_bus_reg <= 0;
		end else if(ms_to_ws_valid & ws_allowin_o) begin
			ms_to_ws_bus_reg <= ms_to_ws_bus;
		end
	end

    assign {
            wd_i			,
            wreg_o		 	,
            reg_wdata_o		,
            csr_wdata_o		,
            csr_waddr_o		,
            csr_type_i		,
            csr_mcause_o	,
            fencei_sign_i	,
            ebreak_flag_i   } = ms_to_ws_bus_reg;

    assign ws_to_xx_valid = ws_valid;
    assign ws_to_xx_flush_bus = {
                                fencei_sign_i, 
                                fencei_flush_pc
                                    };


    assign wd_o = wd_i & ws_valid; 
    assign csr_type_o = csr_type_i & {3{ws_valid}}; 
    

`ifdef N_YOSYS_STA_CHECK
	reg finish;
    // register
	always @(posedge clock) begin
		if(reset) begin
			finish <= 0;
		end else begin
			finish <= ms_to_ws_valid;
		end
	end
    reg diff;
	always @(posedge clock) begin
		if(reset) begin
			diff <= 0;
		end else begin
			diff <= diff_skip_flag_i;
		end
	end
wire diff_skip = 1'bz;
`ifdef DIFFTEST
assign diff_skip = diff;
`endif
	import "DPI-C" function void finish_get(byte finish, byte diff_skip);
	// 检测到ebreak
    import "DPI-C" function void ifebreak_func(byte ebreak_flag);
    always @(posedge clock)
        ifebreak_func({7'b0,ebreak_flag_i});

	always @(posedge clock) begin
		// $display("pc = %x dpc = %x",pc,pc_next);
		if(finish & diff_skip) begin
			finish_get({7'b0,1'b1}, {7'b0,1'b1});
        end else if(finish) begin
            finish_get({7'b0,1'b1}, {7'b0,1'b0});
        end
			
	end
`endif    
endmodule
