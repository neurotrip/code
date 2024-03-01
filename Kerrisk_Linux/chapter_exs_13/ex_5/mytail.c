#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
#include "/home/code/Kerrisk_Linux/lib/error_functions.c"

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
	int lines_to_read = 0;
	int fd;
	off_t file_size, current_pos, read_pos;
	char buffer[BUF_SIZE];
	int lines = 0;
	ssize_t bytes_read;

	if ((fd = open(argv[3], O_RDONLY)) == -1)
		errExit("open");
	
	if (strcmp(argv[2], "n") == 0)
		lines_to_read = 10;
	else 
		lines_to_read = atoi(argv[2]);

	file_size = lseek(fd, 0, SEEK_END);
	
	current_pos = lseek(fd, file_size-1, SEEK_SET);
	if (current_pos == -1)
		errExit("lseek");

	while (lines < lines_to_read && current_pos >= 0) {
		if ((bytes_read = read(fd, buffer, BUF_SIZE)) == -1)	
			errExit("read");
		read_pos = current_pos;

		for (ssize_t i = bytes_read - 1; i >=0 ; i--) {
			if (buffer[i] == '\n') {
				lines++;
				if (lines == lines_to_read + 1) {
					read_pos += i + 1;
					break;
				}
			}
			read_pos--;
		}
		if (lseek(fd, read_pos, SEEK_SET) == -1) 
			errExit("lseek");
		write(STDOUT_FILENO, buffer, bytes_read);

		current_pos -= BUF_SIZE;
	}

	close(fd);

	exit(EXIT_SUCCESS);
}

