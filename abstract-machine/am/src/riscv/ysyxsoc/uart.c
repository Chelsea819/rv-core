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


/*
Data Ready (DR) indicator. 
  ‘0’ – No characters in the FIFO 
  ‘1’ – At least one character has been received and is in the 
FIFO.
*/


void __am_uart_rx(AM_UART_RX_T *recv) {
  if ((inb(UART_LSR_REG) & 0b00000001) == 0) {
    recv->data = 0xff;
  } else {
    recv->data = (inb(SERIAL_PORT));
  }
  
}




