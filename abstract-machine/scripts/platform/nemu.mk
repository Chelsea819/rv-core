AM_SRCS := platform/nemu/trm.c \
           platform/nemu/ioe/ioe.c \
           platform/nemu/ioe/timer.c \
           platform/nemu/ioe/input.c \
           platform/nemu/ioe/gpu.c \
           platform/nemu/ioe/audio.c \
           platform/nemu/ioe/disk.c \
           platform/nemu/mpe.c
ALL ?= $(NAME)
CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker-nemu.ld \
             --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
NEMUFLAGS += -l $(shell dirname $(IMAGE).elf)/nemu-log.txt 
NEMUFLAGS += -f $(shell dirname $(IMAGE).elf)/$(ALL)-$(ARCH).elf #-f $(NEMU_HOME)/../navy-apps/apps/nslider/build/nslider-riscv32 

CFLAGS += -DMAINARGS=\"$(mainargs)\"
CFLAGS += -I$(AM_HOME)/am/src/platform/nemu/include
.PHONY: $(AM_HOME)/am/src/platform/nemu/trm.c

# $(IMAGE).elf：要跑的应用程序生成的目标文件、am、lib库
image: $(IMAGE).elf                                                                             
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin  
# @$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin  
# OBJCOPY将ELF格式的可执行文件转换为二进制格式
#-S从目标文件中剥离（strip）符号表和调试信息,可减小输出文件的大小，符号表和调试信息通常对运行时是不必要的。
# .bss=alloc 未初始化的全局变量和静态变量在加载时分配空间
# -O binary 生成一个没有ELF头信息的原始二进制文件

run: image
	$(info ARCHIVES = $(ARCHIVES))
	$(info ARCHIVE = $(ARCHIVE))
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NEMUFLAGS)" IMG=/home/chelsea/ysyx-workbench/am-kernels/tests/cpu-tests/build/load-store-riscv32e-ysyxsoc.bin
#$(IMAGE).bin
# bear --output ~/ysyx-workbench/.vscode/compile_commands.json -- $(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin

gdb: image
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin
