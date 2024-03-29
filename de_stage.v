`include "define.vh"


module DE_STAGE(
  input wire clk,
  input wire reset,
  input wire [`FE_latch_WIDTH-1:0] from_FE_latch,
  input wire [`from_AGEX_to_DE_WIDTH-1:0] from_AGEX_to_DE,
  input wire [`from_MEM_to_DE_WIDTH-1:0] from_MEM_to_DE,
  input wire [`from_WB_to_DE_WIDTH-1:0] from_WB_to_DE,
  input wire [`from_BP_to_DE_WIDTH-1:0] from_BP_to_DE,
  output wire [`from_DE_to_FE_WIDTH-1:0] from_DE_to_FE,
  output wire [`DE_latch_WIDTH-1:0] DE_latch_out,
  output wire[`from_DE_to_BP_WIDTH-1:0] from_DE_to_BP
);

  `UNUSED_VAR (from_MEM_to_DE)

  /* pipeline latch*/
  reg [`DE_latch_WIDTH-1:0] DE_latch;


  /* architecture register file */
  reg [`DBITS-1:0] regs [`REGWORDS-1:0];


  /* decode signals */
  wire valid_DE;
  wire [`INSTBITS-1:0] inst_DE;
  wire [`DBITS-1:0] PC_DE;
  wire [`DBITS-1:0] pcplus_DE;
  wire [`DBITS-1:0] inst_count_DE;
  wire[`DE_latch_WIDTH-1:0] DE_latch_contents;



// extracting a part of opcode
  wire [2:0] F3_DE;
  wire [6:0] F7_DE;
  wire [6:0] op_DE;

  assign op_DE = inst_DE[6:0];
  assign F3_DE = inst_DE[14:12];
  assign F7_DE = inst_DE[31:25];

  /* opcode decoding logic */
  reg [`IOPBITS-1:0 ] op_I_DE; //  internal opcode enumerator for easy programming.
  reg [`TYPENOBITS-1:0] type_I_DE;  // instruction format type information for decoding purpose
  reg [`IMMTYPENOBITS-1:0] type_immediate_DE;  // immediate type information for decodding purpose

  always @(*) begin
    if ((op_DE == `ADD_OPCODE) && (F3_DE == `ADD_FUNCT3) && (F7_DE == `ADD_FUNCT7))
      op_I_DE = `ADD_I;
    else if ((op_DE == `SUB_OPCODE) && (F3_DE == `SUB_FUNCT3) && (F7_DE == `SUB_FUNCT7))
      op_I_DE = `SUB_I;
    else if ((op_DE == `AND_OPCODE) && (F3_DE == `AND_FUNCT3) && (F7_DE == `AND_FUNCT7))
      op_I_DE = `AND_I;
    else if ((op_DE == `OR_OPCODE) && (F3_DE == `OR_FUNCT3) && (F7_DE == `OR_FUNCT7))
      op_I_DE = `OR_I;
    else if ((op_DE == `XOR_OPCODE) && (F3_DE == `XOR_FUNCT3) && (F7_DE == `XOR_FUNCT7))
      op_I_DE = `XOR_I;
    else if ((op_DE == `SLT_OPCODE) && (F3_DE == `SLT_FUNCT3) && (F7_DE == `SLT_FUNCT7))
      op_I_DE = `SLT_I;
    else if ((op_DE == `SLTU_OPCODE) && (F3_DE == `SLTU_FUNCT3) && (F7_DE == `SLTU_FUNCT7))
      op_I_DE = `SLTU_I;
    else if ((op_DE == `SRA_OPCODE) && (F3_DE == `SRA_FUNCT3) && (F7_DE == `SRA_FUNCT7))
      op_I_DE = `SRA_I;
    else if ((op_DE == `SRL_OPCODE) && (F3_DE == `SRL_FUNCT3) && (F7_DE == `SRL_FUNCT7))
      op_I_DE = `SRL_I;
    else if ((op_DE == `SLL_OPCODE) && (F3_DE == `SLL_FUNCT3) && (F7_DE == `SLL_FUNCT7))
      op_I_DE = `SLL_I;
    else if ((op_DE == `MUL_OPCODE) && (F3_DE == `MUL_FUNCT3) && (F7_DE == `MUL_FUNCT7))
      op_I_DE = `MUL_I;
    else if ((op_DE == `ADDI_OPCODE) && (F3_DE == `ADDI_FUNCT3))
      op_I_DE = `ADDI_I;
    else if ((op_DE == `ANDI_OPCODE) && (F3_DE == `ANDI_FUNCT3))
      op_I_DE = `ANDI_I;
    else if ((op_DE == `ORI_OPCODE) && (F3_DE == `ORI_FUNCT3))
      op_I_DE = `ORI_I;
    else if ((op_DE == `XORI_OPCODE) && (F3_DE == `XORI_FUNCT3))
      op_I_DE = `XORI_I;
    else if ((op_DE == `SLTI_OPCODE) && (F3_DE == `SLTI_FUNCT3))
      op_I_DE = `SLTI_I;
    else if ((op_DE == `SLTIU_OPCODE) && (F3_DE == `SLTIU_FUNCT3))
      op_I_DE = `SLTIU_I;
    else if ((op_DE == `SRAI_OPCODE) && (F3_DE == `SRAI_FUNCT3) && (F7_DE == `SRAI_FUNCT7))
      op_I_DE = `SRAI_I;
    else if ((op_DE == `SRLI_OPCODE) && (F3_DE == `SRLI_FUNCT3) && (F7_DE == `SRLI_FUNCT7))
      op_I_DE = `SRLI_I;
    else if ((op_DE == `SLLI_OPCODE) && (F3_DE == `SLLI_FUNCT3) && (F7_DE == `SLLI_FUNCT7))
      op_I_DE = `SLLI_I;
    else if ((op_DE == `LUI_OPCODE))
      op_I_DE = `LUI_I;
    else if ((op_DE == `AUIPC_OPCODE))
      op_I_DE = `AUIPC_I;
    else if ((op_DE == `LW_OPCODE) && (F3_DE == `LW_FUNCT3))
      op_I_DE = `LW_I;
    else if ((op_DE == `SW_OPCODE) && (F3_DE == `SW_FUNCT3))
      op_I_DE = `SW_I;
    else if ((op_DE == `JAL_OPCODE))
      op_I_DE = `JAL_I;
    else if ((op_DE == `JALR_OPCODE) && (F3_DE == `JALR_FUNCT3))
      op_I_DE = `JALR_I;
    else if ((op_DE == `BEQ_OPCODE) && (F3_DE == `BEQ_FUNCT3))
      op_I_DE = `BEQ_I;
    else if ((op_DE == `BNE_OPCODE) && (F3_DE == `BNE_FUNCT3))
      op_I_DE = `BNE_I;
    else if ((op_DE == `BLT_OPCODE) && (F3_DE == `BLT_FUNCT3))
      op_I_DE = `BLT_I;
    else if ((op_DE == `BGE_OPCODE) && (F3_DE == `BGE_FUNCT3))
      op_I_DE = `BGE_I;
    else if ((op_DE == `BLTU_OPCODE) && (F3_DE == `BLTU_FUNCT3))
      op_I_DE = `BLTU_I;
    else if ((op_DE == `BGEU_OPCODE) && (F3_DE == `BGEU_FUNCT3))
      op_I_DE = `BGEU_I;
    else if ((op_DE == `CSRR_OPCODE) && (F3_DE == `CSRR_FUNCT3))
      op_I_DE = `CSRR_I;
    else if ((op_DE == `CSRW_OPCODE) && (F3_DE == `CSRW_FUNCT3))
      op_I_DE = `CSRW_I;
    else
      op_I_DE = `INVALID_I;
  end

always @(*) begin
    type_I_DE = `TYPENOBITS'bx;
    type_immediate_DE = `IMMTYPENOBITS'bx;

    if ((op_I_DE == `ADD_I) ||
      (op_I_DE == `SUB_I ) ||
      (op_I_DE ==  `AND_I) ||
      (op_I_DE == `OR_I) ||
      (op_I_DE == `XOR_I) ||
      (op_I_DE == `SLT_I) ||
      (op_I_DE ==  `SLTU_I) ||
      (op_I_DE ==  `SRA_I) ||
      (op_I_DE == `SRL_I ) ||
      (op_I_DE == `SLL_I) ||
      (op_I_DE ==  `MUL_I) ) begin
        type_I_DE = `R_Type;
      end

    else if ((op_I_DE == `CSRR_I) ||
      (op_I_DE == `CSRW_I) ||
      (op_I_DE == `ADDI_I ) ||
      (op_I_DE == `ANDI_I) ||
      (op_I_DE == `ORI_I) ||
      (op_I_DE == `XORI_I) ||
      (op_I_DE == `SLTI_I) ||
      (op_I_DE == `SLTIU_I ) ||
      (op_I_DE == `LW_I ) ||
      (op_I_DE == `JR_I) ||
      (op_I_DE == `JALR_I) ) begin
        type_I_DE = `I_Type;
        type_immediate_DE = `I_immediate;
      end

    else if ((op_I_DE ==  `SRAI_I ) ||
      (op_I_DE == `SRLI_I) ||
      (op_I_DE == `SLLI_I)) begin
        type_I_DE = `I_Type;
        type_immediate_DE = `I_immediate;
      end

    else if ((op_I_DE ==  `LUI_I) ||
      (op_I_DE == `AUIPC_I )) begin
        type_I_DE = `I_Type;
        type_immediate_DE = `U_immediate;
      end

    else if (op_I_DE == `SW_I) begin
        type_I_DE = `S_Type;
        type_immediate_DE = `S_immediate;
      end

    else if (op_I_DE ==  `JAL_I) begin
        type_I_DE = `U_Type;
        type_immediate_DE = `J_immediate;
      end

    else if ((op_I_DE ==  `BEQ_I ) ||
      (op_I_DE == `BNE_I) ||
      (op_I_DE == `BLT_I) ||
      (op_I_DE == `BGE_I) ||
      (op_I_DE == `BLTU_I) ||
      (op_I_DE == `BGEU_I)) begin
        type_I_DE = `S_Type;
        type_immediate_DE = `B_immediate;
      end

end



//////////////////////////////////
    // **TODO: Complete the rest of the pipeline
   reg  signed [`DBITS-1:0] sxt_imm_DE; // TODO is this necessary?
always @(*) begin
  case (type_immediate_DE )
    // TODO: DOUBLE CHECK THIS SHIT
  `I_immediate:
    sxt_imm_DE = {{21{inst_DE[31]}}, inst_DE[30:25], inst_DE[24:21], inst_DE[20]};
  `S_immediate:
    sxt_imm_DE = {{21{inst_DE[31]}}, inst_DE[30:25], inst_DE[11:8], inst_DE[7]};
  `B_immediate:
    sxt_imm_DE = {{20{inst_DE[31]}}, inst_DE[7], inst_DE[30:25], inst_DE[11:8], 1'b0};
  `U_immediate:
    sxt_imm_DE = {inst_DE[31], inst_DE[30:20], inst_DE[19:12], 12'b0};
  `J_immediate:
    sxt_imm_DE = {{12{inst_DE[31]}}, inst_DE[19:12], inst_DE[20], inst_DE[30:25], inst_DE[24:21], 1'b0};
   default:
    sxt_imm_DE = 32'b0;
  endcase
end

   reg  [`REGNOBITS-1:0] rs1_DE;
   reg  [`REGNOBITS-1:0] rs2_DE;
always @(*) begin
  rs1_DE = {`REGNOBITS{1'b0}};
  rs2_DE = {`REGNOBITS{1'b0}};
  case (type_I_DE)
  `R_Type: begin
    rs1_DE = inst_DE[19:15];
    rs2_DE = inst_DE[24:20];
  end
  `I_Type: begin
    rs1_DE = inst_DE[19:15];
  end
  `S_Type: begin
    rs1_DE = inst_DE[19:15];
    rs2_DE = inst_DE[24:20];
  end
  endcase
end



 /* this signal is passed from WB stage */
  wire wr_reg_WB; // is this instruction writing into a register file?
  wire [`REGNOBITS-1:0] wregno_WB; // destination register ID
  wire [`DBITS-1:0] regval_WB;  // the contents to be written in the register file (or CSR )


  // signals come from WB stage for register WB
  assign { wr_reg_WB, wregno_WB, regval_WB} = from_WB_to_DE;


  wire [`REGNOBITS-1:0] rd_AGEX; // AGEX destination register ID
  wire [`REGNOBITS-1:0] rd_MEM; // MEM destination register ID
  wire [`TYPENOBITS-1:0] op_Type_AGEX; // AGEX destination register ID
  wire [`TYPENOBITS-1:0] op_Type_MEM; // MEM destination register ID
  reg pipeline_stall_DE;
  wire branch_invalid;
  assign {branch_invalid, rd_AGEX, op_Type_AGEX} = from_AGEX_to_DE;
  assign {rd_MEM, op_Type_MEM} = from_MEM_to_DE;
  //
  always @ (*) begin // TODO u and i type have invalid srcregs
    /*
    if (op_Type_AGEX != 0 && op_Type_AGEX != `S_Type) begin
      pipeline_stall_DE = ((rd_AGEX == rs1_DE) || (rd_AGEX == rs2_DE));
    end
    if (op_Type_MEM != 0 && op_Type_MEM != `S_Type) begin
      pipeline_stall_DE = ((rd_MEM == rs1_DE) || (rd_MEM == rs2_DE));
    end
    */
   /*
    if (
        (( op_Type_AGEX != 0 && op_Type_AGEX != `S_Type) &&((rd_AGEX == rs1_DE) || (rd_AGEX == rs2_DE)))
        || ((op_Type_MEM != 0 && op_Type_MEM != `S_Type) && ((rd_MEM == rs1_DE) || (rd_MEM == rs2_DE)))
        ) begin
      pipeline_stall_DE = 1;
    end
    else begin
      pipeline_stall_DE = 0;
    end
    */


    pipeline_stall_DE =  ((( op_Type_AGEX != 0 && op_Type_AGEX != `S_Type) &&((rd_AGEX == rs1_DE) || (rd_AGEX == rs2_DE)))
        || ((op_Type_MEM != 0 && op_Type_MEM != `S_Type) && ((rd_MEM == rs1_DE) || (rd_MEM == rs2_DE))));
  end


// decoding the contents of FE latch out. the order should be matched with the fe_stage.v
  assign {
            valid_DE,
            inst_DE,
            PC_DE,
            pcplus_DE,
            inst_count_DE
            }  = from_FE_latch;  // based on the contents of the latch, you can decode the content


// assign wire to send the contents of DE latch to other pipeline stages
  assign DE_latch_out = DE_latch;

   assign DE_latch_contents = {
                                  valid_DE,
                                  inst_DE,
                                  PC_DE,
                                  pcplus_DE,
                                  op_I_DE,
                                  type_I_DE,
                                  inst_count_DE,
                                  sxt_imm_DE,
                                  regs[rs1_DE],
                                  regs[rs2_DE],
                                  BP_dir_DE,
                                  pht_idx_DE,
                                  BTB_hit_DE
                                  // more signals might need
                                  };

  // BP stuff
  wire BP_dir_DE;
  wire [`BPBITS-1:0] pht_idx_DE;
  wire BTB_hit_DE;
  assign {BP_dir_DE, pht_idx_DE, BTB_hit_DE} = from_BP_to_DE;
  assign from_DE_to_BP = { // is_branch , pc
                          (op_I_DE >= `BEQ_I && op_I_DE <=`BGEU_I),
                          pcplus_DE
                          };

  assign from_DE_to_FE = {pipeline_stall_DE}; // pass the DE stage stall signal to FE stage




  always @ (negedge clk) begin
  /* register write code is completed for your benefit */
    if(reset) begin
      regs[0] <= {`DBITS{1'b0}};
      regs[1] <= {`DBITS{1'b0}};
      regs[2] <= {`DBITS{1'b0}};
      regs[3] <= {`DBITS{1'b0}};
      regs[4] <= {`DBITS{1'b0}};
      regs[5] <= {`DBITS{1'b0}};
      regs[6] <= {`DBITS{1'b0}};
      regs[7] <= {`DBITS{1'b0}};
      regs[8] <= {`DBITS{1'b0}};
      regs[9] <= {`DBITS{1'b0}};
      regs[10] <= {`DBITS{1'b0}};
      regs[11] <= {`DBITS{1'b0}};
      regs[12] <= {`DBITS{1'b0}};
      regs[13] <= {`DBITS{1'b0}};
      regs[14] <= {`DBITS{1'b0}};
      regs[15] <= {`DBITS{1'b0}};
      regs[16] <= {`DBITS{1'b0}};
      regs[17] <= {`DBITS{1'b0}};
      regs[18] <= {`DBITS{1'b0}};
      regs[19] <= {`DBITS{1'b0}};
      regs[20] <= {`DBITS{1'b0}};
      regs[21] <= {`DBITS{1'b0}};
      regs[22] <= {`DBITS{1'b0}};
      regs[23] <= {`DBITS{1'b0}};
      regs[24] <= {`DBITS{1'b0}};
      regs[25] <= {`DBITS{1'b0}};
      regs[26] <= {`DBITS{1'b0}};
      regs[27] <= {`DBITS{1'b0}};
      regs[28] <= {`DBITS{1'b0}};
      regs[29] <= {`DBITS{1'b0}};
      regs[30] <= {`DBITS{1'b0}};
      regs[31] <= {`DBITS{1'b0}};
    end
    else if(wr_reg_WB && wregno_WB != 0)
		  	regs[wregno_WB] <= regval_WB;
  end


always @ (posedge clk) begin // you need to expand this always block
    if(reset) begin
      DE_latch <= {`DE_latch_WIDTH{1'b0}};
      end
     else begin
        if (pipeline_stall_DE) begin
          DE_latch <= {`DE_latch_WIDTH{1'b0}};
        end else if (branch_invalid) begin
          DE_latch <= {`DE_latch_WIDTH{1'b0}};
        end
        else begin
          DE_latch <= DE_latch_contents;
        end
     end
  end



endmodule


module BRANCH_PREDICTOR(
  input wire clk,
  input wire reset,
  input wire [`from_DE_to_BP_WIDTH-1:0] from_DE,
  input wire [`from_AGEX_to_BP_WIDTH-1:0] from_AGEX,
  output wire [`from_BP_to_FE_WIDTH-1:0] to_FE,
  output wire [`from_BP_to_DE_WIDTH-1:0] to_DE
  //output wire [`from_BP_to_AGEX_WIDTH-1:0] to_AGEX
);

  reg [1:0] pattern_hist_table_BP [255:0];        // PHT -- use 8 bits to index
  reg [`BPBITS-1:0] branch_hist_reg_BP;            // BHR
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

  wire pht_predict_BP;
  assign pht_predict_BP = (pattern_hist_table_BP[pht_idx_BP] >= 2);




  // Fetches update information
  wire is_branch_update_BP;
  wire actual_dir_BP;
  wire predicted_dir_BP;
  wire [`BPBITS-1:0] update_pht_idx_BP;
  //wire [`BPBITS-1:0] update_idx_BP;
  wire [`DBITS-1:0] update_target_BP;
  wire [`DBITS-1:0] pc_from_AGEX_BP;

  assign {is_branch_update_BP, actual_dir_BP, predicted_dir_BP, update_pht_idx_BP, update_target_BP, pc_from_AGEX_BP} = from_AGEX;


  always @(posedge clk) begin
    if (reset) begin
      for (int i = 0; i < 16; ++i) begin
        pattern_hist_table_BP[i] <= 01;
      end
    end else begin
      if (is_branch_update_BP) begin
        branch_hist_reg_BP <= branch_hist_reg_BP << 1 | {7'b0, actual_dir_BP};
        if (actual_dir_BP) begin
          if (pattern_hist_table_BP[update_pht_idx_BP] < 3)
            pattern_hist_table_BP[update_pht_idx_BP] <= pattern_hist_table_BP[update_pht_idx_BP] + 1;
        end else begin
          if (pattern_hist_table_BP[update_pht_idx_BP] > 0)
            pattern_hist_table_BP[update_pht_idx_BP] <= pattern_hist_table_BP[update_pht_idx_BP] - 1;
        end
      end
    end
  end

  always @(negedge clk) begin
    //if (!reset && is_branch_update_BP && update_target_BP == branch_target_buffer_BP[update_idx_BP]) begin
    if (!reset && is_branch_update_BP ) begin  // TODO update with branch target even if not taken?
      branch_target_buffer_BP[pc_from_AGEX_BP[5:2]] <= {pc_from_AGEX_BP[25:0],1'b1, update_target_BP};
    end
  end


  assign to_DE = {pht_predict_BP, pht_idx_BP,
                  (branch_target_buffer_BP[PC_from_DE_BP[5:2]][`DBITS])   // BTB valid & hit
                  && (branch_target_buffer_BP[PC_from_DE_BP[5:2]][58:`DBITS+1] == PC_from_DE_BP[25:0])};
  //assign to_FE = {is_branch_DE_BP && (actual_dir_BP == predicted_dir_BP), PC_target_BP};
  assign to_FE = {is_branch_DE_BP, pht_predict_BP, PC_target_BP};

endmodule
