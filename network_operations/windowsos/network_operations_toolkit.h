#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <Windows.h>

/*------------------------------------------------------------------------------------*/
void err_exit(LPCSTR lpszMsg, int status, DWORD dwLastError);
int read_line_unbuffered(SOCKET sock, char *buf, size_t len);
int read_socket(SOCKET sock, void *buf, size_t len);
int open_connetion(const char *hostname, const int portno, const char **msgs);
int get_file_via_http(const char *hostname, const char *portno, const char *filename);
/*------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------*/
int open_tcpip_server(int);
int open_tcpip_client(char *,int);
/*------------------------------------------------------------------------------------*/
