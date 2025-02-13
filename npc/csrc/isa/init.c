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
    0x00100093,  // addi x1, x0, 1       # x1 = 0 + 1 = 1
    0x00200113,  // addi x2, x0, 2       # x2 = 0 + 2 = 2
    0x00300193,  // addi x3, x0, 3       # x3 = 0 + 3 = 3
    0x00400213,  // addi x4, x0, 4       # x4 = 0 + 4 = 4

    // 测试 beq
    0x00208463,  // beq x1, x2, 8        # if x1 == x2, jump to PC + 8 (0x18)
    0x00100073,  // ebreak               # 如果未跳转，触发断点
    0x00500293,  // addi x5, x0, 5       # x5 = 0 + 5 = 5 (跳转目标)

    // 测试 bne
    0x00209463,  // bne x1, x2, 8        # if x1 != x2, jump to PC + 8 (0x24)
    0x00100073,  // ebreak               # 如果未跳转，触发断点
    0x00600313,  // addi x6, x0, 6       # x6 = 0 + 6 = 6 (跳转目标)

    // 测试 blt
    0x0020c463,  // blt x1, x2, 8        # if x1 < x2, jump to PC + 8 (0x30)
    0x00100073,  // ebreak               # 如果未跳转，触发断点
    0x00700393,  // addi x7, x0, 7       # x7 = 0 + 7 = 7 (跳转目标)

    // 测试 bge
    0x0020d463,  // bge x2, x1, 8        # if x2 >= x1, jump to PC + 8 (0x3c)
    0x00100073,  // ebreak               # 如果未跳转，触发断点
    0x00800413,  // addi x8, x0, 8       # x8 = 0 + 8 = 8 (跳转目标)

    // 测试 jal
    0x0100006f,  // jal x0, 16           # jump to PC + 16 (0x4c)
    0x00100073,  // ebreak               # 如果未跳转，触发断点
    0x00900493,  // addi x9, x0, 9       # x9 = 0 + 9 = 9 (跳转目标)

    // 测试 jalr
    0x00000517,  // auipc x10, 0         # x10 = PC + 0 = 0x4c
    0x00850513,  // addi x10, x10, 8     # x10 = 0x4c + 8 = 0x54
    0x00050067,  // jalr x0, x10, 0      # jump to x10 + 0 = 0x54
    0x00100073,  // ebreak               # 如果未跳转，触发断点
    0x00a00513,  // addi x10, x0, 10     # x10 = 0 + 10 = 10 (跳转目标)

    // 测试 lui
    0x000105b7,  // lui x11, 0x10        # x11 = 0x10 << 12 = 0x10000
    0x00158593,  // addi x11, x11, 1     # x11 = 0x10000 + 1 = 0x10001

    // 测试 add
    0x00b60633,  // add x12, x12, x11    # x12 = x12 + x11 = 0 + 0x10001 = 0x10001

    // 结束
    0x00100073  // ebreak               # 触发断点，停止执行
};

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
}
