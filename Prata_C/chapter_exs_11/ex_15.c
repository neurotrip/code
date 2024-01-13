#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000
void printOriginal(char *s);
void printUpper(char *s);
void printLower(char *s);

int main(int argc, char *argv[])
{
	char input[MAX];
	while (fgets(input, MAX, stdin) != NULL)
	{
		if (argc > 1)
		{
			for (int i = 1; i < argc; i++) {
				if (strcmp(argv[i], "-p") == 0)
					printOriginal(input);
				else if (strcmp(argv[i], "-u") == 0) {
					printUpper(input);
					printf ("Данные в верхнем регистре\n");
					fputs(input, stdout);
				}
				else if (strcmp(argv[i], "-l") == 0) {
					printLower(input);
					printf ("Данные в нижнем регистре\n");
					fputs(input, stdout);
				}
			}
		}
	}

	return 0;

}

void printOriginal(char *s)
{
	printf ("Оригинальные данные\n");
	fputs(s, stdout);

}

void printUpper(char *s)
{
	while (*s != '\0')
	{
		*s = toupper(*s);
		s++;
	}
	printf ("Данные в верхнем регистре\n");
//	printf ("%c\n", *s++);
//	fputs(s, stdout);
//	fputs("\n", stdout);

}

void printLower(char *s)
{
	while (*s != '\0')
	{
		*s = tolower(*s);
		s++;
	}
}

