#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/syslog.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <sched.h>

#define MAX 3000
#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (MAX_EVENTS * (EVENT_SIZE + 16))

struct ThreadArgs {
    int inotify_fd;
    int in_fd;
    int out_fd;
    bool *thread_exit;
    pthread_mutex_t *mutex;
    bool *should_exit;
};

static void *threadLessfunc(void *arg)
{
    int cpu_number = 1;
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_number, &cpuset);
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    const char *errmsg;
    system("/usr/bin/less +F /home/code/testlesson/tmp/outdata.txt");

    pthread_mutex_lock(args->mutex);
    if (write(args->out_fd, "\n", 1) == -1) {
        perror("pthread(less) write outdata.txt");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "pthread(less) write outdata.txt | %s", errmsg);
        exit(EXIT_FAILURE);
    }
    pthread_mutex_unlock(args->mutex);

    printf("Less done!\n");
    *args->thread_exit = true;
    pthread_exit(NULL);
}

static void *threadFileWatcher(void *arg)
{
    int cpu_number = 2;
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_number, &cpuset);
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    const char *errmsg;
    char buffer[MAX];
    ssize_t bytes_read;
    struct inotify_event *event;

    while (!(*args->thread_exit))
    {
        char event_buf[BUF_LEN];
        int num_bytes = read(args->inotify_fd, event_buf, BUF_LEN);
        if (num_bytes == -1)
        {
            perror("read inotify_fd");
            errmsg = strerror(errno);
            syslog(LOG_ERR, "read inotify_fd | %s", errmsg);
            exit(EXIT_FAILURE);
        }

        int i = 0;
        while (i < num_bytes)
        {
            event = (struct inotify_event *)&event_buf[i];
            if ((event->mask & IN_MODIFY) && (strcmp(event->name, "indata.txt") == 0))
            {
                bytes_read = read(args->in_fd, buffer, MAX);
                if (bytes_read == -1)
                {
                    perror("read indata.txt");
                    errmsg = strerror(errno);
                    syslog(LOG_ERR, "read in_fd | %s", errmsg);
                    exit(EXIT_FAILURE);
                }

                pthread_mutex_lock(args->mutex);
                if (write(args->out_fd, buffer, bytes_read) == -1)
                {
                    perror("write outdata.txt");
                    errmsg = strerror(errno);
                    syslog(LOG_ERR, "write outdata.txt | %s", errmsg);
                    exit(EXIT_FAILURE);
                }
                pthread_mutex_unlock(args->mutex);
            }
            i += EVENT_SIZE + event->len;
        }
    }
    printf("Program done!\n");

    pthread_exit(NULL);
}

int main()
{
    openlog("program", LOG_PID, LOG_USER);
    syslog(LOG_INFO, "LAUNCH");

    int in_fd, out_fd;
    const char *errmsg;
    pthread_t less_thread, file_watcher_thread;
    int s_less,s_watcher;
    bool thread_exit = false;
    struct ThreadArgs thread_args;

    int inotify_fd = inotify_init();
    if (inotify_fd == -1) {
        perror("inotify_init");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "inotify_init | %s",errmsg);
        exit(EXIT_FAILURE);
    }

    if ((in_fd = open("/home/code/testlesson/tmp/indata.txt", O_RDONLY)) == -1) {
        perror("open indata.txt");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "open indata.txt | %s", errmsg);
        exit(EXIT_FAILURE);
    }

    int wd = inotify_add_watch(inotify_fd, "/home/code/testlesson/tmp/", IN_MODIFY);
    if (wd == -1) {
        perror("inotify_add_watch");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "inotify_add_watch | %s", errmsg);
        exit(EXIT_FAILURE);
    }

    if ((out_fd = open("/home/code/testlesson/tmp/outdata.txt", O_RDWR | O_TRUNC| O_CREAT, S_IRUSR | S_IWUSR)) == -1) {
        perror("open outdata.txt");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "open outdata.txt | %s", errmsg);
        exit(EXIT_FAILURE);
    }
    thread_args.in_fd = in_fd;
    thread_args.inotify_fd = inotify_fd;
    thread_args.out_fd = out_fd;
    thread_args.thread_exit = &thread_exit;

    s_less = pthread_create(&less_thread, NULL, threadLessfunc, (void *)&thread_args);
    if (s_less != 0) {
        perror("pthread_create");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "pthread_create s_less | %s", errmsg);
        exit(EXIT_FAILURE);
    }
    s_watcher = pthread_create(&file_watcher_thread, NULL, threadFileWatcher, (void *)&thread_args);
    if (s_watcher != 0) {
        perror("pthread_create");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "pthread_create s_watcher | %s", errmsg);
        exit(EXIT_FAILURE);
    }

    s_less = pthread_join(less_thread, NULL);
    if (s_less != 0) {
        perror("pthread_join");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "pthread_join s_less | %s", errmsg);
        exit(EXIT_FAILURE);
    }

    s_watcher = pthread_join(file_watcher_thread, NULL);
    if (s_watcher != 0) {
        perror("pthread_join");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "pthread_join s_watcher | %s", errmsg);
        exit(EXIT_FAILURE);
    }

    inotify_rm_watch(inotify_fd, wd);
    close(inotify_fd);
    if (close(out_fd) == -1) {
        perror("close out_fd");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "close out_fd | %s", errmsg);
        exit(EXIT_FAILURE);
    }
    if (close(in_fd) == -1) {
        perror("close in_fd");
        errmsg = strerror(errno);
        syslog(LOG_ERR, "close in_fd | %s", errmsg);
        exit(EXIT_FAILURE);
    }
    if (remove("/home/code/testlesson/tmp/outdata.txt") == -1) {
        errmsg = strerror(errno);
        syslog(LOG_ERR, "remove outdata.txt | %s", errmsg);
        perror("remove outdata.txt");
        exit(EXIT_FAILURE);
    }

    syslog(LOG_INFO, "CLOSE");
    exit(EXIT_SUCCESS);
}

