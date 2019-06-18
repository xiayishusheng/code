#include <arpa/inet.h>
#include <fcntl.h>
#include <net/if.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// 获得公网ip
int getpublicip(char* ip)
{
    int    sock;
    char **pptr = NULL;
    struct sockaddr_in    destAddr;
    struct hostent    *ptr = NULL;
    char destIP[128];

    sock = socket(AF_INET,SOCK_STREAM,0);
    if( -1 == sock ){
        perror("creat socket failed");
        return -1;
    }
    bzero((void *)&destAddr,sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(80);
    ptr = gethostbyname("www.ip138.com");
    if(NULL == ptr){
        perror("gethostbyname error");
        return -1;
    }
    for(pptr=ptr->h_addr_list ; NULL != *pptr ; ++pptr){
        inet_ntop(ptr->h_addrtype,*pptr,destIP,sizeof(destIP));
        printf("addr:%s\n",destIP);
        ip = destIP;
        return 1;
    }
    return 1;
}

// 获得内网ip
int getlocalip(char* outip)
{
    int i=0;
    int sockfd;
    struct ifconf ifconf;
    char buf[512];
    struct ifreq *ifreq;
    char* ip;
    //初始化ifconf
    ifconf.ifc_len = 512;
    ifconf.ifc_buf = buf;
    strcpy(outip,"127.0.0.1");
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
    {
        return -1;
    }
    ioctl(sockfd, SIOCGIFCONF, &ifconf);    //获取所有接口信息
    close(sockfd);
    //接下来一个一个的获取IP地址
    ifreq = (struct ifreq*)buf;
    for(i=(ifconf.ifc_len/sizeof(struct ifreq)); i>0; i--)
    {
        ip = inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr);


        if(strcmp(ip,"127.0.0.1")==0)  //排除127.0.0.1，继续下一个
        {
            ifreq++;
            continue;
        }
    }
    strcpy(outip,ip);
    return 0;
}

int main()
{
    char *ip1;
    getpublicip(ip1);
    printf("%s", ip1);

    char *ip2;
    getlocalip(ip2);
    printf("%s", ip2);
    return 0;
}
