#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int dice, roll;
	int sides;
	srand((unsigned int) time(0));
	printf ("Введите количество грайне кости или 0 для завершения программы\n");

	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf ("Сколько нужно костей?\n");
		scanf ("%d", &dice);
		roll = roll_n_dice(dice, sides);
		printf ("Вы бросали %d раз, используя %d %d-гранные кости.\n",
				roll, dice, sides);
		printf ("Сколько должно быть граней? Введите 0 для завершения программы\n");
	}

	printf ("Функция rollem() была вызвана %d раз.\n", roll_count);

	printf ("Удачи\n");

	return 0;
}

