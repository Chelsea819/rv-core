/*************************************************************************
	> File Name: ysyx_23060025_MuxKey.v
	> Author: Chelsea
	> Mail: 1938166340@qq.com 
	> Created Time: 2023年08月04日 星期五 17时35分46秒
 ************************************************************************/

module ysyx_23060025_MuxKey#(parameter NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
	output			[DATA_LEN - 1:0]	out	,
	input			[KEY_LEN - 1:0 ]	key ,
	input			[NR_KEY*(KEY_LEN + DATA_LEN) - 1:0] lut
);
	
	ysyx_23060025_MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 0) i0 (out, key, {DATA_LEN{1'b0}}, lut);
endmodule

