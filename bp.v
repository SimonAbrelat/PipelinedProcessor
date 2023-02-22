 `include "define.vh"

module BRANCH_PREDICTOR(
  input wire clk,
  input wire reset,
  input wire [`from_DE_to_BP_WIDTH-1:0] from_DE,
  input wire [`from_AGEX_to_BP_WIDTH-1:0] from_AGEX,
  output wire [`from_BP_to_DE_WIDTH-1:0] to_DE,
  output wire [`from_BP_to_AGEX_WIDTH-1:0] to_AGEX
);

  reg [`BPBITS-1:0] hist_reg_BP;
  reg [1:0] pattern_hist_BP [15:0];
  reg [`DBITS-1:0] branch_target_BP [15:0];

  // Fetches prediction information
  wire val_pred_BP;
  wire [`DBITS-1:0] pred_PC_BP;

  assign {val_pred_BP, pred_PC_BP} = from_DE;

  wire [`BPBITS-1:0] pred_idx_BP;
  assign pred_idx_BP = pred_PC_BP[9:2] ^ hist_reg_BP;

  wire [`DBITS-1:0] pred_target_BP;
  assign pred_target_BP = (pattern_hist_BP[pred_idx_BP[3:0]] >= 2) ? branch_target_BP[pred_idx_BP[3:0]] : pred_PC_BP + 4;


  // Fetches update information
  wire val_update_BP;
  wire update_dir_BP;
  wire [`BPBITS-1:0] update_idx_BP;
  wire [`BPBITS-1:0] update_idx_BP;
  wire [`DBITS-1:0] update_target_BP;

  assign {val_update_BP, update_dir_BP, update_idx_BP, update_target_BP} = from_AGEX;

  // Combinational logic
  assign hist_reg_BP = hist_reg_BP << 1 | {7'b0, update_dir_BP};

  always @(posedge clk) begin
    if (reset) begin
      for (int i = 0; i < 16; ++i) begin
        pattern_hist_BP[i] <= 01;
      end
    end else begin
      if (val_update_BP) begin
        if(update_target_BP == branch_target_BP[update_idx_BP[3:0]]) begin
          if (pattern_hist_BP[update_idx_BP[3:0]] < 3)
            pattern_hist_BP[update_idx_BP[3:0]] <= pattern_hist_BP[update_idx_BP[3:0]] + 1;
        end else begin
          if (pattern_hist_BP[update_idx_BP[3:0]] > 0)
            pattern_hist_BP[update_idx_BP[3:0]] <= pattern_hist_BP[update_idx_BP[3:0]] - 1;
        end
      end
    end
  end

  always @(negedge clk) begin
    if (!reset && val_update_BP && update_target_BP == branch_target_BP[update_idx_BP[3:0]]) begin
      branch_target_BP[update_idx_BP[3:0]] <= update_target_BP;
    end
  end

endmodule
