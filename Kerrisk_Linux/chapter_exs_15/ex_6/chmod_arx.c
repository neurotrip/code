#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
	char *filename;

	if (argc != 2) 
		errExit("Использование: имя программы [имя файла]");

	filename = argv[1];

	struct stat filestat;

	if (stat(filename, &filestat) == -1)
		errExit("stat");

	if (chmod(filename, S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH) == -1)
		errExit("chmod");

	printf("Права %s изменены\n", filename);

	exit(EXIT_SUCCESS);
}
	

