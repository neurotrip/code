#include <stdio.h>
#define LEN 40
#define CSIZE 4

struct name {
	char name[LEN];
	char surname[LEN];
};

struct student {
	struct name student_name;
	double grade[3];
	double middle_grade;
};

void student_data(struct student unit[]);

int main(void) 
{
	struct student unit[CSIZE];
	student_data(unit);

	return 0;
}

void student_data(struct student unit[])
{
	for (int i = 0; i < CSIZE; i++) {
		printf("Введите имя студента\n");
		fgets(unit[i].student_name.name, LEN, stdin);
		printf("Введите фамилию студента\n");
		fgets(unit[i].student_name.surname, LEN, stdin);
		
	}
	for (int i = 0; i < CSIZE; i++) {
		printf ("Введите три оценки для %s\n", unit[i].student_name.surname);
		for (int j = 0; j < 3; j++) {
			int n = 1;
			printf ("%d оценка\n", n);
			scanf("%lf", &unit[i].grade[j]);
			n++;
		}
		unit[i].middle_grade = (unit[i].grade[0] + unit[i].grade[1] + unit[i].grade[2]) / 3;
	}

	for (int i = 0; i < CSIZE; i++) {
		printf("Данные студента %s\n", unit[i].student_name.surname);
		printf("Имя %s\nФамилия%s\nОценки %.2lf  %.2lf  %.2lf\n",
				unit[i].student_name.name, unit[i].student_name.surname, unit[i].grade[0], unit[i].grade[1], unit[i].grade[2]);
		printf("Среднее значение оценок равно %.2lf\n", unit[i].middle_grade);
	}
}


