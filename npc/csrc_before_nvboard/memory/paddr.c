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
// extern "C" void pmem_write_task(int waddr, int wdata, char wmask) {
//   // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
//   // `wmask`中每比特表示`wdata`中1个字节的掩码,
//   // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
//   // printf("pmem_write_task pc = 0x%08x\n",cpu.pc);
//   // printf("wmask = 0x%01u\n",wmask);
//   // printf("waddr = 0x%08x\n",(paddr_t)waddr);
//   // printf("wdata = 0x%08x\n",(paddr_t)wdata);
//   if (wmask == 0) {
//       return;
//     }
//   #ifdef CONFIG_DEVICE
//     #ifdef CONFIG_SERIAL_MMIO 
//       if(waddr == CONFIG_SERIAL_MMIO) {
//       // assert(0);
//     // Log("Write device --- [addr: 0x%08x data: 0x%08x]",waddr,wdata);
//     // putchar(wdata);
//     }
//     #endif
//   #endif
//   // else {
//     int len = 0; 
//     switch (wmask){
//       case 0x1: len = 1; break;
//       case 0x2: len = 2; break;
//       case 0x4: len = 4; break;
//       IFDEF(CONFIG_ISA64, case 0x8: len = 8; return);
//       IFDEF(CONFIG_RT_CHECK, default: assert(0));
//     }
//     vaddr_write((vaddr_t)waddr, (vaddr_t)len, (word_t)wdata);
//   // }
// }

static word_t pmem_read(paddr_t addr,int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

// static void pmem_write(paddr_t addr, int len, word_t data) {
//   host_write(guest_to_host(addr), len, data);
// }

static void out_of_bound(paddr_t addr) {
  // panic("address = " FMT_PADDR " is out of bound of psram [" FMT_PADDR ", " FMT_PADDR "] or flash [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
  //     addr, PSRAM_LEFT, PSRAM_RIGHT, FLASH_LEFT, FLASH_RIGHT, cpu.pc);
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


extern "C" void flash_read(int32_t addr, int32_t *data) {
  // printf("flash_read\n");
  if (likely(in_pmem(addr))) {
    *data = pmem_read(addr, 4);
    // uint32_t tmp = *data;
    // printf("flash_read [0x%08x\n",tmp);
    // *data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
    // printf("flash_read ---  [addr: 0x%08x rdata: 0x%08x]\n", addr, *data);
#ifdef CONFIG_MTRACE
    
#endif
    return;
  }
  out_of_bound_flash(addr);
  return;
}

void flash_read_sdb(int32_t addr, int32_t *data, int len) {
  // printf("flash_read\n");
  if (likely(in_pmem(addr))) {
    *data = pmem_read(addr, len);
    // uint32_t tmp = *data;
    // printf("flash_read [0x%08x\n",tmp);
    // *data = (BITS(tmp,7,0) << 24) | (BITS(tmp,15,8) << 16) | (BITS(tmp,23,16) << 8) | (BITS(tmp,31,24));
    // printf("flash_read ---  [addr: 0x%08x rdata: 0x%08x]\n", addr, *data);
#ifdef CONFIG_MTRACE
    
#endif
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

// vaddr_t paddr_read(paddr_t addr,int len) {
//   printf("paddr_read\n");
// 	if (likely(in_pmem(addr))) {
//     word_t rdata = pmem_read(addr,len);
//     Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
//     #ifdef CONFIG_MTRACE
//       // Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
//     #endif
//     return rdata;
//   }
//   // printf("read device\n");
//   IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
//   // printf("read device---out of bound\n");
//   out_of_bound(addr);
//   return 0;
// }
void psram_read(int32_t addr, int32_t *data);
void psram_read_sdb(int32_t addr, int32_t *data, int len);
vaddr_t paddr_read(paddr_t addr,int len) {
  // printf("paddr_read\n");
	if (likely(in_psram(addr))) {
    addr = addr & 0x1fffffff;
    int32_t rdata = 0;
    psram_read_sdb(addr,&rdata,len);
    Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      // Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
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
    Log("sdram_read ---  [addr: 0x%08x len: %d rdata: 0x%x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      // Log("sdram_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
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
    Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      // Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
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

// void paddr_write(vaddr_t addr, vaddr_t len, word_t data) {
//   printf("write device\n");
//   #ifdef CONFIG_MTRACE
//   // Log("paddr_write --- [addr: 0x%08x len: %d data: 0x%08x]",addr,len,data);
//   #endif
//   if (likely(in_pmem(addr))) { return pmem_write(addr, len, data);}
//   // printf("write device\n");

//   IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
//   // printf("paddr_write device---out of bound\n");

//   out_of_bound(addr);
// }
