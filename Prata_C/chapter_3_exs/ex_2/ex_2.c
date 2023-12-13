#include <stdio.h>

int main(void)
{
	int  ch_d;
	char ch;
	printf ("Введите значение в коде ASCII:\n");
	scanf ("%d", &ch_d);
	ch = ch_d;
	printf ("Значение в символьной форме: %c\n", ch);
	return 0;
}

