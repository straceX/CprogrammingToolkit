int is_prime(unsigned int param)
{
    int iter,length;

    if(param < 2) return 0;

    else if( param == 2 || param == 3 || param == 5 || param == 7 ) return 1;

    else
    {
        length  = param / 2;
        iter    = 2;

        while(iter <= length)
        {
            if( !(param%iter) )
                return 0;

            ++iter;
        }

        return 1;

    }
}

/*array first element step_count(array size)*/
int *division_steps(int val)
{

    int iter;
    int *ptrSteps;
    int step_count = log10(val)+1;

    if ( !(ptrSteps = (int *)malloc( sizeof(int) * ( step_count + 1 ) )) )
        return NULL;
    else
    {
        ptrSteps[0] = step_count;


        for(iter=1; iter <= step_count ;++iter)
        {
            ptrSteps[iter] = val%10;
            val /= 10;
        }
        return ptrSteps;
    }
}

int division_steps_sum(int val)
{
    int iter;
    int sum =0;
    int step_count=0;

    int *ptr = division_steps(val);

    step_count = ptr[0];


    for(iter = 1; iter <= step_count; ++iter)
        sum += ptr[iter];

    return sum;

}

/*Max 20! calculate x64 system*/
unsigned long long factorial(size_t val)
{
    size_t iter;
    unsigned long long res=1;

    if(val==0 || val == 1)
        return 1;
    else
    {
        for(iter=2;iter<=val;++iter)
        {
            res *=iter;
        }
    }
    return res;
}

/* nPr | n max 20*/
unsigned long long Permutations(size_t n,size_t r)
{
    if(n<r)
        return 0;
    else
        return (factorial(n)/factorial(n-r));
}

/* nCr | n max 20*/
unsigned long long Combinations(size_t n,size_t r)
{
    if(n<r)
        return 0;
    else
        return (Permutations(n,r) / factorial(r));
}


int greatest_common_divisor(int ival1,int ival2)
{

    return -1;
}

int least_common_multiple(int ival1,int ival2)
{

    return -1;
}

int *get_fibonacci_numbers(int ptrFib[], size_t size)
{
    int iter;
    if (!size)
        return NULL;
    if (size == 1) {
        ptrFib[0] = 1;
        return ptrFib;
    }
    else
    {
        ptrFib[0] = 1;
        ptrFib[1] = 1;

        for (iter = 2; iter < size; ++iter) {
            ptrFib[iter] = ptrFib[iter - 1] + ptrFib[iter - 2];
        }
        return ptrFib;
    }
    
}

/* In recreational number theory, a narcissistic number (also known as a pluperfect digital invariant (PPDI), 
an Armstrong number (after Michael F. Armstrong) or a plus perfect number) 
is a number that is the sum of its own digits each raised to the power of the number of digits. [1]
[1] : https://en.wikipedia.org/wiki/Narcissistic_number */
int is_armstrong_number(int number)
{
    int is = 0;
    int iter = 0;
    int stepN;
    int stepSize = log10(number) + 1;

    for (iter = 0; iter < stepSize; ++iter)
    {
        stepN = (number / ((int)pow(10, iter))) % 10;
        is += pow(stepN, stepSize);

        if (is>number)
            break;
    }

    if (is == number)
        return 1;
    else
        return 0;
}
