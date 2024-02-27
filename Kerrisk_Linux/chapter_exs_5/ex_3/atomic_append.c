#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
#include "/home/code/Kerrisk_Linux/lib/error_functions.c"
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
	int fd;
	int flag = 0;
	ssize_t buf;
	mode_t filePerms;
	if (argc > 3 && strcmp(argv[3], "x") == 0)
		flag = 1;
	int openFlags;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
				S_IROTH | S_IWOTH;
	if (flag == 0) 
		openFlags = O_RDWR | O_CREAT | O_APPEND;
	else 
		openFlags = O_RDWR | O_CREAT;

	if ((fd = open(argv[1], openFlags, filePerms)) == -1) 
		errExit("open");

	buf = atoll(argv[2]);
	if (buf <= 0 && errno == EINVAL) 
		errExit("atoll");
	char *buffer;
	buffer = (char *)malloc(buf);
	if (buffer == NULL) 
		errExit("malloc");
	if (flag == 0) {
		if (write(fd, buffer, buf) == -1) 
			errExit("write");
	} else if (flag == 1) {
		lseek(fd, 0, SEEK_END);
		if (write(fd, buffer, buf) == -1)
			errExit("write");
	}
	free(buffer);	
	close(fd);
	exit(EXIT_SUCCESS);
}



	

