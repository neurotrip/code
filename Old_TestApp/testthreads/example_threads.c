#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_NUM 10

// Функция, которую будут выполнять потоки
void *compute_square(void *arg) {
    int number = *((int*) arg);
    printf("Квадрат числа %d: %d\n", number, number * number);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int numbers[NUM_THREADS];

    // Создаем потоки для каждого числа
    for (int i = 0; i < NUM_THREADS; ++i) {
        numbers[i] = i + 1;
        if (pthread_create(&threads[i], NULL, compute_square, &numbers[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // Ждем завершения всех потоков
    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    printf("Все потоки завершили выполнение.\n");

    return 0;
}

