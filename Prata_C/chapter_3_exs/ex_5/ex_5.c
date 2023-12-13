#include <stdio.h>

int main(void)
{
	int year;
	long double sec;
	printf ("Введите количество лет\n");
	scanf ("%d", &year);
	sec = year * (3.156 *(10*10*10*10*10*10*10));
	printf ("Значение в секундах %Lf\n", sec);
	return 0;
}

