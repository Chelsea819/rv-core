// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060025_top.h for the primary calling header

#include "Vysyx_23060025_top__pch.h"
#include "Vysyx_23060025_top__Syms.h"
#include "Vysyx_23060025_top___024root.h"

extern "C" void ifebreak_func(int inst);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ifebreak_func_TOP(IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ifebreak_func_TOP\n"); );
    // Body
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    ifebreak_func(inst__Vcvt);
}

extern "C" void resp_check(char resp);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__resp_check_TOP(CData/*7:0*/ resp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__resp_check_TOP\n"); );
    // Body
    char resp__Vcvt;
    for (size_t resp__Vidx = 0; resp__Vidx < 1; ++resp__Vidx) resp__Vcvt = resp;
    resp_check(resp__Vcvt);
}

extern "C" void inst_get(int inst);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_get_TOP(IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_get_TOP\n"); );
    // Body
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    inst_get(inst__Vcvt);
}

extern "C" void inst_invalid_get(char invalid);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__inst_invalid_get_TOP(CData/*7:0*/ invalid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__inst_invalid_get_TOP\n"); );
    // Body
    char invalid__Vcvt;
    for (size_t invalid__Vidx = 0; invalid__Vidx < 1; ++invalid__Vidx) invalid__Vcvt = invalid;
    inst_invalid_get(invalid__Vcvt);
}

extern "C" void ifu_p_counter_update();

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__ifu_p_counter_update_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__ifu_p_counter_update_TOP\n"); );
    // Body
    ifu_p_counter_update();
}

extern "C" void pc_get(int pc, int dnpc);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_get_TOP(IData/*31:0*/ pc, IData/*31:0*/ dnpc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_get_TOP\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int dnpc__Vcvt;
    for (size_t dnpc__Vidx = 0; dnpc__Vidx < 1; ++dnpc__Vidx) dnpc__Vcvt = dnpc;
    pc_get(pc__Vcvt, dnpc__Vcvt);
}

extern "C" void idu_p_counter_update(char opcode, char func3);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__idu_p_counter_update_TOP(CData/*7:0*/ opcode, CData/*7:0*/ func3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__idu_p_counter_update_TOP\n"); );
    // Body
    char opcode__Vcvt;
    for (size_t opcode__Vidx = 0; opcode__Vidx < 1; ++opcode__Vidx) opcode__Vcvt = opcode;
    char func3__Vcvt;
    for (size_t func3__Vidx = 0; func3__Vidx < 1; ++func3__Vidx) func3__Vcvt = func3;
    idu_p_counter_update(opcode__Vcvt, func3__Vcvt);
}

extern "C" void exu_p_counter_update();

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__exu_p_counter_update_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__exu_p_counter_update_TOP\n"); );
    // Body
    exu_p_counter_update();
}

extern "C" void lsu_p_counter_update();

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_p_counter_update_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_p_counter_update_TOP\n"); );
    // Body
    lsu_p_counter_update();
}

extern "C" void lsu_delay_counter_update();

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_delay_counter_update_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_delay_counter_update_TOP\n"); );
    // Body
    lsu_delay_counter_update();
}

extern "C" void finish_get(char finish);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__finish_get_TOP(CData/*7:0*/ finish) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__finish_get_TOP\n"); );
    // Body
    char finish__Vcvt;
    for (size_t finish__Vidx = 0; finish__Vidx < 1; ++finish__Vidx) finish__Vcvt = finish;
    finish_get(finish__Vcvt);
}

extern "C" void diff_skip();

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__diff_skip_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__diff_skip_TOP\n"); );
    // Body
    diff_skip();
}

extern "C" int pmem_read_task(int raddr, char wmask);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ raddr, CData/*7:0*/ wmask, IData/*31:0*/ &pmem_read_task__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    int pmem_read_task__Vfuncrtn__Vcvt;
    pmem_read_task__Vfuncrtn__Vcvt = pmem_read_task(raddr__Vcvt, wmask__Vcvt);
    pmem_read_task__Vfuncrtn = pmem_read_task__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write_task(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_write_task_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_write_task_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write_task(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060025_top___024root___dump_triggers__ico(Vysyx_23060025_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_23060025_top___024root___eval_triggers__ico(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
    vlSelfRef.__VicoTriggered.set(1U, ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state) 
                                       != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state__1)));
    vlSelfRef.__Vtrigprevexpr___TOP__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state__1 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.__VicoDidInit))))) {
        vlSelfRef.__VicoDidInit = 1U;
        vlSelfRef.__VicoTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_23060025_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060025_top___024root___dump_triggers__act(Vysyx_23060025_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_23060025_top___024root___eval_triggers__act(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state) 
                                       != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state__2)));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.clock) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state__2 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state;
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.__VactDidInit))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.set(0U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_23060025_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vysyx_23060025_top___024root___nba_sequent__TOP__0(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task__13__Vfuncout;
    __Vfunc_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task__13__Vfuncout = 0;
    IData/*31:0*/ __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0;
    __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0;
    __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1;
    __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1 = 0;
    CData/*0:0*/ __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1 = 0;
    CData/*0:0*/ __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v0;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v0 = 0;
    IData/*31:0*/ __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3;
    __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 = 0;
    CData/*2:0*/ __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3;
    __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 = 0;
    CData/*0:0*/ __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 = 0;
    IData/*31:0*/ __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4;
    __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4 = 0;
    CData/*0:0*/ __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4 = 0;
    IData/*31:0*/ __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v5;
    __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v5 = 0;
    VlWide<9>/*287:0*/ __Vtemp_58;
    // Body
    if (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_wen) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_write_task_TOP(
                                                                                (0xfffffffcU 
                                                                                & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o), vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata, (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o));
    }
    if ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__con_state))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__exu_p_counter_update_TOP();
    }
    if ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__ifu_p_counter_update_TOP();
    }
    if ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_p_counter_update_TOP();
    }
    if ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_delay_counter_update_TOP();
    }
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v0 = 0U;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 = 0U;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4 = 0U;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 = 0U;
    __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1 = 0U;
    if (((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__con_state)) 
         & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__next_state)))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__idu_p_counter_update_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode, (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3));
    }
    if (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i) 
         & (0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i)))) {
        __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 
            = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i 
               & (~ (- (IData)((IData)(vlSelfRef.reset)))));
        __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 
            = (0xfU & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i));
        __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0 = 1U;
    } else if (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i) 
                & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i)))) {
        __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1 
            = (0xfU & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i));
        __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1 = 1U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__exu_valid_o 
        = (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__next_state));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__idu_valid_o 
        = (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__next_state));
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime = 0ULL;
        __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v0 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__con_state = 0U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime 
            = (1ULL + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime);
        if ((1U & VL_REDXOR_4(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT____Vlvbound_h606fd410__0 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i;
            if ((5U >= (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_idx))) {
                __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT____Vlvbound_h606fd410__0;
                __VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_idx;
                __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3 = 1U;
            }
        } else if ((6U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i))) {
            __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_mcause_i;
            __VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4 = 1U;
            __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v5 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_mepc_i;
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state;
    }
    if (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_ren) 
         & (~ (IData)(vlSelfRef.reset)))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task_TOP(
                                                                                (&(vlSymsp->__Vscope_ysyx_23060025_top__u_ysyx_23060025_AXI_SRAM__u_ysyx_23060025_SRAM)), 
                                                                                "/home/chelsea/ysyx-workbench/npc-rare/vsrc/ysyx_23060025_SRAM.v", 0x1cU, 
                                                                                (0xfffffffcU 
                                                                                & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o), 
                                                                                (0xffU 
                                                                                & (- (IData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_ren)))), __Vfunc_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task__13__Vfuncout);
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data 
            = __Vfunc_ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__pmem_read_task__13__Vfuncout;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_device_tmp 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device));
    if ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))) {
        if ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i;
        }
        if ((1U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
            if ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i;
            }
        }
    }
    if (((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__next_state)) 
         & (3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state)))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__aligned_store_reg 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__aligned_store;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_unaligned 
            = (3U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i);
    }
    if (__VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf[__VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0] 
            = __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v0;
    }
    if (__VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf[__VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf__v1] = 0U;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_data_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_target_reg = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i = 0U;
    } else {
        if (((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state)) 
             & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__next_state)))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_data_i 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_data;
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state;
        if (((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state)) 
             & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state)))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_target_reg 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i;
        }
        if ((6U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr
                [3U];
        } else if ((5U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr
                [2U];
        }
    }
    if (__VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v0) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[1U] = 0x1800U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[4U] = 0x79737978U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[5U] = 0x15fde39U;
    }
    if (__VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[__VdlyDim0__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3] 
            = __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v3;
    }
    if (__VdlySet__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[0U] 
            = __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v4;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[2U] 
            = __VdlyVal__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr__v5;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_rdata_usigned_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid 
        = ((~ (IData)(vlSelfRef.reset)) & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid 
        = ((~ (IData)(vlSelfRef.reset)) & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_awready 
        = ((~ (IData)(vlSelfRef.reset)) & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__jmp_target_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_target_reg;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_pc_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__csr_pc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned 
        = ((1U & ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__aligned_store_reg)) 
                  | (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_unaligned))))
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i
            : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_unaligned))
                ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i, 8U)
                : ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_unaligned))
                    ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i, 0x10U)
                    : ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_unaligned))
                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_data_i, 0x18U)
                        : 0U))));
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i = 0x80000000U;
    } else if (((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state)) 
                & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_next;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i 
        = (3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__pc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_pc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_mepc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i;
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__con_state = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__con_state = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4 = 0x80000000U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state = 0U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__next_state;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__next_state;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__next_state;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__next_state;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4 
            = ((IData)(4U) + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i);
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state;
    }
    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ifebreak_func_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst);
    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_get_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                                            [(0xfU 
                                              & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                 >> 0xfU))])));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                                            [(0xfU 
                                              & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                 >> 0x14U))])));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                                            [(0xfU 
                                              & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                 >> 0xfU))])));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_raddr1_i 
        = (0x1fU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                    >> 0xfU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_raddr2_i 
        = (0x1fU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                    >> 0x14U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_reg1_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0xfU))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_reg2_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0x14U))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_reg1_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0xfU))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_reg2_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0x14U))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[1U] 
        = (0x1700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[2U] 
        = (0x3700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_inst_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0xfU))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0x14U))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0x14U))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                  >> 0xfU))];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[1U] 
        = (0xfffff000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[2U] 
        = (0xfffff000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_48 = (((- (IData)(
                                                             (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0x800U 
                                                     & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                        << 4U)) 
                                                    | ((0x7e0U 
                                                        & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                           >> 0x14U)) 
                                                       | (0x1eU 
                                                          & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                             >> 7U)))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_19 = (((- (IData)(
                                                             (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0x14U) 
                                                 | (((0xff000U 
                                                      & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                                     | (0x800U 
                                                        & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                           >> 9U))) 
                                                    | (0x7feU 
                                                       & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                          >> 0x14U))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i 
        = (0x1fU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                    >> 7U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func7 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
           >> 0x19U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3 
        = (7U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                 >> 0xcU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode 
        = (0x7fU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
           >> 0x14U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__bkwd_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_arready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_rare_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__r_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__csr_pc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__csr_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_pcPlus__DOT__pc_old 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__pc_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__pc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_pc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__pc_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_mepc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_mepc_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_mepc_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_plus_4 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_pcPlus__DOT__pc_new 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__inst_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rsc1 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_raddr1_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reg1_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_raddr1_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rsc2 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_raddr2_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reg2_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_raddr2_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__r_data1 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_reg1_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reg1_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_reg1_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__r_data2 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_reg2_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reg2_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_reg2_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reg1_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_reg1_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__reg1_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_reg1_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reg2_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_reg2_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__reg2_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_reg2_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__id_inst_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_inst_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__inst_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_inst_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__mem_wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[3U] 
        = (0x6300000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_48)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_48;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[0U] 
        = (0x6f00000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_19)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_19;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__wreg_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__wreg_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_wreg_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_wreg_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i;
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_47 = (((- (IData)(
                                                             (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func7) 
                                                     << 5U) 
                                                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_5 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
           | (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_6 
        = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3) 
            << 7U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func7));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13 
        = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode) 
            << 3U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__csr_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_addr 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0U] 
        = (IData)((0x6f00000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_19))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[1U] 
        = ((0xfff80000U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                           << 7U)) | (IData)(((0x6f00000000ULL 
                                               | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_19))) 
                                              >> 0x20U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[2U] 
        = (0xb80U | ((0xfc000000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[2U]) 
                     | (0x7ffffU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                    >> 0x19U))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[2U] 
        = ((0x3ffffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[2U]) 
           | (0xfc000000U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                             << 0xeU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[3U] 
        = ((0xffffc000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[3U]) 
           | (0x3ffffffU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                            >> 0x12U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[3U] 
        = ((0x3fffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[3U]) 
           | (0xffffc000U & (0xdc000U | ((0xfc000000U 
                                          & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                             << 1U)) 
                                         | (0x3c00000U 
                                            & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                               << 0xeU))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[4U] 
        = ((0xffe00000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[4U]) 
           | ((0x1ffffeU & ((- (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                        >> 0x1fU))) 
                            << 1U)) | (1U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                             >> 7U))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[4U] 
        = ((0x1fffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[4U]) 
           | ((IData)((((QData)((IData)((0xfffffU & 
                                         (- (IData)(
                                                    (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                     >> 0x1fU)))))) 
                        << 0x13U) | (QData)((IData)(
                                                    (0x63U 
                                                     | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func7) 
                                                         << 0xcU) 
                                                        | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i) 
                                                           << 7U))))))) 
              << 0x15U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[5U] 
        = ((0xf0000000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[5U]) 
           | (((IData)((((QData)((IData)((0xfffffU 
                                          & (- (IData)(
                                                       (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                        >> 0x1fU)))))) 
                         << 0x13U) | (QData)((IData)(
                                                     (0x63U 
                                                      | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func7) 
                                                          << 0xcU) 
                                                         | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i) 
                                                            << 7U))))))) 
               >> 0xbU) | ((IData)(((((QData)((IData)(
                                                      (0xfffffU 
                                                       & (- (IData)(
                                                                    (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                     >> 0x1fU)))))) 
                                      << 0x13U) | (QData)((IData)(
                                                                  (0x63U 
                                                                   | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func7) 
                                                                       << 0xcU) 
                                                                      | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wreg_i) 
                                                                         << 7U)))))) 
                                    >> 0x20U)) << 0x15U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[5U] 
        = ((0xfffffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[5U]) 
           | ((IData)((0x23ULL | ((QData)((IData)((
                                                   ((- (IData)(
                                                               (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                  << 7U))) << 0x1cU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[6U] 
        = (((IData)((0x23ULL | ((QData)((IData)((((- (IData)(
                                                             (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                << 7U))) >> 4U) | ((IData)(
                                                           ((0x23ULL 
                                                             | ((QData)((IData)(
                                                                                (((- (IData)(
                                                                                (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                                >> 0x1fU))) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                                                << 7U)) 
                                                            >> 0x20U)) 
                                                   << 0x1cU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[7U] 
        = ((0xfffffff8U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[7U]) 
           | ((IData)(((0x23ULL | ((QData)((IData)(
                                                   (((- (IData)(
                                                                (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                   << 7U)) >> 0x20U)) 
              >> 4U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[7U] 
        = ((7U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[7U]) 
           | ((IData)((0x67ULL | ((QData)((IData)((
                                                   ((- (IData)(
                                                               (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                  << 7U))) << 3U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[8U] 
        = ((0xfffffc00U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[8U]) 
           | (((IData)((0x67ULL | ((QData)((IData)(
                                                   (((- (IData)(
                                                                (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                   << 7U))) >> 0x1dU) 
              | ((IData)(((0x67ULL | ((QData)((IData)(
                                                      (((- (IData)(
                                                                   (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                      << 7U)) >> 0x20U)) 
                 << 3U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[8U] 
        = ((0x3ffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[8U]) 
           | ((IData)((0x73ULL | ((QData)((IData)((
                                                   ((- (IData)(
                                                               (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                  << 7U))) << 0xaU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[9U] 
        = ((0xfffe0000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[9U]) 
           | (((IData)((0x73ULL | ((QData)((IData)(
                                                   (((- (IData)(
                                                                (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                   << 7U))) >> 0x16U) 
              | ((IData)(((0x73ULL | ((QData)((IData)(
                                                      (((- (IData)(
                                                                   (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                      << 7U)) >> 0x20U)) 
                 << 0xaU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[9U] 
        = ((0x1ffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[9U]) 
           | ((IData)((3ULL | ((QData)((IData)((((- (IData)(
                                                            (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                               << 7U))) << 0x11U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xaU] 
        = ((0xff000000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xaU]) 
           | (((IData)((3ULL | ((QData)((IData)((((- (IData)(
                                                             (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                << 7U))) >> 0xfU) | 
              ((IData)(((3ULL | ((QData)((IData)(((
                                                   (- (IData)(
                                                              (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                               >> 0x1fU))) 
                                                   << 0xcU) 
                                                  | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i)))) 
                                 << 7U)) >> 0x20U)) 
               << 0x11U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xaU] 
        = (0x13000000U | (0xffffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xaU]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xbU] = 0x80000000U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xcU] = 0x19U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_idx 
        = ((0x342U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i))
            ? 0U : ((0x300U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i))
                     ? 1U : ((0x341U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i))
                              ? 2U : ((0x305U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i))
                                       ? 3U : ((0xf11U 
                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i))
                                                ? 4U
                                                : (
                                                   (0xf12U 
                                                    == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i))
                                                    ? 5U
                                                    : 3U))))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_46 = (((- (IData)(
                                                             (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_addr_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i 
        = ((~ (IData)(vlSelfRef.reset)) & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i 
        = ((~ (IData)(vlSelfRef.reset)) & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_bkwd_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_valid_o 
        = (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o 
        = (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data 
        = ((IData)(vlSelfRef.reset) ? 0U : ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
                                             ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wdata_i
                                             : 0U));
    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__finish_get_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__finish 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__last_finish 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__con_state 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o 
        = (3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o 
        = ((~ (IData)(vlSelfRef.reset)) & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__inst 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__inst_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__wreg_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__wreg_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__wreg_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wreg_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_wreg_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[4U] 
        = (0x2300000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_47)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[4U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_47;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_7 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
           | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_5));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0 
        = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode) 
            << 0xaU) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_6));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[1U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[2U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[3U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[3U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[4U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[4U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[5U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[5U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[6U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[6U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[7U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[7U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[8U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[8U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[9U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[9U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[0xaU] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xaU];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[0xbU] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xbU];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut[0xcU] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__lut[0xcU];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i 
        = ((5U >= (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_idx))
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr
           [vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_idx]
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[5U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_46)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[6U] 
        = (0x7300000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_46)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[7U] 
        = (0x300000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_46)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__pair_list[8U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_46)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_46;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[6U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_46;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[7U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_46;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list[8U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_46;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i 
        = (3U & (- (IData)((1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__lsu_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__lsu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o 
        = ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__last_finish 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__last_finish;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__inst_invalid 
        = (1U & (~ ((0x37U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                    | ((0x17U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                       | ((0x6fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                          | ((0x67U == (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3) 
                                         << 7U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode))) 
                             | ((0x63U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                | (((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                    & ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_7) 
                                       | ((4U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                          | (5U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3))))) 
                                   | (((0x73U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                       & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_5)) 
                                      | (((0x23U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                          & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_7)) 
                                         | (((0x13U 
                                              == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                             & ((2U 
                                                 == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                                | ((3U 
                                                    == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                                   | ((0U 
                                                       == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                                      | ((4U 
                                                          == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                                         | ((6U 
                                                             == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                                            | ((7U 
                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3)) 
                                                               | ((0x80U 
                                                                   == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_6)) 
                                                                  | ((0x280U 
                                                                      == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_6)) 
                                                                     | (0x2a0U 
                                                                        == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT____VdfgRegularize_he8bcb7c1_1_6))))))))))) 
                                            | ((0x33U 
                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                               | ((0x73U 
                                                   == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                                  | ((0x30200073U 
                                                      == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                                     | (0x100073U 
                                                        == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst)))))))))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__key;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_rdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__r_data 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__pair_list[0U] 
        = (0x300000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[0U] 
        = (IData)((0x300000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[1U] 
        = ((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i 
            << 2U) | (IData)(((0x300000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i))) 
                              >> 0x20U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[2U] 
        = (8U | ((0xfffffff0U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[2U]) 
                 | (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i 
                    >> 0x1eU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[2U] 
        = ((0xfU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[2U]) 
           | (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
              [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                        >> 0xfU))] << 4U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[3U] 
        = (0x10U | (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                    [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                              >> 0xfU))] >> 0x1cU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[4U] = 0U;
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_10 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i 
                                                 | vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                                                 [(0xfU 
                                                   & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                      >> 0xfU))]);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_rdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [0U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [1U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [2U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [3U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [4U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [4U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [4U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [5U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [5U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [5U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [6U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [6U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [6U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [7U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [7U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [7U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [8U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [8U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [8U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
                          [9U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__data_list
              [9U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__opcode) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__key_list
              [9U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__hit)
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__lut_out
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_bkwd_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_valid_o;
    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__inst_invalid_get_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__inst_invalid);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[0U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[1U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[2U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut[3U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[3U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut[4U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__lut[4U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__pair_list[0U] 
        = (0x200000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_10)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[0U] 
        = (IData)((0x200000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_10))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[1U] 
        = ((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
            [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                      >> 0xfU))] << 3U) | (IData)((
                                                   (0x200000000ULL 
                                                    | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_10))) 
                                                   >> 0x20U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[2U] 
        = ((0x38U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[2U]) 
           | (0x3fU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                       [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                 >> 0xfU))] >> 0x1dU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[2U] 
        = (8U | (7U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_10;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__imm_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[0U] = 4U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[1U] 
        = (3U | (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i 
                 << 2U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[2U] 
        = (8U | ((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                  [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                            >> 0x14U))] << 4U) | (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i 
                                                  >> 0x1eU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[3U] 
        = ((0xfffffff0U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[3U]) 
           | (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
              [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                        >> 0x14U))] >> 0x1cU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[3U] 
        = (0x10U | (0xfU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[4U] = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__imm_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_target_i 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i 
           + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23 
        = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode) 
            << 0xaU) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__func3) 
                         << 7U) | (0x7fU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i 
                                            >> 5U))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[0U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[1U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__lut[2U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[0U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[1U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[2U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut[3U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[3U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut[4U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__lut[4U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__imm_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__branch_target_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_target_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__branch_target_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_target_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44 
        = ((0x338U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))
            ? (8ULL | ((QData)((IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_imm_i 
                                        + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf
                                        [(0xfU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst 
                                                  >> 0xfU))]))) 
                       << 4U)) : ((0x6fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode))
                                   ? (8ULL | ((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_target_i)) 
                                              << 4U))
                                   : ((0x73U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst)
                                       ? 6ULL : ((0x30200073U 
                                                  == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst)
                                                  ? 5ULL
                                                  : 
                                                 ((0x399U 
                                                   == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))
                                                   ? 1ULL
                                                   : 
                                                  ((0x39aU 
                                                    == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))
                                                    ? 2ULL
                                                    : 0ULL))))));
    if ((0xcc00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcc20U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xce00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 2U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcf00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcf80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 4U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcc80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 7U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xce80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcea0U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 6U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcd00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 8U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0xcd80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
    } else if ((0x73U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 0U;
    } else if ((0x30200073U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 0U;
    } else if ((0x399U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 0U;
    } else if ((0x39aU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 0U;
    } else if ((0x98U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x9cU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 2U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x9eU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x9fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 4U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x9aU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 8U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x9bU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x338U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 0xeU;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 2U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 3U;
    } else if ((0x4c80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 7U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x4e80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x4ea0U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23)) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 6U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x118U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x119U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else if ((0x11aU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 2U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
    } else {
        if ((0x18U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 3U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
        } else if ((0x19U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 1U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
        } else if ((0x1aU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 2U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
        } else if ((0x1cU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 7U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
        } else if ((0x1dU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 9U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 5U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
        } else {
            if ((0x6fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 0xeU;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 2U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 3U;
            } else if ((0x318U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
            } else if ((0x319U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
            } else if ((0x31cU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 8U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
            } else if ((0x31dU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 8U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
            } else if ((0x31eU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 9U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
            } else if ((0x31fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 5U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 9U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 1U;
            } else {
                if ((0x17U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode))) {
                    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 0xaU;
                    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 2U;
                    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
                } else {
                    if ((0x37U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode))) {
                        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 8U;
                        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 2U;
                    } else {
                        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i = 0U;
                        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2 = 0U;
                    }
                    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2 = 0U;
                }
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i = 0U;
            }
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i = 0U;
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wd_i 
        = ((0xcc00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
           | ((0xcc20U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
              | ((0xce00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                 | ((0xcf00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                    | ((0xcf80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                       | ((0xcc80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                          | ((0xce80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                             | ((0xcea0U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                | ((0xcd00U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                   | ((0xcd80U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                      | ((0x73U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                         & ((0x30200073U 
                                             != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                            & ((0x399U 
                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                               | ((0x39aU 
                                                   == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                  | ((0x98U 
                                                      == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                     | ((0x9cU 
                                                         == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                        | ((0x9eU 
                                                            == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                           | ((0x9fU 
                                                               == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                              | ((0x9aU 
                                                                  == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                 | ((0x9bU 
                                                                     == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                    | ((0x338U 
                                                                        == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                       | ((0x4c80U 
                                                                           == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                          | ((0x4e80U 
                                                                              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                             | ((0x4ea0U 
                                                                                == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                                | ((0x118U 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x119U 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x11aU 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x18U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x19U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x1aU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x1cU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x1dU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x6fU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                                                                | ((0x318U 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x319U 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x31cU 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x31dU 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x31eU 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x31fU 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x17U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode)) 
                                                                                | (0x37U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__opcode))))))))))))))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg 
        = ((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state)) 
           & ((0xcc00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
              & ((0xcc20U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                 & ((0xce00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                    & ((0xcf00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                       & ((0xcf80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                          & ((0xcc80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                             & ((0xce80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                & ((0xcea0U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                   & ((0xcd00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                      & ((0xcd80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                         & ((0x73U 
                                             != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                            & ((0x30200073U 
                                                != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                               & ((0x399U 
                                                   != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                  & ((0x39aU 
                                                      != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                     & ((0x98U 
                                                         != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                        & ((0x9cU 
                                                            != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                           & ((0x9eU 
                                                               != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                              & ((0x9fU 
                                                                  != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                 & ((0x9aU 
                                                                     != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                    & ((0x9bU 
                                                                        != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                       & ((0x338U 
                                                                           != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                          & ((0x4c80U 
                                                                              != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                             & ((0x4e80U 
                                                                                != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                                & ((0x4ea0U 
                                                                                != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                                & ((0x118U 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x119U 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x11aU 
                                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                & ((0x18U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x19U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x1aU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x1cU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | (0x1dU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))))))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i 
        = ((0xcc00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
           & ((0xcc20U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
              & ((0xce00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                 & ((0xcf00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                    & ((0xcf80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                       & ((0xcc80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                          & ((0xce80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                             & ((0xcea0U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                & ((0xcd00U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                   & ((0xcd80U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_0) 
                                      & ((0x73U != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                         & ((0x30200073U 
                                             != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst) 
                                            & ((0x399U 
                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                               & ((0x39aU 
                                                   != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                  & ((0x98U 
                                                      != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                     & ((0x9cU 
                                                         != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                        & ((0x9eU 
                                                            != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                           & ((0x9fU 
                                                               != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                              & ((0x9aU 
                                                                  != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                 & ((0x9bU 
                                                                     != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                    & ((0x338U 
                                                                        != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                       & ((0x4c80U 
                                                                           != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                          & ((0x4e80U 
                                                                              != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                             & ((0x4ea0U 
                                                                                != vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_23) 
                                                                                & ((0x118U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | ((0x119U 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                                                                                | (0x11aU 
                                                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))))))))))))))))))))))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__branch_target_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__branch_target_i;
    if ((0x318U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i = 0U;
    } else if ((0x319U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i = 2U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i = 0U;
    } else if ((0x31cU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i = 3U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i = 0U;
    } else if ((0x31dU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i = 4U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i = 0U;
    } else if ((0x31eU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i = 5U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i = 0U;
    } else if ((0x31fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i = 6U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i = 0U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i 
            = (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44 
                       >> 4U));
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i 
            = (7U & (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44 
                             >> 0x24U)));
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i 
            = (7U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44));
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__branch_flag_i 
        = ((0x318U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
           | ((0x319U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
              | ((0x31cU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                 | ((0x31dU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                    | ((0x31eU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                       | (IData)(((0ULL != (0x7000000000ULL 
                                            & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44)) 
                                  | (0x31fU == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__csr_jmp_i 
        = ((0x318U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
           & ((0x319U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
              & ((0x31cU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                 & ((0x31dU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                    & ((0x31eU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                       & ((0x31fU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                          & (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44 
                                     >> 2U))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_flag_i 
        = ((0x318U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
           & ((0x319U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
              & ((0x31cU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                 & ((0x31dU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                    & ((0x31eU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                       & ((0x31fU != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_13)) 
                          & (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT____VdfgRegularize_h087cf4e8_0_44 
                                     >> 3U))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__alusel_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_sel 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_alusel_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__wd_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wd_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__wd_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wd_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_wd_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wd_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wen_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_wd_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__load_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__load_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i))
            ? (((- (IData)((1U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned 
                                  >> 7U)))) << 8U) 
               | (0xffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned))
            : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i))
                ? (((- (IData)((1U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned 
                                      >> 0xfU)))) << 0x10U) 
                   | (0xffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned))
                : ((7U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i))
                    ? (0xffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned)
                    : ((5U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i))
                        ? (0xffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned)
                        : vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata_unaligned))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_load_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__store_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__store_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_store_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_store_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__mem_wen_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_wen_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_memory_inst_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg) 
           | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__aluop_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_control 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
                          [0U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
                          [1U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
                          [2U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
                          [3U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__data_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src1_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__hit)
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__lut_out
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
                          [0U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__data_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
                          [1U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__data_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
                          [2U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__data_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
                          [3U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__data_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT____Vcellinp__src2_choose____pinNumber2) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__hit)
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__lut_out
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__i0__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__my_gen__DOT__imm_gen__DOT__out;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_target_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__jmp_target_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_target_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__branch_flag_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__branch_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__csr_jmp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__csr_jmp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__jmp_flag_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_flag_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__branch_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__csr_flag_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_flag_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut_out = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__hit = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__key_list
                          [0U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__data_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__key_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__key_list
                          [1U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__data_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_csr_flag_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__key_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_wdata_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__hit)
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__lut_out
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__wd_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_wd_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__wd_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_wd_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__wd_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wd_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__load_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__load_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__store_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_store_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__store_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_store_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__memory_inst_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_memory_inst_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__memory_inst_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_memory_inst_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__alu_control 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_control;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__key;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__src1 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__key;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__src2 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2;
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_12 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
                                                 + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_13 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
                                                 ^ vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_14 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
                                                 | vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_15 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
                                                 & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_16 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_17 = VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1, 
                                                               (0x1fU 
                                                                & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_18 = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__get_second_cout 
        = ((IData)(1U) + ((~ (0x80000000U | (0x7fffffffU 
                                             & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2))) 
                          + (0x7fffffffU & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout 
        = (1U & (IData)((1ULL & ((1ULL + ((~ (0x100000000ULL 
                                              | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2)))) 
                                          + (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1)))) 
                                 >> 0x20U))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_result 
        = ((IData)(1U) + ((~ vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2) 
                          + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__branch_flag_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__branch_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__csr_jmp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__csr_jmp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__jmp_flag_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_flag_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__csr_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__csr_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__csr_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__csr_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_csr_wdata_i;
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_size_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_size_o 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 0U;
    } else {
        if ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o 
                = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                    ? 0U : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                             ? 1U : ((7U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                                      ? 0U : ((5U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                                               ? 1U
                                               : 2U))));
            if ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_store_type_i))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb = 1U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 0U;
            } else if ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_store_type_i))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb = 3U;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 1U;
            } else {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb 
                    = ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_store_type_i))
                        ? 0xfU : 0U);
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 2U;
            }
        } else {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 0U;
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_size_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_size_o 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__alu_control;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__i0__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src1_choose__DOT__out;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__i0__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__src2_choose__DOT__out;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[9U] 
        = (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_12));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[9U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_12;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[7U] 
        = (0x200000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[7U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_13;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[6U] 
        = (0x300000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[6U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_14;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[5U] 
        = (0x400000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_15;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[4U] 
        = (0x500000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[4U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_16;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[3U] 
        = (0x600000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_17;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[2U] 
        = (0x700000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.__VdfgRegularize_hd87f99a1_0_18;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[0U] 
        = (0x900000000ULL | (QData)((IData)((1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__u_compare_result 
        = (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[8U] 
        = (0x100000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_result)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[8U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_result;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero 
        = (0U == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_result);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__key;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__key;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__csr_wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__csr_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__key;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__u_compare_result;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__alu_zero_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__pair_list[4U] 
        = (4U | (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__pair_list[5U] 
        = (2U | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list[4U] 
        = (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT____VdfgRegularize_h66a5e278_0_2 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero)) 
           & (((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__get_second_cout 
                >> 0x1fU) ^ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout)) 
              != (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_result 
                  >> 0x1fU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__i0__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__csr_wdata_choose__DOT__out;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__pair_list[1U] 
        = (0x800000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT____VdfgRegularize_h66a5e278_0_2)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__s_compare_result 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT____VdfgRegularize_h66a5e278_0_2;
    __Vtemp_58[7U] = ((0xffffU & (((IData)((0x300000000ULL 
                                            | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14)))) 
                                   >> 8U) | ((IData)(
                                                     ((0x400000000ULL 
                                                       | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15))) 
                                                      >> 0x20U)) 
                                             >> 0xcU))) 
                      | ((0xff0000U & ((IData)((0x300000000ULL 
                                                | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14)))) 
                                       >> 8U)) | (((IData)(
                                                           (0x200000000ULL 
                                                            | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13)))) 
                                                   << 0x1cU) 
                                                  | ((IData)(
                                                             ((0x300000000ULL 
                                                               | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14))) 
                                                              >> 0x20U)) 
                                                     << 0x18U))));
    __Vtemp_58[8U] = ((0xffffU & (((IData)((0x200000000ULL 
                                            | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13)))) 
                                   >> 4U) | ((IData)(
                                                     ((0x300000000ULL 
                                                       | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14))) 
                                                      >> 0x20U)) 
                                             >> 8U))) 
                      | ((0xff0000U & (((IData)((0x200000000ULL 
                                                 | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13)))) 
                                        >> 4U) | ((IData)(
                                                          ((0x300000000ULL 
                                                            | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14))) 
                                                           >> 0x20U)) 
                                                  >> 8U))) 
                         | ((0xf000000U & ((IData)(
                                                   (0x200000000ULL 
                                                    | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13)))) 
                                           >> 4U)) 
                            | ((IData)(((0x200000000ULL 
                                         | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_13))) 
                                        >> 0x20U)) 
                               << 0x1cU))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[0U] 
        = (IData)((0x900000000ULL | (QData)((IData)(
                                                    (1U 
                                                     & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout)))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[1U] 
        = (((IData)((0x800000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__s_compare_result)))) 
            << 4U) | (IData)(((0x900000000ULL | (QData)((IData)(
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout)))))) 
                              >> 0x20U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[2U] 
        = (((IData)((0x700000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18)))) 
            << 8U) | (((IData)((0x800000000ULL | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__s_compare_result)))) 
                       >> 0x1cU) | ((IData)(((0x800000000ULL 
                                              | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__s_compare_result))) 
                                             >> 0x20U)) 
                                    << 4U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[3U] 
        = (((IData)((0x700000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18)))) 
            >> 0x18U) | (((IData)((0x600000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17)))) 
                          << 0xcU) | ((IData)(((0x700000000ULL 
                                                | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18))) 
                                               >> 0x20U)) 
                                      << 8U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[4U] 
        = (((IData)((0x500000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16)))) 
            << 0x10U) | (((0xffU & ((IData)((0x600000000ULL 
                                             | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17)))) 
                                    >> 0x14U)) | ((IData)(
                                                          ((0x700000000ULL 
                                                            | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_18))) 
                                                           >> 0x20U)) 
                                                  >> 0x18U)) 
                         | ((0xf00U & ((IData)((0x600000000ULL 
                                                | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17)))) 
                                       >> 0x14U)) | 
                            ((IData)(((0x600000000ULL 
                                       | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_17))) 
                                      >> 0x20U)) << 0xcU))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[5U] 
        = (((IData)((0x500000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16)))) 
            >> 0x10U) | (((IData)((0x400000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15)))) 
                          << 0x14U) | ((IData)(((0x500000000ULL 
                                                 | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16))) 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[6U] 
        = (((0xffffU & ((IData)((0x400000000ULL | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15)))) 
                        >> 0xcU)) | ((IData)(((0x500000000ULL 
                                               | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_16))) 
                                              >> 0x20U)) 
                                     >> 0x10U)) | (
                                                   ((IData)(
                                                            (0x300000000ULL 
                                                             | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_14)))) 
                                                    << 0x18U) 
                                                   | ((0xf0000U 
                                                       & ((IData)(
                                                                  (0x400000000ULL 
                                                                   | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15)))) 
                                                          >> 0xcU)) 
                                                      | ((IData)(
                                                                 ((0x400000000ULL 
                                                                   | (QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_15))) 
                                                                  >> 0x20U)) 
                                                         << 0x14U))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[7U] 
        = __Vtemp_58[7U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[8U] 
        = __Vtemp_58[8U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[9U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_result;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[0xaU] 
        = (IData)((1ULL | ((QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_12)) 
                           << 4U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[0xbU] 
        = (IData)(((1ULL | ((QData)((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_12)) 
                            << 4U)) >> 0x20U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__s_compare_result;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[0U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[0U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[1U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[2U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[2U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[3U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[3U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[4U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[4U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[5U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[5U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[6U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[6U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[7U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[7U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[8U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[8U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[9U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[9U];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[0xaU] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[0xaU];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut[0xbU] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__lut[0xbU];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [0U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [1U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [2U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [3U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [4U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [4U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [4U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [5U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [5U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [5U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [6U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [6U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [6U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [7U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [7U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [7U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [8U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [8U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [8U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
        = (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
                          == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
                          [9U]))) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__data_list
              [9U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__key_list
              [9U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__hit)
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__lut_out
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wdata_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg)
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_rdata
            : vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__aligned_store 
        = (((0xf000000U <= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp) 
            & (0xf001fffU >= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp)) 
           | (((0x30000000U <= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp) 
               & (0xf001fffU >= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp)) 
              | (((0xa0000000U <= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp) 
                  & (0xbfffffffU >= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp)) 
                 | (((0x10000000U <= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp) 
                     & (0x10000fffU >= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp)) 
                    | ((0x80000000U <= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp) 
                       & (0x9fffffffU >= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less 
        = (1U & ((8U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i))
                  ? (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT____VdfgRegularize_h66a5e278_0_2)
                  : ((9U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ex_aluop_i))
                      ? (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__sub_cout))
                      : (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp 
                         >> 0x1fU))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result_tmp;
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o = 0U;
    } else if ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__i0__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__ALUmode__DOT__out;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__reg_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__alu_less_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__lut 
        = (((((((IData)(1U) << 1U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero)) 
              << 8U) | (((((IData)(2U) << 1U) | (1U 
                                                 & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_zero)))) 
                         << 4U) | (((IData)(3U) << 1U) 
                                   | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less)))) 
            << 0xcU) | (((((IData)(4U) << 1U) | (1U 
                                                 & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less)))) 
                         << 8U) | (((((IData)(5U) << 1U) 
                                     | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less)) 
                                    << 4U) | (((IData)(6U) 
                                               << 1U) 
                                              | (1U 
                                                 & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less)))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__pair_list[0U] 
        = (0xcU | (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__pair_list[1U] 
        = (0xaU | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__pair_list[2U] 
        = (8U | (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__pair_list[3U] 
        = (6U | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list[0U] 
        = (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list[2U] 
        = (1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_less;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__alu_result_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_result_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__lut;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
               == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
               [0U]) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
              [0U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
               == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
               [1U]) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
              [1U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
               == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
               [2U]) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
              [2U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
               == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
               [3U]) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
              [3U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
               == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
               [4U]) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list
              [4U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
              [4U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
               == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
               [5U]) & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__data_list
              [5U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_type_i) 
              == vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__key_list
              [5U]));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_request_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__hit) 
           && (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__lut_out));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__my_alu__DOT__result 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__alu_result_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT____VdfgRegularize_h52a8c717_0_2 
        = ((1U & ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__aligned_store)) 
                  | (0U == (3U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o))))
            ? (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb)) 
                << 0x20U) | (QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data)))
            : ((1U == (3U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o))
                ? (((QData)((IData)((7U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb)))) 
                    << 0x21U) | (QData)((IData)(VL_SHIFTL_III(32,32,32, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data, 8U))))
                : ((2U == (3U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o))
                    ? (((QData)((IData)((3U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb)))) 
                        << 0x22U) | (QData)((IData)(
                                                    VL_SHIFTL_III(32,32,32, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data, 0x10U))))
                    : ((3U == (3U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o))
                        ? (((QData)((IData)((1U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb)))) 
                            << 0x23U) | (QData)((IData)(
                                                        VL_SHIFTL_III(32,32,32, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data, 0x18U))))
                        : 0ULL))));
    if ((((0x10000000U == (0xfffff000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o)) 
          | (0x10002000U <= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o)) 
         | (0x9fffffffU >= vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o))) {
        Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__diff_skip_TOP();
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
            ? (0x2000000U == (0xffff0000U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o))
            : (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_device_tmp));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__branch_request_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_request_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_request_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_next 
        = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__branch_flag_i) 
            & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_request_i))
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_target_i
            : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_flag_i)
                ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_target_reg
                : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__csr_jmp_i)
                    ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i
                    : vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o 
        = (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT____VdfgRegularize_h52a8c717_0_2);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o 
        = (0xfU & (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT____VdfgRegularize_h52a8c717_0_2 
                           >> 0x20U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_addr_o;
    if (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_device = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_device = 1U;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awlen = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awburst = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arlen = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arburst = 0U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_device = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_device = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awlen 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_len_o;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awburst 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_burst_o;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arlen 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_len_o;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arburst 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_burst_o;
    }
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wlast 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_last_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__branch_request_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__branch_request_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_o;
    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_get_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_next);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_strb_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awlen 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awlen;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awburst 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awburst;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wlast 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wlast;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arlen 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arlen;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arburst 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arburst;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__i0__DOT__out 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__branch_request_mux__DOT__out;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_len_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awlen;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_burst_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awburst;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_last_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wlast;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_len_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arlen;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_burst_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arburst;
}
