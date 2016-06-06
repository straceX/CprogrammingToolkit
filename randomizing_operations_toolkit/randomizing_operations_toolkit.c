
int irand(int imin, int imax)
{
	
	srand((unsigned)time(NULL));
	return (rand() % imax) + imin;
}
double drand(int dmin, int dmax)
{
	srand((unsigned)time(NULL));
	return ((double)rand() / RAND_MAX) + (rand() % dmax + dmin);
}


