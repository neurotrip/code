#include <stdio.h>

void to_base(unsigned long n, unsigned long s);

int main(void)
{
        unsigned long number;
	unsigned long sst;
        printf ("Введите целов число(или q для выхода):\n");
        while (scanf("%lu %lu", &number, &sst) == 2)
        {
                printf ("Заданный эквивалент: ");
                to_base(number, sst);
                putchar('\n');
                printf ("Введите целое число(или q для завершения программы):\n");
        }
        printf ("Программы завершена.\n");

        return 0;
}

void to_base(unsigned long n, unsigned long s)
{
        int r;

        r = n % s;
        if (n >= s)
                to_base(n/s, s);
	if (r < 10)
        	putchar('0' + r);
	else
		putchar('A' + (r - 10));

        return;
}


