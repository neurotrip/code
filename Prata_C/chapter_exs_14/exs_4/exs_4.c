#include <stdio.h>
#define LEN 40

struct human_data {
	char name[LEN];
	char surname[LEN];
	char fathername[LEN];
};

struct data {
	long card;
	struct human_data human;
};

void printstruct(const struct data pers[]);

int main(void)
{
	struct data unit[3] = {
						{148814881488, {"Boris", "Brejcha", "Technovich"}},
						{1991, {"Yeltsin", "Boris", "GospodiHraniAmericyvich"}},
						{1999, {"Putin", "Vladimir", "VsimPizdetsovich"}}
						};

	printf ("Данные человека\n");
	printstruct(unit);
//	for (int i = 0; i < 3; i++) {
//		printf ("%s, %s %c. -- %ld\n", unit[i].human.name, unit[i].human.surname, unit[i].human.fathername[0], unit[i].card);
//	}


	return 0;
}

void printstruct(const struct data pers[])
{
	for (int i = 0; i < 3; i++) {
    	printf ("%s, %s %c. -- %ld\n", pers[i].human.name, pers[i].human.surname, pers[i].human.fathername[0], pers[i].card);
    }
}
