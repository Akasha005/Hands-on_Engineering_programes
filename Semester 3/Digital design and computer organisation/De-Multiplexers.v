// Design Verilog program to implement types of De-Multiplexer
module demux_1to2(input I, Sel, output Y0, Y1);
  assign Y0 = (Sel == 0) ? I : 0;
  assign Y1 = (Sel == 1) ? I : 0;
endmodule

module demux_1to4(input I, input [1:0] Sel, output Y0, Y1, Y2, Y3);
  assign Y0 = (Sel == 2'b00) ? I : 0;
  assign Y1 = (Sel == 2'b01) ? I : 0;
  assign Y2 = (Sel == 2'b10) ? I : 0;
  assign Y3 = (Sel == 2'b11) ? I : 0;
endmodule
