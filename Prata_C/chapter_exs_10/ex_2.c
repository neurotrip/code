#include <stdio.h>
void coppy_arr(double ar1[], double ar2[], int n);
void coppy_ptr(double *ar1, double *ar2, int n);

int main(void)
{
	double source[5] = {1.3, 2.2, 3.4, 4.4, 5.5};
	double target1[5];
	double target2[5];
	int i;

	coppy_arr(source, target1, 5);
	coppy_ptr(source, target2, 5);
	printf ("Форма массива\n");
	for (i = 0; i < 5; i++)
		printf ("%.1f\n", target1[i]);
	printf ("Форма указателя\n");
	for (i = 0; i < 5; i++)
		printf ("%.1f\n", target2[i]);

	return 0;

}

void coppy_arr(double ar1[], double ar2[], int n)
{
	for(int i = 0; i < n; i++)
		ar2[i] = ar1[i];
}

void coppy_ptr(double *ar1, double *ar2, int n) 
{
	for(int i = 0; i < n; i++)
		*ar2++ = *ar1++;
}

