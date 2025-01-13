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

#include <cstdint>
#include <cstdlib>
#include <isa.h>
#include <cpu/cpu.h>
#include <cpu/difftest.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sdb.h>
#include <memory/vaddr.h>
#include "config.h"
#include "debug.h"
#include "utils.h"

void init_wp_pool();

static int is_batch_mode = false;
extern WP *head;
WP* new_wp(char *args);
void free_wp(WP *wp);
vaddr_t paddr_read(paddr_t addr,int len);
void init_regex();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
  static char *line_read = NULL;

  if (line_read)
  {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read)
  {
    add_history(line_read);
  }

  return line_read;
}

static char too_lessArg(char *args){
  if(args == NULL) {
    Log("Without necessary arguments!");
    return 1;
  }
  return 0;
}

static int cmd_c(char *args)
{
  /*Simulate how the CPU works.*/
  cpu_exec(-1);
  return 0;
}

uint32_t convert_ten(char *args){
  uint32_t flag = 1;
  uint32_t flag_neg = 0;
  uint32_t n = 0;

  int i = strlen(args) - 1;
  for(  ;i >= 0;i --){
    if(args[i] == 'n'){
      flag_neg += 1;
      continue;
    }
    n += ((int)args[i] - (int)'0') * flag;
    flag = flag * 10;
  }
  while(flag_neg --) n = n * (-1);
  return n;
}

uint32_t convert_16(char *args){
  uint32_t addr = 0;
  uint32_t flag = 1;
  for(int i = strlen(args) - 1;i >= 2;i --){
    if(args[i] >= 'a' && args[i] <= 'f'){
      addr += ((int)args[i] - (int)'a' + 10) * flag;
    }
    else {
      addr += ((int)args[i] - (int)'0') * flag;
  }
    flag *= 16;
  }
  return addr;
}

static int cmd_si(char *args){
  uint64_t n = 0;
  if(args == NULL)  n = 1;
  else {
    for(int i = 0; i < strlen(args) ; i ++){
      if(args[i] > '9' || args[i] < '0'){
        Log("Please input number!");
        return 0;
      }
    }
    n = convert_ten(args);
  }
  cpu_exec(n);
  return 0;
}

static int cmd_q(char *args)
{
  if(npc_state.state != NPC_ABORT)
    npc_state.state = NPC_QUIT;
  return -1;
}

static void watchPoints_display(){
  WP *index = head;
  if(index == NULL ) {
    printf("Now, no WP in watchPool!\n");
    return;
  }
  //printf("head : %p\n",index);
  //printf("head->next : %p\n",index->next);
  printf("\033[92m Num \tTYpe \tDisp \tEnb \tAddress \t What \033[m \n");
  while(index != NULL){
    printf("\033[92m %d \thw watchpoint \tkeep \ty \t %s \033[m \n",index->NO,index->target);
    printf("\033[96m \tbreakpoint already hit %d time \033[m \n",index->times);
    index = index->next;
  }
  return;
}

static int cmd_w(char *args){
  if(too_lessArg(args) == 1) return 0;
  WP* ret = new_wp(args);
  if(ret==NULL) printf("%s already in wp_pool!\n",args); 
  watchPoints_display();
  return 0;
}

static int cmd_pcount(char *args){
  bool success = true;
  if(too_lessArg(args) == 1) {
    return 0;
  }
  word_t result = expr(args,&success);
  printf("\033[105m [ %s ] = [%u] [0x%08x]\033[0m\n",args,result,result);
  Assert(success,"Make_token fail!");
  return 0;
}

static int cmd_x(char *args){
  if(too_lessArg(args) == 1) return 0;

  char *arg1 = strtok(NULL," ");
  char *arg2 = strtok(NULL," ");
  char *arg3 = strtok(NULL," ");
  if(too_lessArg(arg3) == 1) return 0;

  int per = convert_ten(arg1);
  int len = convert_ten(arg2);
  vaddr_t addr = convert_16(arg3);
  // printf("addr = %08x\n",addr);

  for (int i = 0;i < len;i = i + 1){
    printf("\033[105m 0x%08x: \033[0m \t0x%08x\n",addr + i*per,vaddr_read(addr + i*per,per));
  }
  return 0; 
}
#ifdef CONFIG_DIFFTEST
static int cmd_xref(char *args){
  if(too_lessArg(args) == 1) return 0;

  char *arg1 = strtok(NULL," ");
  char *arg2 = strtok(NULL," ");
  char *arg3 = strtok(NULL," ");
  if(too_lessArg(arg3) == 1) return 0;

  int per = convert_ten(arg1);
  int len = convert_ten(arg2);
  vaddr_t addr = convert_16(arg3);
  uint8_t *ref_mem = (uint8_t *)malloc(len*per);
  ref_difftest_memcpy(addr, ref_mem, len*per, DIFFTEST_TO_DUT);

  // printf("addr = %08x\n",addr);
  switch(per){
    case 1: 
      for (int i = 0;i < len;i += 1)
        printf("\033[105m 0x%08x: \033[0m \t0x%08x\n",addr + i, ref_mem[i]);
      break;
    case 2:
      for (int i = 0;i < len;i += 1)
        printf("\033[105m 0x%08x: \033[0m \t0x%08x\n",addr + 2*i, ((uint16_t*)ref_mem)[i]);
      break;
    case 4:
      for (int i = 0;i < len;i += 1)
        printf("\033[105m 0x%08x: \033[0m \t0x%08x\n",addr + 4*i, ((uint32_t*)ref_mem)[i]);
      break;
    default:  Assert(0,"Unlegal word:[%d]",per);

  }

  // for (int i = 0;i < len;i += 1){
  //   printf("\033[105m 0x%08x: \033[0m \t0x%08x\n",addr + i*4, ref_mem[i]);
  // }

  free(ref_mem);
  ref_mem = NULL;

  
  return 0; 
}

static int cmd_rref(char *args){
  CPU_state ref;
  ref_difftest_regcpy(&ref, DIFFTEST_TO_DUT);
  for(int i = 0; i < RISCV_GPR_NUM; i++){
      printf("\033[103m %d: \033[0m \t%s  \033[104m 0x%08x\033[0m\n",i,regs[i],ref.gpr[i]);
  }
  printf("\033[105m ref->pc: \033[0m \t0x%08x\n",ref.pc);
  return 0; 
}
#endif

static int cmd_info(char *args){
  if (too_lessArg(args) == 1) return 0; 
  else if (*args == 'r')  isa_reg_display();
  else if (*args == 'w')  watchPoints_display();
  else Log("Unknown command '%s'", args);
  return 0;
}

static int cmd_help(char *args);

static int cmd_d(char *args){
  if(too_lessArg(args) == 1) return 0;
  WP *index = head;
  while(index != NULL){
    if(convert_ten(args) == index->NO){
      free_wp(index);
      watchPoints_display();

      return 0;
    }
    index = index->next;
  }
  printf("No %s in watchpool!\n",args);
  watchPoints_display();
  return 0;
}


static struct
{
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NPC", cmd_q},
    {"si", "Execuate one by one.",cmd_si},
    {"info","Print the state of register(r) or the content of watchpoint(w)",cmd_info},
    {"p","Get the result of EXPR.",cmd_pcount},
    {"x","Scan the memory.",cmd_x},
    {"w","Set a watchpoint.",cmd_w},
    {"d","Delete certain watchpoint.",cmd_d},
    #ifdef CONFIG_DIFFTEST
    {"xref","Scan the memory of reference in difftest.",cmd_xref},
    {"rref","Scan the register of reference in difftest.",cmd_rref},
    #endif
    /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL)
  {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++)
    {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else
  {
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(arg, cmd_table[i].name) == 0)
      {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}
void sdb_set_batch_mode()
{
  is_batch_mode = true;
}
/* Receive commands from user. */
void sdb_mainloop()
{
  if (is_batch_mode)
  {
    cmd_c(NULL);
    //return;
  }
#ifdef CONFIG_AUTO_Q
  cmd_c(NULL);
  cmd_q(NULL);
  return;
#endif
  for (char *str; (str = rl_gets()) != NULL;)
  {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL)
    {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end)
    {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(cmd, cmd_table[i].name) == 0)
      {
        if (cmd_table[i].handler(args) < 0)
        {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD)
    {
      printf("Unknown command '%s'\n", cmd);
    }
  }
  WP *head = head;
  while(head != NULL){
    free(head->target);
    if (head->target != NULL) {
      head->target = NULL;
    }
    head = head->next;
  }
  // iringbuf *head_i = get_head_iringbuf();
  // while(head_i != NULL && head_i->rbuf != NULL){
  //   free(head_i->rbuf);
  //   head_i->rbuf = NULL;
  //   head_i = head_i->next;
  // }
  
}

void init_sdb()
{
  /* Compile the regular expressions. */
  // 编译正则表达式
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
