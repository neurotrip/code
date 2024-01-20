#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file;
	char filename[100];
	double value;

	printf("Введите имя файла для чтения\n");
	scanf("%99s", filename);

	file = fopen(filename, "rb");
	if (file == NULL) {
		perror("Ошибка при открытии файла");
		exit(EXIT_FAILURE);
	}

	printf("Данные '%s'\n", filename);
	while (fread(&value, sizeof (double), 1, file) == 1) {
		printf("%lf\n", value);
	}

	fclose(file);

	return 0;
}

