#include <stdio.h>

void *my_strncpy(char *s1, const char *s2, int n);

int main(void)
{
	char mas1[20];
	char mas2[] = "Hello world!";
	int n = 0;

	printf ("Введите количество символов, которое вы хотите скопировать\n");
	scanf ("%d", &n);
	my_strncpy(mas1, mas2, n);

	printf ("Скопированная строка: %s\n", mas1);

	return 0;
}

void *my_strncpy(char *s1, const char *s2, int n)
{
	char *result = s1;

	while(n > 0 && *s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}

	while(n > 0)
	{
		*s1 = '\0';
		s1++;
		n--;
	}

	return result;
}

