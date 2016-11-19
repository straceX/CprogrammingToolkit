#ifdef OS_WINDOWS
  
   

#endif

#ifdef LINUX

 #define SWAP(valX,valY)                              \
        {                                             \
          typeof (valX) valZ;                         \
          valZ = valX;                                \
          valX = valY;                                \
          valY = valZ;                                \
        }

#endif



/*Swap 2 integer number by xor method*/
void swap2int(int *,int *);

char *decimal_to_binary(size_t);

/*Inverse number like 1136 -> 6311*/
int inverse_number(int);

char * base64_decoder(const char *);
char * base64_encoder(const char *);
char * url_decoder(const char *);
char * url_encoder(const char *);

/*ASCII values convert HEX values*/
char *ascii2hex(const char  *,size_t);

/*HEX values convert ASCII values*/
char *hex2ascii(const char  *,size_t);

const int is_little_endian_ival = 1;
#define is_little_endian() ( ( *((char*) &is_little_endian_ival) ) == 1 )