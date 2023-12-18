#include <stdio.h>
#include <unistd.h>
#define FIRST_C 1.8
#define SECOND_C 32.0
#define THIRD_C 273.16
int temp(double far);

int main(void)
{
	double t_far;
	char ch = 0;
       	while (ch != 'n'){	
	printf ("Введите значение в Фаренгейтах\n");
	scanf ("%lf", &t_far);
	temp(t_far);
	printf ("Хотите продолжить?\n");
	scanf ("%c", &ch);
	}
	return 0;
}

int temp(double far)
{
	double cel;
	double kel;
	cel = FIRST_C * far + SECOND_C;
	kel = cel + THIRD_C;
	
	return  printf ("%lf температура в Цельсиях,%lf температура в Кельвинах\n", cel, kel); 
	
}

