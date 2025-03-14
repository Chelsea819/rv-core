/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __NPC_REG_H__
#define __NPC_REG_H__

#include "common.h"
#include "sim.h"
extern TOP_NAME *dut; extern VerilatedFstC *tfp;
#define REG_NUM MUXDEF(CONFIG_RVE, 16, 32)
extern const char* regs[];
/*check register index*/
static inline int check_reg_idx(int idx) {
  /* if index in certain range */
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
  return idx;
}

#define R(idx) (dut->rootp->ysyx_23060025_top__DOT__u_ysyx_23060025__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf[check_reg_idx(idx)])

// #define gpr(idx) (cpu.gpr[check_reg_idx(idx)])


static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif
