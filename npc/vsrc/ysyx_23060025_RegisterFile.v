/*************************************************************************
	> File Name: ysyx_23060025_register.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 18时19分21秒
 ************************************************************************/

module ysyx_23060025_RegisterFile #(parameter REG_NUM = 16, DATA_WIDTH = 32)(
	input								clock		,
	input		[DATA_WIDTH - 1:0]		wdata	,
	input	    [4:0]					rsc1	,
	input	    [4:0]					rsc2	,
	input	    [4:0]					rd		,
	input								reset	,
	input								regWrite,
	output		[DATA_WIDTH - 1:0]		r_data1	,
	output		[DATA_WIDTH - 1:0]		r_data2	
);
	reg [DATA_WIDTH - 1:0] rf [REG_NUM - 2:0];

	always @(posedge clock) begin
		if (regWrite && rd != 0) rf[rd[3:0]-1] <= wdata;
	end

	//读取操作数
	assign r_data1 = rf[rsc1[3:0]-1];
	assign r_data2 = rf[rsc2[3:0]-1];

endmodule
