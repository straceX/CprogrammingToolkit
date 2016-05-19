int is_leap_year(unsigned int year)
{
	if( !year )				return 0;
	else if( !(year%400) )	return 1;
	else if( !(year%100) )	return 0;
	else if( !(year%4) 	 )	return 1;
	else 					return 0;

}