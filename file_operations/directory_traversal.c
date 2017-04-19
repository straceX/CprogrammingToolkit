
void list_directory_contents(const char *path)
{
	const size_t SIZE= 1024;
    char tmpArray[SIZE];
    DIR *dir;
    struct dirent *dirstream;    
    int len;

    if ( !( dir = opendir(path)  ) )
        return;
    
    if ( !( dirstream = readdir(dir) ) )
        return;

    do {

        if (dirstream->d_type == DT_DIR) 
        {

            len = snprintf(tmpArray, SIZE-1, "%s/%s", path, dirstream->d_name);
            if(len > SIZE)
            	printf("Error!.");
            if(len > -1)
            	tmpArray[len] = '\0';
            
            if (strcmp(".",dirstream->d_name) == 0 || strcmp("..",dirstream->d_name) == 0)
                continue;
            
            printf("%s/%s\n", path, dirstream->d_name);
            
            list_directory_contents(tmpArray);

        }
        else
            printf("%s/%s\n",path, dirstream->d_name);

    } while (dirstream = readdir(dir));

    closedir(dir);

    return;
}




BOOL display(LPCTSTR path, const WIN32_FIND_DATA *fd, int level)
{
    if (fd->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        printf("%*s%s\n", level * 4, "", fd->cFileName);

    return TRUE;
}

BOOL iterateFilesRecursive(LPCTSTR path, BOOL (*funcptrOp)(LPCTSTR, const WIN32_FIND_DATA *, int), int level)
{    
    
    char pwd[MAX_PATH];
    char fullPath[MAX_PATH];
    WIN32_FIND_DATA fd;
    HANDLE hFindFile;

    if ( !SetCurrentDirectory(path) ) return FALSE;


    GetCurrentDirectory(MAX_PATH, pwd);

    if ((hFindFile = FindFirstFile("*.*", &fd)) == INVALID_HANDLE_VALUE) 
    {
        SetCurrentDirectory("..");
        return TRUE;
    }

    do
    {
        if (!strcmp(fd.cFileName, ".") || !strcmp(fd.cFileName, ".."))
            continue;

        sprintf(fullPath, "%s\\%s", pwd, fd.cFileName);

        if (!funcptrOp(fullPath, &fd, level))
            return FALSE;

        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if (!iterateFilesRecursive(fd.cFileName, funcptrOp, level + 1))
                return FALSE;
        }

    }while (FindNextFile(hFindFile, &fd));


    FindClose(hFindFile);
    SetCurrentDirectory("..");
    return TRUE;
}

BOOL iterateFiles(LPCTSTR path, BOOL (*funcptrOp)(LPCTSTR, const WIN32_FIND_DATA *, int))
{
    char curDir[MAX_PATH];
    BOOL result;

    GetCurrentDirectory(MAX_PATH, curDir);

    result = iterateFilesRecursive(path, funcptrOp, 0);

    SetCurrentDirectory(curDir);
    return result;
}
