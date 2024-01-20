#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4000
int main(void)
{
    FILE *fp;
    char words[MAX];
	int i, j = 0;
	int count = 1;
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Не удаётся открыть файл \"words\".\n");
        exit(1);
    }

    puts("Введите слова, которые нужно включить в файл; нажмите клавишу Enter");
    puts("в начале строки для завершения программы.");
	while(gets(words) != NULL) {
		if (words[i] == SPACE) {
			words[i] = count + '0';
		}
		count++;
	}

	
        fprintf(fp, "%s",words);
		

    puts("Cодержимое файла:");
    rewind(fp);

    while (fscanf(fp, "%s", words) == 1)
        puts(words);

    if (fclose(fp) != 0)
        fprintf(stderr, "Ошибка при закрытии файла\n");

    return 0;
}

