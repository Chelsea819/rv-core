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

#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>
// 16 16 16 2
#define SRAM_SIZE  0x1fff
#define SRAM_LEFT  0x0f000000
#define SRAM_RIGHT  0x0f000000 + SRAM_SIZE
#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)

#define PSRAM_SIZE 0x0400000
#define PSRAM_ADDR 0x80000000

#define PSRAM_LEFT  ((paddr_t)PSRAM_ADDR)
#define PSRAM_RIGHT ((paddr_t)PSRAM_ADDR + PSRAM_SIZE - 1)

static inline bool in_psram(paddr_t addr) {
  return addr - PSRAM_ADDR < PSRAM_SIZE;
}

#define FLASH_SIZE 0x10000000
#define FLASH_ADDR 0x30000000
uint8_t* guest_to_flash(paddr_t paddr);
uint8_t* guest_to_psram(paddr_t paddr);
uint8_t* guest_to_sram(paddr_t paddr);
/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

//判断 addr 是否在 内存区域中
static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

//判断 addr 是否在 内存区域中
static inline bool in_sram(paddr_t addr) {
  return addr - SRAM_LEFT < SRAM_SIZE;
}
void init_psram();

static inline bool in_flash(paddr_t addr) {
  return addr - FLASH_ADDR < FLASH_SIZE;
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
