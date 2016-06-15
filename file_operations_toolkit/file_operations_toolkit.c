stream_info *learn_buffer_inf(FILE *fp)
{
	stream_info *si = NULL;

	if( !(si = (stream_info *) malloc(sizeof(stream_info)) ) )
		return NULL;
	else
	{

		if (fp->_flags & _IONBF)
			si->buff_type = "Unbuffered";
		else if (fp->_flags & _IOLBF)
			si->buff_type = "Line buffered";
		else 
			si->buff_type = "Fully buffered";

		si->buff_size = __fbufsize(fp);
		return si;
	}
    
}
