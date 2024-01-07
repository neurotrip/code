#include <stdio.h>
#include <ctype.h>
#define MAX 1000
int PunctCount(char *str);
int WordCount(char *str);
int HighCount(char *str);
int LowCount(char *str);

int main(void)
{
	char string[MAX];
	fgets(string, MAX, stdin);
	printf ("Знаков препинания %d\n", PunctCount(string));
	printf ("Слов %d\n", WordCount(string));
	printf ("Высоких букв %d\n", HighCount(string));
	printf ("Низких букв %d\n", LowCount(string));

	return 0;

}

int PunctCount(char *str)
{
	int count = 0;

	while(*str != '\0')
	{
		if (ispunct(*str))
			count++;
		str++;
	}

	return count;
}

int WordCount(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		if (isspace(*str))
			count++;
		str++;
	}

	return count;
}

int HighCount(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		if (isupper(*str))
			count++;
		str++;
	}
	return count;
}

int LowCount(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		if (islower(*str))
			count++;
		str++;
	}
	return count;
}

