// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpipeline__Syms.h"


VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__pipeline__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
    tracep->declBus(c+1,"cycle_count", false,-1, 31,0);
    tracep->declArray(c+2,"FE_latch_out", false,-1, 128,0);
    tracep->declArray(c+7,"DE_latch_out", false,-1, 230,0);
    tracep->declArray(c+15,"AGEX_latch_out", false,-1, 135,0);
    tracep->declArray(c+20,"MEM_latch_out", false,-1, 135,0);
    tracep->declBus(c+169,"from_DE_to_FE", false,-1, 0,0);
    tracep->declBus(c+170,"from_AGEX_to_FE", false,-1, 0,0);
    tracep->declBus(c+171,"from_MEM_to_FE", false,-1, 0,0);
    tracep->declBus(c+172,"from_WB_to_FE", false,-1, 0,0);
    tracep->declBus(c+173,"from_AGEX_to_DE", false,-1, 0,0);
    tracep->declBus(c+174,"from_MEM_to_DE", false,-1, 0,0);
    tracep->declQuad(c+25,"from_WB_to_DE", false,-1, 37,0);
    tracep->declBus(c+175,"from_MEM_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+176,"from_WB_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+177,"from_WB_to_MEM", false,-1, 0,0);
    tracep->pushNamePrefix("my_AGEX_stage ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
    tracep->declBus(c+175,"from_MEM_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+176,"from_WB_to_AGEX", false,-1, 0,0);
    tracep->declArray(c+7,"from_DE_latch", false,-1, 230,0);
    tracep->declArray(c+15,"AGEX_latch_out", false,-1, 135,0);
    tracep->declBus(c+170,"from_AGEX_to_FE", false,-1, 0,0);
    tracep->declBus(c+173,"from_AGEX_to_DE", false,-1, 0,0);
    tracep->declArray(c+15,"AGEX_latch", false,-1, 135,0);
    tracep->declArray(c+27,"AGEX_latch_contents", false,-1, 135,0);
    tracep->declBit(c+32,"valid_AGEX", false,-1);
    tracep->declBus(c+33,"inst_AGEX", false,-1, 31,0);
    tracep->declBus(c+34,"PC_AGEX", false,-1, 31,0);
    tracep->declBus(c+35,"inst_count_AGEX", false,-1, 31,0);
    tracep->declBus(c+36,"pcplus_AGEX", false,-1, 31,0);
    tracep->declBus(c+37,"op_I_AGEX", false,-1, 5,0);
    tracep->declBus(c+38,"sxt_imm_AGEX", false,-1, 31,0);
    tracep->declBus(c+39,"rs1_val_AGEX", false,-1, 31,0);
    tracep->declBus(c+40,"rs2_val_AGEX", false,-1, 31,0);
    tracep->declBus(c+178,"rd_AGEX", false,-1, 4,0);
    tracep->declBit(c+41,"br_cond_AGEX", false,-1);
    tracep->declBus(c+42,"arith_AGEX", false,-1, 31,0);
    tracep->declBit(c+43,"reg_wr_AGEX", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_DE_stage ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
    tracep->declArray(c+2,"from_FE_latch", false,-1, 128,0);
    tracep->declBus(c+173,"from_AGEX_to_DE", false,-1, 0,0);
    tracep->declBus(c+174,"from_MEM_to_DE", false,-1, 0,0);
    tracep->declQuad(c+25,"from_WB_to_DE", false,-1, 37,0);
    tracep->declBus(c+169,"from_DE_to_FE", false,-1, 0,0);
    tracep->declArray(c+7,"DE_latch_out", false,-1, 230,0);
    tracep->declArray(c+7,"DE_latch", false,-1, 230,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+94+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->declBit(c+44,"valid_DE", false,-1);
    tracep->declBus(c+45,"inst_DE", false,-1, 31,0);
    tracep->declBus(c+46,"PC_DE", false,-1, 31,0);
    tracep->declBus(c+47,"pcplus_DE", false,-1, 31,0);
    tracep->declBus(c+48,"inst_count_DE", false,-1, 31,0);
    tracep->declArray(c+86,"DE_latch_contents", false,-1, 230,0);
    tracep->declBus(c+49,"F3_DE", false,-1, 2,0);
    tracep->declBus(c+50,"F7_DE", false,-1, 6,0);
    tracep->declBus(c+51,"op_DE", false,-1, 6,0);
    tracep->declBus(c+52,"op_I_DE", false,-1, 5,0);
    tracep->declBus(c+53,"type_I_DE", false,-1, 3,0);
    tracep->declBus(c+54,"type_immediate_DE", false,-1, 2,0);
    tracep->declBus(c+55,"sxt_imm_DE", false,-1, 31,0);
    tracep->declBus(c+56,"rs1_DE", false,-1, 4,0);
    tracep->declBus(c+57,"rs2_DE", false,-1, 4,0);
    tracep->declBit(c+58,"wr_reg_WB", false,-1);
    tracep->declBus(c+59,"wregno_WB", false,-1, 4,0);
    tracep->declBus(c+60,"regval_WB", false,-1, 31,0);
    tracep->declBit(c+169,"pipeline_stall_DE", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_FE_stage ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
    tracep->declBus(c+169,"from_DE_to_FE", false,-1, 0,0);
    tracep->declBus(c+170,"from_AGEX_to_FE", false,-1, 0,0);
    tracep->declBus(c+171,"from_MEM_to_FE", false,-1, 0,0);
    tracep->declBus(c+172,"from_WB_to_FE", false,-1, 0,0);
    tracep->declArray(c+2,"FE_latch_out", false,-1, 128,0);
    tracep->declArray(c+2,"FE_latch", false,-1, 128,0);
    tracep->declBit(c+179,"valid_FE", false,-1);
    tracep->declBus(c+61,"PC_FE_latch", false,-1, 31,0);
    tracep->declBus(c+62,"inst_count_FE", false,-1, 31,0);
    tracep->declBus(c+180,"inst_count_AGEX", false,-1, 31,0);
    tracep->declBus(c+63,"inst_FE", false,-1, 31,0);
    tracep->declBus(c+64,"pcplus_FE", false,-1, 31,0);
    tracep->declBit(c+181,"stall_pipe_FE", false,-1);
    tracep->declArray(c+65,"FE_latch_contents", false,-1, 128,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_MEM_stage ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
    tracep->declBus(c+177,"from_WB_to_MEM", false,-1, 0,0);
    tracep->declArray(c+15,"from_AGEX_latch", false,-1, 135,0);
    tracep->declArray(c+20,"MEM_latch_out", false,-1, 135,0);
    tracep->declBus(c+171,"from_MEM_to_FE", false,-1, 0,0);
    tracep->declBus(c+174,"from_MEM_to_DE", false,-1, 0,0);
    tracep->declBus(c+175,"from_MEM_to_AGEX", false,-1, 0,0);
    tracep->declArray(c+20,"MEM_latch", false,-1, 135,0);
    tracep->declBit(c+70,"valid_MEM", false,-1);
    tracep->declArray(c+15,"MEM_latch_contents", false,-1, 135,0);
    tracep->declBus(c+71,"op_I_MEM", false,-1, 5,0);
    tracep->declBus(c+72,"inst_count_MEM", false,-1, 31,0);
    tracep->declBus(c+73,"inst_MEM", false,-1, 31,0);
    tracep->declBus(c+74,"PC_MEM", false,-1, 31,0);
    tracep->declBus(c+75,"regval_MEM", false,-1, 31,0);
    tracep->declBit(c+76,"reg_wr_MEM", false,-1);
    tracep->declBus(c+182,"memaddr_MEM", false,-1, 31,0);
    tracep->declBus(c+77,"rd_val_MEM", false,-1, 31,0);
    tracep->declBus(c+183,"wr_val_MEM", false,-1, 31,0);
    tracep->declBit(c+184,"wr_mem_MEM", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"reset", false,-1);
    tracep->declArray(c+20,"from_MEM_latch", false,-1, 135,0);
    tracep->declBus(c+172,"from_WB_to_FE", false,-1, 0,0);
    tracep->declQuad(c+25,"from_WB_to_DE", false,-1, 37,0);
    tracep->declBus(c+176,"from_WB_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+177,"from_WB_to_MEM", false,-1, 0,0);
    tracep->declBit(c+78,"valid_WB", false,-1);
    tracep->declBus(c+79,"op_I_WB", false,-1, 5,0);
    tracep->declBus(c+80,"inst_WB", false,-1, 31,0);
    tracep->declBus(c+81,"PC_WB", false,-1, 31,0);
    tracep->declBus(c+82,"inst_count_WB", false,-1, 31,0);
    tracep->declBit(c+83,"wr_reg_WB", false,-1);
    tracep->declBus(c+84,"wregno_WB", false,-1, 4,0);
    tracep->declBus(c+85,"regval_WB", false,-1, 31,0);
    tracep->pushNamePrefix("last_WB_value");
    tracep->declBus(c+129,"[0]", false,-1, 31,0);
    tracep->declBus(c+130,"[1]", false,-1, 31,0);
    tracep->declBus(c+131,"[2]", false,-1, 31,0);
    tracep->declBus(c+132,"[3]", false,-1, 31,0);
    tracep->declBus(c+133,"[4]", false,-1, 31,0);
    tracep->declBus(c+134,"[5]", false,-1, 31,0);
    tracep->declBus(c+135,"[6]", false,-1, 31,0);
    tracep->declBus(c+136,"[7]", false,-1, 31,0);
    tracep->declBus(c+137,"[8]", false,-1, 31,0);
    tracep->declBus(c+138,"[9]", false,-1, 31,0);
    tracep->declBus(c+139,"[10]", false,-1, 31,0);
    tracep->declBus(c+140,"[11]", false,-1, 31,0);
    tracep->declBus(c+141,"[12]", false,-1, 31,0);
    tracep->declBus(c+142,"[13]", false,-1, 31,0);
    tracep->declBus(c+143,"[14]", false,-1, 31,0);
    tracep->declBus(c+144,"[15]", false,-1, 31,0);
    tracep->declBus(c+145,"[16]", false,-1, 31,0);
    tracep->declBus(c+146,"[17]", false,-1, 31,0);
    tracep->declBus(c+147,"[18]", false,-1, 31,0);
    tracep->declBus(c+148,"[19]", false,-1, 31,0);
    tracep->declBus(c+149,"[20]", false,-1, 31,0);
    tracep->declBus(c+150,"[21]", false,-1, 31,0);
    tracep->declBus(c+151,"[22]", false,-1, 31,0);
    tracep->declBus(c+152,"[23]", false,-1, 31,0);
    tracep->declBus(c+153,"[24]", false,-1, 31,0);
    tracep->declBus(c+154,"[25]", false,-1, 31,0);
    tracep->declBus(c+155,"[26]", false,-1, 31,0);
    tracep->declBus(c+156,"[27]", false,-1, 31,0);
    tracep->declBus(c+157,"[28]", false,-1, 31,0);
    tracep->declBus(c+158,"[29]", false,-1, 31,0);
    tracep->declBus(c+159,"[30]", false,-1, 31,0);
    tracep->declBus(c+160,"[31]", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("WB_counters");
    tracep->declBus(c+161,"[0]", false,-1, 31,0);
    tracep->declBus(c+162,"[1]", false,-1, 31,0);
    tracep->declBus(c+163,"[2]", false,-1, 31,0);
    tracep->declBus(c+164,"[3]", false,-1, 31,0);
    tracep->declBus(c+165,"[4]", false,-1, 31,0);
    tracep->declBus(c+166,"[5]", false,-1, 31,0);
    tracep->declBus(c+167,"[6]", false,-1, 31,0);
    tracep->declBus(c+168,"[7]", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+126,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_top(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_top\n"); );
    // Body
    Vpipeline___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    tracep->pushNamePrefix("pipeline ");
    Vpipeline___024root__trace_init_sub__TOP__pipeline__0(vlSelf, tracep);
    tracep->pushNamePrefix("my_WB_stage ");
    Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(vlSelf, tracep);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpipeline___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpipeline___024root__trace_register(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vpipeline___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vpipeline___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vpipeline___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpipeline___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_full_top_0\n"); );
    // Init
    Vpipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpipeline___024root*>(voidSelf);
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpipeline___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<5>/*159:0*/ __Vtemp_h8d3a512a__0;
    VlWide<5>/*159:0*/ __Vtemp_h336dc861__0;
    VlWide<3>/*95:0*/ __Vtemp_hee67c980__0;
    VlWide<8>/*255:0*/ __Vtemp_heae1d6bb__0;
    // Body
    bufp->fullIData(oldp+1,(vlSymsp->TOP__pipeline.__PVT__cycle_count),32);
    bufp->fullWData(oldp+2,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch),129);
    bufp->fullWData(oldp+7,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch),231);
    bufp->fullWData(oldp+15,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch),136);
    bufp->fullWData(oldp+20,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch),136);
    bufp->fullQData(oldp+25,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE),38);
    __Vtemp_h8d3a512a__0[0U] = (IData)((((QData)((IData)(
                                                         ((1U 
                                                           == 
                                                           (0x3fU 
                                                            & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U]))
                                                           ? 
                                                          (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U] 
                                                           + 
                                                           vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U])
                                                           : 0U))) 
                                         << 1U) | (QData)((IData)(
                                                                  (1U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U]))))));
    __Vtemp_h8d3a512a__0[1U] = (((IData)((0x3fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U]))))) 
                                 << 1U) | (IData)((
                                                   (((QData)((IData)(
                                                                     ((1U 
                                                                       == 
                                                                       (0x3fU 
                                                                        & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U]))
                                                                       ? 
                                                                      (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U] 
                                                                       + 
                                                                       vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U])
                                                                       : 0U))) 
                                                     << 1U) 
                                                    | (QData)((IData)(
                                                                      (1U 
                                                                       == 
                                                                       (0x3fU 
                                                                        & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U]))))) 
                                                   >> 0x20U)));
    __Vtemp_h8d3a512a__0[2U] = ((0xffffff80U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                                << 1U)) 
                                | (((IData)((0x3fffffffffULL 
                                             & (((QData)((IData)(
                                                                 vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U]))))) 
                                    >> 0x1fU) | ((IData)(
                                                         ((0x3fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U])))) 
                                                          >> 0x20U)) 
                                                 << 1U)));
    __Vtemp_h8d3a512a__0[3U] = (((0x7eU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                           << 1U)) 
                                 | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                    >> 0x1fU)) | (0xffffff80U 
                                                  & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                                     << 1U)));
    __Vtemp_h8d3a512a__0[4U] = (((0x7eU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                           << 1U)) 
                                 | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                    >> 0x1fU)) | (0x80U 
                                                  & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                                     << 1U)));
    bufp->fullWData(oldp+27,(__Vtemp_h8d3a512a__0),136);
    bufp->fullBit(oldp+32,((1U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                  >> 6U))));
    bufp->fullIData(oldp+33,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                            >> 6U))),32);
    bufp->fullIData(oldp+34,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                            >> 6U))),32);
    bufp->fullIData(oldp+35,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U]),32);
    bufp->fullIData(oldp+36,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                            >> 6U))),32);
    bufp->fullCData(oldp+37,((0x3fU & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])),6);
    bufp->fullIData(oldp+38,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U]),32);
    bufp->fullIData(oldp+39,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U]),32);
    bufp->fullIData(oldp+40,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U]),32);
    bufp->fullBit(oldp+41,(((0x1cU == (0x3fU & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                            & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U] 
                               == vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U]))));
    bufp->fullIData(oldp+42,(((1U == (0x3fU & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U]))
                               ? (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U] 
                                  + vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U])
                               : 0U)),32);
    bufp->fullBit(oldp+43,((1U == (0x3fU & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U]))));
    bufp->fullBit(oldp+44,((1U & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[4U])));
    bufp->fullIData(oldp+45,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U]),32);
    bufp->fullIData(oldp+46,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U]),32);
    bufp->fullIData(oldp+47,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U]),32);
    bufp->fullIData(oldp+48,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U]),32);
    bufp->fullCData(oldp+49,((7U & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+50,((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                              >> 0x19U)),7);
    bufp->fullCData(oldp+51,((0x7fU & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U])),7);
    bufp->fullCData(oldp+52,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE),6);
    bufp->fullCData(oldp+53,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_I_DE),4);
    bufp->fullCData(oldp+54,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE),3);
    bufp->fullIData(oldp+55,(((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                               ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                               >> 0x1fU))) 
                                   << 0xbU) | (0x7ffU 
                                               & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                  >> 0x14U)))
                               : ((4U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                   ? (((- (IData)((
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x1fU))) 
                                       << 0xbU) | (
                                                   (0x7e0U 
                                                    & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                         >> 7U))))
                                   : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                       ? (((- (IData)(
                                                      (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       >> 0x1fU))) 
                                           << 0xcU) 
                                          | ((0x800U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 7U)))))
                                       : ((3U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                           ? (0xfffff000U 
                                              & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U])
                                           : ((2U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                               ? ((
                                                   (- (IData)(
                                                              (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                               >> 0x1fU))) 
                                                   << 0x14U) 
                                                  | ((0xff000U 
                                                      & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U]) 
                                                     | ((0x800U 
                                                         & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                              >> 0x14U)))))
                                               : 0U)))))),32);
    bufp->fullCData(oldp+56,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__rs1_DE),5);
    bufp->fullCData(oldp+57,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__rs2_DE),5);
    bufp->fullBit(oldp+58,((1U & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                                          >> 0x25U)))));
    bufp->fullCData(oldp+59,((0x1fU & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                                               >> 0x20U)))),5);
    bufp->fullIData(oldp+60,((IData)(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE)),32);
    bufp->fullIData(oldp+61,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch),32);
    bufp->fullIData(oldp+62,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_FE),32);
    bufp->fullIData(oldp+63,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                             [(0x3fffU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                          >> 2U))]),32);
    bufp->fullIData(oldp+64,(((IData)(4U) + vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch)),32);
    __Vtemp_h336dc861__0[0U] = vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_FE;
    __Vtemp_h336dc861__0[1U] = ((IData)(4U) + vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch);
    __Vtemp_h336dc861__0[2U] = (IData)((((QData)((IData)(
                                                         vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                                                         [
                                                         (0x3fffU 
                                                          & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                                             >> 2U))])) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch))));
    __Vtemp_h336dc861__0[3U] = (IData)(((((QData)((IData)(
                                                          vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                                                          [
                                                          (0x3fffU 
                                                           & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                                              >> 2U))])) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch))) 
                                        >> 0x20U));
    __Vtemp_h336dc861__0[4U] = vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__valid_FE;
    bufp->fullWData(oldp+65,(__Vtemp_h336dc861__0),129);
    bufp->fullBit(oldp+70,((1U & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
                                  >> 7U))));
    bufp->fullCData(oldp+71,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                                       >> 1U))),6);
    bufp->fullIData(oldp+72,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                               << 0x1fU) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
                                            >> 1U))),32);
    bufp->fullIData(oldp+73,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+74,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+75,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
                               << 0x1fU) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] 
                                            >> 1U))),32);
    bufp->fullBit(oldp+76,((1U & vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U])));
    bufp->fullIData(oldp+77,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__dmem
                             [(0x3fffU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__memaddr_MEM 
                                          >> 2U))]),32);
    bufp->fullBit(oldp+78,((1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                  >> 7U))));
    bufp->fullCData(oldp+79,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                       >> 1U))),6);
    bufp->fullIData(oldp+80,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+81,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+82,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                               << 0x1fU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                            >> 1U))),32);
    bufp->fullBit(oldp+83,((1U & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])));
    bufp->fullCData(oldp+84,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                       >> 0xeU))),5);
    bufp->fullIData(oldp+85,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                               << 0x1fU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                            >> 1U))),32);
    __Vtemp_hee67c980__0[1U] = (IData)((((QData)((IData)(
                                                         vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((1U 
                                                            == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                            ? 
                                                           (((- (IData)(
                                                                        (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                         >> 0x1fU))) 
                                                             << 0xbU) 
                                                            | (0x7ffU 
                                                               & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                  >> 0x14U)))
                                                            : 
                                                           ((4U 
                                                             == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                             ? 
                                                            (((- (IData)(
                                                                         (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 0x1fU))) 
                                                              << 0xbU) 
                                                             | ((0x7e0U 
                                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                    >> 0x14U)) 
                                                                | (0x1fU 
                                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                      >> 7U))))
                                                             : 
                                                            ((5U 
                                                              == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                              ? 
                                                             (((- (IData)(
                                                                          (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 0x1fU))) 
                                                               << 0xcU) 
                                                              | ((0x800U 
                                                                  & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                     << 4U)) 
                                                                 | ((0x7e0U 
                                                                     & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                        >> 0x14U)) 
                                                                    | (0x1eU 
                                                                       & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 7U)))))
                                                              : 
                                                             ((3U 
                                                               == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                               ? 
                                                              (0xfffff000U 
                                                               & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U])
                                                               : 
                                                              ((2U 
                                                                == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                                ? 
                                                               (((- (IData)(
                                                                            (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                             >> 0x1fU))) 
                                                                 << 0x14U) 
                                                                | ((0xff000U 
                                                                    & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U]) 
                                                                   | ((0x800U 
                                                                       & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 9U)) 
                                                                      | (0x7feU 
                                                                         & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                            >> 0x14U)))))
                                                                : 0U)))))))));
    __Vtemp_hee67c980__0[2U] = (IData)(((((QData)((IData)(
                                                          vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           ((1U 
                                                             == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                             ? 
                                                            (((- (IData)(
                                                                         (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 0x1fU))) 
                                                              << 0xbU) 
                                                             | (0x7ffU 
                                                                & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                   >> 0x14U)))
                                                             : 
                                                            ((4U 
                                                              == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                              ? 
                                                             (((- (IData)(
                                                                          (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 0x1fU))) 
                                                               << 0xbU) 
                                                              | ((0x7e0U 
                                                                  & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                     >> 0x14U)) 
                                                                 | (0x1fU 
                                                                    & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                       >> 7U))))
                                                              : 
                                                             ((5U 
                                                               == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                               ? 
                                                              (((- (IData)(
                                                                           (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                            >> 0x1fU))) 
                                                                << 0xcU) 
                                                               | ((0x800U 
                                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                      << 4U)) 
                                                                  | ((0x7e0U 
                                                                      & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                         >> 0x14U)) 
                                                                     | (0x1eU 
                                                                        & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 7U)))))
                                                               : 
                                                              ((3U 
                                                                == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                                ? 
                                                               (0xfffff000U 
                                                                & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U])
                                                                : 
                                                               ((2U 
                                                                 == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                                 ? 
                                                                (((- (IData)(
                                                                             (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                              >> 0x1fU))) 
                                                                  << 0x14U) 
                                                                 | ((0xff000U 
                                                                     & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U]) 
                                                                    | ((0x800U 
                                                                        & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 9U)) 
                                                                       | (0x7feU 
                                                                          & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                             >> 0x14U)))))
                                                                 : 0U)))))))) 
                                        >> 0x20U));
    __Vtemp_heae1d6bb__0[0U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
        [vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__rs2_DE];
    __Vtemp_heae1d6bb__0[1U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
        [vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__rs1_DE];
    __Vtemp_heae1d6bb__0[2U] = __Vtemp_hee67c980__0[1U];
    __Vtemp_heae1d6bb__0[3U] = __Vtemp_hee67c980__0[2U];
    __Vtemp_heae1d6bb__0[4U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U] 
                                 << 6U) | (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE));
    __Vtemp_heae1d6bb__0[5U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U] 
                                 >> 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U] 
                                              << 6U));
    __Vtemp_heae1d6bb__0[6U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U] 
                                 >> 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                              << 6U));
    __Vtemp_heae1d6bb__0[7U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                 >> 0x1aU) | (0x40U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[4U] 
                                                 << 6U)));
    bufp->fullWData(oldp+86,(__Vtemp_heae1d6bb__0),231);
    bufp->fullIData(oldp+94,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[0]),32);
    bufp->fullIData(oldp+95,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[1]),32);
    bufp->fullIData(oldp+96,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[2]),32);
    bufp->fullIData(oldp+97,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[3]),32);
    bufp->fullIData(oldp+98,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[4]),32);
    bufp->fullIData(oldp+99,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[5]),32);
    bufp->fullIData(oldp+100,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[6]),32);
    bufp->fullIData(oldp+101,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[7]),32);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[8]),32);
    bufp->fullIData(oldp+103,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[9]),32);
    bufp->fullIData(oldp+104,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[10]),32);
    bufp->fullIData(oldp+105,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[11]),32);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[12]),32);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[13]),32);
    bufp->fullIData(oldp+108,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[14]),32);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[15]),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[16]),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[17]),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[18]),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[19]),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[20]),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[21]),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[22]),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[23]),32);
    bufp->fullIData(oldp+118,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[24]),32);
    bufp->fullIData(oldp+119,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[25]),32);
    bufp->fullIData(oldp+120,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[26]),32);
    bufp->fullIData(oldp+121,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[27]),32);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[28]),32);
    bufp->fullIData(oldp+123,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[29]),32);
    bufp->fullIData(oldp+124,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[30]),32);
    bufp->fullIData(oldp+125,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[31]),32);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+127,(vlSelf->clk));
    bufp->fullBit(oldp+128,(vlSelf->reset));
    bufp->fullIData(oldp+129,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0U]),32);
    bufp->fullIData(oldp+130,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[1U]),32);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[2U]),32);
    bufp->fullIData(oldp+132,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[3U]),32);
    bufp->fullIData(oldp+133,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[4U]),32);
    bufp->fullIData(oldp+134,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[5U]),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[6U]),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[7U]),32);
    bufp->fullIData(oldp+137,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[8U]),32);
    bufp->fullIData(oldp+138,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[9U]),32);
    bufp->fullIData(oldp+139,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xaU]),32);
    bufp->fullIData(oldp+140,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xbU]),32);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xcU]),32);
    bufp->fullIData(oldp+142,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xdU]),32);
    bufp->fullIData(oldp+143,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xeU]),32);
    bufp->fullIData(oldp+144,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xfU]),32);
    bufp->fullIData(oldp+145,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x10U]),32);
    bufp->fullIData(oldp+146,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x11U]),32);
    bufp->fullIData(oldp+147,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x12U]),32);
    bufp->fullIData(oldp+148,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x13U]),32);
    bufp->fullIData(oldp+149,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x14U]),32);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x15U]),32);
    bufp->fullIData(oldp+151,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x16U]),32);
    bufp->fullIData(oldp+152,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x17U]),32);
    bufp->fullIData(oldp+153,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x18U]),32);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x19U]),32);
    bufp->fullIData(oldp+155,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1aU]),32);
    bufp->fullIData(oldp+156,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1bU]),32);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1cU]),32);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1dU]),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1eU]),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1fU]),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[0U]),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[1U]),32);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[2U]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[3U]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[4U]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[5U]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[6U]),32);
    bufp->fullIData(oldp+168,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[7U]),32);
    bufp->fullBit(oldp+169,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__pipeline_stall_DE));
    bufp->fullBit(oldp+170,(vlSymsp->TOP__pipeline.__PVT__from_AGEX_to_FE));
    bufp->fullBit(oldp+171,(vlSymsp->TOP__pipeline.__PVT__from_MEM_to_FE));
    bufp->fullBit(oldp+172,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_FE));
    bufp->fullBit(oldp+173,(vlSymsp->TOP__pipeline.__PVT__from_AGEX_to_DE));
    bufp->fullBit(oldp+174,(vlSymsp->TOP__pipeline.__PVT__from_MEM_to_DE));
    bufp->fullBit(oldp+175,(vlSymsp->TOP__pipeline.__PVT__from_MEM_to_AGEX));
    bufp->fullBit(oldp+176,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_AGEX));
    bufp->fullBit(oldp+177,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_MEM));
    bufp->fullCData(oldp+178,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__rd_AGEX),5);
    bufp->fullBit(oldp+179,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__valid_FE));
    bufp->fullIData(oldp+180,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_AGEX),32);
    bufp->fullBit(oldp+181,(1U));
    bufp->fullIData(oldp+182,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__memaddr_MEM),32);
    bufp->fullIData(oldp+183,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__wr_val_MEM),32);
    bufp->fullBit(oldp+184,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__wr_mem_MEM));
}
