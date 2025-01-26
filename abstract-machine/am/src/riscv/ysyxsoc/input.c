#include <am.h>
#include <ysyxsoc.h>
#include <klib.h>
#define KEYDOWN_MASK 0x8000 

// uint32_t code_trans(uint32_t keycode){
//   uint32_t keycode = 0;
//   return keycode;
// }

// 拓展码读两次
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  // 断码 or 通码
  // 断码 F0+通码
  // 通码： 1个byte（??） or 2个byte（E0+??）
  uint8_t key[3] = {0};
  int i = 0;
  uint32_t keycode = 0;
  int len = 1;
  bool f0_flag = false;
  // putstr("111\n");
  while (len > 0) {
    if (i > 2) panic("key[i] out of bound!");
    key[i] = inb(KBD_ADDR); len --;
    keycode = (keycode << 8) | key[i];
    if (key[i] == 0xf0) {
      f0_flag = true;
      len ++;
    } else if (key[i] == 0xe0) {
      len ++;
    }
    i ++;
  }
  // printf("keycode = %x\n", keycode);
  // putstr("222\n");
  if(f0_flag) keycode = keycode & 0xff;
  kbd->keycode = KEY_MAP(keycode);
  // printf("kbd->keycode = %d keycode = %d flag = %d\n", kbd->keycode, keycode, f0_flag);
  kbd->keydown = (kbd->keycode != 0) && (f0_flag != true);
}
