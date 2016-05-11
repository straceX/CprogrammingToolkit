void swap2int(int *val1,int *val2)
{

    *val1 = (*val1) ^ (*val2);
    *val2 = (*val1) ^ (*val2);
    *val1 = (*val1) ^ (*val2);

}