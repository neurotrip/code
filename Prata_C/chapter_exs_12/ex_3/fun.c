#include <stdio.h>


void get_info(int *rast, float *rashod, int MODE)
{
	if (MODE == 0) {
		printf ("Введите пройденное расстояние в км\n");
		scanf("%d", rast);
		printf ("Введите расход в литрах\n");
		scanf("%f", rashod);
	}
	else if (MODE == 1) {
		printf ("Введите пройденное расстояние в милях\n");
		scanf("%d", rast);
		printf ("Введите расход в галлонах\n");
		scanf("%f", rashod);
	}
	
}

void show_info(int *rast, float *rashod, int MODE)
{
	
	if (MODE == 0) {
		printf ("Расход горючеего составляет %0.2f на 100 км\n", (*rashod/ *rast) * 100);
	}
	else if (MODE == 1) {
		printf ("Расход горючего составляет %0.2f на 1 галлон\n", (*rashod/ *rast) * 62);
	}
}


