char *get_ip_address(const char * interface)
{
	 int ptrSfd;
	 struct ifreq ifr;

	 ptrSfd = socket(AF_INET, SOCK_DGRAM, 0);

	 if(ptrSfd == -1)
	 	return NULL;
	 else
	 {	 
	 	ifr.ifr_addr.sa_family = AF_INET;
	 
	 	strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);

	 	ioctl(ptrSfd, SIOCGIFADDR, &ifr);

	 	close(ptrSfd);

	 	return inet_ntoa( ( (struct sockaddr_in *)(&ifr.ifr_addr) )->sin_addr );
	} 

}

int open_tcpip_server(int port)
{

}

int open_tcpip_client(char *ip,int port)
{

}

