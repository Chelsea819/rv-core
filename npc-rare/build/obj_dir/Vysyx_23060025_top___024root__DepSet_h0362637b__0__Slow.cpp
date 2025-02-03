// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060025_top.h for the primary calling header

#include "Vysyx_23060025_top__pch.h"
#include "Vysyx_23060025_top__Syms.h"
#include "Vysyx_23060025_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060025_top___024root___dump_triggers__stl(Vysyx_23060025_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060025_top___024root___eval_triggers__stl(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.set(1U, ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state) 
                                       != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state__0 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.__VstlDidInit))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_23060025_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
