#include <stdio.h>
#include <ctype.h>

int atoi(char *s);

int main(void)
{

	char string[] = "-123";

	printf ("Строка\n");
	puts(string);
	printf ("Целочисленное значение\n");
	int result = atoi(string);
	printf ("%d\n", result);

	return 0;
}

int atoi(char *s)
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;

}


