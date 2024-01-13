#include <stdio.h>

void large_of(double *x, double *y);

int main(void)
{
	double x, y;
	printf ("Введите x и y\n");
	scanf ("%lf %lf", &x, &y);
	large_of(&x, &y);
	printf ("x = %lf и y = %lf\n", x, y);

	return 0;


}

void large_of(double *x, double *y)
{
	double temp;
	temp = *x > *y ? *x : *y;

	*x = temp;
	*y = temp;
}
