#include <stdio.h>

void bar(char ch, int i, int j);

int main(void)
{
	char c;
	int s;
	int str;
	printf ("Введите символ\n");
	scanf ("%c", &c);
	printf ("Введите кол-во в строке и кол-во столбцов\n");
	scanf ("%d %d", &s, &str);
	bar(c, s, str);

	return 0;
}

void bar(char ch, int i, int j)
{
	int k, l;

	for(l = 0; l < j; l++) {
		for(k = 0; k <= i; k++) 
			putchar(ch);
		printf ("\n");
	}
}


