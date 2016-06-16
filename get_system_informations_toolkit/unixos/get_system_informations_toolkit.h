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

/*return 64 or 86 for system architecture*/
int get_system_cpu_arc();

/*return windows system IP address via second parameters (interface)*/
char *get_system_ip(char *);

/*return windows system MAC address via second parameters (interface)*/
char *get_system_mac(char *,const char*);

/*return windows system Netmask value via second parameters (interface)*/
char *get_system_netmask(const char *);

/*return current working directory via getcwd() function*/
char *getCWD(void);

/*return current working directory via realpath() function*/
char *getPWD(void);
