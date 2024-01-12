#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINES 1000
#define MAX 1000

int main(int argc, char *argv[])
{
	char *string[MAXLINES];
	int n = 10;
	int count = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0) {
	                n = atoi(argv[2]);
	}

	while (count < MAXLINES && fgets(string[count] = (char *)malloc(MAX), MAX, stdin) != NULL)
   	{
        	
        	count++;
    	}


	printf ("Вывод\n");
	if (count < n)
	{
		printf ("Введено меньше N строк\n");
		for (int i = 0; i < count ; i++)
		{
			fputs(string[i], stdout);
			free(string[i]);
			
		}
	}
	else
	{
		printf ("Последние N строк\n");
		for (int i = count - n; i < count; i++)
		{
			fputs(string[i], stdout);
			free(string[i]);
		}
	}



	return 0;
}


