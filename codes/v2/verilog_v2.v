module lfsr (out, clk, rst,data,flag);

  output reg [2:0] out;
  reg [2:0] temp1;
  reg [8:0] temp2;
  reg [2:0] temp3;
  input wire [8:0] data;
  input clk, rst,flag;
  integer x = 0;
  
  always @(posedge clk)
  begin
    if (rst) begin
      out = 3'b000;
      temp3 = 3'b000;
      temp2 = {data[8:3],temp3};
      if (flag) begin
        temp2 = {data};   
      end
      x = 0;
    end
    else if(x<9) begin
      temp1 = {out[2] ^ out[1],out[0],out[2] ^ temp2[8-x]};
      out = {temp1};
	x=x+1;
    end
  end
endmodule