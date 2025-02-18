#include <cpu/decode.h>
#include <isa.h>
#include <elf.h>
#include "reg.h"
#include <cpu/cpu.h>
#include <locale.h>
#include <cpu/difftest.h>
#include <debug.h>
#include <config.h>
#include "sdb.h"
#include "verilated_fst_c.h"
#include <nvboard.h>

#define OPCODE_JAL  0b1101111
#define OPCODE_JALR 0b1100111
#define PC_FIFO_LEN 10

word_t expr(char *e, bool *success);
Decode s;

typedef struct pc_node{
  uint32_t pc;
  uint32_t dnpc;
  struct pc_node *next;
}PC_node;

PC_node pc_fifo[PC_FIFO_LEN] = {0};

PC_node *pc_write = pc_fifo;
PC_node *pc_read = pc_write;

#ifdef CONFIG_DIFFTEST
// store the last pc
static struct diff_pc{
  paddr_t pc;
  paddr_t dnpc;
}diff;
#endif

extern vluint64_t sim_time;
extern TOP_NAME *dut; extern VerilatedFstC *tfp;
CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
bool ifbreak = false;

#define INST_TYPE_NUM       6
#define TYPE_COUNT          0  
#define TYPE_MEM            1
#define TYPE_JMP            2
#define TYPE_CSR            3
#define TYPE_STATE_TRANS    4
#define TYPE_FENCEI         5

uint64_t ifu_p_counter = 0;
uint64_t lsu_p_counter = 0;
uint64_t lsu_delay_counter = 0;
uint64_t exu_p_counter = 0;

uint64_t idu_count_p_counter = 0;
uint64_t idu_memory_p_counter = 0;
uint64_t idu_jmp_p_counter = 0;
uint64_t idu_csr_p_counter = 0;
uint64_t idu_state_trans_p_counter = 0;
uint64_t idu_fence_p_counter = 0;

// 当前执行的指令是哪种指令
bool type_flag[INST_TYPE_NUM] = {0};
// 每种指令运行的周期总数
uint64_t inst_type_cycle[INST_TYPE_NUM] = {0};

extern "C" void ifu_p_counter_update(){
  ifu_p_counter ++;
}
extern "C" void exu_p_counter_update(){
  exu_p_counter ++;
}
extern "C" void lsu_p_counter_update(){
  lsu_p_counter ++;
}
extern "C" void lsu_delay_counter_update(){
  lsu_delay_counter ++;
}

#define TYPE_R_OPCODE       0b0110011
#define TYPE_I_BASE_OPCODE  0b0010011
#define TYPE_I_JALR_OPCODE  0b1100111
#define TYPE_U_LUI_OPCODE   0b0110111 
#define TYPE_U_AUIPC_OPCODE 0b0010111
#define TYPE_B_OPCODE       0b1100011
#define TYPE_J_JAL_OPCODE   0b1101111
#define TYPE_S_OPCODE       0b0100011
#define TYPE_I_CSR_OPCODE   0b1110011
#define TYPE_I_FENCEI_OPCODE 0b0001111
#define TYPE_I_LOAD_OPCODE  0b0000011
#define TYPE_I_ECALL_FUNC3  0b000


extern "C" void idu_p_counter_update(char opcode, char func3){
  switch (opcode) {
    // 计算
    case TYPE_I_BASE_OPCODE:
    case TYPE_U_LUI_OPCODE:
    case TYPE_U_AUIPC_OPCODE:
    case TYPE_R_OPCODE:
      idu_count_p_counter ++;
      type_flag[TYPE_COUNT] = true;
      break;

    // 访存
    case TYPE_S_OPCODE:
    case TYPE_I_LOAD_OPCODE:
      idu_memory_p_counter ++;
      type_flag[TYPE_MEM] = true;
      break;

    // 跳转
    case TYPE_B_OPCODE:
    case TYPE_J_JAL_OPCODE:
    case TYPE_I_JALR_OPCODE:
      idu_jmp_p_counter ++;
      type_flag[TYPE_JMP] = true;
      break;

    
    case TYPE_I_CSR_OPCODE:
      if (func3 == TYPE_I_ECALL_FUNC3) {
        // 状态转移
        // ebreak -- opcod
        // ecall -- opcode
        // mret
        type_flag[TYPE_STATE_TRANS] = true;
        idu_state_trans_p_counter ++;
      } else {
        // csr指令
        type_flag[TYPE_CSR] = true;
        idu_csr_p_counter ++;
      }
      break;

    case TYPE_I_FENCEI_OPCODE:
      type_flag[TYPE_FENCEI] = true;
      idu_fence_p_counter ++;
      break;
    default: 
      break;
  }
}

size_t write_index = 0;
size_t read_index = 0;
extern "C" void pc_node_init(int pc, int dnpc){
  pc_write[write_index].pc = pc;
  pc_write[write_index].dnpc = dnpc;
  printf("[init] dnpc: 0x%08x pc: 0x%08x\n",pc_write[write_index].dnpc, pc_write[write_index].pc);
  write_index = (write_index + 1) % PC_FIFO_LEN;
}

void pc_get(){
  if(pc_read[read_index].pc == 0x30000000 - 4){
    read_index = (read_index + 1) % PC_FIFO_LEN;
  }
  // printf("dnpc: 0x%08x pc: 0x%08x\n",pc_read[read_index].dnpc, pc_read[read_index].pc);
  cpu.pc = pc_read[read_index].dnpc;
  # if (defined CONFIG_DIFFTEST) || (defined CONFIG_TRACE)
    s.pc = pc_read[read_index].pc;
    s.dnpc = pc_read[read_index].dnpc;
  #endif
  read_index = (read_index + 1) % PC_FIFO_LEN;
}
char inst_finish = 0;
void finish_get(char finish){
  pc_get();
  inst_finish = finish;
  // printf("s.isa.inst.val:0x%08x\n",s.isa.inst.val);
  // printf("inst:0x%08x\n",inst);
  // printf("get inst! \n");
}


#ifdef CONFIG_FTRACE

typedef struct elf_table{
  char *name;
  int NO;
  FILE *ftrace_fp;
  Elf32_Ehdr Elf_header;
  Elf32_Shdr Elf_sec;
  Elf32_Off sym_off;
  Elf32_Off str_off;
  Elf32_Sym Elf_sym;
  Elf32_Xword str_size;
  Elf32_Xword sym_size;
  int sym_num;
  char *strtab;
} ELF; 

#define FILE_NUM 5
static ELF *elf_header = NULL;
static ELF *elf_pool = NULL;
// static ELF *elf_cur = NULL;
static int fileNum = 0;

typedef struct ftrace_file{
  char *name;
  int NO;
  struct ftrace_file *next;
} Ftrace_file;

struct func_call
{
  char *func_name;
  struct func_call *next;
  struct func_call *past;
};


int init_ftrace(Ftrace_file *file_header, Ftrace_file *file_cur)
{
  Assert(file_header != NULL && file_cur != NULL,"Pass file failed!");
  FILE *fp = NULL;
  // 需要读取的文件数
  fileNum = file_cur->NO - file_header->NO;

  // 初始化链表
  elf_pool = (ELF*)malloc(fileNum * sizeof(ELF));
  elf_header = elf_pool;

  // 循环读取文件
  for(int indx = 0; indx < fileNum; indx ++){
    fp = NULL;
    printf("fileNum = %d\n",fileNum);
    elf_header[indx].name = file_header[indx].name;
    elf_header[indx].NO = file_header[indx].NO;
    // 检查文件是否能正常读取
    Assert(file_header[indx].name, "file_header[indx].name is NULL!\n");
    Assert(elf_header[indx].name, "ftrace_file is NULL!\n");

    fp = fopen(elf_header[indx].name, "r");
    Assert(fp, "Can not open '%s'", elf_header[indx].name);

    elf_header[indx].ftrace_fp = fp;

    // 读取ELF header
    int ret = fread(&(elf_header[indx].Elf_header), sizeof(Elf32_Ehdr), 1, elf_header[indx].ftrace_fp);
    if (ret != 1){
      perror("Error reading from file");
    }
      printf("Elf_header.e_ident: %s\n",elf_header[indx].Elf_header.e_ident);

    if (elf_header[indx].Elf_header.e_ident[0] != '\x7f' || memcmp(&(elf_header[indx].Elf_header.e_ident[1]), "ELF", 3) != 0){
      Assert(0, "Not an ELF file!\n");
    }

    Assert(elf_header[indx].Elf_header.e_ident[EI_CLASS] == ELFCLASS32, "Not a 32-bit ELF file\n");
    Assert(elf_header[indx].Elf_header.e_type == ET_EXEC, "Not an exec file\n");

    // 移到.strtab的位置，并进行读取
    fseek(elf_header[indx].ftrace_fp, elf_header[indx].Elf_header.e_shoff + elf_header[indx].Elf_header.e_shentsize * (elf_header[indx].Elf_header.e_shstrndx - 1), SEEK_SET);
    ret = fread(&elf_header[indx].Elf_sec, elf_header[indx].Elf_header.e_shentsize, 1, elf_header[indx].ftrace_fp);
    if (ret != 1){
      perror("Error reading from file");
    }
    elf_header[indx].str_off = elf_header[indx].Elf_sec.sh_offset;
    elf_header[indx].str_size = elf_header[indx].Elf_sec.sh_size;
    elf_header[indx].strtab = (char*)malloc( elf_header[indx].str_size);

    fseek(elf_header[indx].ftrace_fp, elf_header[indx].str_off, SEEK_SET);
    ret = fread(elf_header[indx].strtab, elf_header[indx].str_size, 1, elf_header[indx].ftrace_fp);
    if (ret != 1){
      perror("Error reading from file");
    }

    // get .symtab
    for (int n = 0; n < elf_header[indx].Elf_header.e_shnum; n++){
      fseek(elf_header[indx].ftrace_fp, elf_header[indx].Elf_header.e_shoff + n * elf_header[indx].Elf_header.e_shentsize, SEEK_SET);
      ret = fread(&elf_header[indx].Elf_sec, elf_header[indx].Elf_header.e_shentsize, 1, elf_header[indx].ftrace_fp);
      if (ret != 1){
        perror("Error reading from file");
      }
      if (elf_header[indx].Elf_sec.sh_type == SHT_SYMTAB){
        elf_header[indx].sym_off = elf_header[indx].Elf_sec.sh_offset;
        elf_header[indx].sym_size = elf_header[indx].Elf_sec.sh_entsize;
        elf_header[indx].sym_num = elf_header[indx].Elf_sec.sh_size / elf_header[indx].Elf_sec.sh_entsize;
        continue;
      }
    }
  }
  return 0;
}


void free_strtab()
{
  for(int i = 0; i < fileNum; i ++){
    free(elf_header[i].strtab);
  }
  
}
#endif

#ifdef CONFIG_WATCHPOINT
extern WP *head;
#endif

void device_update();

void ifebreak_func(char ebreak_flag){
	// printf("while key = 0x%08x\n",inst);printf("ebreak-called: pc = 0x%08x inst = 0x%08x\n",cpu.pc,dut->inst)
	if(ebreak_flag != 0) { ifbreak = true; } 
}

void resp_check(char resp){
  switch (resp) {
    case 0b00: break;
    case 0b01:
      Log("[resp_check]-----[code:01]------[EXOKAY, exclusive access success]"); break;
    case 0b10:
      dut->final();
      #ifdef CONFIG_WAVE
      tfp->close();	//关闭波形跟踪文件
      #endif
      Assert(0, "[resp_check]-----[code:10]------[SLVERR, slave error]");
    case 0b11:
      dut->final();
      #ifdef CONFIG_WAVE
      tfp->close();	//关闭波形跟踪文件
      #endif
      Assert(0, "[resp_check]-----[code:11]------[DECERR, decode error]");
    default:
      dut->final();
      #ifdef CONFIG_WAVE
      tfp->close();	//关闭波形跟踪文件
      #endif
      Assert(0, "[resp_check]-----[code:%u]------[ERROR CODE]",(uint32_t)resp);
  }
}

void diff_skip(){
#ifdef CONFIG_DIFFTEST
  // printf("diff_skip\n");
  difftest_skip_ref();
#endif
}

static void trace_and_difftest(){
#ifdef CONFIG_ITRACE_COND
  if (CONFIG_ITRACE_COND)
  {
    log_write("%s\n", s.logbuf);
  }
#endif
  if (g_print_step)
  {
    IFDEF(CONFIG_ITRACE, puts(s.logbuf));
  }
#ifdef CONFIG_WATCHPOINT
  bool success = true;
  uint32_t addr = 0;

  WP *index = head;
  while (index != NULL){
    addr = expr(index->target, &success);
    Assert(success,"Make_token fail!");
    // printf("index->target: %s, addr: 0x%08x, index->data: 0x%08x\n",index->target,addr,index->data);
    if(addr != index->data){
      npc_state.state = NPC_STOP;
      index->times += 1;

      printf("\n\033[105m Hardware watchpoint %d: %s \033[0m\n", index->NO, index->target);
      printf("Old value = 0x%08x\n", index->data);
      printf("New value = 0x%08x\n\n", addr);

      index->data = addr;
      return;
    }

    index = index->next;
  }
#endif

#ifdef CONFIG_DIFFTEST
  for(int i = 0; i < RISCV_GPR_NUM; i ++){
    cpu.gpr[i] = R(i);
  }
  cpu.mcause = dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[0];
  cpu.mepc = dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[2];
  cpu.mstatus = dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[1];
  cpu.mtvec = dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[3];
  cpu.mventorid = dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[4];
  cpu.marchid = dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_CSR__DOT__csr[5];
//  printf("trace_and_difftest diff.pc=%x diff.dnpc=%x\n",diff.pc,diff.dnpc);
 IFDEF(CONFIG_DIFFTEST, difftest_step(diff.pc, diff.dnpc));
#endif

 

  return;
}

#ifdef CONFIG_FTRACE
char *convertTo_2(char args){
  char *result = (char *)malloc(5);
  int num = 0;

  if(args >= 'a' && args <= 'f'){
    num = (int)args - (int)'a' + 10;
  }
  else {
    num = (int)args - (int)'0';
  }

  int flag = 8;
  //15 -> 8 + 4 + 2 + 1
  //5 -> 4 + 1
  //0
  for(int n = 0; n < 4; n ++){
    //为0 则该位之后的低位均为0
    if(!num){
      for(; n < 4; n ++) result[n] = '0';
      break;
    }

    result[n] = num / flag + '0';
    if(num / flag) num -= flag;
    flag /= 2;
  }
  result[4] = '\0';
  return result;
}
#endif

void inst_get(int inst){
  s.isa.inst.val = inst;
  // printf("s.isa.inst.val:0x%08x\n",s.isa.inst.val);
  // printf("inst:0x%08x\n",inst);
  // printf("get inst! \n");
}

char inst_invalid = 0;
void inst_invalid_get(char invalid){
  inst_invalid = invalid;
  // printf("s.isa.inst.val:0x%08x\n",s.isa.inst.val);
  // printf("inst:0x%08x\n",inst);
  // printf("get inst! \n");
}





#ifndef CONFIG_ISA_loongarch32r
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
#endif
uint64_t clk_cycle = 0;

void per_clk_cycle(){
  do {
    dut->clock ^= 1;
    dut->eval();
    #ifdef CONFIG_WAVE
    tfp->dump(sim_time);
    sim_time++;
    #endif
    
  }while(dut->clock == 1);
  clk_cycle += 1;
  // printf("clk = %d\n",dut->clock);
}



void per_inst_cycle(){
  // printf("dut.pc = [0x%08x]!\n",cpu.pc);
  uint32_t inst_cycle = clk_cycle;
  do {
    // printf("dut.pc = [0x%08x]!\n",cpu.pc);
    nvboard_update();
    per_clk_cycle();
    // printf("unfinshed!\n");
  }while(inst_finish == 0);
  inst_finish = 0;
  size_t i = 0;
  // while (1) {
  //   if(i >= INST_TYPE_NUM){dut->final();
  //       #ifdef CONFIG_WAVE
  //       tfp->close();	//关闭波形跟踪文件
  //       #endif 
  //       panic("Error inst statistic!--[PC:0x%08x]",cpu.pc);}
  //   if (type_flag[i]) {
  //     inst_type_cycle[i] = inst_type_cycle[i] + (clk_cycle - inst_cycle);
  //     type_flag[i] = false;
  //     break;
  //   }
  //   i ++;
  // }
  // printf("finished dut.pc = [0x%08x]!\n",cpu.pc);
}

/* let CPU conduct current command and renew PC */
static void exec_once()
{
  per_inst_cycle();
  // inst invalid check
  if(inst_invalid != 0){
    Log("Invalid instruction!");
    invalid_inst(cpu.pc);
  }

  // ebreak check
  if(ifbreak){
    printf("\nebreak!\n");
    // printf("ebreak: pc = 0x%08x inst = 0x%08x\n",cpu.pc,dut->inst);
    // set_npc_state(NPC_STOP, cpu.pc, 0);ifbreak = false;
    NPCTRAP(cpu.pc, R(10));
  }

  #if (defined CONFIG_TRACE) || (defined CONFIG_TRACE)
  s.snpc = s.pc + 4;
  #endif
  // printf("inst = [0x%08x]----pc = [0x%08x]\n",*(uint32_t*)inst,cpu.pc);

  #ifdef CONFIG_ITRACE
  char *p = s.logbuf;
  p += snprintf(p, sizeof(s.logbuf), FMT_WORD ":", s.pc);
  int ilen = s.snpc - s.pc;
  int i;
  uint8_t *inst = (uint8_t *)&s.isa.inst.val;
  
  for (i = ilen - 1; i >= 0; i--)
  {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0)
    space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  disassemble(p, s.logbuf + sizeof(s.logbuf) - p,
              MUXDEF(CONFIG_ISA_x86, s.snpc, s.pc), (uint8_t *)&s.isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif

#ifdef CONFIG_FTRACE

  // 1.判断函数调用/函数返回
  uint32_t m = s.isa.inst.val;
  // printf("m = %08x\n",m);
  bool if_return = false;
  bool if_conduct = false;
  // bool if_recursion = false;

  // opcode rd rs1
  uint32_t opcode = BITS(m, 6, 0);
  uint32_t rd = BITS(m, 11, 7);
  uint32_t rs1 = BITS(m, 19, 15);

  // 2.1 jal or jalr

  // 2.1.1 jal  函数调用 jal,  rd = x1, imm = ***
  if (opcode == OPCODE_JAL && (rd == 1 || rd == 5)){
    if_return = false;
    if_conduct = true;
  }

  // 2.1.2 jalr 函数调用 or 函数返回

  // 判断出jalr
  else if (opcode == OPCODE_JALR){
    // 函数返回 jalr rs1 = x1, rd = x0 POP
    if ((!(rd == 1 || rd == 5)) && (rs1 == 1 || rs1 == 5)){
      if_return = true;
      if_conduct = true;
    }
    // 函数调用 PUSH
    else if ((rd == 1 || rd == 5) && (!(rs1 == 1 || rs1 == 5))){
      if_return = false;
      if_conduct = true;
    }
    else if ((rd == 1 || rd == 5) && (rs1 == 1 || rs1 == 5) && rd != rs1){
      // assert(0);
      // if_recursion = true;
      if_return = false;
      if_conduct = true;
    }
    else if ((rd == 1 || rd == 5) && (rs1 == 1 || rs1 == 5) && rd == rs1){
      if_return = false;
      if_conduct = true;
    }
  }

  if (if_conduct){
    // 3.找到是哪个函数
    Elf32_Sym sym;
    int ret = 0;
    int indx = 0;
    char name[20] = {0};

    for(indx = 0; indx < fileNum; indx ++){
      int n = elf_header[indx].sym_num - 1;
      for(; n >= 0; n--){
        // 3.1读取符号表
        fseek(elf_header[indx].ftrace_fp, elf_header[indx].sym_off + n * elf_header[indx].sym_size, SEEK_SET);
        ret = fread(&sym, sizeof(Elf32_Sym), 1, elf_header[indx].ftrace_fp);
        if (ret != 1){
          perror("Read error");
        }
        // strncpy(name, elf_header[indx].strtab + sym.st_name, 19); printf("name: %s\n",name);
        // 3.2找到对应的一行
        // 3.2.1 函数返回 是返回到原函数的中间位置
        if (if_return && (sym.st_value <= s.pc && sym.st_value + sym.st_size >= s.pc) && sym.st_info == 18){
          // printf("sym.st_value = 0x%08x sym.st_size = %d \n",sym.st_value,sym.st_size);
          break;
        }
        // 3.2.2 函数调用 是跳转到一个新函数的头部
        else if (!if_return && sym.st_value == s.dnpc && sym.st_info == 18){
          // printf("sym.st_value = 0x%08x s.dnpc = 0x%08x \n",sym.st_value,s.dnpc);
          break;
        }
      }
      if(n >= 0) break;
      if (indx == fileNum - 1){
          // if_same = true;
          Assert(0, "Fail in searching!");
        }
    }
    
    
      // 取出函数名称
      strncpy(name, elf_header[indx].strtab + sym.st_name, 19);
    // 4.调用的函数放入一个数据结构，返回函数放入一个数据结构
    static int index = 1;

    if (if_return){
      // 函数返回，将函数名所在链表节点抽出
        // Assert(name, "name NULL!");
        if(strcmp(name,"putch") != 0) printf("index %d-> 0x%08x: \033[106m ret [%s] \033[m\n", index, cpu.pc, name);
        index++;
    }
    else{
      // 函数调用，将函数名放入链表
      if(strcmp(name,"putch") != 0) printf("index %d-> 0x%08x: \033[102m call[%s @0x%08x] \033[m\n", index, cpu.pc, name, s.dnpc);
      #ifdef CONFIG_FTRACE_PASS
      if(strcmp(name,"putch") != 0) 
        for(int i = 10; i < 15; i++){
          printf("\033[104m %d %s: \033[0m \t0x%08x\n",i,regs[i],dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_23060025_cpu__DOT__ysyx_23060025_RegisterFile__DOT__rf[i]);
        }
      #endif
      index++;
    }
  }

#endif

}

/* stimulate the way CPU works ,get commands constantly */
static void execute(uint64_t n) {
  for (; n > 0; n--)
  {
    exec_once();
    g_nr_guest_inst++;  //记录客户指令的计时器
    //由于rtl对reg的更改是在下一个时钟周期上升沿，而nemu对reg的更改是即时的
    //所以这里要整个往后延迟一个周期
    #ifdef CONFIG_DIFFTEST
    diff.pc = s.pc;
    diff.dnpc = s.dnpc;
    #endif
    // if(cpu.pc != 0x80000000) {
    trace_and_difftest();
// }
  
    //当npc_state.state被设置为NPC_STOP时，npc停止执行指令
    if (npc_state.state != NPC_RUNNING)
      break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}
  uint64_t access_cycle = 0;
  uint64_t penalty_cycle = 0;
  uint64_t cache_hit = 0;

  void cache_cycle_statistic(char state){
    switch (state){
      // STATE_CHECK STATE_PASS
      case 0b001: // STATE_CHECK
      case 0b100: // STATE_PASS
        access_cycle ++;
        break;

      // STATE_LOAD
      case 0b010: // STATE_ADDR_HAND_SHAK
      case 0b011: // STATE_LOAD
      case 0b101: // STATE_UPDATE_REG
        penalty_cycle ++;
        break;
      case 0b111:
        break;
      default:
        dut->final();
        #ifdef CONFIG_WAVE
        tfp->close();	//关闭波形跟踪文件
        #endif
        Assert(0, "Invalid state!");
        break;
    }
  }

  void cache_hit_statistic(){
    cache_hit ++;
  }


// uint64_t ifu_p_counter = 0;
// uint64_t lsu_p_counter = 0;
// uint64_t exu_p_counter = 0;
// uint64_t idu_count_p_counter = 0;
// uint64_t idu_memory_p_counter = 0;
// uint64_t idu_jmp_p_counter = 0;
// uint64_t idu_csr_p_counter = 0;
// uint64_t idu_state_trans_p_counter = 0;

// host time spent = 58,649,453 us
// total guest instructions = 721,836
// simulation frequency       = 12,307 inst/s
// IPC                        = 0.035862 inst/cycle
// CPI                        = 27.884979 cycle/inst
// ifu_p_counter              = 721836	    inst
// lsu_p_counter              = 182100	    inst
// lsu_avg_delay_counter      = 15.769006	    cycle
// exu_p_counter              = 721835	    inst
// idu_count_p_counter        = 355176	    inst --	820627	     cycle/inst] --	204529%] [49.204529%]
// idu_memory_p_counter       = 182100	    inst --	455673	     cycle/inst] --	227339%] [25.227339%]
// idu_jmp_p_counter          = 184559	    inst --	195385	     cycle/inst] --	567997%] [25.567997%]
// idu_csr_p_counter          = 0	    inst --	n	le/inst] --	00000%]                    [0.000000%]
// idu_state_trans_p_counter  = 1	    inst --	.000000	     cycle/inst] --	00139%]      [0.000139%]
// simulation frequency       = 343,198 cycle/s

static void statistic()
{
  // g_nr_guest_inst：执行的指令数
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  printf("host time spent = " NUMBERIC_FMT " us\n", g_timer);
  printf("total guest instructions = " NUMBERIC_FMT "\n", g_nr_guest_inst);
  printf("total cycle = " NUMBERIC_FMT "\n", clk_cycle);
  if (g_timer > 0){
    printf("simulation frequency       = " NUMBERIC_FMT " inst/s\n", g_nr_guest_inst * 1000000 / g_timer);
    printf("IPC                        = %f inst/cycle  \n", (float)g_nr_guest_inst / clk_cycle); 
    printf("CPI                        = %f cycle/inst  \n", (float)clk_cycle / g_nr_guest_inst); 

    printf("ifu_p_counter              = %lu\tinst\n", ifu_p_counter); 
    printf("lsu_p_counter              = %lu\tinst\n", lsu_p_counter); 
    printf("lsu_avg_delay_counter      = %f\tcycle\n", (float)lsu_delay_counter/lsu_p_counter); 
    printf("exu_p_counter              = %lu\tinst\n", exu_p_counter); 
    printf("idu_count_p_counter        = %lu\tinst --\t[%f\t cycle/inst] --\t[%f%%]\n", idu_count_p_counter, (float)inst_type_cycle[TYPE_COUNT]/idu_count_p_counter, (float)idu_count_p_counter/g_nr_guest_inst*100); 
    printf("idu_memory_p_counter       = %lu\tinst --\t[%f\t cycle/inst] --\t[%f%%]\n", idu_memory_p_counter, (float)inst_type_cycle[TYPE_MEM]/idu_memory_p_counter, (float)idu_memory_p_counter/g_nr_guest_inst*100); 
    printf("idu_jmp_p_counter          = %lu\tinst --\t[%f\t cycle/inst] --\t[%f%%]\n", idu_jmp_p_counter, (float)inst_type_cycle[TYPE_JMP]/idu_jmp_p_counter, (float)idu_jmp_p_counter/g_nr_guest_inst*100); 
    printf("idu_csr_p_counter          = %lu\tinst --\t[%f\t cycle/inst] --\t[%f%%]\n", idu_csr_p_counter, (float)inst_type_cycle[TYPE_CSR]/idu_csr_p_counter, (float)idu_csr_p_counter/g_nr_guest_inst*100); 
    printf("idu_state_trans_p_counter  = %lu\tinst --\t[%f\t cycle/inst] --\t[%f%%]\n", idu_state_trans_p_counter, (float)inst_type_cycle[TYPE_STATE_TRANS]/idu_state_trans_p_counter, (float)idu_state_trans_p_counter/g_nr_guest_inst*100); 
    printf("idu_fence_p_counter        = %lu\tinst --\t[%f\t cycle/inst] --\t[%f%%]\n", idu_fence_p_counter, (float)inst_type_cycle[TYPE_FENCEI]/idu_fence_p_counter, (float)idu_fence_p_counter/g_nr_guest_inst*100); 
    // access_time--cache接收访存请求到得出命中结果所需的时间
    // miss_penalty--为cache缺失时的代价, 此处即访问DRAM的时间
    uint64_t cycle_per_sec = clk_cycle * 1000000 / g_timer;
    float hit_percent = (float)cache_hit/ifu_p_counter;
    float access_time = (float)access_cycle / ifu_p_counter;
    float miss_penalty = (float)penalty_cycle / (ifu_p_counter - cache_hit);
    printf("Average Memory Access Time: %f cycle ---[hit_percent: %f%%]\n", (access_time + (1 - hit_percent) * miss_penalty), hit_percent*100);
    printf("Miss Penalty Time: %f cycle\n", miss_penalty);
    printf("simulation frequency       = " NUMBERIC_FMT " cycle/s\n", cycle_per_sec);
  } 
  else
    Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n)
{
  // g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state){
			case NPC_END:
			case NPC_ABORT:
				printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
				dut->final();
        #ifdef CONFIG_WAVE
        tfp->close();	//关闭波形跟踪文件
        #endif
        return;
			default:
			npc_state.state = NPC_RUNNING;
		}	

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (npc_state.state){
			case NPC_RUNNING:
				npc_state.state = NPC_STOP;
				break;

			case NPC_END:
			case NPC_ABORT:
				Log("npc: %s at pc = " FMT_WORD,
					(npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) : (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
					npc_state.halt_pc);
			case NPC_QUIT:
				Log("quit!\n");
        statistic();
		}
}