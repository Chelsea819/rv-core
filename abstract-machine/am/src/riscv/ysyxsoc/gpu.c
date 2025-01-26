#include <am.h>
#include <ysyxsoc.h>
#include <klib.h>
// #define MODE_800x600
// #ifdef MODE_800x600
// # define W    800
// # define H    600
// #else
# define W    640
# define H    480

// # define W_    640
// # define H    300
// #endif
int putchar();
// #define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // int i;
  // int w = W;// TODO: get the correct width
  // int h = H;// TODO: get the correct height
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  // uint32_t size = inl(VGACTL_ADDR + 0);
  // WIDTH = (int)(size >> 16);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = W, .height = H,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) { 
    int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
    // printf("x = %d y = %d\n",x,y);
    volatile uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    uint32_t *p = (uint32_t *)ctl->pixels;
    int k = 0;
    uint32_t addr = 0;
    uint32_t h_addr = 0;
    for(uint32_t i = y; i < y + h; i ++){
      h_addr = i << 10;
      for(uint32_t j = x; j < x + w; j ++){
        asm volatile("" ::: "memory");
        addr = h_addr | (j & 0b1111111111);
        fb[addr] = p[k++];
        asm volatile("" ::: "memory");
      }
      // printf("addr = %x\n", addr);
    }
    // outl(SYNC_ADDR, 1);
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
