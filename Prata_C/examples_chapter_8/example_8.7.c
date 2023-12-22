#include <stdio.h>
#include <stdbool.h>

int get_int(void);
bool bad_limits(int begin, int end, int low, int high);
double sum_squares(int a, int b);

int main(void)
{
	const int MIN = -1000;
	const int MAX = 1000;
	int start;
	int stop;
	double answer;
	printf ("Эта программа вычисляет сумму квадратов целых чисел в заданном диапазоне. \nНижняя граница не должна быть меньше -1000, \nа верхняя -"
		" больше 1000.\nВведите значения границ диапазона(введите 0 для обеих границ для завершения программы):\nнижняя граница:");
	start = get_int();
	printf ("верхняя граница: ");
	stop = get_int();
	while (start != 0 || stop != 0)
	{
		if (bad_limits(start, stop, MIN, MAX))
			printf ("Пожалуйтса повторите попытку\n");
		else
		{	
			answer = (sum_squares(start, stop));
			printf ("Сумма квадратов целых чисел ");
			printf ("от %d до %d равна %g\n" , start, stop, answer);
		}
		printf ("Введите значение границ диапазона (введите 0 для обеих границ для заврешния программы\n");
		printf ("нижняя граница: ");
		start = get_int();
		printf ("верхняя граница: ");
		stop = get_int();
	}
	printf ("Программа завершена.\n ");
	return 0;
	
}

int get_int(void)
{
	int input;
	char ch;
	while(scanf("%d", &input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf ("\nНе является целочисленным. \nПожалуйста введите целое число: ");
		printf ("\nнижняя граница: ");
	}
	return input;
}

double sum_squares(int a, int b)
{
	double total = 0;
	int i;
	for (i = 0;i <=b; i++)
		total += i*i;
	return total;
}

bool bad_limits(int begin, int end, int low, int high)
{
	bool not_good = false;
	if (begin >end)
	{
		printf ("%d не должно быть меньше%d.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf ("Значения  должны быть равными %d или больше.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf ("Значения должны быть равными %d или меньше.\n", high);
		not_good = true;
	}

	return not_good;
}


