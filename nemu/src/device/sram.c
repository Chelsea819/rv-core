/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
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

#include <utils.h>
#include <device/map.h>

/* http://en.wikibooks.org/wiki/Serial_Programming/8250_UART_Programming */
// NOTE: this is compatible to 16550

static uint8_t *sram_base = NULL;

void init_sram() {
  sram_base = new_space(4 * 1024);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("sram", CONFIG_SRAM_PORT, sram_base, 4*1024, NULL);
#else
  add_mmio_map("sram", CONFIG_SRAM_MMIO, sram_base, 4*1024, NULL);
#endif

}
