#include <stdio.h>
#define MAX 1000
void get1(char *mas);

int main(void)
{	
	char Mas[MAX];
	printf ("Введите массив:\n");
	get1(Mas);
	printf ("Ваш массив:\n");
	puts(Mas);

	return 0;
}

void get1(char *mas)
{
	char n;
	while((n = getchar()) != EOF) {
		*mas++ = n;
		
	}
	*mas = '\0';
}

