#include <stdio.h>

int main(void)
{
	char ch;

	printf ("Введите какой-нибудь символ.\n");
	scanf ("%c", &ch);
	printf ("Код символа %c равен %d\n", ch, ch);
       return 0;
}

