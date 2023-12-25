#include <stdio.h>

#define MONTHS 12 // количество месяцев в году
#define YEARS 5   // количество лет, в течение которых проводились наблюдения

int main(void)
{
    // Инициализация массива данными об осадках за период с 2000 по 2004
    const float rain[YEARS][MONTHS] =
        {
            {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
            {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
            {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
            {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
            {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
        };

    float subtot, total;

    printf("ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");

    // Использование указателей вместо индексов
    const float (*yearPtr)[MONTHS] = rain;
    for (; yearPtr < rain + YEARS; ++yearPtr)
    {
        // Для каждого года суммарное количество осадков за каждый месяц
        const float *monthPtr = *yearPtr;
        for (int i = 0, subtot = 0; i < MONTHS; ++i)
            subtot += *(monthPtr + i);

        printf("%5d %15.1f\n", 2000 + (int)(yearPtr - rain), subtot);
        total += subtot; // Общая сумма за все годы
    }

    printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n", total / YEARS);

    printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв Фев Мар Апр Май Июн Июл Авг Сен Окт Ноя Дек\n");

    // Использование указателей вместо индексов
    const float (*monthPtr)[MONTHS] = rain;
    for (int i = 0; i < MONTHS; ++i)
    {
        for (const float (*yearPtr)[MONTHS] = rain, subtot = 0; yearPtr < rain + YEARS; ++yearPtr)
            subtot += *(*(yearPtr) + i);

        printf("%4.1f ", subtot / YEARS);
        printf("\n");
    }

    return 0;
}

