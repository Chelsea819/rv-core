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

    // 测试 beq：如果 x1 == x2，跳转到 end
    0x00208463,  // beq x1, x2, 8        # if x1 == x2, jump to end (0x1C)
    0x00100093,  // addi x1, x0, 1       # x1 = 0 + 1 = 1 (未跳转时执行)

    // 测试 bne：如果 x1 != x2，跳转到 loop_start
    0x00209463,  // bne x1, x2, 8        # if x1 != x2, jump to loop_start (0x24)
    0x00100073,  // ebreak               # 如果未跳转，触发断点

    // loop_start: 循环开始
    0x00108093,  // addi x1, x1, 1       # x1 = x1 + 1 (x1 = 2)
    0x00208463,  // beq x1, x2, 8        # if x1 == x2, jump to end (0x34)
    0xff5ff06f,  // jal x0, -12          # jump to loop_start (0x24)

    // end: 结束循环
    0x00100093,  // addi x1, x0, 1       # x1 = 0 + 1 = 1

    // 测试 jal：跳转到 function
    0x0100006f,  // jal x0, 16           # jump to function (0x44)

    // function: 函数
    0x00108093,  // addi x1, x1, 1       # x1 = x1 + 1 (x1 = 2)
    0x00008067,  // jalr x0, x1, 0       # jump to x1 + 0 = 0x2 (无效地址，仅测试指令)

    // 测试 jalr：跳转到 final
    0x00000297,  // auipc x5, 0          # x5 = PC + 0 = 0x4C
    0x00828293,  // addi x5, x5, 8       # x5 = 0x4C + 8 = 0x54
    0x00028067,  // jalr x0, x5, 0       # jump to x5 + 0 = 0x54

    // final: 最终代码
    0x00100093,  // addi x1, x0, 1       # x1 = 0 + 1 = 1
    0x00200113,  // addi x2, x0, 2       # x2 = 0 + 2 = 2
    0x00300193,  // addi x3, x0, 3       # x3 = 0 + 3 = 3
    0x00400213,  // addi x4, x0, 4       # x4 = 0 + 4 = 4

    // 结束
    0x00100073  // ebreak               # 触发断点，停止执行
};

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
}
