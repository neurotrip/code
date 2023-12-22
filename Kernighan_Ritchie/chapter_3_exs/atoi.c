#include <stdio.h>
#include <stdlib.h>
//int atoi(char s[]) {
//    int i, n;
//    n = 0;
//
//    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
//        n = 10 * n + (s[i] - '0');
//
//    return n;
//}

int main() {
    char str[] = "12345!a";
    int result = atoi(str);

    printf("Строка: %s\n", str);
    printf("Целочисленное значение: %d\n", result);

    return 0;
}

