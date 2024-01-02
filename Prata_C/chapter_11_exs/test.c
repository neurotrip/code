#include <stdio.h>

char *string_in(const char *s1, const char *s2);

int main(void)
{
    char m1[] = "hats";
    char m2[] = "at";
    char *result;

    result = string_in(m1, m2);
    if (result != NULL)
        printf("Адрес начала второй строки в первой: %s\n", result);
    else
        printf("Вторая строка не содержится в первой\n");

    return 0;
}

char *string_in(const char *s1, const char *s2)
{
    while (*s1 != '\0') {
        const char *s1_start = s1;
        const char *s2_start = s2;

        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
            s1++;
            s2++;
        }

        if (*s2 == '\0') {
            return (char *)s1_start; // Вторая строка найдена в первой
        }

        s1 = s1_start + 1;
        s2 = s2_start;
    }

    return NULL; // Вторая строка не найдена в первой
}

