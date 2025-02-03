# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vysyx_23060025_top.mk

default: /home/chelsea/ysyx-workbench/npc-rare/build/ysyx_23060025_top

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vysyx_23060025_top
# Module prefix (from --prefix)
VM_MODPREFIX = Vysyx_23060025_top
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-I/home/chelsea/ysyx-workbench/nvboard/usr/include \
	-I/home/chelsea/ysyx-workbench/npc-rare/include \
	-Wall \
	-DTOP_NAME="Vysyx_23060025_top" \
	-g \
	-MMD \
	-O3 \
	-I/usr/include/SDL2 \
	-D_REENTRANT \
	-I/usr/lib/llvm-14/include \
	-std=c++14 \
	-fno-exceptions \
	-D_GNU_SOURCE \
	-D__STDC_CONSTANT_MACROS \
	-D__STDC_LIMIT_MACROS \
	-fPIE \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	-lz \
	/home/chelsea/ysyx-workbench/nvboard/build/nvboard.a \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lreadline \
	-ldl \
	-lSDL2 \
	-pie \
	-lreadline \
	-ldl \
	-pie \
	-lLLVM-14 \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	auto_bind \
	cpu-exe \
	dut \
	alarm \
	device \
	intr \
	map \
	mmio \
	port-io \
	paddr \
	vaddr \
	monitor \
	expr \
	sdb \
	watchpoint \
	sim_main \
	engine_start \
	hostcall \
	riscv32-dut \
	init \
	logo \
	reg \
	disasm \
	log \
	rand \
	state \
	time \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	.. \
	../.. \
	../../../npc/csrc/engine \
	../../../npc/csrc/isa \
	../../../npc/csrc/isa/difftest \
	../../../npc/csrc/utils \
	../../csrc \
	../../csrc/cpu \
	../../csrc/cpu/difftest \
	../../csrc/device \
	../../csrc/device/io \
	../../csrc/memory \
	../../csrc/monitor \
	../../csrc/monitor/sdb \


### Default rules...
# Include list of all generated classes
include Vysyx_23060025_top_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

auto_bind.o: /home/chelsea/ysyx-workbench/npc-rare/build/auto_bind.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
cpu-exe.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/cpu/cpu-exe.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
dut.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/cpu/difftest/dut.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
alarm.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/device/alarm.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
device.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/device/device.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
intr.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/device/intr.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
map.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/device/io/map.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
mmio.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/device/io/mmio.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
port-io.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/device/io/port-io.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
paddr.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/memory/paddr.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
vaddr.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/memory/vaddr.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
monitor.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/monitor/monitor.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
expr.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/monitor/sdb/expr.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sdb.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/monitor/sdb/sdb.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
watchpoint.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/monitor/sdb/watchpoint.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_main.o: /home/chelsea/ysyx-workbench/npc-rare/csrc/sim_main.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
engine_start.o: /home/chelsea/ysyx-workbench/npc/csrc/engine/engine_start.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
hostcall.o: /home/chelsea/ysyx-workbench/npc/csrc/engine/hostcall.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
riscv32-dut.o: /home/chelsea/ysyx-workbench/npc/csrc/isa/difftest/riscv32-dut.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
init.o: /home/chelsea/ysyx-workbench/npc/csrc/isa/init.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
logo.o: /home/chelsea/ysyx-workbench/npc/csrc/isa/logo.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
reg.o: /home/chelsea/ysyx-workbench/npc/csrc/isa/reg.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
disasm.o: /home/chelsea/ysyx-workbench/npc/csrc/utils/disasm.cc 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
log.o: /home/chelsea/ysyx-workbench/npc/csrc/utils/log.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
rand.o: /home/chelsea/ysyx-workbench/npc/csrc/utils/rand.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
state.o: /home/chelsea/ysyx-workbench/npc/csrc/utils/state.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
time.o: /home/chelsea/ysyx-workbench/npc/csrc/utils/time.c 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
/home/chelsea/ysyx-workbench/npc-rare/build/ysyx_23060025_top: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
