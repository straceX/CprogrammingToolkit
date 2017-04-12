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

int merge_file(const char *ofilename,const size_t filecount,const char **files,unsigned long ofsize)
{
    if(!strlen(ofilename))
    {
        fprintf(stderr, "invalid output filename\n");
        return -1;
    }
    size_t iter;
    size_t n;

    FILE *fdest;
    FILE *fsource;

    char buf[BLOCK_SIZE];
    long size, leftSize;
    char *zeroBlock;

    if ((fdest = fopen(ofilename, "wb")) == NULL)
    {
        fprintf(stderr, "cannot open file: %s\n", ofilename);
        return -1;
    }

    for (iter = 0; iter < filecount; ++iter)
    {
        if ((fsource = fopen(files[iter], "rb")) == NULL)
        {
            fprintf(stderr, "cannot open file: %s\n", files[iter]);
            exit(EXIT_FAILURE);
        }

        while ((n = fread(buf, 1, BLOCK_SIZE, fsource)) > 0)
        {
            if (!fwrite(buf, 1, n, fdest))
            {
                fprintf(stderr, "cannot write file!\n");
                return -1;
            }

            if (ferror(fsource))
            {
                fprintf(stderr, "cannot read file!\n");
                return -1;
            }

            fclose(fsource);
        }
    }

    size = ftell(fdest);
    if(ofsize)
    {
        if(size > ofsize)
        {
           fprintf(stderr, "output file size is wrong!\n");
           fclose(fdest);
           return -1;
         }
        leftSize = ofsize - size;

         if ((zeroBlock = (char *) calloc(BLOCK_SIZE, 1)) == NULL) {
            fprintf(stderr, "cannot allocate mmeory!\n");
            return -1;
        }

         while (leftSize > 0) {
             if (!fwrite(zeroBlock, 1, leftSize >= BLOCK_SIZE ? BLOCK_SIZE : leftSize, fdest)) {
                fprintf(stderr, "cannot write file!\n");
                return -1;
            }
            leftSize -= BLOCK_SIZE;
        }
    }    

    fclose(fdest);

    return 0;
}

void getAllFilesList(const char *path)
{
	struct stat fd;
	struct dirent *ent;
	DIR *dir;

	if (chdir(path) < 0) 
		return;

	if ((dir = opendir(".")) == NULL)
	{
		chdir("..");
		return;
	}

    while ((ent = readdir(dir)) != NULL) 
    {
		if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
            continue;
            
        if(ent->d_type != DT_DIR)    
		    printf("%s\n", ent->d_name);
        
        if (stat(ent->d_name, &fd) < 0)
			goto EXIT;
        
        if (S_ISDIR(fd.st_mode)) 
            getAllFiles(ent->d_name);
    }
    
EXIT:
	closedir(dir);
    chdir("..");
    return;

}


{
    FILE *file = fopen(filePath, "r");   
    int iter = 0;
    char c;
    if(file != NULL)
    {
        while((c = fgetc(file)) != EOF) {
            dest[iter++] = (char) c;
        }

        dest[iter] = '\0';

        fclose(file);
    }
    return dest;
}

