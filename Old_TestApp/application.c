#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 60

int main(int argc, char *argv[])
{
	const char *pathname = "/home/alex/MyApp/TestApp_C++/tmp/indata.txt";
	int fd;
	if ((fd = open(pathname, O_CREAT| O_WRONLY | O_TRUNC, 0777)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < MAX; i++) {
		sleep(1);
        if (i % 2 == 0) {
			if (write(fd, "0", 1) == -1) {
				perror("write");
				exit(EXIT_FAILURE);
			}
        } else {
           if (write(fd, "1", 1) == -1) {
			   perror("write");
			   exit(EXIT_FAILURE);
		   }
        }
		if ((i+1) % 10 == 0)
			if (write(fd, "\n", 1) == -1) {
				perror("write");
				exit(EXIT_FAILURE);
			}
//		printf("%d\n", i);
    }
	
	if (close(fd) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("Done!\n");

	exit(EXIT_SUCCESS);
}


