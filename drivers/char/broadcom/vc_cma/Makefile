<<<<<<< HEAD
ccflags-$(CONFIG_BCM_VC_CMA)  += -Wall -Wstrict-prototypes -Wno-trigraphs -Werror
ccflags-$(CONFIG_BCM_VC_CMA)  += -Iinclude/linux/broadcom -Idrivers/staging/vc04_services -Idrivers/staging/vc04_services/interface/vchi -Idrivers/staging/vc04_services/interface/vchiq_arm
ccflags-$(CONFIG_BCM_VC_CMA)  += -D__KERNEL__ -D__linux__
=======
ccflags-y  += -Wall -Wstrict-prototypes -Wno-trigraphs
ccflags-y  += -Werror
ccflags-y  += -Iinclude/linux/broadcom
ccflags-y  += -Idrivers/misc/vc04_services
ccflags-y  += -Idrivers/misc/vc04_services/interface/vchi
ccflags-y  += -Idrivers/misc/vc04_services/interface/vchiq_arm

ccflags-y  += -D__KERNEL__
ccflags-y  += -D__linux__
ccflags-y  += -Werror
>>>>>>> upstream/rpi-4.4.y

obj-$(CONFIG_BCM_VC_CMA) += vc-cma.o

vc-cma-objs := vc_cma.o
