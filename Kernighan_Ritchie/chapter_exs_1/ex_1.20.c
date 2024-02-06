#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 6 // Задаем количество пробелов для одной табуляции

int detab(char line[], int maxline);

int main() {
    	char line[MAXLINE];
    	int len;

    	while ((len = detab(line, MAXLINE)) > 0) {
        	printf ("%s", line);
    	}

    	return 0;
}

int detab(char line[], int maxline)
{
    	int c, i, j;

    	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        	if (c == '\t') { // Если встречаем табуляцию
            		for (j = 0; j < TABSTOP; ++j) {
                		line[i + j] = ' '; // Заменяем табуляцию нужным числом пробелов
            		}
            		i += TABSTOP - 1;
        	} else {
           		 line[i] = c;
        	}
    	}

    	if (c == '\n') {
        	line[i] = c;
        	++i;
    	}

    	line[i] = '\0';

    return i;
}

