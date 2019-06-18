/*
 * =====================================================================================
 *
 *       Filename:  test1.c
 *
 *    Description:  c语言实现由网络地址获取ip
 *
 *        Version:  1.0
 *        Created:  2019年06月18日 10时51分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    struct addrinfo *res;
    struct sockaddr_in *sinp;
    const char *addr;
    char abuf[1024];

    if(getaddrinfo("www.baidu.com","http",NULL,&res)==-1)  
    {  
        printf("error to get IP from host name");  
    }
    else
    {
        sinp = (struct sockaddr_in *)res->ai_addr;
        addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, 1024);
        printf("address %s\t", addr ? addr : "unknown");
        printf("port %d\n", ntohs(sinp->sin_port));
    }

    return 0;
}
