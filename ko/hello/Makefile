#KERNELDIR := /home/qyg/android/kernel/goldfish/
PWD :=$(shell pwd)
ARCH=arm
CROSS_COMPILE=arm-eabi-
MAKE=make
#CC=$(CROSS_COMPILE)gcc
#LD=$(CROSS_COMPILE)ld
obj-m := hello.o
modules:
	$(MAKE) -C $(KERNELDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules
clean:
	rm -rf *.ko *.o .*.cmd *.mod.c *.order *.symvers .tmp_versions/
