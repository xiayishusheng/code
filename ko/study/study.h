#ifndef _QYG_STUDY_H
#define _QYG_STUDY_H

struct sockaddr {
    char        sa_data[14];
    char        ssa[8];
};

struct qygifreq
{
#define IFHWADDRLEN     6
    union
    {
        char ifrn_name[16];
    } ifr_ifrn;

    union
    {
        struct sockaddr ifru_addr;
        struct sockaddr ifru_hwaddr;
        struct sockaddr ifru_netmask;
        int    ifru_mtu;
        int    ifru_ivalue;
    } ifr_ifru;
};

//#define ifr_name    ifr_ifrn.ifrn_name

#endif /* _QYG_STUDY_H */
