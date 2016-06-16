#include <direct.h>

/*return 64 or 86 for system architecture*/
int get_system_cpu_arc();

/*return windows system IP address via second parameters (interface)*/
char *get_system_ip(char [],const char *);

/*return windows system MAC address via second parameters (interface)*/
char *get_system_mac(char [],const char *);

/*memory for the path, which allows the code to support file paths
longer than _MAX_PATH, which are supported by NTFS.*/
char *getpwd(void);