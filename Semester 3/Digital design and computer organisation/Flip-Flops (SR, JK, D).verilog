// Design Verilog program for implementing various types of Flip-Flops such as SR, JK, and D
module sr_flipflop(input S, R, clk, output reg Q, output reg Qn);
  always @(posedge clk) begin
    if (S == 1 && R == 0) begin
      Q <= 1;
      Qn <= 0;
    end else if (S == 0 && R == 1) begin
      Q <= 0;
      Qn <= 1;
    end else if (S == 0 && R == 0) begin
      Q <= Q;  // No change
    end else begin
      Q <= 0;  // Invalid state
    end
  end
endmodule

module jk_flipflop(input J, K, clk, output reg Q);
  always @(posedge clk) begin
    if (J == 1 && K == 0) begin
      Q <= 1;
    end else if (J == 0 && K == 1) begin
      Q <= 0;
    end else if (J == 1 && K == 1) begin
      Q <= ~Q;  // Toggle
    end
  end
endmodule

module d_flipflop(input D, clk, output reg Q);
  always @(posedge clk) begin
    Q <= D;
  end
endmodule
