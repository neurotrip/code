#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    long count = 0;
    FILE *fp;
	char filename[100];
	printf("Введите имя файла\n");
	scanf("%99s", filename);
	fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf ("Не удаётся открыть %s\n", filename);
        exit(1);
    }

    while ((ch = getc(fp)) != EOF)
    {
		if (ch == '\n')
		{
			count--;
		}

        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("Файл %s содержит %ld символов\n", filename, count);

    return 0;
}

