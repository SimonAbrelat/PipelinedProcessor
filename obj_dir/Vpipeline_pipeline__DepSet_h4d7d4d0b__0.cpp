// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpipeline__Syms.h"
#include "Vpipeline_pipeline.h"

VL_INLINE_OPT void Vpipeline_pipeline___nba_sequent__TOP__pipeline__0(Vpipeline_pipeline* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpipeline_pipeline___nba_sequent__TOP__pipeline__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__my_FE_stage__DOT__inst_count_FE;
    __Vdly__my_FE_stage__DOT__inst_count_FE = 0;
    SData/*13:0*/ __Vdlyvdim0__my_MEM_stage__DOT__dmem__v0;
    __Vdlyvdim0__my_MEM_stage__DOT__dmem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__my_MEM_stage__DOT__dmem__v0;
    __Vdlyvval__my_MEM_stage__DOT__dmem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__my_MEM_stage__DOT__dmem__v0;
    __Vdlyvset__my_MEM_stage__DOT__dmem__v0 = 0;
    // Body
    __Vdlyvset__my_MEM_stage__DOT__dmem__v0 = 0U;
    __Vdly__my_FE_stage__DOT__inst_count_FE = vlSelf->__PVT__my_FE_stage__DOT__inst_count_FE;
    vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[0U] 
        = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[0U];
    vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[1U] 
        = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[1U];
    vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[2U] 
        = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[2U];
    vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[3U] 
        = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U];
    vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[4U] 
        = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[4U];
    if (vlSelf->__PVT__my_MEM_stage__DOT__wr_mem_MEM) {
        __Vdlyvval__my_MEM_stage__DOT__dmem__v0 = vlSelf->__PVT__my_MEM_stage__DOT__wr_val_MEM;
        __Vdlyvset__my_MEM_stage__DOT__dmem__v0 = 1U;
        __Vdlyvdim0__my_MEM_stage__DOT__dmem__v0 = 
            (0x3fffU & (vlSelf->__PVT__my_MEM_stage__DOT__memaddr_MEM 
                        >> 2U));
    }
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__my_FE_stage__DOT__PC_FE_latch = 0x200U;
        vlSelf->__PVT__cycle_count = 0U;
        __Vdly__my_FE_stage__DOT__inst_count_FE = 1U;
        __Vdly__my_FE_stage__DOT__inst_count_FE = 1U;
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[0U] = 0U;
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[1U] = 0U;
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[2U] = 0U;
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[3U] = 0U;
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[4U] = 0U;
    } else {
        vlSelf->__PVT__my_FE_stage__DOT__PC_FE_latch 
            = vlSelf->__PVT__my_FE_stage__DOT__PC_FE_latch;
        vlSelf->__PVT__cycle_count = ((IData)(1U) + vlSelf->__PVT__cycle_count);
        __Vdly__my_FE_stage__DOT__inst_count_FE = ((IData)(1U) 
                                                   + vlSelf->__PVT__my_FE_stage__DOT__inst_count_FE);
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[0U] 
            = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[0U];
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[1U] 
            = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[1U];
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[2U] 
            = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[2U];
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[3U] 
            = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U];
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[4U] 
            = vlSelf->__PVT__my_FE_stage__DOT__FE_latch[4U];
    }
    if (__Vdlyvset__my_MEM_stage__DOT__dmem__v0) {
        vlSelf->__PVT__my_MEM_stage__DOT__dmem[__Vdlyvdim0__my_MEM_stage__DOT__dmem__v0] 
            = __Vdlyvval__my_MEM_stage__DOT__dmem__v0;
    }
    vlSelf->__PVT__my_FE_stage__DOT__inst_count_FE 
        = __Vdly__my_FE_stage__DOT__inst_count_FE;
}

extern const VlWide<8>/*255:0*/ Vpipeline__ConstPool__CONST_hb86cf0f7_0;

VL_INLINE_OPT void Vpipeline_pipeline___nba_sequent__TOP__pipeline__1(Vpipeline_pipeline* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpipeline_pipeline___nba_sequent__TOP__pipeline__1\n"); );
    // Init
    CData/*0:0*/ my_DE_stage__DOT____VdfgTmp_h244a6343__0;
    my_DE_stage__DOT____VdfgTmp_h244a6343__0 = 0;
    CData/*0:0*/ my_DE_stage__DOT____VdfgTmp_hd10b39db__0;
    my_DE_stage__DOT____VdfgTmp_hd10b39db__0 = 0;
    CData/*0:0*/ my_DE_stage__DOT____VdfgTmp_hc55bbd74__0;
    my_DE_stage__DOT____VdfgTmp_hc55bbd74__0 = 0;
    CData/*0:0*/ my_DE_stage__DOT____VdfgTmp_h203db32e__0;
    my_DE_stage__DOT____VdfgTmp_h203db32e__0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_h3bc8b77b__0;
    // Body
    __Vtemp_h3bc8b77b__0[1U] = (IData)((((QData)((IData)(
                                                         vlSelf->__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((1U 
                                                            == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                            ? 
                                                           (((- (IData)(
                                                                        (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                         >> 0x1fU))) 
                                                             << 0xbU) 
                                                            | (0x7ffU 
                                                               & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                  >> 0x14U)))
                                                            : 
                                                           ((4U 
                                                             == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                             ? 
                                                            (((- (IData)(
                                                                         (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 0x1fU))) 
                                                              << 0xbU) 
                                                             | ((0x7e0U 
                                                                 & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                    >> 0x14U)) 
                                                                | (0x1fU 
                                                                   & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                      >> 7U))))
                                                             : 
                                                            ((5U 
                                                              == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                              ? 
                                                             (((- (IData)(
                                                                          (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 0x1fU))) 
                                                               << 0xcU) 
                                                              | ((0x800U 
                                                                  & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                     << 4U)) 
                                                                 | ((0x7e0U 
                                                                     & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                        >> 0x14U)) 
                                                                    | (0x1eU 
                                                                       & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 7U)))))
                                                              : 
                                                             ((3U 
                                                               == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                               ? 
                                                              (0xfffff000U 
                                                               & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])
                                                               : 
                                                              ((2U 
                                                                == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                                ? 
                                                               (((- (IData)(
                                                                            (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                             >> 0x1fU))) 
                                                                 << 0x14U) 
                                                                | ((0xff000U 
                                                                    & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U]) 
                                                                   | ((0x800U 
                                                                       & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 9U)) 
                                                                      | (0x7feU 
                                                                         & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                            >> 0x14U)))))
                                                                : 0U)))))))));
    __Vtemp_h3bc8b77b__0[2U] = (IData)(((((QData)((IData)(
                                                          vlSelf->__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           ((1U 
                                                             == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                             ? 
                                                            (((- (IData)(
                                                                         (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                          >> 0x1fU))) 
                                                              << 0xbU) 
                                                             | (0x7ffU 
                                                                & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                   >> 0x14U)))
                                                             : 
                                                            ((4U 
                                                              == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                              ? 
                                                             (((- (IData)(
                                                                          (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 0x1fU))) 
                                                               << 0xbU) 
                                                              | ((0x7e0U 
                                                                  & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                     >> 0x14U)) 
                                                                 | (0x1fU 
                                                                    & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                       >> 7U))))
                                                              : 
                                                             ((5U 
                                                               == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                               ? 
                                                              (((- (IData)(
                                                                           (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                            >> 0x1fU))) 
                                                                << 0xcU) 
                                                               | ((0x800U 
                                                                   & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                      << 4U)) 
                                                                  | ((0x7e0U 
                                                                      & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                         >> 0x14U)) 
                                                                     | (0x1eU 
                                                                        & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 7U)))))
                                                               : 
                                                              ((3U 
                                                                == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                                ? 
                                                               (0xfffff000U 
                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])
                                                                : 
                                                               ((2U 
                                                                 == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE))
                                                                 ? 
                                                                (((- (IData)(
                                                                             (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                              >> 0x1fU))) 
                                                                  << 0x14U) 
                                                                 | ((0xff000U 
                                                                     & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U]) 
                                                                    | ((0x800U 
                                                                        & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                           >> 9U)) 
                                                                       | (0x7feU 
                                                                          & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                             >> 0x14U)))))
                                                                 : 0U)))))))) 
                                        >> 0x20U));
    if (vlSymsp->TOP.reset) {
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[0U] = 0U;
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[1U] = 0U;
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[2U] = 0U;
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[3U] = 0U;
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[4U] = 0U;
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] = 0U;
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] = 0U;
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] = 0U;
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] = 0U;
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[0U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[0U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[1U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[1U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[2U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[2U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[3U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[3U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[4U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[5U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[5U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[6U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[6U];
        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[7U] 
            = Vpipeline__ConstPool__CONST_hb86cf0f7_0[7U];
    } else {
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
            = vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[0U];
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
            = vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[1U];
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
            = vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[2U];
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
            = vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[3U];
        vlSelf->__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
            = vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[4U];
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] 
            = (IData)((((QData)((IData)(((1U == (0x3fU 
                                                 & vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U]))
                                          ? (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[1U] 
                                             + vlSelf->__PVT__my_DE_stage__DOT__DE_latch[2U])
                                          : 0U))) << 1U) 
                       | (QData)((IData)((1U == (0x3fU 
                                                 & vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U]))))));
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
            = (((IData)((0x3fffffffffULL & (((QData)((IData)(
                                                             vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->__PVT__my_DE_stage__DOT__DE_latch[3U]))))) 
                << 1U) | (IData)(((((QData)((IData)(
                                                    ((1U 
                                                      == 
                                                      (0x3fU 
                                                       & vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U]))
                                                      ? 
                                                     (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[1U] 
                                                      + 
                                                      vlSelf->__PVT__my_DE_stage__DOT__DE_latch[2U])
                                                      : 0U))) 
                                    << 1U) | (QData)((IData)(
                                                             (1U 
                                                              == 
                                                              (0x3fU 
                                                               & vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U]))))) 
                                  >> 0x20U)));
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
            = ((0xffffff80U & (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[5U] 
                               << 1U)) | (((IData)(
                                                   (0x3fffffffffULL 
                                                    & (((QData)((IData)(
                                                                        vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->__PVT__my_DE_stage__DOT__DE_latch[3U]))))) 
                                           >> 0x1fU) 
                                          | ((IData)(
                                                     ((0x3fffffffffULL 
                                                       & (((QData)((IData)(
                                                                           vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[3U])))) 
                                                      >> 0x20U)) 
                                             << 1U)));
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
            = (((0x7eU & (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[6U] 
                          << 1U)) | (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                     >> 0x1fU)) | (0xffffff80U 
                                                   & (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                                      << 1U)));
        vlSelf->__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
            = (((0x7eU & (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[7U] 
                          << 1U)) | (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                     >> 0x1fU)) | (0x80U 
                                                   & (vlSelf->__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                                      << 1U)));
        if (vlSelf->__PVT__my_DE_stage__DOT__pipeline_stall_DE) {
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[0U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[0U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[1U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[1U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[2U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[2U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[3U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[3U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[4U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[5U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[5U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[6U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[6U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[7U] 
                = Vpipeline__ConstPool__CONST_hb86cf0f7_0[7U];
        } else {
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[0U] 
                = vlSelf->__PVT__my_DE_stage__DOT__regs
                [vlSelf->__PVT__my_DE_stage__DOT__rs2_DE];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[1U] 
                = vlSelf->__PVT__my_DE_stage__DOT__regs
                [vlSelf->__PVT__my_DE_stage__DOT__rs1_DE];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[2U] 
                = __Vtemp_h3bc8b77b__0[1U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[3U] 
                = __Vtemp_h3bc8b77b__0[2U];
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[4U] 
                = ((vlSelf->__PVT__my_FE_stage__DOT__FE_latch[1U] 
                    << 6U) | (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE));
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[5U] 
                = ((vlSelf->__PVT__my_FE_stage__DOT__FE_latch[1U] 
                    >> 0x1aU) | (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[2U] 
                                 << 6U));
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[6U] 
                = ((vlSelf->__PVT__my_FE_stage__DOT__FE_latch[2U] 
                    >> 0x1aU) | (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                 << 6U));
            vlSelf->__PVT__my_DE_stage__DOT__DE_latch[7U] 
                = ((vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                    >> 0x1aU) | (0x40U & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[4U] 
                                          << 6U)));
        }
    }
    vlSelf->__PVT__my_FE_stage__DOT__FE_latch[0U] = 
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[0U];
    vlSelf->__PVT__my_FE_stage__DOT__FE_latch[1U] = 
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[1U];
    vlSelf->__PVT__my_FE_stage__DOT__FE_latch[2U] = 
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[2U];
    vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] = 
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[3U];
    vlSelf->__PVT__my_FE_stage__DOT__FE_latch[4U] = 
        vlSelf->__Vdly__my_FE_stage__DOT__FE_latch[4U];
    my_DE_stage__DOT____VdfgTmp_h244a6343__0 = (IData)(
                                                       (0x33U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])));
    my_DE_stage__DOT____VdfgTmp_hd10b39db__0 = (IData)(
                                                       (0x5033U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])));
    my_DE_stage__DOT____VdfgTmp_hc55bbd74__0 = (IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0xfe007000U 
                                                         & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])));
    my_DE_stage__DOT____VdfgTmp_h203db32e__0 = (IData)(
                                                       (0x5013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])));
    vlSelf->__PVT__my_DE_stage__DOT__op_I_DE = (((IData)(my_DE_stage__DOT____VdfgTmp_h244a6343__0) 
                                                 & (0U 
                                                    == 
                                                    (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                     >> 0x19U)))
                                                 ? 1U
                                                 : 
                                                (((IData)(my_DE_stage__DOT____VdfgTmp_h244a6343__0) 
                                                  & (0x20U 
                                                     == 
                                                     (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 0x19U)))
                                                  ? 2U
                                                  : 
                                                 ((IData)(
                                                          (0x7033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                   ? 3U
                                                   : 
                                                  ((IData)(
                                                           (0x6033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                    ? 4U
                                                    : 
                                                   ((IData)(
                                                            (0x4033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                     ? 5U
                                                     : 
                                                    ((IData)(
                                                             (0x2033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                      ? 6U
                                                      : 
                                                     ((IData)(
                                                              (0x3033U 
                                                               == 
                                                               (0xfe00707fU 
                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                       ? 7U
                                                       : 
                                                      (((IData)(my_DE_stage__DOT____VdfgTmp_hd10b39db__0) 
                                                        & (0x20U 
                                                           == 
                                                           (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                            >> 0x19U)))
                                                        ? 8U
                                                        : 
                                                       (((IData)(my_DE_stage__DOT____VdfgTmp_hd10b39db__0) 
                                                         & (0U 
                                                            == 
                                                            (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                             >> 0x19U)))
                                                         ? 9U
                                                         : 
                                                        (((0x33U 
                                                           == 
                                                           (0x7fU 
                                                            & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])) 
                                                          & (IData)(my_DE_stage__DOT____VdfgTmp_hc55bbd74__0))
                                                          ? 0xaU
                                                          : 
                                                         (((IData)(my_DE_stage__DOT____VdfgTmp_h244a6343__0) 
                                                           & (1U 
                                                              == 
                                                              (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                               >> 0x19U)))
                                                           ? 0xbU
                                                           : 
                                                          ((IData)(
                                                                   (0x13U 
                                                                    == 
                                                                    (0x707fU 
                                                                     & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                            ? 0xcU
                                                            : 
                                                           ((IData)(
                                                                    (0x7013U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                             ? 0xdU
                                                             : 
                                                            ((IData)(
                                                                     (0x6013U 
                                                                      == 
                                                                      (0x707fU 
                                                                       & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                              ? 0xeU
                                                              : 
                                                             ((IData)(
                                                                      (0x4013U 
                                                                       == 
                                                                       (0x707fU 
                                                                        & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                               ? 0xfU
                                                               : 
                                                              ((IData)(
                                                                       (0x2013U 
                                                                        == 
                                                                        (0x707fU 
                                                                         & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                ? 0x10U
                                                                : 
                                                               ((IData)(
                                                                        (0x3013U 
                                                                         == 
                                                                         (0x707fU 
                                                                          & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                 ? 0x11U
                                                                 : 
                                                                (((IData)(my_DE_stage__DOT____VdfgTmp_h203db32e__0) 
                                                                  & (0x20U 
                                                                     == 
                                                                     (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                      >> 0x19U)))
                                                                  ? 0x12U
                                                                  : 
                                                                 (((IData)(my_DE_stage__DOT____VdfgTmp_h203db32e__0) 
                                                                   & (0U 
                                                                      == 
                                                                      (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                       >> 0x19U)))
                                                                   ? 0x13U
                                                                   : 
                                                                  (((0x13U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])) 
                                                                    & (IData)(my_DE_stage__DOT____VdfgTmp_hc55bbd74__0))
                                                                    ? 0x14U
                                                                    : 
                                                                   ((0x37U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U]))
                                                                     ? 0x15U
                                                                     : 
                                                                    ((0x17U 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U]))
                                                                      ? 0x16U
                                                                      : 
                                                                     ((IData)(
                                                                              (0x2003U 
                                                                               == 
                                                                               (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                       ? 0x17U
                                                                       : 
                                                                      ((IData)(
                                                                               (0x2023U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                        ? 0x18U
                                                                        : 
                                                                       ((0x6fU 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U]))
                                                                         ? 0x19U
                                                                         : 
                                                                        ((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                          ? 0x1bU
                                                                          : 
                                                                         ((IData)(
                                                                                (0x63U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                           ? 0x1cU
                                                                           : 
                                                                          ((IData)(
                                                                                (0x1063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                            ? 0x1dU
                                                                            : 
                                                                           ((IData)(
                                                                                (0x4063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                             ? 0x1eU
                                                                             : 
                                                                            ((IData)(
                                                                                (0x5063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                              ? 0x1fU
                                                                              : 
                                                                             ((IData)(
                                                                                (0x6063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                               ? 0x20U
                                                                               : 
                                                                              ((IData)(
                                                                                (0x7063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                                ? 0x21U
                                                                                : 
                                                                               ((IData)(
                                                                                (0x2073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                                 ? 0x22U
                                                                                 : 
                                                                                ((IData)(
                                                                                (0x1073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U])))
                                                                                 ? 0x23U
                                                                                 : 0x25U))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE 
        = vlSelf->my_DE_stage__DOT____Vxrand_h9b4a7c25__0;
    if ((1U & (~ (((((((((((1U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                           | (2U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                          | (3U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                         | (4U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                        | (5U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                       | (6U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                      | (7U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                     | (8U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                    | (9U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                   | (0xaU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                  | (0xbU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))))) {
        if ((((((((((((0x22U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                      | (0x23U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                     | (0xcU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                    | (0xdU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                   | (0xeU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                  | (0xfU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                 | (0x10U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                | (0x11U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
               | (0x17U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
              | (0x1aU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
             | (0x1bU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
            vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE = 1U;
        } else if ((((0x12U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                     | (0x13U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                    | (0x14U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
            vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE = 1U;
        } else if (((0x15U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                    | (0x16U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
            vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE = 3U;
        } else if ((0x18U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) {
            vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE = 4U;
        } else if ((0x19U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) {
            vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE = 2U;
        } else if (((((((0x1cU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                        | (0x1dU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                       | (0x1eU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                      | (0x1fU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                     | (0x20U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                    | (0x21U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
            vlSelf->__PVT__my_DE_stage__DOT__type_immediate_DE = 5U;
        }
    }
    vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = vlSelf->my_DE_stage__DOT____Vxrand_h9b4aadca__0;
    if ((((((((((((1U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                  | (2U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                 | (3U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                | (4U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
               | (5U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
              | (6U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
             | (7U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
            | (8U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
           | (9U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
          | (0xaU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
         | (0xbU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 1U;
    } else if ((((((((((((0x22U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                         | (0x23U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                        | (0xcU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                       | (0xdU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                      | (0xeU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                     | (0xfU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                    | (0x10U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                   | (0x11U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                  | (0x17U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                 | (0x1aU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                | (0x1bU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 2U;
    } else if ((((0x12U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                 | (0x13U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                | (0x14U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 2U;
    } else if (((0x15U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                | (0x16U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 2U;
    } else if ((0x18U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 3U;
    } else if ((0x19U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 4U;
    } else if (((((((0x1cU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)) 
                    | (0x1dU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                   | (0x1eU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                  | (0x1fU == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                 | (0x20U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE))) 
                | (0x21U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__op_I_DE)))) {
        vlSelf->__PVT__my_DE_stage__DOT__type_I_DE = 3U;
    }
    vlSelf->__PVT__my_DE_stage__DOT__rs1_DE = 0U;
    vlSelf->__PVT__my_DE_stage__DOT__rs2_DE = 0U;
    if ((1U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_I_DE))) {
        vlSelf->__PVT__my_DE_stage__DOT__rs1_DE = (0x1fU 
                                                   & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 0xfU));
        vlSelf->__PVT__my_DE_stage__DOT__rs2_DE = (0x1fU 
                                                   & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 0x14U));
    } else {
        if ((2U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_I_DE))) {
            vlSelf->__PVT__my_DE_stage__DOT__rs1_DE 
                = (0x1fU & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                            >> 0xfU));
        } else if ((3U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_I_DE))) {
            vlSelf->__PVT__my_DE_stage__DOT__rs1_DE 
                = (0x1fU & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                            >> 0xfU));
        }
        if ((2U != (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_I_DE))) {
            if ((3U == (IData)(vlSelf->__PVT__my_DE_stage__DOT__type_I_DE))) {
                vlSelf->__PVT__my_DE_stage__DOT__rs2_DE 
                    = (0x1fU & (vlSelf->__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                >> 0x14U));
            }
        }
    }
}

VL_INLINE_OPT void Vpipeline_pipeline___nba_sequent__TOP__pipeline__2(Vpipeline_pipeline* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpipeline_pipeline___nba_sequent__TOP__pipeline__2\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__my_DE_stage__DOT__regs__v0;
    __Vdlyvset__my_DE_stage__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__my_DE_stage__DOT__regs__v32;
    __Vdlyvdim0__my_DE_stage__DOT__regs__v32 = 0;
    IData/*31:0*/ __Vdlyvval__my_DE_stage__DOT__regs__v32;
    __Vdlyvval__my_DE_stage__DOT__regs__v32 = 0;
    CData/*0:0*/ __Vdlyvset__my_DE_stage__DOT__regs__v32;
    __Vdlyvset__my_DE_stage__DOT__regs__v32 = 0;
    // Body
    __Vdlyvset__my_DE_stage__DOT__regs__v0 = 0U;
    __Vdlyvset__my_DE_stage__DOT__regs__v32 = 0U;
    if (vlSymsp->TOP.reset) {
        __Vdlyvset__my_DE_stage__DOT__regs__v0 = 1U;
    } else if ((1U & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                              >> 0x25U)))) {
        __Vdlyvval__my_DE_stage__DOT__regs__v32 = (IData)(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE);
        __Vdlyvset__my_DE_stage__DOT__regs__v32 = 1U;
        __Vdlyvdim0__my_DE_stage__DOT__regs__v32 = 
            (0x1fU & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                              >> 0x20U)));
    }
    if (__Vdlyvset__my_DE_stage__DOT__regs__v0) {
        vlSelf->__PVT__my_DE_stage__DOT__regs[0U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[1U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[2U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[3U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[4U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[5U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[6U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[7U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[8U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[9U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0xaU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0xbU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0xcU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0xdU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0xeU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0xfU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x10U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x11U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x12U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x13U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x14U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x15U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x16U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x17U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x18U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x19U] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x1aU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x1bU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x1cU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x1dU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x1eU] = 0U;
        vlSelf->__PVT__my_DE_stage__DOT__regs[0x1fU] = 0U;
    }
    if (__Vdlyvset__my_DE_stage__DOT__regs__v32) {
        vlSelf->__PVT__my_DE_stage__DOT__regs[__Vdlyvdim0__my_DE_stage__DOT__regs__v32] 
            = __Vdlyvval__my_DE_stage__DOT__regs__v32;
    }
}