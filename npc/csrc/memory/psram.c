#include "isa.h"
#include <memory/paddr.h>
#include <memory/host.h>
#include <common.h>
static uint8_t psram[PSRAM_SIZE] PG_ALIGN = {};

extern CPU_state cpu;
uint8_t* guest_to_psram(paddr_t paddr) { 
  // printf("pmem: 0x%08x\n",pmem);
  // printf("paddr: 0x%08x\n",paddr);
  // printf("CONFIG_MBASE: 0x%08x\n",CONFIG_MBASE);
    return (uint8_t*)psram + paddr; 
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


extern "C" void psram_read(int32_t addr, int32_t *data) {
    *data = host_read(guest_to_psram(addr), 4);
    uint32_t tmp = *data;
    *data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
    // Log("psram_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#ifdef CONFIG_MTRACE
    Log("psram_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#endif
    return;
}
extern "C" void psram_write(int32_t addr, int32_t data, char len) {
    uint32_t tmp = data;
    // printf("len = %d", (int)(len));
    int length = ((int)len + 1)/2;
    // Log("psram_write ---  [addr: 0x%08x data: 0x%08x pc: 0x%08x]", addr, data, cpu.pc);
    data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
    // Log("psram_write ---  [addr: 0x%08x data: 0x%08x pc: 0x%08x length: %d]", addr, data, cpu.pc, length);
#ifdef CONFIG_MTRACE
    Log("psram_write ---  [addr: 0x%08x data: 0x%08x pc: 0x%08x length: %d]", addr, data, cpu.pc, length);
#endif
    host_write(guest_to_psram(addr), length,data);
    return;
}

void psram_read_sdb(int32_t addr, int32_t *data, int len) {
    *data = host_read(guest_to_psram(addr), len);
    uint32_t tmp = *data;
    *data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
#ifdef CONFIG_MTRACE
    Log("psram_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#endif
    return;
}
