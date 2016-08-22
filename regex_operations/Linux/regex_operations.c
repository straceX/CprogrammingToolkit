
int find_regex_pattern(const char *pattern, FILE *ptrfile)
{
    regex_t rex;
    size_t n;
    int beg = 0;
    int result;
    regmatch_t matches[1];
    char buf[BUF_SIZE + 1];


    n = fread(buf, 1, BUF_SIZE, ptrfile);

	if (n == 0 && ferror(ptrfile)) 
	{
		fprintf(stderr, "cannot read file!..\n");
		exit(EXIT_FAILURE);	
	}

	buf[n] = '\0';
		
	if ( (result = regcomp(&rex, pattern, REG_EXTENDED)) != 0) 
	{
		fprintf(stderr, "%s\n", strerror(result));
		exit(EXIT_FAILURE);
	}
	
	while ( regexec(&rex, buf + beg, 1, matches, REG_NOTEOL) != REG_NOMATCH ) 
	{ 
		printf("%.*s\n", matches[0].rm_eo - matches[0].rm_so, &buf[beg + matches[0].rm_so]);
		beg += matches[0].rm_eo + 1;
	}
	
	regfree(&rex);

	return beg;
}