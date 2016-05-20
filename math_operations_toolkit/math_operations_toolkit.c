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
