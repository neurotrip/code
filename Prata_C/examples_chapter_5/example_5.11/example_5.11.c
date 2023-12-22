#include <stdio.h>
int main(void)
{
	int a = 1, b = 1;
	int aplus, bplus;

	aplus = a++;
	bplus = ++b;
	printf ("a	aplus	b	bplus\n");
	printf ("%1d %8d %5d %8d\n", a, aplus, b, bplus);
	aplus = aplus + 0;
	printf ("%1d %8d %5d %8d\n", a, aplus, b , bplus);
	return 0;
}

