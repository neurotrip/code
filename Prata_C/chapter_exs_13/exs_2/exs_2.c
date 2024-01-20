#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *input, *output;
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "r+");
	char ch;
	long count = 0;
	if (input == NULL)
	{
		printf("Не удаётся открыть файл\n");
		exit(EXIT_FAILURE);
	}
	
	while ((ch = fgetc(input)) != EOF)
	{
		fputc(ch, output);
		count++;
	}
	fclose(input);
	fclose(output);
	printf("Копирование прошло успешно, скопировано %ld символов\n", count);

	return 0;
}

