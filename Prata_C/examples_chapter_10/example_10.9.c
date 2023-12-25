#include <stdio.h>
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;

	for (index = 0; index < MONTHS; index++)
		printf ("Месяц %2d имеет %d дней (ltym).\n", index + 1, *(days + index));

	return 0;
}

