 `include "define.vh"

module MEM_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_WB_to_MEM_WIDTH-1:0] from_WB_to_MEM,
  input wire [`AGEX_latch_WIDTH-1:0] from_AGEX_latch,
  output wire [`MEM_latch_WIDTH-1:0] MEM_latch_out,
  output wire [`from_MEM_to_FE_WIDTH-1:0] from_MEM_to_FE,
  output wire [`from_MEM_to_DE_WIDTH-1:0] from_MEM_to_DE,
  output wire [`from_WB_to_AGEX_WIDTH-1:0] from_MEM_to_AGEX
);

  `UNUSED_VAR (from_WB_to_MEM)
  // D-MEM
  (* ram_init_file = `IDMEMINITFILE *)
  reg [`DBITS-1:0] dmem[`DMEMWORDS-1:0];

 // DMEM and IMEM should contains the same contents
 initial begin
     $readmemh(`IDMEMINITFILE , dmem);
  end


  reg [`MEM_latch_WIDTH-1:0] MEM_latch;
  wire valid_MEM;
  wire[`MEM_latch_WIDTH-1:0] MEM_latch_contents;



  wire [`IOPBITS-1:0] op_I_MEM;
  wire [`TYPENOBITS-1:0] type_I_MEM;
  wire [`DBITS-1:0] inst_count_MEM;
  wire [`INSTBITS-1:0] inst_MEM;
  wire [`DBITS-1:0] PC_MEM;
  wire [`DBITS-1:0] regval_MEM;
  wire [`DBITS-1:0] mod_regval_MEM;
  //wire reg_wr_MEM = (op_I_MEM==`SW_I);




// **TODO: Complete the rest of the pipeline

  wire [`DBITS-1:0] memaddr_MEM;  // memory address. need to be computed in AGEX stage and pass through a latch
  wire [`DBITS-1:0] rd_val_MEM;  // memory read value
  wire [`DBITS-1:0] wr_val_MEM;  // memory write value
  wire wr_mem_MEM = (op_I_MEM==`SW_I);  // is this instruction writing a value into memory?
  // Read from D-MEM  (read code is completed if there is a correct memaddr_MEM )
  assign rd_val_MEM = dmem[memaddr_MEM[`DMEMADDRBITS-1:`DMEMWORDBITS]];


 // Write to D-MEM
  always @ (posedge clk) begin
  if(wr_mem_MEM)
    // fill out the correct signal name to do write operations
      dmem[memaddr_MEM[`DMEMADDRBITS-1:`DMEMWORDBITS]] <= regval_MEM;
  end


  assign mod_regval_MEM = (op_I_MEM == `LW_I) ? rd_val_MEM : regval_MEM;
  /*
  always @(*) begin
    case(op_I_MEM)
      `LW_I: mod_regval_MEM = rd_val_MEM;
      default: mod_regval_MEM = regval_MEM;
    endcase
  end
  */


  //`UNUSED_VAR (memaddr_MEM)
  //`UNUSED_VAR (rd_mem_MEM)

   assign from_MEM_to_DE = {inst_MEM[11:7], type_I_MEM};

   assign MEM_latch_out = MEM_latch;

   assign {
                                valid_MEM,
                                inst_MEM,
                                PC_MEM,
                                op_I_MEM,
                                type_I_MEM,
                                inst_count_MEM,
                                regval_MEM,
                                memaddr_MEM
                                 // more signals might need
                                 } = from_AGEX_latch;



   assign MEM_latch_contents = {
                                valid_MEM,
                                inst_MEM,
                                PC_MEM,
                                op_I_MEM,
                                type_I_MEM,
                                inst_count_MEM,
                                mod_regval_MEM
                                        // more signals might need
   };


  always @ (posedge clk) begin
    if(reset) begin
        MEM_latch <={`MEM_latch_WIDTH{1'b0}};
    end
    else
     begin
        MEM_latch <= MEM_latch_contents;
     end

  end



endmodule
