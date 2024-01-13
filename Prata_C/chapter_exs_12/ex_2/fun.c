#include <stdio.h>
int MODE;
int rast;
float rashod;

void set_mode(int n)
{
	if (n == 1)
		MODE = 1;
	else if ( n == 0)
		MODE = 0;
	else
		printf ("Вводи нормально, уебище, считаю по-человечески\n");
		MODE = 0;
}

void get_info()
{
	if (MODE == 0) {
		printf ("Введите пройденное расстояние в км\n");
		scanf("%d", &rast);
		printf ("Введите расход в литрах\n");
		scanf("%f", &rashod);
	}
	else if (MODE == 1) {
		printf ("Введите пройденное расстояние в милях\n");
		scanf("%d", &rast);
		printf ("Введите расход в галлонах\n");
		scanf("%f", &rashod);
	}
	
}

void show_info()
{
	float rash;
	rash;
	if (MODE == 0) {
		rash = (rashod/rast) * 100;
		printf ("Расход горючеего составляет %0.2f на 100 км\n", rash);
	}
	else if (MODE == 1) {
		rash = (rashod/rast) * 62;
		printf ("Расход горючего составляет %0.2f на 1 галлон\n", rash);
	}
}


