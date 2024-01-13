#include <stdio.h>

void charbar(char v, int i, int j);

int main(void)
{
	char ch;
	printf ("Введите нужный символ:\n");
	scanf ("%c", &ch);
	int i, j;
	printf ("Введите начало и конец:\n");
	scanf ("%d %d", &i, &j);
	charbar(ch, i, j);
	printf ("\n");
	return 0;
}

void charbar(char v, int i, int j)
{
	int k;
	for(k = i; k <= j; k++)
	       putchar(v);
}

