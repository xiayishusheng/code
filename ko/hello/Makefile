KERNELDIR := /lib/modules/`uname -r`/build
PWD := $(shell pwd)
obj-m := hello.o
MAKE=make
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
