#include <stdio.h>

char *search(char s[], char c);

int main()
{
	char string[] = "Privet";
	char ch = 'v';
	char *result = search(string, ch);

	if (result != NULL) 
		printf ("Символ найден: %c\n", *result);
	else 
		printf ("Символ не найден\n");

	return 0;

}

char *search(char s[], char c)
{
	char *p = s;
	while(*p != '\0')
	{
		if (*p == c)
			return p;
		p++;
	}

	return NULL;
}


