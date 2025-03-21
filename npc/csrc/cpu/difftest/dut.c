#include <dlfcn.h>

#include <isa.h>
#include <cpu/cpu.h>
#include <memory/vaddr.h>
#include <memory/paddr.h>
#include <string.h>
#include <utils.h>
#include <difftest-def.h>
#include <debug.h>
#include "common.h"
#include "reg.h"
#include "config.h"
#include "verilated_fst_c.h"

#ifdef CONFIG_WAVE
extern VerilatedFstC *tfp;
#endif
extern CPU_state cpu;

#ifdef CONFIG_DIFFTEST
int isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
// #define FLASH_SIZE 1024
#define FLASH_ADDR 0x30000000

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *duti, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NEMU
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}


void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  //打开传入的动态库文件
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  //通过动态链接对动态库中的上述API符号进行符号解析和重定位, 返回它们的地址
  ref_difftest_memcpy = (void (*)(paddr_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *duti, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);
  
  //对REF的DIffTest功能进行初始化
  ref_difftest_init(port);
  
  //将DUT的guest memory拷贝到REF中
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);

  // ref_difftest_memcpy(FLASH_ADDR, guest_to_host_flash(0), FLASH_SIZE, DIFFTEST_TO_REF);

  // ref_difftest_memcpy(RESET_VECTOR, guest_to_flash(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  //将DUT的寄存器状态拷贝到REF中
  // printf("cpu.pc = %x\n",cpu.pc);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);

  // init_skip_pool();

}

static void checkregs(CPU_state *ref, vaddr_t npc) {
  int flag = 0;
  if ((flag = isa_difftest_checkregs(ref, npc)) != 0) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = npc;
    for(int i = 0; i < RISCV_GPR_NUM; i++){
      if (flag == i + 1) 
        printf("\033[105m %d:  \t0x%08x\033[0m  \033[106m %s:  \t0x%08x\033[0m\n",i,ref->gpr[i],regs[i],cpu.gpr[i]);
      else
        printf("\033[103m %d: \033[0m \t0x%08x  \033[104m %s: \033[0m \t0x%08x\n",i,ref->gpr[i],regs[i],cpu.gpr[i]);
    }
    if (flag == 33) 
      printf("\033[105m ref->pc: \033[0m \t0x%08x  \033[106m cpu.pc: \033[0m \t0x%08x\n",ref->pc,npc);
    else
      printf("\033[103m ref->pc: \033[0m \t0x%08x  \033[104m cpu.pc: \033[0m \t0x%08x\n",ref->pc,npc);
    if (flag >= 34 && flag <= 37) {
        printf("\033[103m %d: \033[0m \t0x%08x  \033[104m %s: \033[0m \t0x%08x\n",0,ref->mcause,"macuse",cpu.mcause);
        printf("\033[103m %d: \033[0m \t0x%08x  \033[104m %s: \033[0m \t0x%08x\n",1,ref->mepc,"mepc",cpu.mepc);
        printf("\033[103m %d: \033[0m \t0x%08x  \033[104m %s: \033[0m \t0x%08x\n",2,ref->mstatus,"mstatus",cpu.mstatus);
        printf("\033[103m %d: \033[0m \t0x%08x  \033[104m %s: \033[0m \t0x%08x\n",3,ref->mtvec,"mtvec",cpu.mtvec);
    }
    dut->final();
  #ifdef CONFIG_WAVE
    tfp->close();
  #endif
    printf("\33[1;31m Catch difference! \33[0m\n");
    set_npc_state(NPC_ABORT, npc, -1);

    // NEMUTRAP(thispc, npc);
    // Assert(0,"Catch difference!\n");
  }
}

// static void check_mem(void *buf, vaddr_t pc, int len, paddr_t addr) {
//   paddr_t* dut = (paddr_t*)(guest_to_host(addr));
//   int ret = memcmp(dut, buf, len);
//   if (ret != 0) {
//     for (int i = 0;i < len;i ++){
//       printf("\033[105m 0x%08x: \033[0m \t0x%08x-----ref: \t0x%08x\n",addr + i,vaddr_read(addr + i,4), ((uint32_t *)buf)[i]);
//     }
//   }
//   Assert(ret == 0, "mem difference!");
// }

//进行逐条指令执行后的状态对比
void difftest_step(vaddr_t pc, vaddr_t npc) {
  CPU_state ref_r;
  
  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    if (ref_r.pc == npc) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }

  //该指令的执行结果以NEMU的状态为准
  if (is_skip_ref) {

    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }
// ref 0x8000 0x8004 0x8008 0x800c
// dut 0x8000 0x8000 0x8004 0x8008

// ref 0x8004 0x8008 0x800c 0x800f
// dut 0x8004 0x8008 0x800c 0x800f
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  // uint8_t ref_mem[4096] = {0};
  // ref_difftest_memcpy(0x8009df00, ref_mem, 256, DIFFTEST_TO_DUT);
  // check_mem(ref_mem, pc, 256,0x8009df00 );
  checkregs(&ref_r, npc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
