#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef OS_WINDOWS

#include <Windows.h>

/*
	IN Visual Studio must be 
	(Conf. Properties) -> General -> Character Set -> Not Set
*/
BOOL iterateFiles(LPCTSTR path, BOOL (*funcptrOp)(LPCTSTR, const WIN32_FIND_DATA *, int));

#else

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>


void list_directory_contents(const char *);


#endif




