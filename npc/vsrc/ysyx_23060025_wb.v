`include "ysyx_23060025_define.v"
`define MS_TO_WS_BUS_WD 493
module ysyx_23060025_wb #(parameter DATA_LEN = 32, ADDR_LEN = 32)(
    input								reset,
    input		                		clock		    ,
    input		                		wd_i		,
    input		[4:0]		            wreg_i		,
    input       [DATA_LEN - 1:0]        csr_wdata_i	,
    input       [2:0]		            csr_type_i	,
    input       [11:0]		            csr_waddr_i	,
    input       [DATA_LEN - 1:0]        reg_wdata_i	,
    input       [DATA_LEN - 1:0]        csr_mcause_i	,
    input                               ebreak_flag_i	,
`ifdef DIFFTEST
	input								diff_skip_flag_i,
`endif
    // lsu_wbu
    input                               ms_to_ws_valid  ,
    output                              ws_allowin_o  ,

    // input                               memory_inst_i,
    // output                              wb_ready_o  ,
    // output  reg                         finish      ,
    output	reg    	                	    wd_o		,
    output	reg   	[4:0]		            wreg_o		,
    output  reg   [DATA_LEN - 1:0]          csr_mcause_o	,
    output  reg   [DATA_LEN - 1:0]          csr_wdata_o	,
    output  reg     [11:0]		            csr_waddr_o	,
    output  reg    [2:0]		            csr_type_o	,

    output	reg    	[DATA_LEN - 1:0]		wdata_o
);

    // wire ws_ready_go = 1;
    assign ws_allowin_o  = 1;
    // reg ws_valid;
    // always @(posedge clock) begin
    //     if (reset) begin
    //         ws_valid <= 1'b0;
    //     end
    //     else if (ws_allowin_o) begin
    //         ws_valid <= ms_to_ws_valid;
    //     end
    // end

    always @(posedge clock) begin
        if(reset) begin
            wd_o	         <=     0; 
            wreg_o	         <=     0;  	
            csr_wdata_o	     <=     0; 
            csr_mcause_o	 <=     0;             
            csr_waddr_o	     <=     0;             
			csr_type_o		 <=	    0; 
            wdata_o          <=     0;
             
        end else begin 
            wd_o	         <=     wd_i & ms_to_ws_valid; 
            wreg_o	         <=     wreg_i;  	
            csr_wdata_o	     <=     csr_wdata_i; 
            csr_mcause_o	     <=     csr_mcause_i; 
            csr_waddr_o	     <=     csr_waddr_i; 
			csr_type_o		 <=	   csr_type_i & {3{ms_to_ws_valid}}; 
            wdata_o          <=     reg_wdata_i; 
        end
	end

    // assign wd_o                 = ms_to_ws_valid & wd_i;
    // assign wreg_o               = wreg_i;
    // assign csr_wdata_o	     =     csr_wdata_i; 
    // assign csr_waddr_o	     =     csr_waddr_i; 
    // assign csr_type_o		 =	   {3{ms_to_ws_valid}} & csr_type_i; 
    // assign wdata_o          =     reg_wdata_i; 
	


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
