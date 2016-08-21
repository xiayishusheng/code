// linux ioctl使用示例: 检测接口的inet_addr, netmask, broad_addr

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

static void usage()
{
    printf("usage : ./a.out interface \n");
    exit(0);
}

int get_all_if_config(void)
{
    int i=0;
    int sockfd;
    struct ifconf ifconf;
    unsigned char buf[512];
    struct ifreq *ifreq;
    ifconf.ifc_len = 512;
    ifconf.ifc_buf = buf;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
    {
        perror("socket");
        exit(1);
    }

    ioctl(sockfd, SIOCGIFCONF, &ifconf);
    ifreq = (struct ifreq*)buf;

    for(i = (ifconf.ifc_len / sizeof(struct ifreq)); i>0; i--)
    {
        //if(ifreq->ifr_flags == AF_INET){
        //for ipv4
        printf("name = [%s]\n", ifreq->ifr_name);
        printf("local addr = [%s]\n",inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr));
        ifreq++;
        //}
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct sockaddr_in *addr;
    struct ifreq ifr;
    char *name, *address;
    int sockfd;

    if(argc != 2)
    {
        usage();
    }
    else
    {
        name = argv[1];
    }

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    strncpy(ifr.ifr_ifrn.ifrn_name, name, IFNAMSIZ-1);

    if(ioctl(sockfd, SIOCGIFADDR, &ifr) == -1)
    {
        perror("ioctl error");
        printf("error 1!\n");
        exit(1);
    }
    addr = (struct sockaddr_in *)&(ifr.ifr_ifru.ifru_addr);
    address = inet_ntoa(addr->sin_addr);
    printf("inet addr: %s.\n", address);

    if(ioctl(sockfd, SIOCGIFBRDADDR, &ifr) == -1)
    {
        perror("ioctl error");
        printf("error 2!\n");
        exit(2);
    }
    addr = (struct sockaddr_in *)&ifr.ifr_ifru.ifru_broadaddr;
    address = inet_ntoa(addr->sin_addr);
    printf("broad addr: %s.\n", address);

    if(ioctl(sockfd,SIOCGIFNETMASK,&ifr) == -1)
    {
        perror("ioctl error");
        printf("error 3!\n");
        exit(3);
    }
    addr = (struct sockaddr_in *)&ifr.ifr_addr;
    address = inet_ntoa(addr->sin_addr);
    printf("inet mask: %s.\n", address);

    printf("\n");

//  printf("=========================================\n");
//  get_all_if_config();
//  printf("=========================================\n");

    exit(0);
}

