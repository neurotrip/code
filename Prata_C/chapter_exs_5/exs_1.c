#include <stdio.h>
#define MIN_PER_CHOURS 60
int main(void)
{
	int min;
	int chours;
	int num_after;
	char ch;

	do
	{
		printf ("Введите минуты\n");
		scanf ("%d", &min);
		chours = min / MIN_PER_CHOURS;
		num_after = min % MIN_PER_CHOURS;
		printf ("%d часов %d минут\n", chours, num_after);
	} while ((ch=getchar()) !=EOF);
	return 0;
}

