#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
	
int open_tcpip_server(int);
int open_tcpip_client(char *,int);



void err_exit(const char *msg);
int open_connetion(const char *hostname, const int portno,const char **msgs);
int read_line_unbuffered(int sock, char *buf, size_t len);
int read_socket(int sock, void *buf, size_t len);
int get_file_via_http(const char *hostname, const char *portno, const char *filename);





