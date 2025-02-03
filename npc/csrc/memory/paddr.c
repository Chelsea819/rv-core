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
#include <memory/host.h>
#include <memory/vaddr.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>
#include <common.h>
#include <debug.h>
#include <sys/types.h>
#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
//{}使用聚合初始化把数组初始化为0
#endif
void sdram_read_sdb(int32_t addr, int32_t *data, int len);
extern TOP_NAME *dut; extern VerilatedFstC *tfp;
uint8_t* guest_to_host(paddr_t paddr) { 
  // printf("pmem: 0x%08x\n",pmem);
  // printf("paddr: 0x%08x\n",paddr);
  // printf("CONFIG_MBASE: 0x%08x\n",CONFIG_MBASE);
  paddr = paddr & 0x0fffffff;
  return (uint8_t*)pmem + paddr; 
}
// paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

extern "C" int pmem_read_task(int raddr, char wmask) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回给`rdata`
  // printf("read! wmask = %d\n", wmask);
  // printf("raddr = 0x%08x\n",raddr); 
  // vaddr_t rdata = vaddr_read((paddr_t)(raddr & ~0x3u), 4);
  if (wmask == 0) {
    return 0;
  }
  #ifdef CONFIG_DEVICE
    #ifdef CONFIG_RTC_MMIO 
    if(raddr == CONFIG_RTC_MMIO) { 
      // Log("Read device --- [addr: 0x%08x  len: %d]",raddr,len);  
      // time_t current_time;
      // time(&current_time); // 获取系统时间戳
      // return current_time;
    }
    #endif
    #ifdef CONFIG_SERIAL_MMIO 
    if(raddr == CONFIG_SERIAL_MMIO) { 
      // Log("Read device --- [addr: 0x%08x  len: %d]",raddr,len);  
      // time_t current_time;
      // time(&current_time); // 获取系统时间戳
      // return current_time;
    }
    #endif
  #endif
  return vaddr_read((paddr_t)raddr, 4);
}


static word_t pmem_read(paddr_t addr,int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of psram [" FMT_PADDR ", " FMT_PADDR "] or flash [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PSRAM_LEFT, PSRAM_RIGHT, FLASH_LEFT, FLASH_RIGHT, cpu.pc);
}

static void out_of_bound_flash(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of flash [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, FLASH_LEFT, FLASH_RIGHT, cpu.pc);
}

void init_mem(){
    uint32_t *p = (uint32_t *)pmem;
    int i;
    for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
        p[i] = 0;
    }
	return ;
}
#define BITMASK(bits) ((1ull << (bits)) - 1)

//位抽取
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog


void flash_read(int32_t addr, int32_t *data) {
  // printf("flash_read\n");
  if (likely(in_pmem(addr))) {
    *data = pmem_read(addr, 4);
#ifdef CONFIG_MTRACE
      Log("flash_read ---  [addr: 0x%08x rdata: 0x%08x pc: 0x%08x]", addr, *data, cpu.pc);
#endif
    return;
  }
  out_of_bound_flash(addr);
  return;
}

void flash_read_sdb(int32_t addr, int32_t *data, int len) {
  if (likely(in_pmem(addr))) {
    *data = pmem_read(addr, len);
    return;
  }
  out_of_bound_flash(addr);
  return;
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
  printf("mrom_read\n");
//   if (likely(in_pmem(addr))) {
//     *data = pmem_read(addr, 4);
// #ifdef CONFIG_MTRACE
//     // Log("mrom_read ---  [addr: 0x%08x rdata: 0x%08x]", addr, 
//     //     data);
// #endif
//     return;
//   }
  out_of_bound(addr);
  return;
}

void psram_read(int32_t addr, int32_t *data);
void psram_read_sdb(int32_t addr, int32_t *data, int len);
vaddr_t paddr_read(paddr_t addr,int len) {
  // printf("paddr_read\n");
	if (likely(in_psram(addr))) {
    addr = addr & 0x1fffffff;
    int32_t rdata = 0;
    psram_read_sdb(addr,&rdata,len);
    // Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #endif
    switch (len) {
      case 1: return rdata & 0x000000ff;
      case 2: return rdata & 0x0000ffff;
      case 4: return rdata;
      IFDEF(CONFIG_ISA64, case 8: return rdata & 0xffffffffffffffff;);
      default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
    }
  }else if (likely(in_sdram(addr))) {
    addr = addr & 0x03ffffff;
    int32_t rdata = 0;
    sdram_read_sdb(addr,&rdata,len);
    // Log("sdram_read ---  [addr: 0x%08x len: %d rdata: 0x%x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      Log("sdram_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #endif
    switch (len) {
      case 1: return rdata & 0xff000000;
      case 2: return rdata & 0xffff0000;
      case 4: return rdata;
      IFDEF(CONFIG_ISA64, case 8: return rdata & 0xffffffffffffffff;);
      default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
    }
  } else if (likely(in_pmem(addr))) {
    addr = addr & 0x0fffffff;
    int32_t rdata = 0;
    flash_read_sdb(addr,&rdata,len);
    // Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #endif
    switch (len) {
      case 1: return rdata & 0xff000000;
      case 2: return rdata & 0xffff0000;
      case 4: return rdata;
      IFDEF(CONFIG_ISA64, case 8: return rdata & 0xffffffffffffffff;);
      default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
    }
  } 
  // printf("read device\n");
  // IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  // printf("read device---out of bound\n");
  out_of_bound(addr);
  return 0;
}

