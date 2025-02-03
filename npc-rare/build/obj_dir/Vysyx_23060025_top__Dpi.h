// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_23060025_TOP__DPI_H_
#define VERILATED_VYSYX_23060025_TOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_AXI_CTL.v:118:31
    extern void diff_skip();
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_EXE.v:59:31
    extern void exu_p_counter_update();
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_wb.v:95:31
    extern void finish_get(char finish);
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_decoder.v:73:34
    extern void idu_p_counter_update(char opcode, char func3);
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025.v:187:34
    extern void ifebreak_func(int inst);
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_IFU.v:138:31
    extern void ifu_p_counter_update();
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025.v:201:34
    extern void inst_get(int inst);
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_IFU.v:132:31
    extern void inst_invalid_get(char invalid);
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_LSU.v:250:31
    extern void lsu_delay_counter_update();
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_LSU.v:243:31
    extern void lsu_p_counter_update();
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025_counter.v:46:31
    extern void pc_get(int pc, int dnpc);
    // DPI import at /home/chelsea/ysyx-workbench/npc-rare/vsrc/ysyx_23060025_SRAM.v:24:41
    extern int pmem_read_task(int raddr, char wmask);
    // DPI import at /home/chelsea/ysyx-workbench/npc-rare/vsrc/ysyx_23060025_SRAM.v:34:31
    extern void pmem_write_task(int waddr, int wdata, char wmask);
    // DPI import at /home/chelsea/ysyx-workbench/npc/vsrc/ysyx_23060025.v:192:31
    extern void resp_check(char resp);

#ifdef __cplusplus
}
#endif

#endif  // guard
