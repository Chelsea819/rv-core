module ysyx_23060025_Reg_noRst #(WIDTH = 1) (
  input clk,
  input [WIDTH-1:0] din,
  output reg [WIDTH-1:0] dout,
  input wen
);
  always @(posedge clk) begin
    if (wen) dout <= din;
  end
endmodule
