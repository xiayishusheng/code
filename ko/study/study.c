#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "study.h"

void main(int argc, char **argv)
{
    char *ifname;
    struct qygifreq ifr;

    ifname = "wlan0";

    strncpy(ifr.ifr_ifrn.ifrn_name, ifname, sizeof(ifname));
    printf("ifname = %s.\n", ifname);
    printf("ifr.ifru_addr = %s.\n", ifr.ifr_ifrn.ifrn_name);
}
