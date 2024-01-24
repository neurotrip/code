#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20
#define LN 3

struct month {
    char name[LEN];
    char abr[LN];
    int amount;
    int numb;
};

int isLeapYear(int year); 

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

//  {

//      printf("Месяц %s, абревеатура %s, количество дней %d, порядковы номер %d\n",
//              months[i].name, months[i].abr, months[i].amount, months[i].numb);
//  }
    
	
	 
    char month_name[LEN];
	int day = 0;
	int year = 0;
	printf("Введите название месяца\n");
    gets(month_name);
	printf("Введите день\n");
	scanf("%d", &day);
	
	printf("Введите год\n");
	scanf("%d", &year);	
	if (isLeapYear(year)) 
		months[1].amount = 29;


    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month_name, months[i].name) == 0)
        {
			if (day > months[i].amount) {
				printf("Неверные данные, выход\n");
				exit(EXIT_FAILURE);
			}
            int summa = 0;
			int raznost = 0;
			int days = 0;
            for (int j = 0; j < months[i].numb; j++) {
                summa += months[j].amount;
            }
			raznost = months[i].amount - day;
			days = summa - raznost;
            printf("Дней прошло %d\n", days);
        }
    }


    return 0;
}


int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Год високосный
    } else {
        return 0; // Год не високосный
    }
}
