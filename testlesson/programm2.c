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

int sig_exit = 0;

void handler(int sig) {
	sig_exit = 1;
	printf("Handler\n");
}

int main()
{
    int in_fd, out_fd;
    char buffer[MAX];
    ssize_t bytes_read;
	int wstatus;
    struct inotify_event *event;
    pid_t pid_less, pid_parrent;
	int inotify_fd = inotify_init();
	pid_parrent = getpid();
	if (inotify_fd == -1) {
		perror("inotify_init");
		exit(EXIT_FAILURE);
	}

	int wd = inotify_add_watch(inotify_fd, "/home/code/testlesson/tmp/", IN_MODIFY);
	if (wd == -1) {
		perror("inotify_add_watch");
		exit(EXIT_FAILURE);
	}

    if ((out_fd = open("/home/code/testlesson/tmp/outdata.txt", O_RDWR | O_TRUNC| O_CREAT, S_IRUSR | S_IWUSR)) == -1) {
        perror("open outdata.txt");
        exit(EXIT_FAILURE);
    }

    switch(pid_less=fork()) {
    case -1:
            perror("fork");
            exit(EXIT_FAILURE);
    case 0:
            printf("Запуск less\n");
            //char *newargv[] = { "less", "+F", "/home/code/testlesson/tmp/outdata.txt", NULL };
           // char *filename = "/usr/bin/less";
//            execl("/usr/bin/less", "/usr/bin/less", "+F", "/home/code/testlesson/tmp/outdata.txt", (char*) NULL);
			system("/usr/bin/less +F /home/code/testlesson/tmp/outdata.txt");
			kill(pid_parrent, 10);
			write(out_fd, "\n", 1);
			close(out_fd);
			printf("Done!\n");
            _exit(EXIT_SUCCESS);
    default:
			signal(SIGINT, SIG_IGN);
			signal(10, handler);
		    if ((in_fd = open("/home/code/testlesson/tmp/indata.txt", O_RDONLY, S_IWUSR)) == -1)
   	 		{
        		perror("open indata.txt");
        		exit(EXIT_FAILURE);
    		}
    		while (sig_exit == 0)
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
 	        waitpid(pid_less,&wstatus, WUNTRACED | WCONTINUED);
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

