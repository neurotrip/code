#include <stdio.h>

float cube(float n);

int main(void)
{
	float num;
	printf ("Введите число\n");
	scanf ("%f", &num);
	cube(num);
	
	return 0;
}

float cube(float n)
{
	float x;
	x = n * n * n;
	printf ("Куб числа %0.3f\n", x);
	return x;
}

