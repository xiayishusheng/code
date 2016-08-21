#include <net/genetlink.h>  
#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>  

/* netlink attributes ����ͨ��ö�������ҵ���Ӧ������,�û��ռ�Ӧ�ó���Ҫ������������Ϣ */

enum
{
    DOC_EXMPL_A_UNSPEC,
    DOC_EXMPL_A_MSG,
    __DOC_EXMPL_A_MAX,
};
#define DOC_EXMPL_A_MAX (__DOC_EXMPL_A_MAX - 1)

/* atribute policy���Ƕ���������Եľ�������,�μ�net/netlink.h */
static struct nla_policy doc_exmpl_genl_policy[DOC_EXMPL_A_MAX + 1] = {  
    [DOC_EXMPL_A_MSG] = {.type = NLA_NUL_STRING},  
};  

#define VERSION_NR 1  

//generic netlink family ����
static struct genl_family doc_exmpl_genl_family = {// 1 ����family
    .id = GENL_ID_GENERATE,
    .hdrsize = 0,
    .name = "CONTROL_EXMPL",
    .version = VERSION_NR,
    .maxattr = DOC_EXMPL_A_MAX,
};

/*�����������ͣ��û��ռ��Դ���������Ҫִ�е�����*/  
enum
{  
    DOC_EXMPL_C_UNSPEC,  
    DOC_EXMPL_C_ECHO,  
    __DOC_EXMPL_C_MAX,  
};
#define DOC_EXMPL_C_MAX (__DOC_EXMPL_C_MAX - 1)

//echo command handler,����һ��msg���ظ�
int doc_exmpl_echo(struct sk_buff *skb2, struct genl_info *info)
{  
    struct nlattr *na;
    struct sk_buff *skb;
    int rc;
    void *msg_hdr;
    char *data;
    if(info == NULL) goto error;  
    //����ÿ�����ԣ�genl_info����attrs��������������ṹ��������payload  
    na = info->attrs[DOC_EXMPL_A_MSG];  
    if(na)
    {
        data = (char *)nla_data(na);  
        if(!data)
            printk("apr--->Receive data error!\n");
        else
            printk("apr--->Recv:%s\n", data);
    }
    else
    {  
        printk("No info->attrs %d\n",DOC_EXMPL_A_MSG);  
    }  

    skb = genlmsg_new(NLMSG_GOODSIZE,GFP_KERNEL);  
    if(!skb) goto error;  

    /*������Ϣͷ������ԭ���� 
      genlmsg_put(struct sk_buff *,int pid,int seq_number, 
      struct genl_family *,int flags,u8 command_index); 
     */  
    msg_hdr = genlmsg_put(skb,0,info->snd_seq+1,&doc_exmpl_genl_family,  
            0,DOC_EXMPL_C_ECHO);  
    if(msg_hdr == NULL)
    {
        rc = -ENOMEM;
        goto error;
    }

    //�������netlink attribute:DOC_EXMPL_A_MSG������ʵ��Ҫ��������  
    rc = nla_put_string(skb, DOC_EXMPL_A_MSG, "This is a msg from kernel space!");
    if(rc != 0)
        goto error;

    genlmsg_end(skb,msg_hdr);//��Ϣ�������
    //�������͸��û��ռ��ĳ������
    rc = genlmsg_unicast(genl_info_net(info), skb, info->snd_pid);
    if(rc != 0)
    {  
        printk("apr--->Unicast to process:%d failed!\n", info->snd_pid);
        goto error;
    }
    printk("apr--->Unicast to process:%d failed!\n", info->snd_pid);
    return 0;

error:
    printk("apr--->Send:%s.\n", "This is a msg from kernel space!");
    return 0;
}  

//������command echo�;����handler��Ӧ����  
static struct genl_ops doc_exmpl_genl_ops_echo = {// 2 ����operation
    .cmd = DOC_EXMPL_C_ECHO,
    .flags = 0,
    .policy = doc_exmpl_genl_policy,
    .doit = doc_exmpl_echo,
    .dumpit = NULL,
};

//�ں���ڣ�ע��generic netlink family/operations  
static int __init genKernel_init(void)
{  
    int rc;  
    printk("apr--->Generic Netlink Example Module inserted.\n");

    rc = genl_register_family(&doc_exmpl_genl_family);// 3 ע��family
    if (rc != 0)
    {
        goto failure;  
    }  
    rc = genl_register_ops(&doc_exmpl_genl_family, &doc_exmpl_genl_ops_echo);// 4 ע��operation
    if (rc != 0)
    {
        printk("apr--->Register ops: %i\n",rc); 
        genl_unregister_family(&doc_exmpl_genl_family);  
        goto failure;
    }  
    return 0;

failure:
    printk("apr--->Error occured while inserting generic netlink example module\n");  
    return -1;  
}  

static void __exit genKernel_exit(void) {
    int ret;
    printk("apr--->Generic Netlink Example Module unloaded.\n");

    ret = genl_unregister_ops(&doc_exmpl_genl_family,&doc_exmpl_genl_ops_echo);
    if(ret != 0)
    {
        printk("apr--->Unregister ops failed: %i\n",ret);
        return;
    }
    ret = genl_unregister_family(&doc_exmpl_genl_family);
    if(ret !=0)
    {
        printk("apr--->Unregister family failed:%i\n",ret);
        return;
    }
}

module_init(genKernel_init);  
module_exit(genKernel_exit);  
MODULE_LICENSE("GPL");
