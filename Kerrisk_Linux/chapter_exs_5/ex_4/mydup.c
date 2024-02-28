#include <stdlib.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
#include "/home/code/Kerrisk_Linux/lib/error_functions.c"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int mydup(int olfd);
int mydup2(int oldfd, int newfd);

int main() 
{
	int fd1, fd2, fd3;
	
	if ((fd1 = open("test.txt", O_RDONLY)) == -1) 
		errExit("open");

	fd2 = mydup(fd1);
	if (fd2 == -1) 
		errExit("mydup");
	
	fd3 = mydup2(fd1, 5);
	if (fd3 == -1)
		errExit("mydup2");

	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);
	printf("fd3 = %d\n", fd3);

	close(fd1);
	close(fd2);
	close(fd3);

	exit(EXIT_SUCCESS);
}

int mydup(int oldfd)
{
	int newfd = fcntl(oldfd, F_DUPFD);
	if (newfd == -1)
		errExit("newfd md");

	return newfd;
}

int mydup2(int oldfd, int newfd)
{
	if (oldfd == newfd) {
		if (fcntl(oldfd, F_GETFL) == -1) 
			errExit("newfd md2");
		return newfd;
	}

	if (fcntl(newfd, F_GETFL) != -1) 
		if (close(newfd) == -1)
			errExit("close newfd md2");

	newfd = fcntl(oldfd, F_DUPFD);
	if (newfd == -1)
		errExit("newfd md2");

	return newfd;
}
	


