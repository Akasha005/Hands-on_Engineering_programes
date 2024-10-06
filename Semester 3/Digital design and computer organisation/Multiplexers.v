// Design Verilog program to implement different types of multiplexer like 2:1, 4:1 and 8:1
module mux_2to1(input A, B, Sel, output Y);
  assign Y = (Sel) ? B : A;  // 2:1 MUX
endmodule

module mux_4to1(input [3:0] I, input [1:0] Sel, output Y);
  assign Y = (Sel == 2'b00) ? I[0] :
             (Sel == 2'b01) ? I[1] :
             (Sel == 2'b10) ? I[2] : I[3];  // 4:1 MUX
endmodule

module mux_8to1(input [7:0] I, input [2:0] Sel, output Y);
  assign Y = (Sel == 3'b000) ? I[0] :
             (Sel == 3'b001) ? I[1] :
             (Sel == 3'b010) ? I[2] :
             (Sel == 3'b011) ? I[3] :
             (Sel == 3'b100) ? I[4] :
             (Sel == 3'b101) ? I[5] :
             (Sel == 3'b110) ? I[6] : I[7];  // 8:1 MUX
endmodule
