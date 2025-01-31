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


extern "C" void sdram_read(int32_t addr, int32_t *data, char mask) {
    addr = addr & 0x03ffffff;
    *data = host_read(guest_to_sdram(addr), 2);
    // uint32_t tmp = *data;
    // *data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
    // Log("sdram_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#ifdef CONFIG_MTRACE
    Log("sdram_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#endif
    return;
}
extern "C" void sdram_write(int32_t addr, int32_t data, char mask) {
    // d = 0b1101
    addr = addr & 0x03ffffff;
    uint8_t mask_t = (uint8_t)mask;
    // uint32_t tmp = data;
    // printf("len = %d", (int)(len));
    // data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
    // Log("sdram_write ---  [addr: 0x%08x data: 0x%08x pc: 0x%08x mask: %x]", addr, data, cpu.pc, mask_t);
#ifdef CONFIG_MTRACE
    Log("sdram_write ---  [addr: 0x%08x data: 0x%08x pc: 0x%08x mask: %x]", addr, data, cpu.pc, mask_t);
#endif
    // e -- 1110 d -- 1101 b -- 1011 7 0111
    if((mask_t & 0b01) == 0) host_write(guest_to_sdram(addr), 1,BITS(data,7,0) << 24);
    if((mask_t & 0b10) == 0) host_write(guest_to_sdram(addr + 1), 1,BITS(data,15,8) << 24);
    
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
