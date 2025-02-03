// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060025_top.h for the primary calling header

#include "Vysyx_23060025_top__pch.h"
#include "Vysyx_23060025_top___024root.h"

void Vysyx_23060025_top___024root___ico_sequent__TOP__0(Vysyx_23060025_top___024root* vlSelf);
void Vysyx_23060025_top___024root___ico_comb__TOP__0(Vysyx_23060025_top___024root* vlSelf);

void Vysyx_23060025_top___024root___eval_ico(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vysyx_23060025_top___024root___ico_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vysyx_23060025_top___024root___ico_comb__TOP__0(vlSelf);
    }
}

void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__diff_skip_TOP();
void Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_get_TOP(IData/*31:0*/ pc, IData/*31:0*/ dnpc);

VL_INLINE_OPT void Vysyx_23060025_top___024root___ico_sequent__TOP__0(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__rstn 
        = (1U & (~ (IData)(vlSelfRef.reset)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__rstn 
        = (1U & (~ (IData)(vlSelfRef.reset)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__rstn 
        = (1U & (~ (IData)(vlSelfRef.reset)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__rstn 
        = (1U & (~ (IData)(vlSelfRef.reset)));
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4 = 0x80000000U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__reset = 1U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4 
            = ((IData)(4U) + vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i);
        if ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wdata_i;
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
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o 
                = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                    ? 0U : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                             ? 1U : ((7U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                                      ? 0U : ((5U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_load_type_i))
                                               ? 1U
                                               : 2U))));
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_alu_result_i;
        } else {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o = 0U;
        }
        vlSelfRef.ysyx_23060025_top__DOT__reset = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__clock = vlSelfRef.clock;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid 
        = ((~ (IData)(vlSelfRef.reset)) & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid 
        = ((~ (IData)(vlSelfRef.reset)) & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i 
        = ((~ (IData)(vlSelfRef.reset)) & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_awready 
        = ((~ (IData)(vlSelfRef.reset)) & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i 
        = ((~ (IData)(vlSelfRef.reset)) & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o 
        = ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o 
        = ((~ (IData)(vlSelfRef.reset)) & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__rstn 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__rstn;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_plus_4 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_pcPlus__DOT__pc_new 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_next 
        = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__branch_flag_i) 
            & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_request_i))
            ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_branch_target_i
            : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_jmp_flag_i)
                ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__jmp_target_reg
                : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT____Vcellinp__ysyx_23060025_IFU__csr_jmp_i)
                    ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_csr_pc_i
                    : vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__pc_plus_4)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__clk 
        = vlSelfRef.ysyx_23060025_top__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__clock;
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
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__bkwd_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_arready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i 
        = (3U & (- (IData)((1U & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_bkwd_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_3 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1)
            ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o) 
                << 1U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o))
            : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2)
                ? ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o) 
                   << 1U) : 0U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o;
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
    Vysyx_23060025_top___024root____Vdpiimwrap_ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_get_TOP(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__id_pc_i, vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__pc_next);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__clk 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__clk;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o 
        = (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT____VdfgRegularize_h52a8c717_0_2);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o 
        = (0xfU & (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT____VdfgRegularize_h52a8c717_0_2 
                           >> 0x20U)));
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
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o 
        = (1U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_3);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o 
        = (1U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_3 
                 >> 1U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o;
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
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_strb_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_bready 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_rready 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_valid_o;
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
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_pcPlus__DOT__reset 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__reset;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__u_ysyx_23060025_counter__DOT__clock 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__clock;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__bkwd_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rready;
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
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rready;
}

extern const VlUnpacked<CData/*1:0*/, 128> Vysyx_23060025_top__ConstPool__TABLE_h8f86ff8d_0;
extern const VlUnpacked<CData/*1:0*/, 512> Vysyx_23060025_top__ConstPool__TABLE_habc35934_0;
extern const VlUnpacked<CData/*1:0*/, 16> Vysyx_23060025_top__ConstPool__TABLE_hd71bc96c_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vysyx_23060025_top__ConstPool__TABLE_h21b75aee_0;

VL_INLINE_OPT void Vysyx_23060025_top___024root___ico_comb__TOP__0(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___ico_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6;
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 = 0;
    QData/*49:0*/ ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0;
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 = 0;
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*6:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))
            ? (0x2010U | ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o) 
                            << 0x10U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o) 
                                          << 9U) | 
                                         ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o) 
                                          << 8U))) 
                          | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o) 
                              << 1U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o))))
            : ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))
                ? (0x400U | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o) 
                             << 0x10U)) : 0U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o 
        = (0xfU & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                   >> 0xcU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o 
        = (7U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 9U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o 
        = (0xfU & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                   >> 4U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o 
        = (7U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 1U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o 
        = (1U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 8U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o 
        = (1U & ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o 
        = (1U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 0x10U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o));
    if (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device) {
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arid = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arsize 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awid = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_awid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awsize = 0U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arid 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arsize 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awid 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_awid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awsize 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awsize 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awsize;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state))
            ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i) 
                & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o))
                ? 1U : 0U) : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state))
                               ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o) 
                                    & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i)) 
                                   & (~ (IData)((0U 
                                                 != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i)))))
                                   ? 0U : 1U) : 3U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid;
    __Vtableidx5 = (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bready) 
                       << 6U) | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rready) 
                                 << 5U)) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid) 
                                             << 4U) 
                                            | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid) 
                                               << 3U))) 
                    | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid) 
                        << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_h8f86ff8d_0
        [__Vtableidx5];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arsize;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awsize;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_ren 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_wen 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state))));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata 
        = ((IData)(vlSelfRef.reset) ? 0U : (((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)) 
                                             & (0U 
                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state)))
                                             ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data
                                             : 0U));
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)
            ? (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i)) 
                << 0x31U) | (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_data_i)) 
                              << 0x11U) | (QData)((IData)(
                                                          (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i) 
                                                            << 0xfU) 
                                                           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i) 
                                                              << 0xeU))))))
            : (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awready)) 
                << 0x31U) | (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata)) 
                              << 0x11U) | (QData)((IData)(
                                                          (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rresp) 
                                                              << 0xfU) 
                                                             | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rlast) 
                                                                   << 0xdU))) 
                                                            | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rid) 
                                                                << 9U) 
                                                               | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awready) 
                                                                  << 8U))) 
                                                           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awready) 
                                                               << 7U) 
                                                              | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bresp) 
                                                                  << 5U) 
                                                                 | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid) 
                                                                     << 4U) 
                                                                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bid))))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__ren 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_ren;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_wen_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_wen;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rdata 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_r_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i 
        = (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                   >> 0x11U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_last_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0xdU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_id_i 
        = (0xfU & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                           >> 9U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_id_i 
        = (0xfU & (IData)(ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 8U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 7U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i 
        = (3U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 5U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 4U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i 
        = (3U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0xfU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0x31U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0xeU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_last_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_last_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_last_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_last_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i;
    if (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_valid_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_valid_o 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_valid_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_valid_o 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2)
            ? (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i)
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
            ? ((1U & ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i)) 
                      & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i))))
                ? 0U : (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i) 
                           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o)) 
                          & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o)) 
                         & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i))
                         ? 1U : (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i) 
                                  & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o))
                                  ? 1U : (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i) 
                                           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o))
                                           ? 2U : 0U))))
            : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
                ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i) 
                     & (~ (IData)((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i))))) 
                    & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o))
                    ? 0U : ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i) 
                              & (~ (IData)((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i))))) 
                             & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o))
                             ? 0U : 1U)) : ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
                                             ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i) 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i))))) 
                                                 & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o))
                                                 ? 0U
                                                 : 2U)
                                             : 3U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_bkwd_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_bkwd_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o = 0U;
    if ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))) {
        if ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_addr_o;
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i;
    } else {
        if ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))) {
            if ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o;
            }
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__bkwd_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__bkwd_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_waddr_i 
        = (((0x3fffffffU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o 
                            >> 2U)) << 2U) | 0U);
    vlSelfRef.ysyx_23060025_top__DOT__io_master_awaddr 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_strb_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_wmask 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wstrb 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_raddr_i 
        = (((0x3fffffffU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                            >> 2U)) << 2U) | 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__bit_sel 
        = (0U != (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                  - (IData)(0x2000000U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_araddr 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i;
    __Vtableidx1 = ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o) 
                      << 8U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i) 
                                 << 7U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i) 
                                              << 4U)))) 
                    | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i) 
                        << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o) 
                                   << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_habc35934_0
        [__Vtableidx1];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_w_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awaddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awaddr 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awaddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_strb_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wstrb;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wstrb 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wstrb;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_data 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__bit_sel)
            ? (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime 
                       >> 0x20U)) : (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_araddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_araddr 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_araddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_inst_en 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state)) 
           & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o) 
           & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awaddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wstrb;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_araddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    __Vtableidx2 = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__idu_valid_o) 
                     << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o) 
                                << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_hd71bc96c_0
        [__Vtableidx2];
    __Vtableidx3 = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__exu_valid_o) 
                     << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o) 
                                << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_hd71bc96c_0
        [__Vtableidx3];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__next_state 
        = ((2U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
            ? ((1U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
                ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg) 
                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i))
                    ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o) 
                        & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i))
                        ? 1U : (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o) 
                                   & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i)) 
                                  & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i)) 
                                 & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o))
                                 ? 1U : 3U)) : 0U) : 0U)
            : ((1U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
                ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i) 
                     & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o)) 
                    | (((~ (IData)((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i)))) 
                        & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i)) 
                       & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o)))
                    ? 2U : 1U) : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o)
                                   ? 3U : 0U)));
    __Vtableidx4 = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o) 
                     << 4U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_memory_inst_i) 
                                << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_valid_o) 
                                           << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__con_state))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_h21b75aee_0
        [__Vtableidx4];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state)) 
           && (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wen_i));
    if ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_wreg_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_wdata_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_type_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wdata_i;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__regWrite 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wd_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rd 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wreg_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__csr_wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__csr_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i;
}

void Vysyx_23060025_top___024root___eval_triggers__ico(Vysyx_23060025_top___024root* vlSelf);

bool Vysyx_23060025_top___024root___eval_phase__ico(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vysyx_23060025_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vysyx_23060025_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vysyx_23060025_top___024root___act_sequent__TOP__0(Vysyx_23060025_top___024root* vlSelf);

void Vysyx_23060025_top___024root___eval_act(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vysyx_23060025_top___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vysyx_23060025_top___024root___act_sequent__TOP__0(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___act_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6;
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 = 0;
    QData/*49:0*/ ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0;
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 = 0;
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*6:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state)) 
           & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2 
        = ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state)) 
           & (0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)));
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))
            ? (0x2010U | ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o) 
                            << 0x10U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_size_o) 
                                          << 9U) | 
                                         ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o) 
                                          << 8U))) 
                          | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_size_o) 
                              << 1U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o))))
            : ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))
                ? (0x400U | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o) 
                             << 0x10U)) : 0U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o 
        = (0xfU & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                   >> 0xcU));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o 
        = (7U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 9U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o 
        = (0xfU & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                   >> 4U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o 
        = (7U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 1U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o 
        = (1U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 8U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o 
        = (1U & ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o 
        = (1U & (ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_6 
                 >> 0x10U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_3 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1)
            ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o) 
                << 1U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o))
            : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2)
                ? ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o) 
                   << 1U) : 0U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o 
        = (1U & vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_3);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o 
        = (1U & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_3 
                 >> 1U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_size_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_valid_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_valid_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_valid_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_bready 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_ready_o));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_rready 
        = ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_ready_o));
    if (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device) {
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arid = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arsize 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awid = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_awid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awsize = 0U;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arid 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_id_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_size_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arsize 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_arsize;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awid 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_id_o;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awid 
            = vlSelfRef.ysyx_23060025_top__DOT__io_master_awid;
        vlSelfRef.ysyx_23060025_top__DOT__io_master_awsize 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_size_o;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awsize 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awsize;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arvalid 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__bkwd_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_bready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state))
            ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i) 
                & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_valid_o))
                ? 1U : 0U) : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__con_state))
                               ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_ready_o) 
                                    & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i)) 
                                   & (~ (IData)((0U 
                                                 != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i)))))
                                   ? 0U : 1U) : 3U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rready 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rready;
    __Vtableidx5 = (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bready) 
                       << 6U) | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rready) 
                                 << 5U)) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_wvalid) 
                                             << 4U) 
                                            | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awvalid) 
                                               << 3U))) 
                    | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_arvalid) 
                        << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_h8f86ff8d_0
        [__Vtableidx5];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arsize;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_size_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awsize;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_arvalid;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_bkwd_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_bready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rready;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_ren 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_wen 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)) 
           & ((~ (IData)(vlSelfRef.reset)) & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state))));
    vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata 
        = ((IData)(vlSelfRef.reset) ? 0U : (((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__con_state)) 
                                             & (0U 
                                                == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__next_state)))
                                             ? vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data
                                             : 0U));
    ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__axi_device)
            ? (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_ready_i)) 
                << 0x31U) | (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_data_i)) 
                              << 0x11U) | (QData)((IData)(
                                                          (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_resp_i) 
                                                            << 0xfU) 
                                                           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_r_valid_i) 
                                                              << 0xeU))))))
            : (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awready)) 
                << 0x31U) | (((QData)((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata)) 
                              << 0x11U) | (QData)((IData)(
                                                          (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rresp) 
                                                              << 0xfU) 
                                                             | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rvalid) 
                                                                 << 0xeU) 
                                                                | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rlast) 
                                                                   << 0xdU))) 
                                                            | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_rid) 
                                                                << 9U) 
                                                               | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awready) 
                                                                  << 8U))) 
                                                           | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_awready) 
                                                               << 7U) 
                                                              | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bresp) 
                                                                  << 5U) 
                                                                 | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bvalid) 
                                                                     << 4U) 
                                                                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__io_master_bid))))))))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__ren 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_ren;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_wen_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__mem_wen;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rdata 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_rdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_r_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_rdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i 
        = (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                   >> 0x11U));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_last_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0xdU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_id_i 
        = (0xfU & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                           >> 9U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_id_i 
        = (0xfU & (IData)(ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 8U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 7U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i 
        = (3U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 5U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 4U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i 
        = (3U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0xfU)));
    if (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0x31U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i 
        = (1U & (IData)((ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT____VdfgRegularize_h814658eb_1_0 
                         >> 0xeU)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_last_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_last_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_last_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_last_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_id_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_id_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_id_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_bkwd_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_bkwd_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2)
            ? (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i)
            : 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_1) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT____VdfgRegularize_h49571472_0_2) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
            ? ((1U & ((~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i)) 
                      & (~ (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i))))
                ? 0U : (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i) 
                           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o)) 
                          & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o)) 
                         & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i))
                         ? 1U : (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i) 
                                  & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o))
                                  ? 1U : (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i) 
                                           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o))
                                           ? 2U : 0U))))
            : ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
                ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_valid_i) 
                     & (~ (IData)((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_bkwd_resp_i))))) 
                    & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o))
                    ? 0U : ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i) 
                              & (~ (IData)((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i))))) 
                             & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o))
                             ? 0U : 1U)) : ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))
                                             ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_valid_i) 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_r_resp_i))))) 
                                                 & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o))
                                                 ? 0U
                                                 : 2U)
                                             : 3U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_bkwd_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_bkwd_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_r_resp_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_r_valid_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o = 0U;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_ready_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state)) 
           & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_ready_i));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o = 0U;
    if ((2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))) {
        if ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o = 0U;
            vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_addr_o;
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_ready_i;
    } else {
        if ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__next_state))) {
            if ((0U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__con_state))) {
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_addr_o;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_data_o;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_strb_o;
                vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                    = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_addr_o;
            }
        }
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__bkwd_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__bkwd_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_bkwd_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_resp_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_resp_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_valid_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_r_valid_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_w_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_waddr_i 
        = (((0x3fffffffU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o 
                            >> 2U)) << 2U) | 0U);
    vlSelfRef.ysyx_23060025_top__DOT__io_master_awaddr 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_w_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_data_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_w_strb_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_wmask 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_wstrb 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_w_strb_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_addr_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__data_w_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__axi_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_ctl_addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_raddr_i 
        = (((0x3fffffffU & (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                            >> 2U)) << 2U) | 0U);
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__bit_sel 
        = (0U != (vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o 
                  - (IData)(0x2000000U)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__io_master_araddr 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__xbar_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_AXI_CTL__DOT__inst_addr_r_ready_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i;
    __Vtableidx1 = ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_valid_o) 
                      << 8U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_addr_r_ready_i) 
                                 << 7U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__if_last_finish_i) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_resp_i) 
                                              << 4U)))) 
                    | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_valid_i) 
                        << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o) 
                                   << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_habc35934_0
        [__Vtableidx1];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_w_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awaddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awaddr 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_awaddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_data_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_strb_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wstrb;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wstrb 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_wstrb;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__addr_w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_addr_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__w_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__data_w_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__r_data 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__bit_sel)
            ? (IData)((vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime 
                       >> 0x20U)) : (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__mtime));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__clint_addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_CLINT__DOT__addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__clint_addr_r_addr_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__addr_r_addr_i 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_araddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_araddr 
        = vlSelfRef.ysyx_23060025_top__DOT__io_master_araddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__addr_r_ready_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__inst_addr_r_ready_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__r_inst_en 
        = ((1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__con_state)) 
           & (2U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o 
        = ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__inst_r_ready_o) 
           & (1U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__next_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_w_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_awaddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_data_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wdata;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__u_ysyx_23060025_SRAM__DOT__mem_wdata_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025_AXI_SRAM__DOT__w_data_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_w_strb_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_wstrb;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__u_ysyx_23060025_xbar__DOT__axi_addr_r_addr_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__io_master_araddr;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_IFU__DOT__valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__ifu_valid 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o;
    __Vtableidx2 = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__idu_valid_o) 
                     << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o) 
                                << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_decoder__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_hd71bc96c_0
        [__Vtableidx2];
    __Vtableidx3 = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__exu_valid_o) 
                     << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o) 
                                << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__con_state)));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_EXE__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_hd71bc96c_0
        [__Vtableidx3];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__next_state 
        = ((2U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
            ? ((1U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
                ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__mem_to_reg) 
                    | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_mem_wen_i))
                    ? (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_valid_o) 
                        & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_r_ready_i))
                        ? 1U : (((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_valid_o) 
                                   & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_addr_w_ready_i)) 
                                  & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_ready_i)) 
                                 & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_w_valid_o))
                                 ? 1U : 3U)) : 0U) : 0U)
            : ((1U & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_LSU__DOT__con_state))
                ? ((((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_valid_i) 
                     & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_r_ready_o)) 
                    | (((~ (IData)((0U != (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_resp_i)))) 
                        & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_valid_i)) 
                       & (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__data_bkwd_ready_o)))
                    ? 2U : 1U) : ((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o)
                                   ? 3U : 0U)));
    __Vtableidx4 = (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ifu_valid_o) 
                     << 4U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_memory_inst_i) 
                                << 3U) | (((IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__lsu_valid_o) 
                                           << 2U) | (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__con_state))));
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state 
        = Vysyx_23060025_top__ConstPool__TABLE_h21b75aee_0
        [__Vtableidx4];
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i 
        = ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state)) 
           && (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wen_i));
    if ((3U == (IData)(vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__next_state))) {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_wreg_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_wdata_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_csr_type_i;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i 
            = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__wb_reg_wdata_i;
    } else {
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i = 0U;
        vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i = 0U;
    }
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__regWrite 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wd_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wen_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rd 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wreg_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_waddr_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__csr_wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__csr_type_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr_type_i 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__csr_type_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__wdata 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i;
    vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_wb__DOT__wdata_o 
        = vlSelfRef.ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__reg_wdata_i;
}

void Vysyx_23060025_top___024root___nba_sequent__TOP__0(Vysyx_23060025_top___024root* vlSelf);

void Vysyx_23060025_top___024root___eval_nba(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_23060025_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_23060025_top___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vysyx_23060025_top___024root___eval_triggers__act(Vysyx_23060025_top___024root* vlSelf);

bool Vysyx_23060025_top___024root___eval_phase__act(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vysyx_23060025_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vysyx_23060025_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vysyx_23060025_top___024root___eval_phase__nba(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vysyx_23060025_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060025_top___024root___dump_triggers__ico(Vysyx_23060025_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060025_top___024root___dump_triggers__nba(Vysyx_23060025_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060025_top___024root___dump_triggers__act(Vysyx_23060025_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_23060025_top___024root___eval(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vysyx_23060025_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/chelsea/ysyx-workbench/npc-rare/vsrc/ysyx_23060025_top.v", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vysyx_23060025_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vysyx_23060025_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/chelsea/ysyx-workbench/npc-rare/vsrc/ysyx_23060025_top.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060025_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/chelsea/ysyx-workbench/npc-rare/vsrc/ysyx_23060025_top.v", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vysyx_23060025_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vysyx_23060025_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_23060025_top___024root___eval_debug_assertions(Vysyx_23060025_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_23060025_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060025_top___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelfRef.reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
