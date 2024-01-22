#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("image.txt", "r"); // Открываем файл для чтения
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    int image[20][30]; // Массив для хранения целочисленных значений
    char imageChar[20][31]; // Массив для хранения символьного представления изображения

    // Считываем данные из файла и заполняем массив image
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    // Закрываем файл
    fclose(file);

    // Преобразуем массив image в символьное представление и сохраняем его в массив imageChar
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            switch (image[i][j]) {
                case 0:
                    imageChar[i][j] = ' ';
                    break;
                case 1:
                    imageChar[i][j] = '.';
                    break;
                case 2:
                    imageChar[i][j] = ':';
                    break;
                case 3:
                    imageChar[i][j] = 'o';
                    break;
                case 4:
                    imageChar[i][j] = 'c';
                    break;
                case 5:
                    imageChar[i][j] = 'w';
                    break;
                case 6:
                    imageChar[i][j] = 'W';
                    break;
                case 7:
                    imageChar[i][j] = 'O';
                    break;
                case 8:
                    imageChar[i][j] = 'X';
                    break;
                case 9:
                    imageChar[i][j] = '#';
                    break;
                default:
                    imageChar[i][j] = ' ';
                    break;
            }
        }
        imageChar[i][30] = '\0'; // Завершаем строку
    }

    // Отображаем символьное представление изображения
    for (int i = 0; i < 20; i++) {
        printf("%s\n", imageChar[i]);
    }

    // Сохраняем результат в файл
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Не удалось создать файл для сохранения результата\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        fprintf(outputFile, "%s\n", imageChar[i]);
    }

    fclose(outputFile);

    return 0;
}

