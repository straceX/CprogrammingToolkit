
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