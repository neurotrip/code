#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
#define MAX 100

void menu();
void printOriginalList(char *str[], int length);
void printOrderedASCII(char *str[], int length);
int compareStrings(const void *a, const void *b);

int main(void)
{
    char *string[LENGTH];
    char buffer[MAX];
    char **input = string;
    printf("Введите не более 10 строк\n");

    while (input < string + LENGTH && fgets(buffer, MAX, stdin) != NULL)
    {
        *input++ = strdup(buffer);
    }

    menu();

    printOriginalList(string, LENGTH);

    // Копируем строки в новый массив для сортировки
    char *sortedStrings[LENGTH];
    for (int i = 0; i < LENGTH; ++i)
    {
        sortedStrings[i] = string[i];
    }

    printOrderedASCII(sortedStrings, LENGTH);

    // Освобождаем память, выделенную под строки
    for (int i = 0; i < LENGTH; ++i)
    {
        free(string[i]);
    }

    return 0;
}

void menu()
{
    printf("Выберете одно из предложенных действий\n");
    printf("1. Печать исходного списка строк\n");
    printf("2. Печать строк в виде упорядоченной последовательности\n");
    printf("3. Печать строк в порядке возрастания их длины\n");
    printf("4. Печать строк в порядке возрастания длины первого слова строки\n");
    printf("5. Выход\n");
}

void printOriginalList(char *str[], int length)
{
    char **current = str;
    while (*current != NULL)
    {
        fputs(*current++, stdout);
    }
}

void printOrderedASCII(char *str[], int length)
{
    // Сортировка массива строк в порядке ASCII
    qsort(str, length, sizeof(char *), compareStrings);

    printf("\nУпорядоченная последовательность строк в кодировке ASCII:\n");

    // Печать упорядоченной последовательности
    char **current = str;
    while (*current != NULL)
    {
        fputs(*current++, stdout);
    }
}

int compareStrings(const void *a, const void *b)
{
    // Сравнение строк в порядке ASCII
    return strcmp(*(const char **)a, *(const char **)b);
}

