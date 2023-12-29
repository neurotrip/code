#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5
int main(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	printf ("Введите %d слов, начинающихся с буквы q:\n", LIM);
	while (i < LIM && gets(temp))
	{
		if (temp[0] != 'q')
			printf ("%s не начинается с буквы q!\n", temp);
		else
		{
			strcpy(qwords[i], temp);
			i++;
		}
	}

	puts("Перечень слов, удовлетворяющих заданному критерию:");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);
	return 0;
}

