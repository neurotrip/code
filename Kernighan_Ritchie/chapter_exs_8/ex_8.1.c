#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) 
{
	int fd;
	ssize_t nread;
	char buf[BUF_SIZE];

	for (int i = 1; i < argc; i++) {
		fd = open(argv[i], O_RDONLY);
		if (fd == -1) {
			perror(argv[i]);
			exit(EXIT_FAILURE);
		}

		while ((nread = read(fd, buf, BUF_SIZE)) > 0) {
			if (write(STDOUT_FILENO, buf, nread) != nread) {
				perror("write");
				close(fd);
				exit(EXIT_FAILURE);
			}
		}

		if (nread == -1) {
			perror("read");
			close(fd);
			exit(EXIT_FAILURE);
		}

		if (close(fd) == -1) {
			perror("close");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}



