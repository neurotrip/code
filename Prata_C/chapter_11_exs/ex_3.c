#include <stdio.h>


void fun(char *s);

int main()
{
	char string[100];
	gets(string);
	fun(string);
	puts(string);

	return 0;
}

void fun (char *s)
{
	while (*s != '\0')
	{
		if (*s == '\t' || *s == '\n')
			*s = '\0';
		s++;
	}
}

