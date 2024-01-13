#include <stdio.h>
int main(void)
{
	char ch;
	int count = 0;
	
	printf ("Введите символы или # для выхода\n");

	while ((ch = getchar()) != '#')
	{
		printf (" %c символ %d ASCII ", ch, ch);
		count++;

		if ((count % 8) == 0)
			printf ("\n");
	}
	return 0;
}

