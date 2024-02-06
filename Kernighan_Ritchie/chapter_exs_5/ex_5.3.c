#include <stdio.h>

void nstrcat(char *s, const char *t) {

    // Находим конец s
    
    while (*s != '\0') {
	s++;
    }

    // Копируем t в конец s
    
    while ((*s++ = *t++)) 
	    ;
}

int main() {
    // Пример использования функции strcat
    char str1[50] = "Hello, ";
    const char str2[] = "world!";

    // Вызываем функцию strcat для конкатенации строк
    nstrcat(str1, str2);

    // Вывод результата
    printf("Результат конкатенации: %s\n", str1);

    return 0;
}

