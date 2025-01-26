#include <am.h>
#include <nemu.h>
#include <string.h>

//支撑程序运行在TRM上的API

extern char _heap_start;
extern char _heap_end;
extern char _data_start [];
extern char _data_size [];
extern char _data_load_start [];

int main(const char *args);

// Area:Memory area for [@start, @end]
// 用于指示堆区的起始和末尾
Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

//用于输出一个字符
void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

// void copy_data(){
//   if (_data_start != _data_load_start) {
//     memcpy(_data_start, _data_load_start, (size_t)_data_size);
//   }
// }

//用于结束程序的运行
void halt(int code) {
  nemu_trap(code);

  // should not reach here
  while (1);
}

//用于进行TRM相关的初始化工作
void _trm_init() {
  // copy_data();
  if (heap.start == 0) {
    halt(1);
  }
  int ret = main(mainargs);
  halt(ret);
}
