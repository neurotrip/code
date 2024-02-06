#include <stdio.h>

int ngetline(char line[], int MAXLINE);
void copy(char to[], char from[]);

/* печать самой длинной строки */
int main(void) {
	long MAXLINE = 1000;
    int len;               /* длина текущей строки */
    int max;               /* длина максимальной из просмотренных строк */
    char line[MAXLINE];    /* текущая строка */
    char longest[MAXLINE]; /* самая длинная строка */
    max = 0;

    while ((len = ngetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* была ли хоть одна строка? */
        printf("%s", longest);

    return 0;
}

/* ngetline: читает строку в s, возвращает длину */
int ngetline(char *s, int lim) {
    int c, i;
    char *s_ptr = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s_ptr++ = c;
    }

    if (c == '\n') {
        *s_ptr++ = c;
    }

    *s_ptr = '\0';
    return (int)(s_ptr - s);
}

/* copy: копирует из 'from' в 'to'; to достаточно большой */
void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

