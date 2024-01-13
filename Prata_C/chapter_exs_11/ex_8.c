#include <stdio.h>
#include <string.h>

void rev(char *s);

int main(void)
{
	char mas[] = "ABCD";
	printf ("Изначальный массив: %s\n", mas);
	rev(mas);
	printf ("Реверс: %s\n", mas);

	return 0;
}

void rev(char *s)
{
	char *start = s;
	char *end = s + strlen(s) - 1;
	char temp;
	printf ("START %c\n", *start);
	printf ("END %c\n", *end);
	printf ("Было %s\n", s);
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
//		printf ("START %s\n", start);
//		printf ("END %s\n", end);
		printf ("Шаг %s\n", s);
		++start;
		--end;
	}
	printf ("Стало %s\n", s);
}

