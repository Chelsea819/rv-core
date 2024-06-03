#include <fs.h>
size_t ramdisk_read(void *buf, size_t offset, size_t len);
size_t ramdisk_write(const void *buf, size_t offset, size_t len);
size_t fb_write(const void *buf, size_t offset, size_t len);
size_t serial_write(const void *buf, size_t offset, size_t len);
size_t events_read(void *buf, size_t offset, size_t len);
size_t dispinfo_read(void *buf, size_t offset, size_t len);

typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

typedef struct {
  char *name; // 文件名 把目录分隔符/也认为是文件名的一部分
  size_t size; // 文件大小
  size_t disk_offset; // 文件在ramdisk中的偏移
  ReadFn read;  // 读函数指针
  WriteFn write; // 写函数指针
} Finfo;

#define FILE_NUM 40
typedef struct
{
  size_t open_offset[FILE_NUM];
  bool if_init[FILE_NUM];
} OpenOff;

static OpenOff open_table = {};

// static size_t open_table.Open_offset[FILE_NUM];
static bool fs_if_init = false;
// static char *fb = NULL;

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB, FD_EVENT, FD_DISPINFO};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = { // 文件记录表
  [FD_STDIN]  = {"stdin", 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
  [FD_EVENT] = {"/dev/event", 0, 0, events_read, invalid_write},
  [FD_FB] = {"/dev/fb", 0, 0, invalid_read, fb_write},  // 支持写操作和lseek
  [FD_DISPINFO] = {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write}, // 屏幕信息 支持读操作
#include "files.h"
};

void init_file_offset(){
  int file_num = sizeof(file_table) / sizeof(Finfo);
  assert(file_num <= FILE_NUM);
  for(int i = 0; i < file_num; i ++){
    open_table.open_offset[i] = file_table[i].disk_offset;
    open_table.if_init[i] = false;
  }
  fs_if_init = true;
}

// void free_file_offset(){
//   free(open_table.Open_offset);
//   open_table.Open_offset = NULL;
// }

char *get_filename(int fd){
  return file_table[fd].name;
}

// 为了简化实现, 我们允许所有用户程序都可以对所有已存在的文件进行读写, 
// 这样以后, 我们在实现fs_open()的时候就可以忽略flags和mode了
int fs_open(const char *pathname, int flags, int mode){
  if(fs_if_init == false)
    init_file_offset();
  // find the certain file
  int file_num = sizeof(file_table) / sizeof(Finfo);
  int fd = 0;
  for(fd = 0; fd < file_num; fd ++){
    if(strcmp(file_table[fd].name, pathname) == 0){
      break;
    }
    if(fd == file_num - 1) panic("Cannot find this file!  [%s]",pathname);
  }
  open_table.if_init[fd] = true;
  // printf("fd = %d\n",fd);
  return fd;

}

size_t fs_read(int fd, void *buf, size_t len){
  // printf("file_table[%d].disk_offset = 0x%08x\n",fd,open_table.open_offset[fd]);
  // printf("file_table[i].disk_offset = 0x%08x\n",file_table[i].disk_offset);
  if(file_table[fd].read == NULL){
    assert(fd >= 0 && fd < sizeof(file_table) / sizeof(Finfo));
    assert(buf != NULL);
    assert(len <= 0x7ffff000);
    if(open_table.open_offset[fd] + len > file_table[fd].disk_offset + file_table[fd].size)
      len = file_table[fd].disk_offset + file_table[fd].size - open_table.open_offset[fd];
    // printf("len = 0x%08x file_table[%d].disk_offset = 0x%08x open_table.Open_offset[%d] = 0x%08x file_table[%d].size = 0x%08x",len,fd,open_table.open_offset[fd],fd,file_table[i].disk_offset,fd,file_table[fd].size);
    // printf("open_table.open_offset[fd] + len = 0x%08x, file_table[i].disk_offset + file_table[fd].size = 0x%08x\n",open_table.open_offset[fd] + len,file_table[i].disk_offset + file_table[fd].size);
    int ret = ramdisk_read(buf, open_table.open_offset[fd], len);
    // assert(open_table.open_offset[fd] + ret <= file_table[i].disk_offset + file_table[fd].size);
  
    open_table.open_offset[fd] += ret;
    return ret;
    // printf("fs_write fd = %d len = %d\n",fd,len);
  }
  else{
    return file_table[fd].read(buf,open_table.open_offset[fd],len);
  }
}

size_t fs_write(int fd, const void *buf, size_t len){
  // printf("fs_write fd = %d len = %d\n",fd,len);
  if(file_table[fd].write == NULL){
    assert(fd >= 0 && fd < sizeof(file_table) / sizeof(Finfo));
    assert(buf != NULL);
    assert(len <= 0x7ffff000);
    assert(open_table.open_offset[fd] + len <= file_table[fd].disk_offset + file_table[fd].size);
    int ret = ramdisk_write(buf, open_table.open_offset[fd], len);
    open_table.open_offset[fd] += ret;
    return ret;
  }
  else{
    return file_table[fd].write(buf,open_table.open_offset[fd],len);
  }
  
}

// size_t fs_write(int fd, const void *buf, size_t len){
//   // printf("fs_write fd = %d len = %d\n",fd,len);
//   if(fd == 1 || fd == 2){  // stdout stderr
//     int i = 0; 
//     for(i = 0; i < len; i ++){
//       putch(*((char*)buf + i));
//     }
//     // printf("i = %d\n",i);
//     return i;
//   }
//   else{
//     assert(fd >= 0 && fd < sizeof(file_table) / sizeof(Finfo));
//     assert(buf != NULL);
//     assert(len <= 0x7ffff000);
//     assert(open_table.open_offset[fd] + len <= file_table[i].disk_offset + file_table[fd].size);
//     int ret = ramdisk_write(buf, open_table.open_offset[fd], len);
//     open_table.open_offset[fd] += ret;
//     return ret;
//   }
  
// }



size_t fs_lseek(int fd, size_t offset, int whence){
  assert(fd >= 0 && fd < sizeof(file_table) / sizeof(Finfo));
  // printf("file_table[i].disk_offset = 0x%08x file_table[fd].size = 0x%08x\n",file_table[i].disk_offset,file_table[fd].size);
  if(whence == SEEK_SET){
    assert(offset <= file_table[fd].size);
    open_table.open_offset[fd] = file_table[fd].disk_offset + offset;
  }
  else if(whence == SEEK_CUR){
    assert(open_table.open_offset[fd] + offset <= file_table[fd].disk_offset + file_table[fd].size);
    open_table.open_offset[fd] += offset;
  }
  else if(whence == SEEK_END){
    assert(file_table[fd].disk_offset + offset + file_table[fd].size <= file_table[fd].disk_offset + file_table[fd].size);
    open_table.open_offset[fd] = file_table[fd].disk_offset + offset + file_table[fd].size;
  }
  // printf("[fs_lseek] offset=%d whence=%d file_table[%d].disk_offset=0x%08x\n",offset,whence,fd,open_table.open_offset[fd]);
  return open_table.open_offset[fd] - file_table[fd].disk_offset;
}

int fs_close(int fd){
  assert(fd >= 0 && fd < sizeof(file_table) / sizeof(Finfo));
  // free_file_offset();
  open_table.if_init[fd] = true;
  open_table.open_offset[fd] = file_table[fd].disk_offset;
  return 0;
}

void init_fs() {
  // TODO: initialize the size of /dev/fb
  // char buf[64];
  AM_GPU_CONFIG_T ds = io_read(AM_GPU_CONFIG);
  int sw = ds.width;
  int sh = ds.height;
  file_table[FD_FB].size = sw * sh * 4;
  // fb = malloc(file_table[FD_FB].size);
}
