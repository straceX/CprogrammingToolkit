void swaper(char *val1, char *val2, size_t width)
{
	size_t iter;
	char temp;

	for (iter = 0; iter < width; ++iter) {
		temp = pc1[iter];
		val1[iter] = val2[iter];
		val2[iter] = temp;
	}
}

void sort(void *base, size_t count, size_t width, int (*cmp)(const void *, const void *))
{
	size_t  i, k;
	char *cbase = (char *)base;
	char *pc1, *pc2;

	for (i = 0; i < count - 1; ++i)
		for (k = 0; k < count - 1 - i; ++k) {
			pc1 = cbase + k * width;
			pc2 = cbase + (k + 1) * width;

			if (cmp(pc1, pc2) > 0) 
				swaper(pc1, pc2, width);
		}
}

/*
int comparer(const void *pv1, const void *pv2)
{
	const int *pi1 = (const int *)pv1;
	const int *pi2 = (const int *)pv2;

	if (*pi1 > *pi2)
		return 1;
	if (*pi1 < *pi2)
		return -1;

	return 0;
}

int main(void)
{
		int a[10] = { 34, 23, 45, 11, 78, 43, 34, 87, 33, 21 };
		int i;

		sort(a, 10, sizeof(int), comparer);

		for (i = 0; i < 10; ++i)
			printf("%d ", a[i]);
		printf("\n");
		printf("--------------------\n");

}
*/