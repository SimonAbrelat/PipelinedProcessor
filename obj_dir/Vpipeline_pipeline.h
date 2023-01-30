// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpipeline.h for the primary calling header

#ifndef VERILATED_VPIPELINE_PIPELINE_H_
#define VERILATED_VPIPELINE_PIPELINE_H_  // guard

#include "verilated.h"

class Vpipeline__Syms;
class Vpipeline_WB_STAGE;


class Vpipeline_pipeline final : public VerilatedModule {
  public:
    // CELLS
    Vpipeline_WB_STAGE* my_WB_stage;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ __PVT__from_AGEX_to_FE;
    CData/*0:0*/ __PVT__from_MEM_to_FE;
    CData/*0:0*/ __PVT__from_AGEX_to_DE;
    CData/*0:0*/ __PVT__from_MEM_to_DE;
    CData/*0:0*/ __PVT__from_MEM_to_AGEX;
    CData/*0:0*/ __PVT__my_FE_stage__DOT__valid_FE;
    CData/*2:0*/ my_DE_stage__DOT____Vxrand_h9b4a7c25__0;
    CData/*3:0*/ my_DE_stage__DOT____Vxrand_h9b4aadca__0;
    CData/*5:0*/ __PVT__my_DE_stage__DOT__op_I_DE;
    CData/*3:0*/ __PVT__my_DE_stage__DOT__type_I_DE;
    CData/*2:0*/ __PVT__my_DE_stage__DOT__type_immediate_DE;
    CData/*4:0*/ __PVT__my_DE_stage__DOT__rs1_DE;
    CData/*4:0*/ __PVT__my_DE_stage__DOT__rs2_DE;
    CData/*0:0*/ __PVT__my_DE_stage__DOT__pipeline_stall_DE;
    CData/*4:0*/ __PVT__my_AGEX_stage__DOT__rd_AGEX;
    CData/*0:0*/ __PVT__my_MEM_stage__DOT__wr_mem_MEM;
    IData/*31:0*/ __PVT__cycle_count;
    VlWide<5>/*128:0*/ __PVT__my_FE_stage__DOT__FE_latch;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__PC_FE_latch;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__inst_count_FE;
    IData/*31:0*/ __PVT__my_FE_stage__DOT__inst_count_AGEX;
    VlWide<8>/*230:0*/ __PVT__my_DE_stage__DOT__DE_latch;
    VlWide<5>/*135:0*/ __PVT__my_AGEX_stage__DOT__AGEX_latch;
    VlWide<5>/*135:0*/ __PVT__my_MEM_stage__DOT__MEM_latch;
    IData/*31:0*/ __PVT__my_MEM_stage__DOT__memaddr_MEM;
    IData/*31:0*/ __PVT__my_MEM_stage__DOT__wr_val_MEM;
    VlWide<5>/*128:0*/ __Vdly__my_FE_stage__DOT__FE_latch;
    VlUnpacked<IData/*31:0*/, 16384> __PVT__my_FE_stage__DOT__imem;
    VlUnpacked<IData/*31:0*/, 32> __PVT__my_DE_stage__DOT__regs;
    VlUnpacked<IData/*31:0*/, 16384> __PVT__my_MEM_stage__DOT__dmem;

    // INTERNAL VARIABLES
    Vpipeline__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpipeline_pipeline(Vpipeline__Syms* symsp, const char* name);
    ~Vpipeline_pipeline();
    VL_UNCOPYABLE(Vpipeline_pipeline);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
