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

#include <common.h>
#include <utils.h>
#include <device/alarm.h>
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>
#endif

void init_map();
void init_serial();
void init_timer();
void init_vga();
void init_i8042();
void init_audio();
void init_disk();
void init_sdcard();
void init_alarm();

void send_key(uint8_t, bool);
void vga_update_screen();

void device_update() {
  // 检查距离上次设备更新是否已经超过了一定时间，若是，则会尝试刷新屏幕
  static uint64_t last = 0;
  uint64_t now = get_time();
  if (now - last < 1000000 / TIMER_HZ) {
    return;  // 直接返回，避免检查过于频繁
  }
  last = now;

  IFDEF(CONFIG_HAS_VGA, vga_update_screen());

// 进一步检查是否有按键按下/释放，以及是否点击了窗口的X按钮
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        nemu_state.state = NEMU_QUIT;
        break;
#ifdef CONFIG_HAS_KEYBOARD
      // If a key was pressed
      case SDL_KEYDOWN:
      case SDL_KEYUP: {
        uint8_t k = event.key.keysym.scancode;
        bool is_keydown = (event.key.type == SDL_KEYDOWN);
        send_key(k, is_keydown);
        break;
      }
#endif
      case SDL_WINDOWEVENT:
        switch (event.window.event) {
          case SDL_WINDOWEVENT_MINIMIZED:
            // 处理窗口最小化
            SDL_MinimizeWindow(SDL_GetWindowFromID(event.window.windowID));
            break;
          case SDL_WINDOWEVENT_MAXIMIZED:
            // 处理窗口最大化
            SDL_MaximizeWindow(SDL_GetWindowFromID(event.window.windowID));
            break;
          case SDL_WINDOWEVENT_RESTORED:
            // 处理窗口从最小化或最大化还原
            SDL_RestoreWindow(SDL_GetWindowFromID(event.window.windowID));
            break;
          default:
            break;
        }
        break;
      default: break;
    }
  }
#endif
}

void sdl_clear_event_queue() {
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event));
#endif
}

void init_device() {
  IFDEF(CONFIG_TARGET_AM, ioe_init());
  init_map();  // 初始化

  IFDEF(CONFIG_HAS_SERIAL, init_serial());
  IFDEF(CONFIG_HAS_TIMER, init_timer());
  IFDEF(CONFIG_HAS_VGA, init_vga()); // 初始化VGA时还会进行一些和SDL相关的初始化工作，包括创建窗口，设置显示功能
  IFDEF(CONFIG_HAS_KEYBOARD, init_i8042());
  IFDEF(CONFIG_HAS_AUDIO, init_audio());
  IFDEF(CONFIG_HAS_DISK, init_disk());
  IFDEF(CONFIG_HAS_SDCARD, init_sdcard());
  IFDEF(CONFIG_HAS_SRAM, init_sram());
  IFNDEF(CONFIG_TARGET_AM, init_alarm());
}
