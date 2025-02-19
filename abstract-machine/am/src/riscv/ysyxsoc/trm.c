#include <am.h>
#include <ysyxsoc.h>
#include <klib.h>

extern char _heap_start;
extern char _heap_end;
extern char _text_start [];
extern char _text_size [];
extern char _text_load_start [];
extern char _rodata_start [];
extern char _rodata_size [];
extern char _rodata_load_start [];
extern char _data_start [];
extern char _data_size [];

extern char _bootloader_load_start [];
extern char _bootloader_start [];
extern char _bootloader_size [];

extern char _data_load_start [];
// extern char _sramtext_start [];
// extern char _sramtext_size [];
// extern char _sramtext_load_start [];

#define SRAM_ADDR 0x0f000000

//位抽取
#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1))

void __am_uart_init() {
  // 写线控制寄存器
  uint8_t lcr = inb(UART_LCR_REG);
  lcr = 0x80;
  outb(UART_LCR_REG, lcr);

  // 写Divisor Latch
  outb(UART_DIVISOR_LATCH_MSB, (0x10 >> 8) & 0xff);
  outb(UART_DIVISOR_LATCH_LSB, 0x10 & 0xff);

  // 写线控制寄存器
  // lcr &= 0x7f;
  // lcr |= 0b00011111; // 设置数据校验 数据格式
  lcr = 0x03;
  outb(UART_LCR_REG, lcr);

  // enable interupt
  uint8_t ier = 0b111;
  outb(UART_IER_REG, ier);

}

int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
    // volatile uint8_t receive_buffer = 0;
    // if(count == 16){while ((inb(UART_LSR_REG) & 0b01100000) == 0 && count > 10) {
    //     receive_buffer = inb(SERIAL_PORT);count--;
    // } 
    // }
    *(volatile uint8_t  *)SERIAL_PORT = ch;
    while ((inb(UART_LSR_REG) & 0b00100000) == 0);
    // count ++;
}

void copy_data(void *d, void *s, size_t data_size){
  if (d != s) {
    // memcpy(_data_start, _data_load_start, (size_t)_data_size); // 每次cpy的字节数为1，速度太慢
    uint32_t *dst = (uint32_t *)d;
    uint32_t *src = (uint32_t *)s;
    data_size = (data_size + 3) & ~((size_t)3);
    size_t i = 0;
    while (i <= data_size / sizeof(uint32_t)) {
      *(dst + i) = *(src + i);
      i ++;
    }
  }
}

__attribute__((section(".fsbl.text")))
void _fsbl(){
  copy_data(_bootloader_start,_bootloader_load_start,(size_t)_bootloader_size);
}


__attribute__((section(".bootloader.text")))
void _bootloader(){
  copy_data(_data_start,_data_load_start,(size_t)_data_size);
  copy_data(_text_start, _text_load_start,(size_t)_text_size);
  copy_data(_rodata_start, _rodata_load_start,(size_t)_rodata_size);
}

void halt(int code) {
  //htif_poweroff();
  //exit(0);
  // asm volatile：这个关键字告诉编译器，嵌入的汇编代码不要对内联汇编代码进行优化
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}


__attribute__((section(".bootloader.text")))
void _trm_init() {
  // printf("heap.start = %x\n",heap.start);
  _bootloader();
  if (heap.start == 0) {
    halt(1);
  }
  // __am_uart_init();

  // int (*funcPtr)(const char *) = &main;
  // funcPtr = (int (*)(const char *))((char *)funcPtr - (char *)_text_start + (char *)SRAM_ADDR);
  // int ret = funcPtr(mainargs);
  // halt(ret);

  /**
  asm volatile (
        "mv %0, tp"  // 将tp寄存器的值赋给%0（输出操作数）
        : "=r" (value) // 输出：将结果存入变量value r表示操作数为寄存器
        :              // 无输入操作数
        :              // 无clobbered寄存器
    );
    **/
  
  // uint32_t ventorid = 0;
  // uint32_t marchid = 0;

  // asm volatile("csrrs %0, mvendorid, x0" : "=r" (ventorid));
  // asm volatile("csrrs %0, marchid, x0" : "=r" (marchid));

  // char vendor_id[5] = {0};
  // for (int i = 0; i < 4; i ++) {
  //   vendor_id[i] = BITS(ventorid, (3-i)*8+7, (3-i)*8);
  // }
  // vendor_id[4] = '\0';
  
  // printf("[--TRM--]\n");
  // printf("VENDOR_ID: [%s]\n",vendor_id);
  // printf("ARCH_ID: [%u]\n",marchid);
  // printf("[--TRM--]\n");
  

  // bootloader_extend();
  
  int ret = main(mainargs);
  halt(ret);
}
