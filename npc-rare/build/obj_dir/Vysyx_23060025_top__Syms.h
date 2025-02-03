// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VYSYX_23060025_TOP__SYMS_H_
#define VERILATED_VYSYX_23060025_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vysyx_23060025_top.h"

// INCLUDE MODULE CLASSES
#include "Vysyx_23060025_top___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vysyx_23060025_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vysyx_23060025_top* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vysyx_23060025_top___024root   TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_ysyx_23060025_top__u_ysyx_23060025_AXI_SRAM__u_ysyx_23060025_SRAM;

    // CONSTRUCTORS
    Vysyx_23060025_top__Syms(VerilatedContext* contextp, const char* namep, Vysyx_23060025_top* modelp);
    ~Vysyx_23060025_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
