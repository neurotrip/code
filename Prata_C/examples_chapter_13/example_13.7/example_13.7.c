#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main()
{
	double numbers[ARSIZE];
	double value;
	const char *file = "numbers.dat";
	int i;
	long pos;
	FILE *iofile;

	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0/ (i + 1);

	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Не удаётся открыть %s для вывода.\n", file);
		exit(1);
	}

	fwrite(numbers, sizeof (double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Не удаётся открыть %s для произвольного доступа.\n", file);
		exit(1);
	}
	printf("Введите индекс из диапазона от 0 до %d.\n", ARSIZE - 1);
	scanf("%d", &i);

	while (i >= 0 && i < ARSIZE)
	{
		pos = (long) i * sizeof(double);
		fseek (iofile, pos, SEEK_SET);
		fread(&value, sizeof (double), 1, iofile);
		printf("В этом случае значение равно %f.\n", value);
		printf("Введите следующий индекс (или значение за пределами диапазона для завершения):\n");
		scanf("%d", &i);
	}

	fclose(iofile);
	puts("Конец");

	return 0;
}




