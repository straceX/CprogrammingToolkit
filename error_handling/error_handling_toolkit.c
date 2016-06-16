void info_message(const char *file_name, const char *function_name,const int line_number)
{
    printf("Information:\tFile Name             	:[ %s ]\n",file_name);
    printf("Information:\tFunction Name         	:[ %s ]\n",function_name);
    printf("Information:\tLine Number of Function 	:[ %d ]\n",line_number);
}

void debug_message(const char *file_name, const char *function_name,const int line_number)
{
    printf("Debug Information:\tFile Name             	:[ %s ]\n",file_name);
    printf("Debug Information:\tFunction Name         	:[ %s ]\n",function_name);
    printf("Debug Information:\tLine Number of Function :[ %d ]\n",line_number);
}

void error_message(const char *file_name, const char *function_name,const int line_number)
{
    fprintf(stderr,"Error Information:\tFile Name             	:[ %s ]\n",file_name);
    fprintf(stderr,"Error Information:\tFunction Name         	:[ %s ]\n",function_name);
    fprintf(stderr,"Error Information:\tLine Number of Function :[ %d ]\n",line_number);
}
