#include <stdio.h>
int main(void)
{
	char name[40];
	float height;
	printf ("Введите ваше имя и рост\n");
	scanf ("%s %f", name, &height);
	printf ("%s , ваш рост составляет %0.2f футов\n", name, height);
	return 0;
}

