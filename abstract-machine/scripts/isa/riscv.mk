CROSS_COMPILE := riscv64-linux-gnu-
COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align -Os
CFLAGS        += $(COMMON_CFLAGS) -static -Os 
ASFLAGS       += $(COMMON_CFLAGS) -Os
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h
