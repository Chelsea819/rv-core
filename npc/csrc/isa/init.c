/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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

#include <isa.h>
#include <memory/paddr.h>

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
// static const uint32_t img [] = {
//   // 0x00010537,  // lui	a0,0x10
//   // 0x01050513,  // auipc t0,0
//   // 0x00010537,  // addi    x[1] = 0 + 1
//   // 0x01050513,  // auipc t0,0
//   0x00100093,  // addi    x[1] = 0 + 1
//   0x01440413,          	// addi	s0,s0,20
//   0x00178793,          	// addi	a5,a5,1
//   0x00f586b3,          	// add	a3,a1,a5
//   0x00100073  // ebreak (used ass npc_trap)
// };

static const uint32_t img[] = {
    // 初始化寄存器
    0x00100093,  // addi x1, x0, 1       # x1 = 1
    0x00200113,  // addi x2, x0, 2       # x2 = 2
    0x00300193,  // addi x3, x0, 3       # x3 = 3

    // 测试条件分支（beq）
    0x00208463,  // beq  x1, x2, 8       # if x1 == x2, jump to PC + 8 (不会跳转)
    0x00400293,  // addi x5, x0, 4       # x5 = 4 (执行)
    0x00108663,  // beq  x1, x1, 12      # if x1 == x1, jump to PC + 12 (会跳转)
    0x00500313,  // addi x6, x0, 5       # x6 = 5 (不会执行)

    // 跳转到目标地址
    0x0100006f,  // jal  x0, 16          # jump to PC + 16 (绝对跳转)
    0x00600393,  // addi x7, x0, 6       # x7 = 6 (不会执行)

    // 目标地址
    0x00700413,  // addi x8, x0, 7       # x8 = 7 (跳转目标)
    0x00800493,  // addi x9, x0, 8       # x9 = 8

    // 测试 jalr
    0x00048567,  // jalr x10, x9, 0      # jump to x9 + 0 (x10 = PC + 4)
    0x00900513,  // addi x10, x0, 9      # x10 = 9 (不会执行)

    // 目标地址
    0x00a00593,  // addi x11, x0, 10     # x11 = 10 (jalr 跳转目标)

    // 结束程序
    0x00100073   // ebreak               # 触发断点
};
void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
}
