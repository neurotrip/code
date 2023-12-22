#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    const char digits[] = "0123456789ABCDEF";  // Допустимые цифры в различных системах счисления
    int i = 0;
    int sign = (n < 0) ? -1 : 1;

    do {
        s[i++] = digits[sign * (n % b)];  // Получаем цифру и добавляем ее в строку
        n /= b;
    } while (n != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);  // Разворачиваем строку, чтобы получить правильный порядок цифр
}

int main() {
    int n = 255;
    char s[100];  // Предполагаем максимальную длину

    itob(n, s, 10);

    printf("Результат: %s\n", s);

    return 0;
}

