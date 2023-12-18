#include <stdio.h>

int main(void)
{
	int a, b;
	printf ("Введите верхний и нижний предел\n");
	scanf ("%d %d", &a, &b);

	while( a <= b){
		printf ("%d %d", a, a*a*a);
		printf ("\n");
		a++;
	}
	return 0;
}

