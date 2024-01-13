#include <stdio.h>
#include "libex2.h"

int main(void)
{
	int mode;
	printf ("Введите 0 для выбора метрического режима или 1 для выбора режима США\n");
	scanf("%d", &mode);

	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf ("Введите 0 для выбора метрического режима или 1 для выбора режима США\n");
		printf ("Или -1 для выхода\n");
		scanf ("%d", &mode);
	}
	
	printf ("Конец\n");

	return 0;
}

