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
#include <syslog.h>

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
	openlog("program", LOG_PID, LOG_USER);
	syslog(LOG_INFO, "LAUNCH");
    int in_fd, out_fd;
    char buffer[MAX];
    ssize_t bytes_read;
	int wstatus;
    struct inotify_event *event;
    pid_t pid_less, pid_parrent;
	const char *errmsg;
	int inotify_fd = inotify_init();
	pid_parrent = getpid();
	if ((in_fd = open("/home/code/testlesson/tmp/indata.txt", O_RDONLY)) == -1)
            {
                perror("open indata.txt");
                errmsg = strerror(errno);
                syslog(LOG_ERR, "open indata.txt | %s", errmsg);
                exit(EXIT_FAILURE);
            }

	if (inotify_fd == -1) {
		perror("inotify_init");
		const char *errmsg = strerror(errno);
		syslog(LOG_ERR, "inotify_init | %s",errmsg);
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
			if (write(out_fd, "\n", 1) == -1) {
                perror("child(less) write outdata.txt");
				errmsg = strerror(errno);
                syslog(LOG_ERR, "child(less) write outdata.txt | %s", errmsg);
                exit(EXIT_FAILURE);
            }

			if (close(out_fd) == -1) {
                perror("close out_fd");
				errmsg = strerror(errno);
                syslog(LOG_ERR, "close out_fd | %s", errmsg);
                exit(EXIT_FAILURE);
            }
			printf("Done!\n");
            _exit(EXIT_SUCCESS);
    default:
			signal(SIGINT, SIG_IGN);
			signal(10, handler);
    		while (sig_exit == 0)
    		{
        		char event_buf[BUF_LEN];
        		int num_bytes = read(inotify_fd, event_buf, BUF_LEN);
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
                		bytes_read = read(in_fd, buffer, MAX);
                		if (bytes_read == -1)
                		{
                    		perror("read indata.txt");
							errmsg = strerror(errno);
							syslog(LOG_ERR, "read in_fd | %s", errmsg);
                    		exit(EXIT_FAILURE);
                		}
						
                		if (write(out_fd, buffer, bytes_read) == -1)
                		{
                    		perror("write outdata.txt");
							errmsg = strerror(errno);
							syslog(LOG_ERR, "write outdata.txt | %s", errmsg);
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
    }
	syslog(LOG_INFO, "CLOSE");
    exit(EXIT_SUCCESS);

}

