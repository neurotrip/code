#include <stdio.h.>
int main(void)
{
	int guess = 1;

	printf ("Выберите целое число от 0 до 100. Я попробую отгадать ");
	printf (" его. \nНажмите клавишу y, если моя догадка верна и ");
	printf ("\n клавишу n в противном случае.\n");
	printf ("Вашим числов является %d?\n", guess);
	while (getchar() = 'y')
		printf ("Итак это будет %d?\n", ++guess);
	printf ("Я знал что у меня получится!\n");

	return 0;
}
