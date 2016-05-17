char *xor_cipher(char message[], char key[])
{
    size_t mlen = strlen(message);
    size_t klen = strlen(key);
    size_t iter;
    char * encrypted_message = NULL;

    if(mlen < 1 || klen <1)
    {
        printf("Error: mlen or klen error!..\n");
        return NULL;
    }

    if(!(encrypted_message = (char *) malloc(mlen+1)))
    {
        printf("Error: Malloc function can not allocate!..\n");
        return NULL;
    }

    for(iter = 0; iter < mlen; ++iter)
        encrypted_message[iter] = ( message[iter] ^ key[iter % klen] );

    encrypted_message[iter] = '\0';

    return encrypted_message;
}