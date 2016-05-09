

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


int is_sorted(const int *ptr,size_t size)
{
    int iter =0;
    int loop = size-1;

    while (iter != loop)
    {
        if(ptr[iter] > ptr[iter+1])
            return 0;
        else
            ++iter;
    }

    return 1;
}