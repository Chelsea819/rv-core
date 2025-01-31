#include "isa.h"
#include <memory/paddr.h>
#include <memory/host.h>
#include <common.h>
static uint8_t sdram[SDRAM_SIZE] PG_ALIGN = {};

extern CPU_state cpu;
uint8_t* guest_to_sdram(paddr_t paddr) { 
  // printf("pmem: 0x%08x\n",pmem);
  // printf("paddr: 0x%08x\n",paddr);
  // printf("CONFIG_MBASE: 0x%08x\n",CONFIG_MBASE);
    return (uint8_t*)sdram + paddr; 
}
static void out_of_bound_sdram(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of sdram [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, SDRAM_LEFT, SDRAM_RIGHT, cpu.pc);
}
void init_sdram() {
#ifdef CONFIG_MEM_RANDOM
    /*如果定义了CONFIG_MEM_RANDOM,
    则将pmem作为uint32_t指针,
    循环初始化为随机数*/
    uint32_t *p = (uint32_t *)sdram;
    int i;
    for (i = 0; i < (int) (SDRAM_SIZE / sizeof(p[0])); i ++) {
        p[i] = 0;
    }
#endif
    /*打印日志,输出初始化的内存区域的地址范围,
    FMT_PADDR是地址格式化的宏*/
    /*PMEM_LEFT和PMEM_RIGHT应该是
    预定义的内存区域起始和结束地址*/
    Log("sdram area [" FMT_PADDR ", " FMT_PADDR "]", SDRAM_LEFT, SDRAM_RIGHT);
}


word_t sdram_read(int32_t addr, int len) {
  if (likely(in_sdram(addr))) {
    addr = addr & 0x07ffffff;
    word_t data = host_read(guest_to_sdram(addr), len);
    // Log("[nemu]:psram_read ---  [addr: 0x%08x len: 0x%08x data=0x%08x]", addr, len,data);
#ifdef CONFIG_MTRACE
    Log("sdram_read ---  [addr: 0x%08x rdata: 0x%08x]", addr, data);
#endif
    return data;
  }
    out_of_bound_sdram(addr);
    return 0;
}

void sdram_write(int32_t addr, int len, int32_t data) {
  if (likely(in_sdram(addr))) {
    // Log("[nemu]:psram_write ---  [addr: 0x%08x data: 0x%08x]", addr, data);
#ifdef CONFIG_MTRACE
    Log("sdram_write ---  [addr: 0x%08x data: 0x%08x]", addr, data);
#endif
    addr = addr & 0x07ffffff;
    host_write(guest_to_sdram(addr), len,data);
    return;
  }
  out_of_bound_sdram(addr);
  return;
}

void sdram_read_sdb(int32_t addr, int32_t *data, int len) {
    *data = host_read(guest_to_sdram(addr), len);
    uint32_t tmp = *data;
    *data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
#ifdef CONFIG_MTRACE
    Log("sdram_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#endif
    return;
}
