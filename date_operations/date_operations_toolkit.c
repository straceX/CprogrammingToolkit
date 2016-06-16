int is_leap_year(unsigned int year)
{
	if( !year )			return 0;
	else if( !(year%400) )		return 1;
	else if( !(year%100) )		return 0;
	else if( !(year%4) 	 )	return 1;
	else 				return 0;

}

/*current_date length min 20 elements*/
char *get_system_current_date(char current_date[],size_t size)
{
	time_t t = time(NULL);
	struct tm *lc_time = localtime(&t);	

	/*	Second way without strftime
		lc_time->tm_year + 1900, 
		lc_time->tm_mon + 1, 
		lc_time->tm_mday, 
		lc_time->tm_hour, 
		lc_time->tm_min, 
		lc_time->tm_sec
	*/
	
	strftime(current_date, size, "%x - %I:%M%p", lc_time);

	return current_date;
}
