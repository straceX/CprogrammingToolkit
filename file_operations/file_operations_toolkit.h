#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <dirent.h>
#include <unistd.h>

#ifdef OS_WINDOWS
  
   


#else

#include <stdio_ext.h>
#include <sys/stat.h>
typedef struct stream_Info
{
	char *buff_type;
	size_t  buff_size;
} stream_info;

stream_info *learn_buffer_inf(FILE *);

void getAllFilesList(const char *path);

#endif










#define BLOCK_SIZE      8192
/*Merge files and write the rest to zero at the desired size*/
int merge_file(const char *ofilename,const size_t filecount,const char **files,unsigned long ofsize);
char *extractFileContents(const char *filePath, char *dest);







