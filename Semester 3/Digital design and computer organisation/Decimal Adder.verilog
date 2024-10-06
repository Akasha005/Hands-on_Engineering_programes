// Design Verilog HDL to implement Decimal adder
module decimal_adder(input [3:0] A, B, input Cin, output [3:0] Sum, output Cout);
  wire [4:0] temp_sum;
  assign temp_sum = A + B + Cin;
  assign Sum = (temp_sum > 9) ? (temp_sum + 4'b0110) : temp_sum;
  assign Cout = (temp_sum > 9) ? 1 : 0;
endmodule
