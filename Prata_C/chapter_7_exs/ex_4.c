#include <stdio.h>

int main(void)
{
	char ch;
	int count;
	printf ("Введите\n");

	while ((ch = getchar()) != '#')
	{
		if (ch == '!') {
			putchar('!');
			putchar('!');
			count++;
	       	}
		else if (ch == '.') {
			putchar('!');
	 		count++;      
		}
		else {
			putchar(ch);
		}

	}
	printf ("Замен %d\n", count);
	return 0;
}


			
