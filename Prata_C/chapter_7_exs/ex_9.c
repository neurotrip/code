#include <stdio.h>
int main(void)
{
	int x;
	int i;

	printf ("Введите число\n");
	scanf ("%d", &x);
	
	for (i = x; i <= x && i >= 0; i--)
	{
		printf ("Простое число %d\n", i);
	}

	return 0;
}

		
