#include <stdio.h>

int main() {
    int x = 5;
    int *ptr1 = &x; // Обычный указатель

    int **ptr2 = &ptr1; // Указатель на указатель

    printf("Значение x: %d\n", x);
    printf("Значение, на которое указывает ptr1: %d\n", *ptr1);
    printf("Значение, на которое указывает ptr2: %d\n", **ptr2);

    // Меняем значение через указатель на указатель
    **ptr2 = 10;

    printf("Новое значение x: %d\n", x);

    return 0;
}

