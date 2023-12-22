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

void itoa(int n, char s[], int minWidth) {
    int i, sign;
    if ((sign = n) < 0) /* сохраняем знак */
        n = -n;          /* делаем n положительным */
    i = 0;
    do { /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0'; /* следующая цифра */
    } while ((n /= 10) > 0);   /* исключить ее */
    if (sign < 0)
        s[i++] = '-';
    
    // Дополнение пробелами до минимальной ширины поля
    while (i < minWidth)
        s[i++] = ' ';
    
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];  // Предполагаем максимальную длину

    itoa(123, s, 8);

    printf("Результат: %s\n", s);

    return 0;
}

