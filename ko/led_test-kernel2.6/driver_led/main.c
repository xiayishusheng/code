
//head
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/cdev.h>

#define BASE_NUM 0
#define COUNT 1
#define DEV_NAME "led"

static char k_buf[128] = {0};
//static struct cdev *led_cdev = NULL;
static struct cdev led_cdev;
static dev_t dev = 0;
//#define VADDR __REG(0x10500000)
static volatile unsigned int pa = 0x10500000;
static volatile unsigned int va;

//description
MODULE_AUTHOR("huangminqiang2007@163.com");
MODULE_DESCRIPTION("THIS IS FOR TESTING");
MODULE_LICENSE("GPL");

//open close read write
//open
static int led_open(struct inode *i_node, struct file *filep)
{
	return 0;
}

//close
static int led_close(struct inode *i_node, struct file *filep)
{
	return 0;
}

//read
static int led_read(struct file *filep,char *buf,
			size_t size,loff_t *offset)
{
	int cnt = -1;
	
	if(NULL == filep)
	{
		goto _out;
	}	
	
	cnt = copy_to_user(buf,k_buf,sizeof(k_buf));
	
	return (sizeof(k_buf)-cnt);
_out:
	return -1;
}

//write
static int led_write(struct file *filep,const char *buf,
			size_t size,loff_t *offset)
{
	if(NULL == filep)
	{
		goto _out;
	}	

	copy_from_user(k_buf,buf,size);
	*(char *)va = k_buf[0];	
	//writew(k_buf[0],va);
	//*(char *)VADDR = k_buf[0];
	return size;
_out:
	return -1;
}

//file operations
static struct file_operations led_ops = {
	.owner=	 	THIS_MODULE,
	.open=		led_open,
	.release=	led_close,	
	.read= 		led_read,
	.write= 	led_write,
};

//init
static int __init led_init(void)
{
	int cnt = -1;
	
	//paddr to vaddr
	(int *)va = ioremap(pa,4);

	//alloc cdev region
	cnt = alloc_chrdev_region(&dev,BASE_NUM,COUNT,DEV_NAME);
	if(0 > cnt)
	{
		goto _out;
	}
		
	//alloc cdev，如果直接定义变量则不用申请内存。
	//led_cdev = cdev_alloc();
	//init cdev
	cdev_init(&led_cdev,&led_ops);
	//add cdev
	cnt = cdev_add(&led_cdev,dev,COUNT);
	//printk major_num
	printk("<0>" "major number : %d\n",MAJOR(dev));


	if(0 > cnt)
	{
		goto _out;
	}

	printk("<0>" "init ok!\n");

	return 0;
_out:
	return -1;
}

//exit
static void __exit led_exit(void)
{
	//unregister cdev region
	unregister_chrdev_region(dev,COUNT);
	//del cdev
	cdev_del(&led_cdev);

	iounmap((char *)va);

	printk("<0>" "exit ok!\n");
}

//add to kernel
module_init(led_init);
module_exit(led_exit);

