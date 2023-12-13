#include <stdio.h>
int main(void)
{
	char name[40];
	char surname[40];
	printf ("Введите ваше имя и фамилию\n");
	scanf ("%s %s", name, surname);
	printf ("Приятно познакомиться, %s %s\n", name, surname);
	return 0;
}
