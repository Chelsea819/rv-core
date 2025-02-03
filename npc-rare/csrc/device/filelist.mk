#***************************************************************************************
# Copyright (c) 2014-2022 Zihao Yu, Nanjing University
#
# NPC is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

DIRS-y += $(NPC_RARE_HOME)/csrc/device/io
CSRCS-y += $(NPC_RARE_HOME)/csrc/device/device.c $(NPC_RARE_HOME)/csrc/device/alarm.c $(NPC_RARE_HOME)/csrc/device/intr.c
# CSRCS-$(CONFIG_DEVICE) += $(NPC_RARE_HOME)/csrc/device/device.c $(NPC_RARE_HOME)/csrc/device/alarm.c csrc/device/intr.c
CSRCS-$(CONFIG_HAS_SERIAL) += $(NPC_RARE_HOME)/csrc/device/serial.c
CSRCS-$(CONFIG_HAS_TIMER) += $(NPC_RARE_HOME)/csrc/device/timer.c
CSRCS-$(CONFIG_HAS_KEYBOARD) += $(NPC_RARE_HOME)/csrc/device/keyboard.c
CSRCS-$(CONFIG_HAS_VGA) += $(NPC_RARE_HOME)/csrc/device/vga.c
CSRCS-$(CONFIG_HAS_AUDIO) += $(NPC_RARE_HOME)/csrc/device/audio.c
CSRCS-$(CONFIG_HAS_DISK) += $(NPC_RARE_HOME)/csrc/device/disk.c
CSRCS-$(CONFIG_HAS_SDCARD) += $(NPC_RARE_HOME)/csrc/device/sdcard.c

CSRCS-BLACKLIST-$(CONFIG_TARGET_AM) += $(NPC_RARE_HOME)/csrc/device/alarm.c

ifdef CONFIG_DEVICE
ifndef CONFIG_TARGET_AM
LIBS += -lSDL2
endif
endif