#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEGABYTE 100000
#define FILE_SIZE_MB 100

int main() {
    FILE *fp;
    long long int fileSize = MEGABYTE * FILE_SIZE_MB;
    long long int bytesWritten = 0;
    int i;
    
    // Открываем файл для записи
    fp = fopen("text_file.txt", "w");
    if (fp == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }
    
    // Устанавливаем seed для генератора случайных чисел
    srand(time(NULL));
    
    // Записываем случайные символы в файл
    while (bytesWritten < fileSize) {
        // Генерируем случайный символ (ASCII код от 32 до 126)
        char c = rand() % (126 - 32 + 1) + 32;
        // Записываем символ в файл
        fprintf(fp, "%c", c);
        bytesWritten++;
    }
    
    // Закрываем файл
    fclose(fp);
    
    printf("Текстовый файл размером %d МБ создан успешно.\n", FILE_SIZE_MB);
    
    return 0;
}

