#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);
int is_valid_date(int year, int month, int day);
static char daytab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
int main(void) 
{

	int year = 2022;
    	int month = 2;
    	int day = 29;

	if (is_valid_date(year, month, day)) 
	{
        	int yearday = day_of_year(year, month, day);
        	printf ("День года для %d-%d-%d: %d\n", year, month, day, yearday);

        	int pmonth, pday;
        	if (month_day(year, yearday, &pmonth, &pday)) {
            		printf ("Month and day for %d-th day of %d: %d-%d\n", yearday, year, pmonth, pday);
       		} else {
            	printf ("Invalid day of year.\n");
       		 }
    		} 
	else 
	{
        	printf ("Invalid date.\n");
    	}


    	return 0;


}

int is_valid_date(int year, int month, int day)
{
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return 0;

	int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    	if (day > daytab[leap][month]) 
        	return 0;  
	return 1;

}

    
int day_of_year(int year, int month, int day)
{
	if (!is_valid_date(year, month, day))
	{
		return -1;
	}

	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (!is_valid_date(year, 1, 1) || yearday < 1 || yearday > 365) 
	{
        	return 0; 
	}

	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 1;
}

