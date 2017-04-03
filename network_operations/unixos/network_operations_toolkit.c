int open_tcpip_server(int port)
{

}

int open_tcpip_client(char *ip,int port)
{

}



int open_connetion(const char *hostname, const int portno,const char **msgs)
{
	int clientSock,iter;
	struct sockaddr_in sinClient;
    struct hostent *host;
	if ((clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		err_exit("socket");

	sinClient.sin_family = AF_INET;
	sinClient.sin_port = htons(portno);
	sinClient.sin_addr.s_addr = inet_addr(hostname);
	if (sinClient.sin_addr.s_addr == INADDR_NONE) 
	{
		if ((host = gethostbyname(hostname)) == NULL)
			err_exit("gethostbyname");
		
		memcpy(&sinClient.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
	}
	
	if (connect(clientSock, (struct sockaddr *) &sinClient, sizeof(sinClient)) == -1)
		err_exit("connect");

	for (iter = 0; msgs[iter] != NULL; ++iter)
		if (send(clientSock, msgs[iter], strlen(msgs[iter]), 0) == -1)
			err_exit("send");
	
	return clientSock;
}


int read_line_unbuffered(int sock, char *buf, size_t len)
{
	char ch1 = '\0', ch2;
	size_t i;
	int result;

	for (i = 0; i < len - 1; ++i) 
	{
		if ((result = recv(sock, &ch2, 1, 0)) == -1)
			return -1;
		if (result == 0)
			return 0;
		buf[i] = ch2;
		if (ch2 == '\n' && ch1 == '\r') {
			buf[i + 1] = '\0';
			return i + 1;
		}
		else
			ch1 = ch2;
	}
	return i;
}

int read_socket(int sock, void *buf, size_t len)
{
	int result;
	size_t index = 0;
	size_t left = len;
	char *cbuf = (char *)buf;

	while (left > 0) {
		if ((result = recv(sock, cbuf + index, left, 0)) == -1)
			return -1;
		if (result == 0)
			break;
		left -= result;
		index += result;
	}
	return index;
}

void err_exit(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}


/*
#Linux
>>>run "python -m SimpleHTTPServer <port no>" command where Test.txt file include

get_file_via_http("localhost",<port no>,"Test.txt");
*/
int get_file_via_http(const char *hostname, const char *portno, const char *filename)
{
	int clientSock;
	long contentLength;
	char line[1024];
	char *buf;
	int result;
	int iter;

	const int sizeG = (sizeof(filename)/ sizeof(char)) + 18;
	const int sizeH = (sizeof(hostname)/ sizeof(char)) + 18;
	char *ptrGetMsg[] = {NULL,NULL,"\r\n", NULL };

	char *ptrGetPART = (char*) malloc( sizeG*sizeof(char) );
	char *ptrHostPART = (char*) malloc( sizeH*sizeof(char) );


	if(!ptrGetPART || !ptrHostPART)
		err_exit("malloc\n");
	else
	{
		strcpy(ptrGetPART,"GET /");
		strcat(ptrGetPART,filename);
		strcat(ptrGetPART," HTTP/1.1\r\n");
		ptrGetMsg[0] = ptrGetPART;

 		strcpy(ptrHostPART,"Host: ");
		strcat(ptrHostPART,hostname);				
		strcat(ptrHostPART,"\r\n");
		ptrGetMsg[1] = ptrHostPART;		

	} 

	clientSock = open_connetion(hostname,portno,ptrGetMsg);
	contentLength = -1;
	for (;;) 
	{

		result = read_line_unbuffered(clientSock, line, 1024);
		if (result == -1)
			err_exit("read_line_unbuffered");
		if (result == 0)		/* socket is closed*/
			break;
		if (result == 2)		/* header lines ended*/
			break;

		if (strstr(line, "Content-Length: "))
			contentLength = strtol(line + 15, NULL, 10);
		
		printf(line);
	}

	if (contentLength != -1) {
		if ((buf = (char *)malloc(contentLength)) == NULL) {
			fprintf(stderr, "cannot allocate memory!\n");
			exit(EXIT_FAILURE);
		}
		if (read_socket(clientSock, buf, contentLength) == -1)
			err_exit("read_socket");

		for (iter = 0; iter < contentLength; ++iter)
			putchar(buf[iter]);
		putchar('\n');
		free(buf);
	}
	
	shutdown(clientSock, SHUT_RDWR);
	close(clientSock);

	return 0;

}



