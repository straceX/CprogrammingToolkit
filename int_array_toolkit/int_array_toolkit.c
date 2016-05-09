

int min_array(int *ptrVal,size_t size)
{
	int iter = 0;
	int min;
	min = ptrVal[iter++];

	while (iter < size)
	{
		if (min > ptrVal[iter])
			min = ptrVal[iter];

		++iter;
	}	

	return min;

}