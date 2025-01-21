#include <am.h>
#include <ysyxsoc.h>
// Divisor Latch Addr
// MSB
// LSB

// LCR Register Addr

// void __am_uart_init() {
//   outb(UART_DIVISOR_LATCH_MSB, (100 >> 8) & 0xff);
//   outb(UART_DIVISOR_LATCH_LSB, 100 & 0xff);
//   uint8_t lcr = inb(UART_LCR_REG);
//   lcr &= 0b01111111;
//   outb(UART_LCR_REG, lcr);
// }



