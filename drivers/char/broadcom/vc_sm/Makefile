<<<<<<< HEAD
ccflags-$(CONFIG_BCM_VC_SM) += -Werror -Wall -Wstrict-prototypes -Wno-trigraphs -O2
ccflags-$(CONFIG_BCM_VC_SM) += -I"drivers/staging/vc04_services" -I"drivers/staging/vc04_services/interface/vchi" -I"drivers/staging/vc04_services/interface/vchiq_arm" -I"$(srctree)/fs/"
ccflags-$(CONFIG_BCM_VC_SM) += -DOS_ASSERT_FAILURE -D__STDC_VERSION=199901L -D__STDC_VERSION__=199901L -D__VCCOREVER__=0 -D__KERNEL__ -D__linux__
=======
EXTRA_CFLAGS  += -Wall -Wstrict-prototypes -Wno-trigraphs -O2

EXTRA_CFLAGS  += -I"drivers/misc/vc04_services"
EXTRA_CFLAGS  += -I"drivers/misc/vc04_services/interface/vchi"
EXTRA_CFLAGS  += -I"drivers/misc/vc04_services/interface/vchiq_arm"
EXTRA_CFLAGS  += -I"$(srctree)/fs/"

EXTRA_CFLAGS  += -DOS_ASSERT_FAILURE
EXTRA_CFLAGS  += -D__STDC_VERSION=199901L
EXTRA_CFLAGS  += -D__STDC_VERSION__=199901L
EXTRA_CFLAGS  += -D__VCCOREVER__=0
EXTRA_CFLAGS  += -D__KERNEL__
EXTRA_CFLAGS  += -D__linux__
EXTRA_CFLAGS  += -Werror
>>>>>>> upstream/rpi-4.4.y

obj-$(CONFIG_BCM_VC_SM) := vc-sm.o

vc-sm-objs := \
    vmcs_sm.o \
    vc_vchi_sm.o
