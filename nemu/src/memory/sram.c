#include <memory/paddr.h>
#include <common.h>
static uint8_t sram[SRAM_SIZE] PG_ALIGN = {};
void init_sram() {
#ifdef CONFIG_MEM_RANDOM
    /*如果定义了CONFIG_MEM_RANDOM,
    则将pmem作为uint32_t指针,
    循环初始化为随机数*/
    uint32_t *p = (uint32_t *)sram;
    int i;
    for (i = 0; i < (int) (SRAM_SIZE / sizeof(p[0])); i ++) {
        p[i] = 0;
    }
#endif
    /*打印日志,输出初始化的内存区域的地址范围,
    FMT_PADDR是地址格式化的宏*/
    /*PMEM_LEFT和PMEM_RIGHT应该是
    预定义的内存区域起始和结束地址*/
    Log("sram area [" FMT_PADDR ", " FMT_PADDR "]", SRAM_LEFT, SRAM_RIGHT);
}
uint8_t* guest_to_sram(paddr_t paddr) { return sram + paddr - SRAM_LEFT; }

static inline word_t sram_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr);
    default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
  }
}

static inline void sram_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return);
    IFDEF(CONFIG_RT_CHECK, default: assert(0));
  }
}


word_t sram_addr_read(paddr_t addr, int len) {
    word_t ret = sram_read(guest_to_sram(addr), len);
#ifdef CONFIG_MTRACE
        Log("sram_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,ret);
#endif
    return ret;
}

void sram_addr_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
    Log("sram_write --- [addr: 0x%08x len: %d data: 0x%08x]",addr,len,data);
#endif
    sram_write(guest_to_sram(addr), len, data);
}
