#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char *argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;
	char filename_1[100];
	char filename_2[100];

	printf("Введите имя первого файла\n");
	scanf("%99s", filename_1);
	in = fopen(filename_1, "r");
	if (in == NULL) {
		fprintf(stderr, "Не удаётся открыть файл \"%s\"\n", filename_1);
		exit (EXIT_FAILURE);
	}
	printf ("Введите имя второго файла\n");
	scanf("%99s", filename_2);
	out = fopen(filename_2, "r");
	if (out == NULL) {
		fprintf(stderr, "Не удаётся открыть файл \"%s\"\n",filename_2);
		exit(EXIT_FAILURE);
	}
    strncpy(name, filename_2, LEN - 5);
    name[LEN -5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Не могу построить выходной файл\n");
        exit(3);
    }


    while ((ch = getc(in)) != EOF) {
        if (count++ % 3 ==0)
            putc(ch, out);
    }

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Ошибка при закрытии файла\n");

    return 0;
}

