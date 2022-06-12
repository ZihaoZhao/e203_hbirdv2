`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/09 16:46:10
// Design Name: 
// Module Name: divide
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module divide #(
    parameter WIDTH=16,
    parameter N=500
)(
    input clk,
    input rst_n,
    output reg clk_out
    );
    
    reg [WIDTH-1:0] cnt;
    always @(posedge clk) begin
        if (~rst_n) begin
            clk_out <= 0;
            cnt     <= 0;
        end
        else begin
            if (cnt >= N/2) begin
                clk_out <= ~clk_out;
                cnt <= 0;
            end
            else begin
                cnt <= cnt +1;
            end
        end
    end
    
endmodule
