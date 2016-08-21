/*
 * =====================================================================================
 *
 *       Filename:  module.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/15/2014 11:38:40 AM
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
#include <linux/types.h>
#include <linux/sched.h>
#include <net/sock.h>
#include <net/netlink.h>

#define NETLINK_TEST 23

struct sock *nl_sk = NULL;
EXPORT_SYMBOL_GPL(nl_sk);

void nl_data_ready (struct sk_buff *__skb)
{
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    u32 pid;
    int rc;
    int len = NLMSG_SPACE(1200);
    char str[100];
    printk("apr--->net_link: data is ready to read.\n");
    skb = skb_get(__skb);
    if (skb->len >= NLMSG_SPACE(0))
    {
        nlh = nlmsg_hdr(skb);
        printk("apr--->net_link: recv %s.\n", (char *)NLMSG_DATA(nlh));
        memcpy(str,NLMSG_DATA(nlh), sizeof(str));
        pid = nlh->nlmsg_pid; /*pid of sending process */
        printk("apr--->net_link: pid is %d\n", pid);
        kfree_skb(skb);
        skb = alloc_skb(len, GFP_ATOMIC);
        if (!skb)
        {
            printk(KERN_ERR "apr--->net_link: allocate failed.\n");
            return;
        }
        nlh = nlmsg_put(skb,0,0,0,1200,0);
        //NETLINK_CB(skb).pid = 0; /* from kernel */
        NETLINK_CB(skb).pid = 0; /* from kernel */
        memcpy(NLMSG_DATA(nlh), str, sizeof(str));
        printk("apr--->net_link: going to send.\n");
        rc = netlink_unicast(nl_sk, skb, pid, MSG_DONTWAIT);
        if (rc < 0)
        {
            printk(KERN_ERR "apr--->net_link: can not unicast skb (%d)\n", rc);
        }
        printk("apr--->net_link: send is ok.\n");
    }
    return;
}

static int test_netlink(void)
{
    struct netlink_kernel_cfg netlink_cfg = {                                                               
        .input = nl_data_ready,
    };
    nl_sk = netlink_kernel_create(&init_net, NETLINK_TEST, &netlink_cfg);
    //netlink_kernel_create(&init_net, NETLINK_DEV_ERROR, &netlink_cfg);
    if (!nl_sk)
    {
        printk(KERN_ERR "apr--->net_link: Cannot create netlink socket.\n");
        return -EIO;
    }
    printk("apr--->net_link: create socket ok.\n");
    return 0;
}

static int hello_init(void)
{
    printk(KERN_ALERT "apr--->Hello, module!\n");
    test_netlink();
    return 0;
}

static void hello_exit(void)
{
    if(nl_sk != NULL)
    {
        sock_release(nl_sk->sk_socket);
    }
    printk(KERN_ALERT "apr--->Goodbye, module!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("Dual BSD/GPL");
