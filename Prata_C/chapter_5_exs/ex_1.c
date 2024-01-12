#include <stdio.h>

void critic(int *u);
int main(void)
{
	int units = 0;
	printf ("Сколько фунтов весит маленький бочонок мёда?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(&units);
	printf ("Вы должны это проверить!\n");
	return 0;
}

void critic(int *u)
{
	printf ("Вам не повезло. Попытайтесь еще раз.\n");
	scanf ("%d", u);
}


