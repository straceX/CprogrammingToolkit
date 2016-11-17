/*ptrS = array size upper than [sizeof(int) * 8 + 1]*/
char *int_to_binary(const int ival,char *ptrS)
{
	if (ival < 0)
		return NULL;
	if(itoa(ival, ptrS, 2))	return ptrS;
	//printf("%0*s\n", sizeof(int) * 8, ptrS);
	
	return NULL;
}

/*set number's .th bit value */
int set_bit(int ival, size_t n)
{
	if (n > 31) return ival;
	return ival |= 1 << n;
}

/*reset number's .th bit value */
int reset_bit(int ival, size_t n)
{
	if (n > 31) return ival;
	return ival &= ~(1 << n);
}
/* swap n. bit value if 0->1 && 1->0*/
int swap_bit(int ival, size_t n)
{
	if (n > 31) return ival;
	return ival ^= (1 << n);
}
/*get n. bit value*/
int get_bit(int ival, size_t n)
{
	if (n > 31) return -1;
	if (ival & (1 << n))
		return 1;
	else
		return 0;
}