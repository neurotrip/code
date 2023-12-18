#include <stdio.h>
int main(void)
{
	int count;
	char ch;
	char prev;
	printf ("Введите или #\n");

	while ((ch = getchar()) != '#')
	{
		if (ch == 'e')
			prev = ch;
	
		if (prev == 'e' && ch == 'i')
			count++;
	}
	printf ("Найдено совпадений ei %d раз\n", count);
	
	return 0;
}




