#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <poll.h>
#define MAX 3000

int main() {
    pid_t pid;
    int in_fd, out_fd;
    char buffer[MAX];
    ssize_t bytes_read;
    struct pollfd fds[1];

    if ((out_fd = open("/home/code/testlesson/tmp/outdata.txt", O_RDWR | O_TRUNC| O_CREAT , S_IRUSR | S_IWUSR)) == -1) {
        perror("open outdata.txt");
        exit(EXIT_FAILURE);
    }

    if ((in_fd = open("/home/code/testlesson/tmp/indata.txt", O_RDONLY)) == -1) {
        perror("open indata.txt");
        exit(EXIT_FAILURE);
    }

    fds[0].fd = in_fd;
    fds[0].events = POLLIN;

    switch(pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            printf("Запуск less\n");
//            char *newargv[] = { "less","-E" , "/home/code/testlesson/tmp/outdata.txt", NULL };
 //           char *filename = "/usr/bin/less";
//            execve(filename, newargv, NULL);
			execlp("less", "less","-F", "/home/code/testlesson/tmp/indata.txt", NULL);            
            _exit(EXIT_SUCCESS);
        default:
            while (1) {
                int ret = poll(fds, 1, -1); // Ждем изменений в indata.txt
                if (ret == -1) {
                    perror("poll");
                    exit(EXIT_FAILURE);
                }
                
                if (fds[0].revents & POLLIN) {
                    bytes_read = read(in_fd, buffer, MAX);
                    if (bytes_read == -1) {
                        perror("read indata.txt");
                        exit(EXIT_FAILURE);
                    }
                    if (write(out_fd, buffer, bytes_read) == -1) {
                        perror("write outdata.txt");
                        exit(EXIT_FAILURE);
                    }
                }
            }
			wait(NULL);
            if (close(out_fd) == -1) {
                perror("close out_fd");
                exit(EXIT_FAILURE);
            }
            if (close(in_fd) == -1) {
                perror("close in_fd");
                exit(EXIT_FAILURE);
            }
            
            if (remove("/home/code/testlesson/tmp/outdata.txt") == -1) {
                perror("remove");
                exit(EXIT_FAILURE);
            }
            printf("PARENT: Выход!\n");
    }
    exit(EXIT_SUCCESS);
}

