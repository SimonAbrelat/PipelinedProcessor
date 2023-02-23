 `include "define.vh"

module BRANCH_PREDICTOR(
  input wire clk,
  input wire reset,
  input wire [`from_DE_to_BP_WIDTH-1:0] from_DE,
  input wire [`from_AGEX_to_BP_WIDTH-1:0] from_AGEX,
  output wire [`from_BP_to_DE_WIDTH-1:0] to_DE,
  output wire [`from_BP_to_AGEX_WIDTH-1:0] to_AGEX
);

  reg [`BPBITS-1:0] branch_hist_reg_BP;            // BHR
  reg [1:0] pattern_hist_table_BP [255:0];        // PHT -- use 8 bits to index
  reg [27+`DBITS-1:0] branch_target_buffer_BP [15:0]; // BTB -- use 4 bits to index
  // [tag(top 26 bits), valid, target(bottom dbits)]
  // the 27 comes from tag and valid bits, the DBITS for the actual address
  // Tag: the lower 27 bits of the PC that is the branch
  // per https://piazza.com/class/lcp4sh03g603oy/post/144

  // Fetches prediction information from decode
  wire is_branch_DE_BP;
  wire [`DBITS-1:0] PC_from_DE_BP;

  assign {is_branch_DE_BP, PC_from_DE_BP} = from_DE;

  wire [`BPBITS-1:0] pht_idx_BP;
  assign pht_idx_BP = PC_from_DE_BP[9:2] ^ branch_hist_reg_BP;

  wire [`DBITS-1:0] PC_target_BP;
  //assign pred_target_BP = (pattern_hist_BP[pred_idx_BP[3:0]] >= 2) ? branch_target_BP[pred_idx_BP[3:0]] : pred_PC_BP + 4;
  // TODO bit twiddling -- indices may need fixes
  assign PC_target_BP = ((branch_target_buffer_BP[PC_from_DE_BP[5:2]][`DBITS])            // BTB valid
    && (branch_target_buffer_BP[PC_from_DE_BP[5:2]][58:`DBITS+1] == PC_from_DE_BP[25:0]) // BTB hit
    && (pattern_hist_table_BP[pht_idx_BP] >= 2)) ?                                      // predicted taken
    branch_target_buffer_BP[PC_from_DE_BP[5:2]][`DBITS-1:0] : PC_from_DE_BP + 4;




  // Fetches update information
  wire is_branch_update_BP;
  wire update_dir_BP;
  wire [`BPBITS-1:0] update_idx_BP;
  //wire [`BPBITS-1:0] update_idx_BP;
  wire [`DBITS-1:0] update_target_BP;
  wire [`DBITS-1:0] pc_from_AGEX_BP;

  assign {is_branch_update_BP, update_dir_BP, update_idx_BP, update_target_BP, pc_from_AGEX_BP} = from_AGEX;

  // Combinational logic
  assign branch_hist_reg_BP = branch_hist_reg_BP << 1 | {7'b0, update_dir_BP};

  always @(posedge clk) begin
    if (reset) begin
      for (int i = 0; i < 16; ++i) begin
        pattern_hist_table_BP[i] <= 01;
      end
    end else begin
      if (is_branch_update_BP) begin
        //if(update_target_BP == branch_target_buffer_BP[update_idx_BP]) begin //TODO btb index by PC
        if (update_dir_BP) begin
          if (pattern_hist_table_BP[update_idx_BP] < 3)
            pattern_hist_table_BP[update_idx_BP] <= pattern_hist_table_BP[update_idx_BP] + 1;
        end else begin
          if (pattern_hist_table_BP[update_idx_BP] > 0)
            pattern_hist_table_BP[update_idx_BP] <= pattern_hist_table_BP[update_idx_BP] - 1;
        end
      end
    end
  end

  always @(negedge clk) begin // TODO btb indexed by PC
    //if (!reset && is_branch_update_BP && update_target_BP == branch_target_buffer_BP[update_idx_BP]) begin
    if (!reset && is_branch_update_BP ) begin
      branch_target_buffer_BP[pc_from_AGEX_BP[5:2]] <= {pc_from_AGEX_BP[25:0],1'b1, update_target_BP};
    end
  end


endmodule
