#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

static void usageError(const char *progName)
{
	fprintf(stderr, "Usage: %s [-cx] shm-name size [octal-perms]\n", progName);
	fprintf(stderr," 	-c 	Create shared memory (O_CREAT)\n");
	fprintf(stderr," 	-x 	Create exclusively (O_EXCL)\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int flags, opt, fd;
	mode_t perms;
	size_t size;
	void *addr;

	flags = O_RDWR;
	while ((opt = getopt(argc, argv, "cx")) != -1) {
		switch (opt) {
			case 'c': 	flags |= O_CREAT; 	break;
			case 'x': 	flags |= O_EXCL; 	break;
			default: 	usageError(argv[0]);
		}
	}

	if (optind + 1 >= argc)
		usageError(argv[0]);

	size = getLong(argv[optind + 1], GN_ANY_BASE, "size");
	perms = (argc <= optind + 2) ? (S_IRUSR | S_IWUSR) :
				getLong(argv[optind + 2], GN_BASE_8, "octal-perms");

	fd = shm_open(argv[optind], flags, perms);
	if (fd == -1)
		errExit("shm_open");

	if (ftruncate(fd, size) == -1)
		errExit("ftruncate");

	addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED)
		errExit("mmap");

	exit(EXIT_SUCCESS);
}

