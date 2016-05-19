char *upper_string(char *ptrVal, size_t size)
{
	size_t iter = 0;

	if (size == 0)
		return NULL;

	while (ptrVal[iter] != '\0' && (iter < size) )
	{
		ptrVal[iter] = toupper(ptrVal[iter++]);
	}
	return ptrVal;
}


char *lower_string(char *ptrVal, size_t size)
{
	size_t iter = 0;

	if (size == 0)
		return NULL;

	while (ptrVal[iter] != '\0' && (iter < size))
	{
		ptrVal[iter] = tolower(ptrVal[iter++]);
	}
	return ptrVal;
}


int sizeof_string(const char *ptrVal)
{
	size_t iter = 0;

	while (ptrVal[iter] != '\0')
		++iter;

	return iter;

}