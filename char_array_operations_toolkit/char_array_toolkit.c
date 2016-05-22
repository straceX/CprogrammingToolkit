char *upper_string(char *ptrVal, size_t size)
{
	size_t iter = 0;

	if (size == 0)
		return NULL;

	while (ptrVal[iter] != '\0' && (iter < size) )
	{
		ptrVal[iter] = toupper(ptrVal[iter++]);
	}
	return ptrVal;
}


char *lower_string(char *ptrVal, size_t size)
{
	size_t iter = 0;

	if (size == 0)
		return NULL;

	while (ptrVal[iter] != '\0' && (iter < size))
	{
		ptrVal[iter] = tolower(ptrVal[iter++]);
	}
	return ptrVal;
}


int sizeof_string(const char *ptrVal)
{
	size_t iter = 0;

	while (ptrVal[iter] != '\0')
		++iter;

	return iter;

}

int atom_number(const char *ptrSentence,const char separator_type)
{

    int length=0;
    int ival=0;

    if(*ptrSentence == separator_type)
        goto First;

    while(*ptrSentence != NULL)
    {
        if (*ptrSentence == separator_type)
        {
           ++ival;

First:
            while(*ptrSentence == separator_type || *ptrSentence == NULL)
                ++ptrSentence;

            if(*ptrSentence == NULL)
                goto Last;

        }
        ++ptrSentence;
    }


Last:

    return ival;

}


int max_word_length(const char *ptrSentence,const char separator_type)
{

    int max_word_length=0;
    int length=0;

    if(*ptrSentence == separator_type)
        goto First;

    while(*ptrSentence != NULL)
    {
        if (*ptrSentence == separator_type)
        {
            if(length>max_word_length)
                max_word_length=length;

            length=0;

First:
            while(*ptrSentence == separator_type || *ptrSentence == NULL)
                ++ptrSentence;

            if(*ptrSentence == NULL)
                goto Last;

        }
        else
            ++length;

        ++ptrSentence;

    }

    if(length>max_word_length)
        max_word_length=length;

Last:

    return max_word_length;

}


Tokenizing_Property *sentence_tokenization(const char *ptrSentence,const char separator_type)
{
    static Tokenizing_Property tp;
    int max_word_length=0;
    int length=0;
    int ival=0;

    if(*ptrSentence == separator_type)
        goto First;

    while(*ptrSentence != NULL)
    {
        if (*ptrSentence == separator_type)
        {
            if(length>max_word_length)
                max_word_length=length;

            length=0;
            ++ival;


First:
            while(*ptrSentence == separator_type || *ptrSentence == NULL)
                ++ptrSentence;

            if(*ptrSentence == NULL)
                goto Last;

        }
        else
            ++length;

        ++ptrSentence;

    }

    if(length>max_word_length)
        max_word_length=length;

Last:
    tp.atom_count = ival;
    tp.max_atom_length = max_word_length;

    return &tp;
}


char ** separation_sentence_words(const char *ptrSentence,const char separator_type)
{
    int ival=1;
    int i,j;
    char **ptr = NULL;
    int max_word_length=0;



    if( !(ptr = (char **) ( malloc( sizeof(char*) * ival ) )) )
            return NULL;
    else
    {
        for(i=0;i<ival;++i)
        {

            if (!(ptr[i]=malloc(sizeof(char)*max_word_length)))
            {
                //error_message(__FILE__,__FUNC__,__LINE__);
                return NULL;
                
            }

        }
        for(i=0;i<ival;++i)
        {
            j=0;

            while ( (*ptrSentence) != ' ' && (*ptrSentence) != '\0')
            {
                ptr[i][j++] = (*ptrSentence);
                ++ptrSentence;

            }
            ++ptrSentence;
        }

    }

    return ptr;
}
