deps_config := \
	csrc/device/Kconfig \
	csrc/memory/Kconfig \
	/home/chelsea/ysyx-workbench/npc/csrc/isa/Kconfig \
	/home/chelsea/ysyx-workbench/npc-rare/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(NPC_HOME)" "/home/chelsea/ysyx-workbench/npc"
include/config/auto.conf: FORCE
endif
ifneq "$(NEMU_HOME)" "/home/chelsea/ysyx-workbench/nemu"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
