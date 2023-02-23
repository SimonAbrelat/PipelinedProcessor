`include "define.vh"


module AGEX_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_MEM_to_AGEX_WIDTH-1:0] from_MEM_to_AGEX,
  input wire [`from_WB_to_AGEX_WIDTH-1:0] from_WB_to_AGEX,
  input wire [`DE_latch_WIDTH-1:0] from_DE_latch,
  output wire [`AGEX_latch_WIDTH-1:0] AGEX_latch_out,
  output wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE,
  output wire [`from_AGEX_to_DE_WIDTH-1:0] from_AGEX_to_DE,
  output wire [`from_AGEX_to_BP_WIDTH-1:0] from_AGEX_to_BP
);

  `UNUSED_VAR (from_MEM_to_AGEX)
  `UNUSED_VAR (from_WB_to_AGEX)

  reg [`AGEX_latch_WIDTH-1:0] AGEX_latch;
  // wire to send the AGEX latch contents to other pipeline stages
  assign AGEX_latch_out = AGEX_latch;

  wire[`AGEX_latch_WIDTH-1:0] AGEX_latch_contents;

  wire valid_AGEX;
  wire [`INSTBITS-1:0]inst_AGEX;
  wire [`DBITS-1:0]PC_AGEX;
  wire [`DBITS-1:0] inst_count_AGEX;
  wire [`DBITS-1:0] pcplus_AGEX;
  wire [`IOPBITS-1:0] op_I_AGEX;
  wire [`TYPENOBITS-1:0] type_I_AGEX;
  wire signed [`DBITS-1:0] sxt_imm_AGEX;
  wire signed [`DBITS-1:0] rs1_val_AGEX; // signed or unsigned?
  wire signed [`DBITS-1:0] rs2_val_AGEX; // signed or unsigned?
  wire [`REGNOBITS-1:0] rd_AGEX;
  reg br_cond_AGEX; // 1 means a branch condition is satisified. 0 means a branch condition is not satisifed
  reg signed [`DBITS-1:0] arith_AGEX;
  reg [`DBITS-1:0] memaddr_AGEX;
  reg [`DBITS-1:0] pctarget_AGEX;

  wire [`DBITS-1:0] rs1_val_unsigned;
  wire [`DBITS-1:0] rs2_val_unsigned;
  wire [`DBITS-1:0] imm_unsigned;
  assign rs1_val_unsigned = rs1_val_AGEX;
  assign rs2_val_unsigned = rs2_val_AGEX;
  assign imm_unsigned = sxt_imm_AGEX;

  wire[`BPBITS-1:0] bht_idx_AGEX;




 // **TODO: Complete the rest of the pipeline
  always @ (*) begin
    case (op_I_AGEX)
      `BEQ_I : br_cond_AGEX = rs1_val_AGEX == rs2_val_AGEX; // write correct code to check the branch condition.
      `BNE_I : br_cond_AGEX = rs1_val_AGEX != rs2_val_AGEX;
      `BLT_I : br_cond_AGEX = rs1_val_AGEX < rs2_val_AGEX;
      `BGE_I : br_cond_AGEX = rs1_val_AGEX >= rs2_val_AGEX;
      `BLTU_I: br_cond_AGEX = rs1_val_unsigned < rs2_val_unsigned;// unsigned comparison
      `BGEU_I : br_cond_AGEX = rs1_val_unsigned >= rs2_val_unsigned;
      `JR_I,
      `JALR_I,
      `JAL_I: br_cond_AGEX = 1'b1;
      default : br_cond_AGEX = 1'b0;
    endcase
  end


 // compute ALU operations  (alu out or memory addresses)

  always @ (*) begin
  case (op_I_AGEX)
    `ADD_I: arith_AGEX = rs1_val_AGEX + rs2_val_AGEX;
    `ADDI_I: arith_AGEX = rs1_val_AGEX + sxt_imm_AGEX;
    `SUB_I: arith_AGEX = rs1_val_AGEX - rs2_val_AGEX;
    `MUL_I: arith_AGEX = rs1_val_AGEX * rs2_val_AGEX;
    `AND_I: arith_AGEX = rs1_val_AGEX & rs2_val_AGEX;
    `ANDI_I: arith_AGEX = rs1_val_AGEX & sxt_imm_AGEX;
    `OR_I: arith_AGEX = rs1_val_AGEX | rs2_val_AGEX;
    `ORI_I: arith_AGEX = rs1_val_AGEX | sxt_imm_AGEX;
    `XOR_I: arith_AGEX = rs1_val_AGEX ^ rs2_val_AGEX;
    `XORI_I: arith_AGEX = rs1_val_AGEX ^ sxt_imm_AGEX;
    `SLT_I: arith_AGEX = {31'b0,(rs1_val_AGEX < rs2_val_AGEX)};
    `SLTI_I: arith_AGEX = {31'b0,(rs1_val_AGEX < sxt_imm_AGEX)};
    `SLTU_I: arith_AGEX = {31'b0, (rs1_val_unsigned < rs2_val_unsigned)};
    `SLTIU_I: arith_AGEX = {31'b0, (rs1_val_unsigned < imm_unsigned)};
    //`SRA_I: arith_AGEX = rs1_val_AGEX >>> {{20{rs2_val_AGEX[4]}},rs2_val_AGEX[4:0]}; // todo check
    `SRA_I: arith_AGEX = rs1_val_AGEX >>> rs2_val_AGEX[4:0]; // todo check
    `SRAI_I: arith_AGEX = rs1_val_AGEX>>> sxt_imm_AGEX[4:0]; // undo the sext
    `SRL_I: arith_AGEX = rs1_val_AGEX >> rs2_val_AGEX[4:0];
    `SRLI_I: arith_AGEX = rs1_val_AGEX >> sxt_imm_AGEX[4:0]; // undo sext
    `SLL_I: arith_AGEX = rs1_val_AGEX << rs2_val_AGEX[4:0];
    `SLLI_I: arith_AGEX = rs1_val_AGEX << sxt_imm_AGEX[4:0]; // undo sxt
    `JAL_I,
    `JALR_I: arith_AGEX = PC_AGEX + 'd4;
    `LUI_I: arith_AGEX = sxt_imm_AGEX ;//<< 'd12; //R[rd] = imm << 12
    `AUIPC_I: arith_AGEX = PC_AGEX + (sxt_imm_AGEX );//<< 12); // R[rd] = PC + ( imm << 12 )
    `SW_I: arith_AGEX = rs2_val_AGEX;
    default: arith_AGEX = {`DBITS{1'b0}};
  endcase
  end


  // compute memaddr
  always @(*) begin
    case(op_I_AGEX)
      `LW_I: memaddr_AGEX = (rs1_val_AGEX + sxt_imm_AGEX) ;
      `SW_I: memaddr_AGEX = (rs1_val_AGEX + sxt_imm_AGEX) ;
    endcase
  end


  // branch / jump target needs to be computed here
  // computed branch target needs to send to other pipeline stages (pctarget_AGEX)

  always @(*)begin
    if (op_I_AGEX == `JAL_I) begin
      pctarget_AGEX = PC_AGEX + sxt_imm_AGEX; // PC = PC + sext(imm)
    end else if (op_I_AGEX == `JALR_I) begin
      pctarget_AGEX = (rs1_val_AGEX + sxt_imm_AGEX) & 'hFFFFFFFE; // PC = ( R[rs1] + sext(imm) ) & 0xfffffffe
    end else if (op_I_AGEX == `JR_I) begin
      pctarget_AGEX = rs1_val_AGEX; // PC = R[rs1]
    end else if (br_cond_AGEX) begin
      pctarget_AGEX = PC_AGEX + sxt_imm_AGEX;
    end else begin
      pctarget_AGEX = {`DBITS{1'b0}};
    end
  end

  assign from_AGEX_to_FE = {br_cond_AGEX, pctarget_AGEX};
  assign from_AGEX_to_DE = {br_cond_AGEX, inst_AGEX[11:7], type_I_AGEX};

  assign {
                                valid_AGEX,
                                inst_AGEX,
                                PC_AGEX,
                                pcplus_AGEX,
                                op_I_AGEX,
                                type_I_AGEX,
                                inst_count_AGEX,
                                sxt_imm_AGEX,
                                rs1_val_AGEX, // TODO: sometimes goes high when in a stall
                                rs2_val_AGEX,
                                bht_idx_AGEX
                                        // more signals might need
                                } = from_DE_latch;


  assign AGEX_latch_contents = {
                                valid_AGEX,
                                inst_AGEX,
                                PC_AGEX,
                                op_I_AGEX,
                                type_I_AGEX,
                                inst_count_AGEX,
                                arith_AGEX,
                                memaddr_AGEX
                                       // more signals might need
                                 };

// is_branch_update_BP, update_dir_BP, update_idx_BP, update_target_BP, pc_from_AGEX_BP

assign from_AGEX_to_BP = {
                          (op_I_AGEX >= `BEQ_I && op_I_AGEX <=`BGEU_I),
                          br_cond_AGEX,
                          bht_idx_AGEX, // TODO
                          pctarget_AGEX,
                          pcplus_AGEX
                          };

  always @ (posedge clk ) begin
    if(reset) begin
      AGEX_latch <= {`AGEX_latch_WIDTH{1'b0}};
      // might need more code here
        end
    else
        begin
      // need to complete
            AGEX_latch <= AGEX_latch_contents ;
        end
  end




endmodule
