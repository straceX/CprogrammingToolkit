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


char dict[] =
{
    0,0,0,0,0,0,12,18,33,63,
    33,33,62,32,62,33,33,62,30,33,
    32,32,33,30,62,33,33,33,33,62,
    63,32,62,32,32,63,63,32,62,32,
    32,32,30,33,32,39,33,30,33,33,
    63,33,33,33,4,4,4,4,4,4,
    1,1,1,1,33,30,33,34,60,36,
    34,33,32,32,32,32,32,63,33,51,
    45,33,33,33,33,49,41,37,35,33,
    30,33,33,33,33,30,62,33,33,62,
    32,32,30,33,33,37,34,29,62,33,
    33,62,34,33,30,32,30,1,33,30,
    31,4,4,4,4,4,33,33,33,33,
    33,30,33,33,33,33,18,12,33,33,
    33,45,51,33,33,18,12,12,18,33,
    17,10,4,4,4,4,63,2,4,8,
    16,63
};

void print_banner(const char *str);