#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
	int i;
	int total = 0;
	for (i = 0; i <= LIMIT; i++) {
		total += 2*i*i + 1;
#ifdef JUST_CHECKING
		printf("i=%d, текущаю сумма = %d\n", i, total);
#endif
	}
	printf("Итоговая сумма = %d\n", total);

	return 0;
}

