#include <stdio.h>
#include "libex2.h"

int main(void)
{
	int mode;
	int rast;
	float rashod;
	printf ("Введите 0 для выбора метрического режима или 1 для выбора режима США\n");
	scanf("%d", &mode);

	while (mode >= 0)
	{
	//	set_mode(mode);
		if (mode == 0) {
			get_info(&rast, &rashod, mode);
			show_info(&rast, &rashod, mode);
		}
		else if (mode == 1) {
		       	get_info(&rast, &rashod, mode);
			show_info(&rast, &rashod, mode);
		}

		printf ("Введите 0 для выбора метрического режима или 1 для выбора режима США\n");
		printf ("Или -1 для выхода\n");
		scanf ("%d", &mode);
	}
	
	printf ("Конец\n");

	return 0;
}

