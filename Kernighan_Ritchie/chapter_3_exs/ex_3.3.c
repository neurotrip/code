#include <stdio.h>

void expand(char s1[], char s2[]); 

int main() {
    char s1[] = "a-z0-9";
    char s2[100];  // Предполагаем максимальную длину

    expand(s1, s2);

    printf("Результат: %s\n", s2);

    return 0;
}
void expand(char s1[], char s2[]) {
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        if (s1[i + 1] == '-' && s1[i] < s1[i + 2]) {
            // Обработка случаев типа a-z
            char start_char = s1[i];
            char end_char = s1[i + 2];
            for (char c = start_char; c <= end_char; ++c) {
                s2[j++] = c;
            }
            i += 3;
        } else {
            // Обработка отдельных символов
            s2[j++] = s1[i++];
        }
    }

    s2[j] = '\0';  // Завершаем строку нулевым символом
}
