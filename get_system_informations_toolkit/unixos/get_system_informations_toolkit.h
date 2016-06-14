#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>
#include <errno.h>

int get_system_cpu_arc();
char *get_system_ip(char *);
char *get_system_mac(char *,const char*);
char *get_system_netmask(const char *interface);
char *getpwd(void);
char *getcwd(void);
