// Design Verilog HDL to implement simple circuits using structural, data flow and behavioural model
module simple_circuit_behavioral(input A, B, output Y);
  assign Y = A & B;  // Behavioral modeling
endmodule

module simple_circuit_dataflow(input A, B, output Y);
  assign Y = A | B;  // Data flow modeling
endmodule

module simple_circuit_structural(input A, B, output Y);
  wire w1;
  and(w1, A, B);  // Structural modeling
  assign Y = w1;
endmodule
