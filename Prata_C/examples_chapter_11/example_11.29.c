#include <stdio.h>
#include <stdlib.h>

int main()
{
	char number[30];
	char * end;
	long value;

	puts("Введите число(или пустую строку для выхода):");
	while (gets(number) && number[0] != '\0')
	{
		value = strtol(number, &end, 10);
		printf ("значение: %ld, останов на %s (%d)\n", value, end, *end);
		value = strtol(number, &end, 16);
		printf ("значение: %ld, останов на %s (%d)\n", value, end, *end);
		puts("Следующее число:");
	}
	puts("Всего хорошего!\n");

	return 0;
}

