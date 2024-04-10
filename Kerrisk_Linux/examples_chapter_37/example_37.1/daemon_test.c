#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

// Функция для инициализации демона
void init_daemon() {
    pid_t pid;

    // Создаем дочерний процесс
    pid = fork();

    // Если произошла ошибка при создании дочернего процесса, завершаем программу
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // Если это родительский процесс, завершаем его
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Устанавливаем файловую маску для новых файлов
    umask(0);

    // Создаем новую сессию
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    // Изменяем текущий каталог на /
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }

    // Закрываем стандартные потоки ввода, вывода и ошибок
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    // Инициализируем демона
    init_daemon();

    // Открываем файл для логирования
    openlog("mydaemon", LOG_PID, LOG_DAEMON);

    // Главный цикл демона
    while (1) {
        // Здесь можно поместить код, который будет выполняться демоном

        // Записываем сообщение в журнал
        syslog(LOG_INFO, "Daemon is running...");

        // Ждем некоторое время перед следующей итерацией
        sleep(10);
    }

    // Закрываем журнал перед выходом
    closelog();

    return 0;
}

