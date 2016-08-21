EXTRA_CFLAGS += $(DEBFLAGS) -Wall

ifneq ($(KERNELRELEASE),)
	obj-m := main.o
else
	KDIR ?= /home/qyg/android/kernel/omap/  #ÄÚºËÎ»ÖÃ
	PWD := $(shell pwd)
all:
	make $(EXTRA_CFLAGS) -C $(KDIR) M=$(PWD) modules
endif
clean:
	rm *.o *.ko main.mod.c 
