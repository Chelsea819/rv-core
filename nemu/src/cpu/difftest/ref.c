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

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
extern CPU_state cpu;
bool initial;
// 在DUT host memory的`buf`和REF guest memory的`addr`之间拷贝`n`字节,
// `direction`指定拷贝的方向, `DIFFTEST_TO_DUT`表示往DUT拷贝, `DIFFTEST_TO_REF`表示往REF拷贝
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if(direction == DIFFTEST_TO_REF){
    if (in_pmem(addr)) {
      memcpy(guest_to_host(addr) ,(const paddr_t*)buf ,n);
    }
    #ifdef CONFIG_SOC
    else if (in_psram(addr)) {
      memcpy(guest_to_psram(addr) ,(const paddr_t*)buf ,n);
    }else if (in_sram(addr)) {
      memcpy(guest_to_sram(addr) ,(const paddr_t*)buf ,n);
    }else if (in_flash(addr)) {
      memcpy(guest_to_flash(addr) ,(const paddr_t*)buf ,n);
    }
    #endif
    else {
      Assert(0, "Out of bound!");
    }
  } else {
    if (in_pmem(addr)) {
      memcpy((paddr_t*)buf ,(const paddr_t*)(guest_to_host(addr)) ,n);
    }
    #ifdef CONFIG_SOC
    else if (in_psram(addr)) {
      memcpy((paddr_t*)buf ,(const paddr_t*)(guest_to_psram(addr)) ,n);
    }else if (in_sram(addr)) {
      memcpy((paddr_t*)buf ,(const paddr_t*)(guest_to_sram(addr)) ,n);
    }else if (in_flash(addr)) {
      memcpy((paddr_t*)buf ,(const paddr_t*)(guest_to_flash(addr)) ,n);
    }
    #endif
    else {
      Assert(0, "Out of bound!");
    }
  
  }
}

// `direction`为`DIFFTEST_TO_DUT`时, 获取REF的寄存器状态到`dut`;
// `direction`为`DIFFTEST_TO_REF`时, 设置REF的寄存器状态为`dut`;
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  CPU_state *ref = &cpu;
  if (direction == DIFFTEST_TO_REF) {
    memcpy(ref, dut, DIFFTEST_REG_SIZE);
    if(!initial) {ref->pc = 0x30000000; initial = true;}
  } else {
    memcpy(dut, ref, DIFFTEST_REG_SIZE);
  }
}



// 让REF执行`n`条指令
__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

//// 初始化REF的DiffTest功能
__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  initial = false;
  /* Perform ISA dependent initialization. */
  init_isa();
}
