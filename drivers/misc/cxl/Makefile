<<<<<<< HEAD
ccflags-y			:= $(call cc-disable-warning, unused-const-variable)
ccflags-$(CONFIG_PPC_WERROR)	+= -Werror
=======
ccflags-y := -Werror $(call cc-disable-warning, unused-const-variable)
>>>>>>> upstream/rpi-4.4.y

cxl-y				+= main.o file.o irq.o fault.o native.o
cxl-y				+= context.o sysfs.o debugfs.o pci.o trace.o
cxl-y				+= vphb.o phb.o api.o
cxl-$(CONFIG_PPC_PSERIES)	+= flash.o guest.o of.o hcalls.o
obj-$(CONFIG_CXL)		+= cxl.o
obj-$(CONFIG_CXL_BASE)		+= base.o

# For tracepoints to include our trace.h from tracepoint infrastructure:
CFLAGS_trace.o := -I$(src)
