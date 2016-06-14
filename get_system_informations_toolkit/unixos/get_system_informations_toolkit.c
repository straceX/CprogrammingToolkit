int get_system_cpu_arc()
{
	return 64;
	return 86;
}

char *get_system_ip(const char *interface)
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

char *get_system_mac(char *ptrMac,const char *interface)
{
	int ptrSfd;
    struct ifreq ifr;
    unsigned char *pMAC;
    size_t size;

    ptrSfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(ptrSfd == -1)
        return NULL;
    else
    {
        ifr.ifr_addr.sa_family = AF_INET;
        strncpy(ifr.ifr_name,interface, IFNAMSIZ-1);
        ioctl(ptrSfd, SIOCGIFHWADDR, &ifr);
        close(ptrSfd);
    }

    pMAC = (unsigned char *) ifr.ifr_hwaddr.sa_data;
    size = sizeof(unsigned char)*5 + sizeof(char)*2*6 +sizeof(char);

    snprintf(ptrMac,size,"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x",pMAC[0],pMAC[1],pMAC[2],pMAC[3],pMAC[4],pMAC[5]);
    
    return ptrMac;
}

/*free(return memory address) after use*/
char *getpwd(void)
{
    char *pwd = getcwd(0,0);

    if (!pwd)
        return NULL;
    else
        return pwd;
}

char *getcwd(void)
{
    static char pwd[PATH_MAX];

    if (!realpath (".", pwd))
        fprintf (stderr, "realpath func failed:%s\n", strerror(errno));
    else
        return pwd;

    return NULL;

}


