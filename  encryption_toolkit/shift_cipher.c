char *shift_cipher(char * ptr,size_t size,size_t shift)
{
    size_t i;

    if((*ptr) == NULL)
        return NULL;

    if(shift == 0)
        return ptr;

    for(i = 0; i<size; ++i)
    {
        ptr[i] = ptr[i] + shift;
    }

    return ptr;
}

char *shift_uncipher(char * ptr,size_t size,size_t shift)
{
    size_t i;

    if((*ptr) == NULL)
        return NULL;

    if(shift == 0)
        return ptr;

    for(i =0;i< size;++i)
    {
        ptr[i] = ptr[i] - shift;
    }

    return ptr;
}