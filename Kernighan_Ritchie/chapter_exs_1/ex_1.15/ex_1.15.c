#include <stdio.h>

int temp(int);


int main()
{
	int fahr;
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf ("%d\t %d\n", fahr, temp(fahr));
}

int temp(int cels)
{
	cels = (5.0/9.0)*(cels-32);
	return cels;
}

