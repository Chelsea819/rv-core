#ifndef __AMDEV_H__
#define __AMDEV_H__

// **MAY SUBJECT TO CHANGE IN THE FUTURE**

/*常见设备的"抽象寄存器"编号和相应的结构. 这些定义是架构无关的, 每个架构在实现各自的IOE API时, 都需要遵循这些定义(约定).*/
#define AM_DEVREG(id, reg, perm, ...) \
  enum { AM_##reg = (id) }; \
  typedef struct { __VA_ARGS__; } AM_##reg##_T;

AM_DEVREG( 1, UART_CONFIG,  RD, bool present);
AM_DEVREG( 2, UART_TX,      WR, char data);
AM_DEVREG( 3, UART_RX,      RD, char data);
AM_DEVREG( 4, TIMER_CONFIG, RD, bool present, has_rtc);
AM_DEVREG( 5, TIMER_RTC,    RD, int year, month, day, hour, minute, second);  // AM实时时钟，读出当前的年月日时分秒，PA中暂时不使用
AM_DEVREG( 6, TIMER_UPTIME, RD, uint64_t us); // AM系统启动时间，可读出系统启动后的微秒数
AM_DEVREG( 7, INPUT_CONFIG, RD, bool present);
/*AM键盘控制器, 可读出按键信息. keydown为true时表示按下按键, 否则表示释放按键. keycode为按键的断码, 没有按键时, keycode为AM_KEY_NONE */
AM_DEVREG( 8, INPUT_KEYBRD, RD, bool keydown; int keycode); 
// AM显示控制器信息, 可读出屏幕大小信息width和height. 另外AM假设系统在运行过程中, 屏幕大小不会发生变化.
AM_DEVREG( 9, GPU_CONFIG,   RD, bool present, has_accel; int width, height, vmemsz);
AM_DEVREG(10, GPU_STATUS,   RD, bool ready);
// AM帧缓冲控制器, 可写入绘图信息, 向屏幕(x, y)坐标处绘制w*h的矩形图像. 
// 图像像素按行优先方式存储在pixels中, 每个像素用32位整数以00RRGGBB的方式描述颜色. 
// 若sync为true, 则马上将帧缓冲中的内容同步到屏幕上.
AM_DEVREG(11, GPU_FBDRAW,   WR, int x, y; void *pixels; int w, h; bool sync);
AM_DEVREG(12, GPU_MEMCPY,   WR, uint32_t dest; void *src; int size);
AM_DEVREG(13, GPU_RENDER,   WR, uint32_t root);
AM_DEVREG(14, AUDIO_CONFIG, RD, bool present; int bufsize);
AM_DEVREG(15, AUDIO_CTRL,   WR, int freq, channels, samples);
AM_DEVREG(16, AUDIO_STATUS, RD, int count);
AM_DEVREG(17, AUDIO_PLAY,   WR, Area buf);
AM_DEVREG(18, DISK_CONFIG,  RD, bool present; int blksz, blkcnt);
AM_DEVREG(19, DISK_STATUS,  RD, bool ready);
AM_DEVREG(20, DISK_BLKIO,   WR, bool write; void *buf; int blkno, blkcnt);
AM_DEVREG(21, NET_CONFIG,   RD, bool present);
AM_DEVREG(22, NET_STATUS,   RD, int rx_len, tx_len);
AM_DEVREG(23, NET_TX,       WR, Area buf);
AM_DEVREG(24, NET_RX,       WR, Area buf);

// Input


// 定义宏KEY_MAP
#define DEFINE_KEY_MAP(index, key) case index: _key = AM_KEY_##key; break;
#define KEY_MAP(index) \
  ({ \
    int _key = AM_KEY_NONE; \
    switch (index) { \
      AM_KEYS_MAP(DEFINE_KEY_MAP) \
      default: _key = AM_KEY_NONE; break; \
    } \
    _key; \
  })

  #define AM_KEYS(_) \
  _(ESCAPE) _(F1) _(F2) _(F3) _(F4) _(F5) _(F6) _(F7) _(F8) _(F9) _(F10) _(F11) _(F12) \
  _(GRAVE) _(1) _(2) _(3) _(4) _(5) _(6) _(7) _(8) _(9) _(0) _(MINUS) _(EQUALS) _(BACKSPACE) \
  _(TAB) _(Q) _(W) _(E) _(R) _(T) _(Y) _(U) _(I) _(O) _(P) _(LEFTBRACKET) _(RIGHTBRACKET) _(BACKSLASH) \
  _(CAPSLOCK) _(A) _(S) _(D) _(F) _(G) _(H) _(J) _(K) _(L) _(SEMICOLON) _(APOSTROPHE) _(RETURN) \
  _(LSHIFT) _(Z) _(X) _(C) _(V) _(B) _(N) _(M) _(COMMA) _(PERIOD) _(SLASH) _(RSHIFT) \
  _(LCTRL) _(APPLICATION) _(LALT) _(SPACE) _(RALT) _(RCTRL) \
  _(UP) _(DOWN) _(LEFT) _(RIGHT) _(INSERT) _(DELETE) _(HOME) _(END) _(PAGEUP) _(PAGEDOWN)


#define AM_KEYS_MAP(_) \
  _(0x76, ESCAPE) _(0x05, F1) _(0x06, F2) _(0x04, F3) _(0x0c, F4) _(0x03, F5) _(0x0b, F6) _(0x83, F7) _(0x0a, F8) _(0x01, F9) _(0x09, F10) _(0x78, F11) _(0x07, F12) \
  _(0x0e, GRAVE) _(0x16, 1) _(0x1e, 2) _(0x26, 3) _(0x25, 4) _(0x2e, 5) _(0x36, 6) _(0x3d, 7) _(0x3e, 8) _(0x46, 9) _(0x45, 0) _(0x4e, MINUS) _(0x55, EQUALS) _(0x66, BACKSPACE) \
  _(0x0d, TAB) _(0x15, Q) _(0x1d, W) _(0x24, E) _(0x2d, R) _(0x2c, T) _(0x35, Y) _(0x3c, U) _(0x43, I) _(0x44, O) _(0x4d, P) _(0x54, LEFTBRACKET) _(0x5b, RIGHTBRACKET) _(0x5d, BACKSLASH) \
  _(0x58, CAPSLOCK) _(0x1c, A) _(0x1b, S) _(0x23, D) _(0x2b, F) _(0x34, G) _(0x33, H) _(0x3b, J) _(0x42, K) _(0x4b, L) _(0x4c, SEMICOLON) _(0x52, APOSTROPHE) _(0x5a, RETURN) \
  _(0x12, LSHIFT) _(0x1a, Z) _(0x22, X) _(0x21, C) _(0x2a, V) _(0x32, B) _(0x31, N) _(0x3a, M) _(0x41, COMMA) _(0x49, PERIOD) _(0x4a, SLASH) _(0x59, RSHIFT) \
  _(0x14, LCTRL) _(0x70, APPLICATION) _(0x11, LALT) _(0x29, SPACE) _(0xe011, RALT) _(0xe014, RCTRL) \
  _(0xe075, UP) _(0xe072, DOWN) _(0xe06b, LEFT) _(0xe074, RIGHT) _(0xe070, INSERT) _(0xe071, DELETE) _(0xe06c, HOME) _(0xe069, END) _(0xe07d, PAGEUP) _(0xe07a, PAGEDOWN)

#define AM_KEY_NAMES(key) AM_KEY_##key,
enum {
  AM_KEY_NONE = 0,
  AM_KEYS(AM_KEY_NAMES)
};

// GPU

#define AM_GPU_TEXTURE  1
#define AM_GPU_SUBTREE  2
#define AM_GPU_NULL     0xffffffff

typedef uint32_t gpuptr_t;

struct gpu_texturedesc {
  uint16_t w, h;
  gpuptr_t pixels;
} __attribute__((packed));

struct gpu_canvas {
  uint16_t type, w, h, x1, y1, w1, h1;
  gpuptr_t sibling;
  union {
    gpuptr_t child;
    struct gpu_texturedesc texture;
  };
} __attribute__((packed));

#endif
