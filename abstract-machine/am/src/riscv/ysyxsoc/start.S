.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer

  # # 拷贝代码的源地址-FLASH
  # la a0, _text_load_start
  # # 代码拷贝的目的地址-SRAM
  # la a1, _sram_addr
  # la a2, _text_size
  # la a3, _rodata_size
  # add a2, a2, a3; # a2 =a2 + a3
  # jal _bootloader
  
  jal _trm_init
