#ifdef OS_WINDOWS
  
   

#else

 #define SWAP(valX,valY)                              \
        {                                             \
          typeof (valX) valZ;                         \
          valZ = valX;                                \
          valX = valY;                                \
          valY = valZ;                                \
        }




#endif


void swap2int(int *,int *);
int inverse_number(int);
char * base64_decoder(const char *);
char * base64_encoder(const char *);
char * url_decoder(const char *);
char * url_encoder(const char *);
char *ascii2hex(const char  *,size_t);
char *hex2ascii(const char  *,size_t);
