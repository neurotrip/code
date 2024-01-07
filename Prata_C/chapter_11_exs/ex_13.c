#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf ("Использование: %s <число> <степень>\n", argv[0]);
		return 1;
	}
	

	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);

	double result = pow(base, exponent);

	printf ("%.2f в степени %d равно %.2f\n", base, exponent, result);

	return 0;
}

