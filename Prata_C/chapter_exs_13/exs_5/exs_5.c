#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
    FILE *fa, *fs;
    int files = 0;
	int i = 2;
    if ((fa = fopen(argv[1], "a")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Не удаётся создать буфер вывода\n", stderr);
        exit(3);
    }
    while (i < argc)
    {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Нельзя добавлять файл в конец самого себя\n", stderr);
        else if ((fs =fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Не удаётся открыть файл %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Не удается создать буфер воода\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Ошибка во время чтения файла %s.\n", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr,"Ошибка во время записи в файл %s.\n", argv[1]);
            fclose(fs);
            files++;
            printf("Файл %s добавлен.\n", argv[i]);
        }
		i++;
    }
    printf ("Готово. Добавлено %d файлов.\n", files);
    fclose(fa);
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
            fwrite(temp, sizeof (char), bytes , dest);

}

