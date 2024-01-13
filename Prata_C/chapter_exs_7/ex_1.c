#include <stdio.h>
#define SPACE ' '

int main(void)
{
	int n_space = 0;
	int n_string = 0;
	int n_char = 0;
	char ch;
	
	printf ("Введите символы или # для выхода\n");

	while ((ch = getchar()) != '#')
	{
		n_char++;
		
		if (ch == SPACE)
		{
			n_space++;
			n_char--;
		}

		if (ch == '\n') 
		{
			n_string++;
			n_char--;
		}

	}

	printf ("%d символов %d пробелов %d новых строк\n", n_char, n_space, n_string);
	return 0;
}



		
