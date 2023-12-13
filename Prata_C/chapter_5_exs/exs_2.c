#include <stdio.h>

int main(void)
{
	int num;
	int count;
	printf ("Введите число\n");
	scanf ("%d", &num);
	count = num + 10;
	while (num <= count)
	{
		printf ("Значение %d\n", num);
		++num;
	}

	return 0;
}

