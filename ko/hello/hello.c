/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年12月30日 00时17分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void)
{
        //提供一个ioctl给上层调用
        printk(KERN_INFO "Hello, world!\n");
        return 0;

}
static void hello_exit(void)
{
        //回收资源
        printk(KERN_INFO "Goodbye, cruel world!\n");

}
module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("qyg");
MODULE_DESCRIPTION("Test ko!");
