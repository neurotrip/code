#include <stdio.h>

int strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;  // Строки равны
        }
    }
    return *s - *t;  // Возвращаем разность символов
}

int main() {
    // Пример использования функции strcmp
    char str1[] = "hello";
    char str2[] = "world";
    
    int result = strcmp(str1, str2);
    
    if (result == 0) {
        printf("Строки равны\n");
    } else if (result < 0) {
        printf("Строка 1 меньше строки 2\n");
    } else {
        printf("Строка 1 больше строки 2\n");
    }

    return 0;
}

