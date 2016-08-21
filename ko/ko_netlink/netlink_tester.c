/*
 * =====================================================================================
 *
 *       Filename:  sender.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2014 02:49:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/socket.h>
#include <cutils/log.h>

#define MAX_PAYLOAD 1024 /* maximum payload size*/
#define NETLINK_TEST 23

struct sockaddr_nl src_addr, dest_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
int sock_fd;
struct msghdr msg;

int main(int argc, char* argv[])
{
	ALOGE("netlink_tester apr--->sleep(5)---------------->\n");
	sleep(5);
	sock_fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_TEST);
	if(0 > sock_fd)
	{
		ALOGE("netlink_tester apr--->create netlink socket failed!\n");
	}
	else
	{
		ALOGE("netlink_tester apr--->create netlink socket ok!\n");
	}
	memset(&msg, 0, sizeof(msg));
	memset(&src_addr, 0, sizeof(src_addr));
	src_addr.nl_family = AF_NETLINK;
	src_addr.nl_pid = getpid(); /* self pid */
	src_addr.nl_groups = 0;     /* not in mcast groups */
	bind(sock_fd, (struct sockaddr*)&src_addr, sizeof(src_addr));
	memset(&dest_addr, 0, sizeof(dest_addr));
	dest_addr.nl_family = AF_NETLINK;
	dest_addr.nl_pid = 0;      /* For Linux Kernel */
	dest_addr.nl_groups = 0;   /* unicast */
	nlh=(struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
	/* Fill the netlink message header */
	nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
	nlh->nlmsg_pid = getpid(); /* self pid */
	nlh->nlmsg_flags = 0;
	/* Fill in the netlink message payload */
	strcpy(NLMSG_DATA(nlh), "WIFI_OPEN-FAILED");
	iov.iov_base = (void *)nlh;
	iov.iov_len = nlh->nlmsg_len;
	msg.msg_name = (void *)&dest_addr;
	msg.msg_namelen = sizeof(dest_addr);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	ALOGE("netlink_tester apr---> Sending message.\n");
	sendmsg(sock_fd, &msg, 0);

	//while(1){}
#if 1
	/* Read message from kernel */
	memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
	recvmsg(sock_fd, &msg, 0);
	ALOGE("netlink_tester apr---> Received message: %s\n", NLMSG_DATA(nlh));
	/* Close Netlink Socket */
#endif
	close(sock_fd);
	return 0;
}
