#include <math.h>

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