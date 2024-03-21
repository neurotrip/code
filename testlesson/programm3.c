#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define MAX 3000
#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (MAX_EVENTS * (EVENT_SIZE + 16))

int main()
{
    int in_fd, out_fd;
    char buffer[MAX];
    ssize_t bytes_read;
    struct inotify_event *event;
    pid_t pid_less;
    long bytes_count = 0;
    int inotify_fd = inotify_init();
    if (inotify_fd == -1)
    {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    int wd = inotify_add_watch(inotify_fd, ".", IN_MODIFY);
    if (wd == -1)
    {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    if ((in_fd = open("indata.txt", O_RDONLY)) == -1)
    {
        perror("open indata.txt");
        exit(EXIT_FAILURE);
    }

    if ((out_fd = open("outdata.txt", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("open outdata.txt");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        char event_buf[BUF_LEN];
        int num_bytes = read(inotify_fd, event_buf, BUF_LEN);
        if (num_bytes == -1)
        {
            perror("read inotify_fd");
            exit(EXIT_FAILURE);
        }

        int i = 0;
        while (i < num_bytes)
        {
            event = (struct inotify_event *)&event_buf[i];
            if ((event->mask & IN_MODIFY) && (strcmp(event->name, "indata.txt") == 0))
            {
                bytes_read = read(in_fd, buffer, MAX);
                if (bytes_read == -1)
                {
                    perror("read indata.txt");
                    exit(EXIT_FAILURE);
                }

                if (write(out_fd, buffer, bytes_read) == -1)
                {
                    perror("write outdata.txt");
                    exit(EXIT_FAILURE);
                }
            }
            i += EVENT_SIZE + event->len;
        }
    }

    inotify_rm_watch(inotify_fd, wd);
    close(inotify_fd);
    if (close(out_fd) == -1)
    {
        perror("close out_fd");
        exit(EXIT_FAILURE);
    }
    if (close(in_fd) == -1)
    {
        perror("close in_fd");
        exit(EXIT_FAILURE);
    }
    if (remove("outdata.txt") == -1)
    {
        perror("remove");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}