#ifdef OS_WINDOWS
  
   

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct stream_Info
{
	char *buff_type;
	size_t  buff_size;
} stream_info;

stream_info *learn_buffer_inf(FILE *);



#endif






