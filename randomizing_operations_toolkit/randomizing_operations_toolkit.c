
int irand(int imin, int imax)
{
	
	srand((unsigned)time(NULL));
	return (rand() % imax) + imin;
}
double drand(int fmin, int fmax)
{
	srand((unsigned)time(NULL));
	return ((double)rand() / RAND_MAX) + (rand() % fmax + fmin);
}




