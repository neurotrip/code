
#include <stdio.h>
#include <unistd.h>
#define FIRST_C 1.8
#define SECOND_C 32.0
#define THIRD_C 273.16
double temp(double far);

int main(void)
{
        double t_far;
	printf ("Введите значение в Фаренгейтах или q\n");
	while ((scanf("%lf", &t_far)) == 1){
        temp(t_far);
	printf ("Введите значение в Фаренгейтах или q\n");
        }
        return 0;
}

double temp(double far)
{
        double cel;
        double kel;
        cel = FIRST_C * far + SECOND_C;
        kel = cel + THIRD_C;

        printf ("%lf температура в Цельсиях,%lf температура в Кельвинах\n", cel, kel);
	return far;
}
