#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int j;
	for (j = 0; j < argc; j++)
		printf("argv[%d] = %s\n", j, argv[j]);
	exit(EXIT_SUCCESS);
}

