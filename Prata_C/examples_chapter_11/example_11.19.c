#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 100
#define STOP "quit"

int main(void)
{
	char input[LIM][SIZE];
	int ct = 0;
	printf ("Введите не более %d строк (или quit для завершения):\n", LIM);
	while (ct < LIM && gets(input[ct]) != NULL && strcmp(input[ct], STOP) != 0)
	{
		ct++;
	}
	printf ("Введено %d строк\n", ct);
	return 0;
}

