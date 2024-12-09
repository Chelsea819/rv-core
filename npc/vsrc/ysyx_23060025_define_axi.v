`include "ysyx_22041211_define_device.v"

`define AXI_XBAR_SOC        1'b0 
`define AXI_XBAR_CLINT       1'b1 

//Addr Read
`define AXI_ADDR_SIZE_1     3'b000 // 字节数
`define AXI_ADDR_SIZE_2     3'b001 
`define AXI_ADDR_SIZE_4     3'b010 
`define AXI_ADDR_SIZE_8     3'b011 
`define AXI_ADDR_SIZE_16    3'b100 
`define AXI_ADDR_SIZE_32    3'b101 
`define AXI_ADDR_SIZE_64    3'b110 
`define AXI_ADDR_SIZE_128   3'b111 

`define AXI_ADDR_BURST_FIXED      2'b00  // 在同一个地址中突发
`define AXI_ADDR_BURST_INCR       2'b01  // 在递增地址中突发
`define AXI_ADDR_BURST_WARP       2'b10  // 用的不是特别多
`define AXI_ADDR_BURST_RESERVED   2'b11 

`define AXI_W_LAST_TRUE 1'b1 
`define AXI_W_LAST_FALSE 1'b0 

`define AXI_W_STRB_8  4'b0001 
`define AXI_W_STRB_16 4'b0011    
`define AXI_W_STRB_32 4'b1111 

`define AXI_R_ID_IF 4'b00
`define AXI_R_ID_LSU 4'b10
// `define AXI_R_ID_IF 4'b0

`define AXI_W_ID_LSU 4'b1




