 `include "define.vh"

module pipeline (
  input wire clk,
  input wire reset
);

  reg [`DBITS-1:0] cycle_count; /* for debugging purpose */

  /* wires to connect between pipeline stages */

  wire [`FE_latch_WIDTH-1:0] FE_latch_out;
  wire [`DE_latch_WIDTH-1:0] DE_latch_out;
  wire [`AGEX_latch_WIDTH-1:0] AGEX_latch_out;
  wire [`MEM_latch_WIDTH-1:0] MEM_latch_out;

  wire [`from_DE_to_FE_WIDTH-1:0] from_DE_to_FE;
  wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE;
  wire [`from_MEM_to_FE_WIDTH-1:0] from_MEM_to_FE;
  wire [`from_WB_to_FE_WIDTH-1:0] from_WB_to_FE;

  wire [`from_AGEX_to_DE_WIDTH-1:0] from_AGEX_to_DE;
  wire [`from_MEM_to_DE_WIDTH-1:0] from_MEM_to_DE;
  wire [`from_WB_to_DE_WIDTH-1:0] from_WB_to_DE;

  wire [`from_MEM_to_AGEX_WIDTH-1:0] from_MEM_to_AGEX;
  wire [`from_WB_to_AGEX_WIDTH-1:0] from_WB_to_AGEX;

  wire [`from_WB_to_MEM_WIDTH-1:0] from_WB_to_MEM;

  wire [`from_DE_to_BP_WIDTH-1:0] from_DE_to_BP;
  wire [`from_BP_to_FE_WIDTH-1:0] from_BP_to_FE;
  wire [`from_BP_to_DE_WIDTH-1:0] from_BP_to_DE;
  wire[`from_AGEX_to_BP_WIDTH-1:0] from_AGEX_to_BP;
  //wire[`from_BP_to_AGEX_WIDTH-1:0] from_BP_to_AGEX;// do we even need this

  FE_STAGE my_FE_stage(
    .clk(clk),
    .reset(reset),
    .from_DE_to_FE(from_DE_to_FE),
    .from_AGEX_to_FE(from_AGEX_to_FE),
    .from_MEM_to_FE(from_MEM_to_FE),
    .from_WB_to_FE(from_WB_to_FE),
    .from_BP_to_FE(from_BP_to_FE),
    .FE_latch_out(FE_latch_out)
  );

  DE_STAGE my_DE_stage(
    .clk(clk),
    .reset(reset),
    .from_FE_latch(FE_latch_out),
    .from_AGEX_to_DE(from_AGEX_to_DE),
    .from_MEM_to_DE(from_MEM_to_DE),
    .from_WB_to_DE(from_WB_to_DE),
    .from_BP_to_DE(from_BP_to_DE),
    .from_DE_to_FE(from_DE_to_FE),
    .DE_latch_out(DE_latch_out),
    .from_DE_to_BP(from_DE_to_BP)
  );
/*input wire clk,
  input wire reset,
  input wire [`from_DE_to_BP_WIDTH-1:0] from_DE,
  input wire [`from_AGEX_to_BP_WIDTH-1:0] from_AGEX,
  output wire [`from_BP_to_DE_WIDTH-1:0] to_DE,
  output wire [`from_BP_to_AGEX_WIDTH-1:0] to_AGEX */
  BRANCH_PREDICTOR my_BP(
    .clk(clk),
    .reset(reset),
    .from_DE(from_DE_to_BP),
    .from_AGEX(from_AGEX_to_BP),
    .to_FE(from_BP_to_FE),
    .to_DE(from_BP_to_DE)
    //.to_AGEX(to_AGEX)
  );

  AGEX_STAGE my_AGEX_stage(
    .clk(clk),
    .reset(reset),
    .from_MEM_to_AGEX(from_MEM_to_AGEX),
    .from_WB_to_AGEX(from_WB_to_AGEX),
    .from_DE_latch(DE_latch_out),
    .AGEX_latch_out(AGEX_latch_out),
    .from_AGEX_to_FE(from_AGEX_to_FE),
    .from_AGEX_to_DE(from_AGEX_to_DE),
    .from_AGEX_to_BP(from_AGEX_to_BP)
  );

  MEM_STAGE my_MEM_stage(
    .clk(clk),
    .reset(reset),
    .from_WB_to_MEM(from_WB_to_MEM),
    .from_AGEX_latch(AGEX_latch_out),
    .MEM_latch_out(MEM_latch_out),
    .from_MEM_to_FE(from_MEM_to_FE),
    .from_MEM_to_DE(from_MEM_to_DE),
    .from_MEM_to_AGEX(from_MEM_to_AGEX)
  );

  WB_STAGE my_WB_stage(
    .clk(clk),
    .reset(reset),
    .from_MEM_latch(MEM_latch_out),
    .from_WB_to_FE(from_WB_to_FE),
    .from_WB_to_DE(from_WB_to_DE),
    .from_WB_to_AGEX(from_WB_to_AGEX),
    .from_WB_to_MEM(from_WB_to_MEM)
  );

  always @ (posedge clk) begin
    if (reset) begin
      cycle_count <= 0;
    end else begin
      cycle_count <= cycle_count + 1;
    end
  end

endmodule
