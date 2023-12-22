#include <stdio.h>
long fact(int n);
long rfact(int n);
int main(void)
{
	int num;

	printf ("Эта программа вычисляет факториалы.\n");
	printf ("Введите значение в диапазоне 0-12 (или q для завершения программы):\n");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)
			printf ("Пожалуйста, не вводите отрицательные числа.\n");
		else if (num > 12)
			printf ("Входное значение должно быть меньше 13.\n");
		else
		{
			printf ("цикл: факториал %d = %ld\n",num, fact(num));
			printf ("рекурсия : факториал %d = %ld\n", num, rfact(num));
		}

		printf ("Введите значение в диапазоне 0-12 (или q для завершения программы):\n");
	}
	printf ("Всего хорошего.\n");
	return 0;
}

long fact(int n)
{
	long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}

long rfact(int n)
{
	long ans;
	if (n > 0)
		ans = n*rfact(n-1);
	else
		ans = 1;
	return ans;
}


