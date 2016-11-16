/*ptrS = array size upper than [sizeof(int) * 8 + 1]*/
char *int_to_binary(const int ival,char *ptrS);
int set_bit(int ival, size_t n);
int reset_bit(int ival, size_t n);