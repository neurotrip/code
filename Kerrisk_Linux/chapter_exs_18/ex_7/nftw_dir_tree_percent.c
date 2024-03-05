#define _XOPEN_SOURCE 600
#include <ftw.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

static uintmax_t regular_files = 0;
static uintmax_t dir = 0;
static uintmax_t sym_links = 0;
static uintmax_t other_files = 0;

static int count_files(const char *pathname, const struct stat *statbuf, int typeflag, struct FTW *ftwbuf);

int main(int argc, char *argv[])
{
	if (nftw(".", count_files, 20, FTW_PHYS) == -1)
		errExit("nftw");
	uintmax_t total = regular_files + dir + sym_links + other_files;

	printf("Regular files: %ju (%.2f%%)\n", regular_files, (float)regular_files /total * 100);
	printf("Directory: %ju (%.2f%%)\n", dir, (float)dir/total * 100);
	printf("Symbolic links: %ju (%.2f%%)\n", sym_links, (float)sym_links/total * 100);
	printf("Other files: %ju (%.2f%%)\n", other_files, (float)other_files/total * 100);	
    exit(EXIT_SUCCESS);
}
static int count_files(const char *pathname, const struct stat *statbuf, int typeflag, struct FTW *ftwbuf)
{
	char *start_dir = ".";
	if (strcmp(pathname, start_dir) == 0)
		return 0;		
	switch (typeflag) {
		case FTW_F:
			regular_files++;
			break;
		case FTW_D:
			dir++;
			break;
		case FTW_SL: 
			sym_links++;
			break;
		default:
			other_files++;
			break;
	}

	return 0;
}

