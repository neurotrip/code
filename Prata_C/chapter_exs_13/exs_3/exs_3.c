#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
	FILE *input, *output;
	char filename_1[100];
	char filename_2[100];
	char ch;
	
	printf("Введите имя исходного файла\n");
	scanf("%99s", filename_1);
	input = fopen(filename_1, "r");
	if (input == NULL)
	{
		printf("Не удаётся открыть файл\n");
		exit(EXIT_FAILURE);
	}
	printf("Введите имя файла, куда копировать\n");
	scanf("%99s", filename_2);
	output = fopen(filename_2, "r+");
	if (output == NULL)
	{
		printf ("Не удаётся открыть файл\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(input)) != EOF)
	{
		fputc(toupper(ch), output);
	}
	printf ("Копирование прошло успешно!\n");
	
	fclose(input);
	fclose(output);
	return 0;
}




