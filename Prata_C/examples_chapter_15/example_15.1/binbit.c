#include <stdio.h>

char *itobs(int, char *);
void show_bstr(const char *);

int main(void)
{
	char bin_str[8 * sizeof(int) + 1];
	int number;

	puts("Введите целые числа и просмотрите их двоичные представления.");
	puts("Нечисловой ввод завершает программу.");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d представляется как ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Программа завершена.");

	return 0;
}

char *itobs(int n, char * ps)
{
	int i;
	static int size = 8 * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}

void show_bstr(const char * str)
{
	int i = 0;
	while (str[i]) {
		putchar(str[i]);
		if(++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

