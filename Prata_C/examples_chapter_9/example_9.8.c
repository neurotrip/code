#include <stdio.h>

void to_binary(unsigned long n);

int main(void)
{
	unsigned long number;
	printf ("Введите целов число(или q для выхода):\n");
	while (scanf("%lu", &number) == 1)
	{
		printf ("Двоичный эквивалент: ");
		to_binary(number);
		putchar('\n');
		printf ("Введите целое число(или q для завершения программы):\n");
	}
	printf ("Программы завершена.\n");

	return 0;
}

void to_binary(unsigned long n)
{
	int r;

	r = n % 2;
	if (n >= 2)
		to_binary(n/2);
	putchar('0' + r);

	return;
}

