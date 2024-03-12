#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NUMS 100000000000000
#define NUM_THREADS 5
#define MAX_NUM 10

// Функция, которую будут выполнять потоки
void *compute_square(void *arg) {
    int number = *((int*) arg);
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(number % 4, &cpuset); // Предполагаем, что у нас 4 ядра
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
    printf("Поток %d выполняется на ядре %d. Квадрат числа %d: %d\n", (int)pthread_self(), number % 4, number, number * number);
	long long int result = 0;
    for (long long int i = 0; i < MAX_NUMS; ++i) {
        result += i * i; // Выполняем интенсивные вычисления
    }
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

