#include <direct.h>

int get_system_cpu_arc();
char *get_system_ip(char *);
char *get_system_mac(char *);

/*memory for the path, which allows the code to support file paths
longer than _MAX_PATH, which are supported by NTFS.*/
char *getpwd(void);