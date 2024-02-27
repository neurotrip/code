#include </home/code/Kerrisk_Linux/lib/tlpi_hdr.h>
#include "/home/code/Kerrisk_Linux/lib/error_functions.c"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
	int fd;
	fd = open(argv[1], O_RDWR | O_APPEND | S_IRUSR | S_IWUSR);
	if (fd == -1)
		errExit("open");
	if (lseek(fd, 0, SEEK_SET) == -1)
		errExit("lseek");
	if (write(fd, "linux", 5) == -1)
		errExit("write");
	close(fd);
	exit(EXIT_SUCCESS);
}
