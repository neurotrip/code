#include <stdio.h>

int  nstrend(char *s, const char *t) {

    // Находим конец s

    while (*s != '\0') {
        s++;
    }
    const char *tt = t;
    while (*tt != '\0') {
	    tt++;
    }
    while (t > tt) {
        if (*--s != *--t) {
		return 0;
	}
    }

    return 1;
}

int main() {
    // Пример использования функции strcat
    char str1[50] = "Hello, ";
    const char str2[] = "world!";

    if (nstrend(str1, str2)) {
	    printf ("Строка str2 расположена в конце строки str1\n");
    } else {
	    printf ("Строка str2 не расположена в конце строки str2\n");

    }
    return 0;
}

