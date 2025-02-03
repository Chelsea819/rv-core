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
#include <nvboard.h>
#include "verilated.h"
#include "verilated_fst_c.h"
#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
//{}使用聚合初始化把数组初始化为0
#endif

extern VerilatedFstC *tfp;
extern TOP_NAME *dut; 
uint8_t* guest_to_host(paddr_t paddr) { 
  // printf("pmem: 0x%08x\n",pmem);
  // printf("paddr: 0x%08x\n",paddr);
  // printf("CONFIG_MBASE: 0x%08x\n",CONFIG_MBASE);
  return pmem + paddr - CONFIG_MBASE; 
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
extern "C" void pmem_write_task(int waddr, int wdata, char wmask) {
  if (wmask == 0) {
      return;
    }
  #ifdef CONFIG_DEVICE
    #ifdef CONFIG_SERIAL_MMIO 
    if(waddr == CONFIG_SERIAL_MMIO) {
    // Log("Write device --- [addr: 0x%08x data: 0x%08x]",waddr,wdata);
    // putchar(wdata);
  }
    #endif
  #endif
  if((wmask & 0b0001) != 0) vaddr_write((waddr), 1,BITS(wdata,7,0) << 24);
  if((wmask & 0b0010) != 0) vaddr_write((waddr + 1), 1,BITS(wdata,15,8) << 24);
  if((wmask & 0b0100) != 0) vaddr_write((waddr + 2), 1,BITS(wdata,23,16) << 24);
  if((wmask & 0b1000) != 0) vaddr_write((waddr + 3), 1,BITS(wdata,31,24) << 24);
}

static word_t pmem_read(paddr_t addr,int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  dut->final();
#ifdef CONFIG_WAVE
  tfp->close(); //关闭波形跟踪文件
#endif
  delete dut;
  nvboard_quit();
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem(){
    uint32_t *p = (uint32_t *)pmem;
    int i;
    for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
        p[i] = 0;
    }
	return ;
}

vaddr_t paddr_read(paddr_t addr,int len) {
  // Log("paddr_read ---  [addr: 0x%08x len: %d]",addr,len);
	if (likely(in_pmem(addr))) {
    word_t rdata = pmem_read(addr,len);
    // Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #ifdef CONFIG_MTRACE
      Log("paddr_read ---  [addr: 0x%08x len: %d rdata: 0x%08x]",addr,len,rdata);
    #endif
    return rdata;
  }
  // printf("read device\n");
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  // printf("read device---out of bound\n");
  out_of_bound(addr);
  return 0;
}

void paddr_write(vaddr_t addr, vaddr_t len, word_t data) {
  // Log("paddr_write --- [addr: 0x%08x len: %d data: 0x%08x]",addr,len,data);
  #ifdef CONFIG_MTRACE
  Log("paddr_write --- [addr: 0x%08x len: %d data: 0x%08x]",addr,len,data);
  #endif
  if (likely(in_pmem(addr))) { return pmem_write(addr, len, data);}
  // printf("write device\n");

  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  // printf("paddr_write device---out of bound\n");

  out_of_bound(addr);
}