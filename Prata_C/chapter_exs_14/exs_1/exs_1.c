#include <stdio.h>
#include <string.h>

#define LEN 20
#define LN 3

struct month {
	char name[LEN];
	char abr[LN];
   	int amount;
	int numb;
};


int main(void)
{
	 struct month months[12] = {
        {"January",   "Jan", 31, 1},
        {"February",  "Feb", 28, 2},
        {"March",     "Mar", 31, 3},
        {"April",     "Apr", 30, 4},
        {"May",       "May", 31, 5},
        {"June",      "Jun", 30, 6},
        {"July",      "Jul", 31, 7},
        {"August",    "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October",   "Oct", 31, 10},
        {"November",  "Nov", 30, 11},
        {"December",  "Dec", 31, 12}
    };

//	{

//		printf("Месяц %s, абревеатура %s, количество дней %d, порядковы номер %d\n",
//				months[i].name, months[i].abr, months[i].amount, months[i].numb);
//	}
	printf("Введите название месяца\n");
	
	char month_name[LEN];
	gets(month_name);

	for (int i = 0; i < 12; i++)
	{
		if (strcmp(month_name, months[i].name) == 0)
		{
			int summa = 0;
			for (int j = 0; j < months[i].numb; j++) {
				summa += months[j].amount;
			}
			printf("%d\n", summa);
		}
	}


	return 0;
}

//int sum(struct month mesyac[], int n)
//{
//	int summa = 0;
//	for (int i = 0; i < n; i++) {
//		summa += mesyac[i].amount;
//	}

//	return summa;
//}

