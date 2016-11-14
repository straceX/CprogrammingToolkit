/*ptrS = array size upper than [sizeof(int) * 8 + 1]*/
char *int_to_binary(const int ival,char *ptrS)
{
	if (ival < 0)
		return NULL;
	if(itoa(ival, ptrS, 2))	return ptrS;
	//printf("%0*s\n", sizeof(int) * 8, ptrS);
	
	return NULL;
}