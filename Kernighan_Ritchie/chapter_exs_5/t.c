#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define DEFAULT_TABSTOP 4

int detab(char *line, int maxline, int *tabstops, int num_stops);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len;
    int tabstops[MAXLINE]; // Массив для стопов табуляции

    // Инициализация стопов табуляции значениями по умолчанию
    for(int i = 0; i < MAXLINE; i++) {
        tabstops[i] = DEFAULT_TABSTOP;
    }

    // Переопределение начальных стопов табуляции аргументами командной строки
    for(int i = 1; i < argc; i++) {
        tabstops[i-1] = atoi(argv[i]);
    }

    while ((len = detab(line, MAXLINE, tabstops, argc - 1)) > 0) {
        printf("%s", line);
    }

    return 0;
}

int detab(char *line, int maxline, int *tabstops, int num_stops) {
    int c, i, j;
    char *ptr = line;
    int tabstop_index = 0;
    int column = 0; // Текущая колонка в строке

    for (i = 0; (c = getchar()) != EOF && c != '\n';) {
        if (c == '\t') {
            int spaces;

            // Определяем количество пробелов до следующего стопа
            if(tabstop_index < num_stops) {
                spaces = tabstops[tabstop_index] - (column % tabstops[tabstop_index]);
            } else {
                spaces = DEFAULT_TABSTOP - (column % DEFAULT_TABSTOP);
            }

            if(i + spaces < maxline - 1) {
                for (j = 0; j < spaces; ++j) {
                    ptr[i++] = ' ';
                }
                column += spaces; // Обновляем колонку после добавления пробелов
            }

            tabstop_index++; // Переход к следующему стопу
        } else {
            ptr[i++] = c;
            column++; // Обновляем колонку после добавления символа
        }
    }

    if (c == '\n' && i < maxline - 1) {
        ptr[i++] = c;
    }

    ptr[i] = '\0';

    return i;
}

