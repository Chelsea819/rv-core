`include "ysyx_23060025_define.v"
module ysyx_23060025_wb #(parameter DATA_LEN = 32, ADDR_LEN = 32)(
    input								reset,
    input		                		wd_i		,
    input		                		clock		    ,
    input		[4:0]		            wreg_i		,
    input       [DATA_LEN - 1:0]        csr_wdata_i	,
    input       [2:0]		            csr_type_i	,
    input       [DATA_LEN - 1:0]        reg_wdata_i	,

    // lsu_wbu
    input                               lsu_valid_i  ,
    output                              wbu_ready_o  ,

    input                               ebreak_flag_i,
    // input                               memory_inst_i,
    // output                              wb_ready_o  ,
    // output  reg                         finish      ,
    output	reg	                		wd_o		,
    output	reg	[4:0]		            wreg_o		,
    output  reg [DATA_LEN - 1:0]        csr_wdata_o	,
    output      [2:0]		            csr_type_o	,

    output	reg	[DATA_LEN - 1:0]		wdata_o
);
    assign wbu_ready_o = 1'b1;

    always @(*) begin
        if(lsu_valid_i) begin
            wd_o	         =     wd_i; 
            wreg_o	         =     wreg_i;  	
            csr_wdata_o	     =     csr_wdata_i; 
			csr_type_o		 =	   csr_type_i; 
            wdata_o          =     reg_wdata_i;  
        end else begin 
            wd_o	         =     0; 
            wreg_o	         =     0;  	
            csr_wdata_o	     =     0; 
			csr_type_o		 =	   0; 
            wdata_o          =     0; 
        end
	end
	


`ifdef N_YOSYS_STA_CHECK
	// reg finish;
	// always @(posedge clock) begin
	// 	if(reset) begin
	// 		finish <= 0;
	// 	end else begin
	// 		finish <= lsu_valid_i;
	// 	end
	// end

	import "DPI-C" function void finish_get(byte finish);
		// always @(posedge clock) begin
		// 	if(finish) begin
		// 		$display("finish!");
		// 		finish_get({7'b0,finish});
		// 	end
				
		// end
	// 检测到ebreak
    import "DPI-C" function void ifebreak_func(byte ebreak_flag);
    always @(posedge clock)
        ifebreak_func({7'b0,ebreak_flag_i});

	always @(posedge clock) begin
		// $display("pc = %x dpc = %x",pc,pc_next);
		if(lsu_valid_i) begin
			finish_get({7'b0,1'b1});
		end
			
	end
`endif    
endmodule
