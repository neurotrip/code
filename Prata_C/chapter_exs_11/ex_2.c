#include <stdio.h>
#include <ctype.h>
#define MAX 1000
#define SPACE ' '
void get1(char *mas, int max);

int main(void)
{
        char Mas[MAX];
        printf ("Введите массив:\n");
        get1(Mas, MAX);
        printf ("Ваш массив:\n");
        puts(Mas);

        return 0;
}

void get1(char *mas, int max)
{
        char n;
	int i;
	for(i = 0; i < max; i++) {
		n = getchar();
	if (n == '\t')
		n = 13;
	if (n == '\n') 
		i = 1001;
	else
		*mas++ = n;
	}

		
	
        *mas = '\0';
}

