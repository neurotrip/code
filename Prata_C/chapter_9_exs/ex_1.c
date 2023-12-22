#include <stdio.h>

double min(double x,double y);

int main(void)
{
	double x;
	double y;
	printf ("Введите первое число\n");
	scanf ("%lf", &x);
	printf ("Введите второе число\n");
	scanf ("%lf", &y);
	printf ("Меньшее: %.2lf\n", min(x,y));

	return 0;
}

double min (double x, double y)
{
	double min;
//	if (x > y)
//		min = y;
//	else 
//		min = x;
	min = x > y ? y : x;
	return min;
}



