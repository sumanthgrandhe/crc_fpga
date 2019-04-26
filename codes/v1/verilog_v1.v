module lfsr (out, clk, rst,data);

  output reg [4:0] out;
  reg [4:0] temp1;
  reg [11:0] temp2;
  reg [4:0] temp3;
  input wire [6:0] data;
  input clk, rst;
  integer x = 0;
  
always @(posedge clk)
  begin
    if (rst) begin
      out = 5'b00000;
      temp3 = 5'b00000;
      temp2 = {data,temp3};
      x = 0;
    end
    else if(x<12) begin
      temp1 = {out[3],out[2],out[4] ^ out[1],out[4] ^ out[0],out[4] ^ temp2[11-x]};
      out = {temp1};
	x=x+1;
    end
  end
endmodule