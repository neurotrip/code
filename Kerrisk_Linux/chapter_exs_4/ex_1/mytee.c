#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

int main(int argc, char *argv[]) 
{
	int fd;
	char buffer[1024];
	ssize_t numRead, numWritten;
	
	if (argc < 3 ) {
		fd = open(argv[1], O_RDWR | O_CREAT,
                 	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                 	S_IROTH | S_IWOTH);
	
	} else if (argc == 3 && (strcmp(argv[1], "-a")) == 0) {
		fd = open(argv[2], O_RDWR | O_CREAT | O_APPEND,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
					S_IROTH | S_IWOTH);
	}
	if (fd == -1) 
		errExit("open");

	while ((numRead = read(STDERR_FILENO, buffer, 1024)) > 0) {
		if (numRead == -1) 
			errExit("read");
		numWritten = write(fd, buffer, numRead);
		numWritten = write(STDOUT_FILENO, buffer, numRead);
		if (numWritten == -1) 
			errExit("write");
	}

	close(fd);

	exit(EXIT_SUCCESS);
}

