#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <linux/genetlink.h>
  
  
//�궨�壺����generic netlink msg�ľ��幹�춨λ
#define GENLMSG_DATA(glh)	          ((void *)(NLMSG_DATA(glh) + GENL_HDRLEN))  
#define GENLMSG_PAYLOAD(glh)    (NLMSG_PAYLOAD(glh, 0) - GENL_HDRLEN)  
#define NLA_DATA(na) ((void *)      ((char*)(na) + NLA_HDRLEN))  
  
#define MESSAGE_TO_KERNEL "WIFI_OPEN-FAILED"
  
struct nlattr *nl_na;
struct sockaddr_nl nl_address;
struct
{
	struct nlmsghdr n;  
	struct genlmsghdr g;  
	char buf[256];  
} nl_request_msg, nl_response_msg;

int main(void)
{
	int nl_fd;
	int nl_family_id = 0;
	int len;
	
	nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_GENERIC);  
	if (nl_fd < 0)
	{
		perror("apr--->socket()");
		return -1;
	}
  
        memset(&nl_address, 0, sizeof(nl_address));
        nl_address.nl_family = AF_NETLINK;
        nl_address.nl_groups = 0;
  
	if (bind(nl_fd, (struct sockaddr *) &nl_address, sizeof(nl_address)) < 0)
	{
		perror("apr--->bind()");
		close(nl_fd);
		return -1;
	}  
  
        nl_request_msg.n.nlmsg_type	= GENL_ID_CTRL;//�ں���genl_ctl��id  = 0x10
        nl_request_msg.n.nlmsg_flags	= NLM_F_REQUEST;
        nl_request_msg.n.nlmsg_seq		= 0;
        nl_request_msg.n.nlmsg_pid		= getpid();
        nl_request_msg.n.nlmsg_len		= NLMSG_LENGTH(GENL_HDRLEN);
        //Populate the payload's "family header" : which in our case is genlmsghdr
        nl_request_msg.g.cmd = CTRL_CMD_GETFAMILY;
        nl_request_msg.g.version = 0x1;
        //Populate the payload's "netlink attributes"
        nl_na = (struct nlattr *) GENLMSG_DATA(&nl_request_msg);// �൱����nl_request_msg ��buf���й���һ��nla
  
        nl_na->nla_type = CTRL_ATTR_FAMILY_NAME;
        nl_na->nla_len = strlen("CONTROL_EXMPL") + 1 + NLA_HDRLEN;
        strcpy(NLA_DATA(nl_na), "CONTROL_EXMPL"); //Family name length can be upto 16 chars including \0
  
        nl_request_msg.n.nlmsg_len += NLMSG_ALIGN(nl_na->nla_len);
  
        memset(&nl_address, 0, sizeof(nl_address));
        nl_address.nl_family = AF_NETLINK;
  
        len= sendto(nl_fd, (char *) &nl_request_msg, nl_request_msg.n.nlmsg_len,
                       0, (struct sockaddr *) &nl_address, sizeof(nl_address));
        if (len != nl_request_msg.n.nlmsg_len)
	{
                perror("apr--->sendto()");
                close(nl_fd);
                return -1;
        }
  
        len= recv(nl_fd, &nl_response_msg, sizeof(nl_response_msg), 0);  
        if (len < 0)
	{
                perror("apr--->recv()");
                return -1;
        }  
  
        if (!NLMSG_OK((&nl_response_msg.n), len))
	{  
                fprintf(stderr, "apr--->family ID request : invalid message\n");
                return -1;
        }
        if (nl_response_msg.n.nlmsg_type == NLMSG_ERROR)
	{ //error  
                fprintf(stderr, "apr--->family ID request : receive error\n");  
                return -1;  
        }  
  
        //������attribute�е�family id  
        nl_na = (struct nlattr *) GENLMSG_DATA(&nl_response_msg);  
        nl_na = (struct nlattr *) ((char *) nl_na + NLA_ALIGN(nl_na->nla_len));  
        if (nl_na->nla_type == CTRL_ATTR_FAMILY_ID)
	{
                nl_family_id = *(__u16 *) NLA_DATA(nl_na);//��һ��ͨ�ž���Ϊ�˵õ���Ҫ��family ID  
        }
  
        memset(&nl_request_msg, 0, sizeof(nl_request_msg));
        memset(&nl_response_msg, 0, sizeof(nl_response_msg));
  
        nl_request_msg.n.nlmsg_len = NLMSG_LENGTH(GENL_HDRLEN);
        nl_request_msg.n.nlmsg_type = nl_family_id;
        nl_request_msg.n.nlmsg_flags = NLM_F_REQUEST;
        nl_request_msg.n.nlmsg_seq = 60;
        nl_request_msg.n.nlmsg_pid = getpid();
        nl_request_msg.g.cmd = 1; //corresponds to DOC_EXMPL_C_ECHO;

        nl_na = (struct nlattr *) GENLMSG_DATA(&nl_request_msg);
        nl_na->nla_type = 1; // corresponds to DOC_EXMPL_A_MSG
        nl_na->nla_len = sizeof(MESSAGE_TO_KERNEL) + NLA_HDRLEN; //Message length
        memcpy(NLA_DATA(nl_na), MESSAGE_TO_KERNEL, sizeof(MESSAGE_TO_KERNEL));
        nl_request_msg.n.nlmsg_len += NLMSG_ALIGN(nl_na->nla_len);

        memset(&nl_address, 0, sizeof(nl_address));
        nl_address.nl_family = AF_NETLINK;

        len = sendto(nl_fd, (char *) &nl_request_msg, nl_request_msg.n.nlmsg_len,
                        0, (struct sockaddr *) &nl_address, sizeof(nl_address));
        if (len != nl_request_msg.n.nlmsg_len)
	{
                perror("apr--->sendto()");
                close(nl_fd);
                return -1;
        }
        printf("apr--->Sent to kernel: %s\n", MESSAGE_TO_KERNEL);

        len = recv(nl_fd, &nl_response_msg, sizeof(nl_response_msg), 0);
        if (len < 0)
	{
                perror("apr--->recv()");
                return -1;  
        }  
  
         //�쳣����  
        if (nl_response_msg.n.nlmsg_type == NLMSG_ERROR)
	{ //Error  
        	printf("apr--->Error while receiving reply from kernel: NACK Received\n");
                close(nl_fd);
                return -1;
        }
        if (len < 0)
	{
                printf("apr--->Error while receiving reply from kernel\n");  
                close(nl_fd);
                return -1;
        }
        if (!NLMSG_OK((&nl_response_msg.n), len))
	{
                printf("apr--->Error while receiving reply from kernel: Invalid Message\n");  
                close(nl_fd);
                return -1;
        }

        //�����յ��������ں˵�reply
        len = GENLMSG_PAYLOAD(&nl_response_msg.n);
        nl_na = (struct nlattr *) GENLMSG_DATA(&nl_response_msg);
        printf("apr--->Kernel replied: %s\n", (char *)NLA_DATA(nl_na));
        close(nl_fd);
        return 0;
}