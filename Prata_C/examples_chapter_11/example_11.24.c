#include <stdio.h>
#define MAX 20
int main(void)
{
	char first[MAX];
	char last[MAX];
	char formal[2 * MAX + 10];
	int prize;

	puts("Введите своё имя:");
	gets(first);

	puts("Введите свою фамилию:");
	gets(last);

	puts("Введите сумму денежного приза:");
	scanf("%d", &prize);

	sprintf(formal, "%s, %-19s: $%6d\n", last, first, prize);
	puts(formal);

	return 0;
}

