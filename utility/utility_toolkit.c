void swap2int(int *val1,int *val2)
{
	if(*val1 != *val2)
	{
	    *val1 = (*val1) ^ (*val2);
	    *val2 = (*val1) ^ (*val2);
	    *val1 = (*val1) ^ (*val2);
	}

}

char *decimal_to_binary(size_t number)
{
	char *binaryFormat;
	int bdigits;
	int iter = 0;
	int tNumber;

	if (!number)
	{
		binaryFormat = "0";
		return binaryFormat;
	}
		 

	tNumber = number;	
	bdigits = 0;
	
	do 
	{
		++bdigits;
	} while (tNumber /= 2);

	

	if (!(binaryFormat = malloc((bdigits + 1)*(sizeof(char)))))
		return NULL;

	
	iter = bdigits;
	binaryFormat[iter--] = '\0';

	tNumber = number;

	do
	{
		binaryFormat[iter] = 48 + tNumber % 2;
		--iter;

	} while (tNumber /= 2);

	return binaryFormat;
	
}

int inverse_number(int val)
{

	return val;
}

char * base64_decoder(const char *sval)
{
	return NULL;
}
char * base64_encoder(const char *ptrVal)
{
	return NULL;
}
char * url_decoder(const char *ptrVal)
{
	return NULL;
}
char * url_encoder(const char *ptrVal)
{
	return NULL;
}

char *ascii2hex(const char  *ptrVal,size_t size)
{
	char *ptr = NULL;
	int iter;
	if (!(ptr = (char *)(malloc(sizeof(char) * ( size * 2 + 1 )))))
		return NULL;
	else
	{
		for (iter = 0; iter < size; ++iter)
			sprintf(ptr + (iter * 2), "%02X", ptrVal[iter]);

		ptr[iter*2] = '\0';
		return ptr;
	}
	
	return NULL;
}

char *hex2ascii(const char  *ptrVal,size_t size)
{
	return NULL;
}


