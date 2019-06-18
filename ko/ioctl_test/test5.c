#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

typedef uint32_t uint32; 
#define MAX_IF 10
int main()
{
    struct ifreq ifVec[MAX_IF];//保存所有接口

    int sock = -1;
    if ( (sock = socket( AF_INET, SOCK_DGRAM, 0 )) < 0 )
        fprintf(stderr, "Error:%d, cannot open RAM;\n", errno);

    // get if vector
    struct ifconf ioIfConf;
    ioIfConf.ifc_buf = (void *)ifVec;
    ioIfConf.ifc_len = sizeof(ifVec);
    printf("Len:%d\n", ioIfConf.ifc_len);     

    if (ioctl(sock, SIOCGIFCONF, &ioIfConf) < 0 )//获取所有网络接口信息
        fprintf(stderr, "Error:%d   ioctl IFCONF\n", errno);

    printf("Len:%d\n", ioIfConf.ifc_len);// 和前面到len对比，发现ioctl修改里len到大小 
    //循环打印每个网络接口信息
    {
        struct ifreq *ifPt;
        struct ifreq *ifEndPt;
        ifPt = ifVec;
        ifEndPt = (void *)((char *)ifVec + ioIfConf.ifc_len);
        for (ifPt = ifVec; ifPt < ifEndPt; ifPt++)
        {
            struct ifreq ifReq;
            if ( ifPt->ifr_addr.sa_family != AF_INET ) {
                continue;
            }

            // Temp keepers of interface params...
            uint32 u32_addr, u32_mask;

            /*  打印ip地址  */
            char ipDotBuf[16], subnetDotBuf[16], maskDotBuf[16]; // 保存点分十进制到ip地址
            u32_addr = ((struct sockaddr_in *)&ifPt->ifr_addr)->sin_addr.s_addr;
            inet_ntop(AF_INET, &u32_addr, ipDotBuf, (socklen_t )sizeof(ipDotBuf)); 
            printf("IP Address: %s\n", ipDotBuf);

            /*    打印地址掩码    */
            bzero(&ifReq,sizeof(struct ifreq));  
            memcpy(ifReq.ifr_name, ifPt->ifr_name, sizeof(ifReq.ifr_name));  
            if (ioctl(sock, SIOCGIFNETMASK, &ifReq ) < 0){
                fprintf(stderr, "Error: %d, cannot get mask\n", errno);
            }
            else{
                u32_mask = ((struct sockaddr_in *)&ifReq.ifr_addr)->sin_addr.s_addr;
                inet_ntop(AF_INET, &u32_mask, maskDotBuf, (socklen_t )sizeof(maskDotBuf));
                printf("Mask: %s\n", maskDotBuf);
            }   
            /*    打印MTU    */
            bzero(&ifReq,sizeof(struct ifreq));  
            memcpy(ifReq.ifr_name, ifPt->ifr_name, sizeof(ifReq.ifr_name));  
            if (ioctl(sock, SIOCGIFMTU, &ifReq ) < 0){
                fprintf(stderr, "Error: %d, cannot get MTU\n", errno);
            }
            else{
                printf("SIOCGIFMTU:%d\n", ifReq.ifr_mtu); 
            }
            /* 其他信息的打印方式与掩码和MTU相同 */
        }
    }
}

