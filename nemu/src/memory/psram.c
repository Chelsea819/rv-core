#include "isa.h"
#include "macro.h"
#include <memory/paddr.h>
#include <memory/host.h>
#include <common.h>
extern CPU_state cpu;
static uint8_t psram[PSRAM_SIZE] PG_ALIGN = {};

uint8_t* guest_to_psram(paddr_t paddr) { 
  // printf("pmem: 0x%08x\n",pmem);
  // printf("paddr: 0x%08x\n",paddr);
  // printf("CONFIG_MBASE: 0x%08x\n",CONFIG_MBASE);
    return (uint8_t*)psram + paddr - PSRAM_ADDR; 
}
static void out_of_bound_psram(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PSRAM_LEFT, PSRAM_RIGHT, cpu.pc);
}

void init_psram() {
#ifdef CONFIG_MEM_RANDOM
    /*如果定义了CONFIG_MEM_RANDOM,
    则将pmem作为uint32_t指针,
    循环初始化为随机数*/
    uint32_t *p = (uint32_t *)psram;
    int i;
    for (i = 0; i < (int) (PSRAM_SIZE / sizeof(p[0])); i ++) {
        p[i] = 0;
    }
#endif
    /*打印日志,输出初始化的内存区域的地址范围,
    FMT_PADDR是地址格式化的宏*/
    /*PMEM_LEFT和PMEM_RIGHT应该是
    预定义的内存区域起始和结束地址*/
    Log("psram area [" FMT_PADDR ", " FMT_PADDR "]", PSRAM_LEFT, PSRAM_RIGHT);
}


word_t psram_read(int32_t addr, int len) {
  if (likely(in_psram(addr))) {
    word_t data = host_read(guest_to_psram(addr), len);
    // Log("[nemu]:psram_read ---  [addr: 0x%08x len: 0x%08x data=0x%08x]", addr, len,data);
#ifdef CONFIG_MTRACE
    Log("psram_read ---  [addr: 0x%08x rdata: 0x%08x]", addr, data);
#endif
    return data;
  }
    out_of_bound_psram(addr);
    return 0;
}
void psram_write(int32_t addr, int len, int32_t data) {
  if (likely(in_psram(addr))) {
    // Log("[nemu]:psram_write ---  [addr: 0x%08x data: 0x%08x]", addr, data);
#ifdef CONFIG_MTRACE
    Log("psram_write ---  [addr: 0x%08x data: 0x%08x]", addr, data);
#endif
    host_write(guest_to_psram(addr), len,data);
    return;
  }
  out_of_bound_psram(addr);
  return;
}