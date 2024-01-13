#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

void print_menu();
void print_original_list(char* lines[], int count);
void print_ordered_ascii(char* lines[], int count);
void print_ordered_by_length(char* lines[], int count);
void print_ordered_by_first_word_length(char* lines[], int count);

int main() {
    char* lines[MAX_LINES];
    int count = 0;
    char input[MAX_LENGTH];

    while (count < MAX_LINES) {
        printf("Введите строку (для завершения введите EOF): ");
        if (fgets(input, MAX_LENGTH, stdin) == NULL || strcmp(input, "EOF\n") == 0) {
            break;
        }

        // Убедимся, что у строки нет символа новой строки в конце
        input[strcspn(input, "\n")] = '\0';

        lines[count] = malloc(strlen(input) + 1);
        strcpy(lines[count], input);
        count++;
    }

    while (1) {
        print_menu();
        int choice;
        printf("Выберите вариант (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_original_list(lines, count);
                break;
            case 2:
                print_ordered_ascii(lines, count);
                break;
            case 3:
                print_ordered_by_length(lines, count);
                break;
            case 4:
                print_ordered_by_first_word_length(lines, count);
                break;
            case 5:
                // Освобождаем выделенную память перед выходом из программы
                for (int i = 0; i < count; i++) {
                    free(lines[i]);
                }
                return 0;
            default:
                printf("Некорректный ввод. Пожалуйста, выберите от 1 до 5.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\nМеню:\n");
    printf("1. Печать исходного списка строк\n");
    printf("2. Печать строк в виде упорядоченной последовательности в кодировке ASCII\n");
    printf("3. Печать строк в порядке возрастания их длины\n");
    printf("4. Печать строк в порядке возрастания длины первого слова строки\n");
    printf("5. Выход из программы\n");
}

void print_original_list(char* lines[], int count) {
    printf("\nИсходный список строк:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }
}

void print_ordered_ascii(char* lines[], int count) {
    printf("\nСтроки в упорядоченной последовательности в кодировке ASCII:\n");
    // Используем стандартную функцию qsort для сортировки строк
    qsort(lines, count, sizeof(char*), strcmp);
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }
}

void print_ordered_by_length(char* lines[], int count) {
    printf("\nСтроки в порядке возрастания их длины:\n");
    // Используем стандартную функцию qsort для сортировки строк по длине
    qsort(lines, count, sizeof(char*), compare_length);
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }
}

void print_ordered_by_first_word_length(char* lines[], int count) {
    printf("\nСтроки в порядке возрастания длины первого слова строки:\n");
    // Используем стандартную функцию qsort для сортировки строк по длине первого слова
    qsort(lines, count, sizeof(char*), compare_first_word_length);
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }
}

// Сравнение строк по длине
int compare_length(const void* a, const void* b) {
    return strlen(*(const char**)a) - strlen(*(const char**)b);
}

// Сравнение строк по длине первого слова
int compare_first_word_length(const void* a, const void* b) {
    const char* word_a = strtok(*(char**)a, " ");
    const char* word_b = strtok(*(char**)b, " ");
    
    return strlen(word_a) - strlen(word_b);
}

