// Design Verilog HDL to implement Binary Adder-Subtractor (Half and Full Adder, Half and Full Subtractor)
module half_adder(input A, B, output Sum, Carry);
  assign Sum = A ^ B;
  assign Carry = A & B;
endmodule

module full_adder(input A, B, Cin, output Sum, Carry);
  wire S1, C1, C2;
  half_adder HA1(A, B, S1, C1);
  half_adder HA2(S1, Cin, Sum, C2);
  assign Carry = C1 | C2;
endmodule

module half_subtractor(input A, B, output Diff, Borrow);
  assign Diff = A ^ B;
  assign Borrow = ~A & B;
endmodule

module full_subtractor(input A, B, Bin, output Diff, Borrow);
  wire D1, B1, B2;
  half_subtractor HS1(A, B, D1, B1);
  half_subtractor HS2(D1, Bin, Diff, B2);
  assign Borrow = B1 | B2;
endmodule
