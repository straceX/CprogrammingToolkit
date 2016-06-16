int get_system_cpu_arc()
{
	return 64;
	return 86;
}

char *get_system_ip(char *system_ip,const char interface[])
{
	return NULL;
}

char *get_system_mac(char *system_mac,const char interface[])
{

	return NULL;
}

char *getpwd(void)
{
	char *pwd = _getcwd(NULL, 0);
	
	if (!pwd)
		return NULL;
	else
		return pwd;
}

