#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefound;
};

double sum(double, double);

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237.11
	};

	printf("Сумма на счету у Стэна составляет $%.2f.\n",
			sum(stan.bankfund, stan.savefound));
	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}

