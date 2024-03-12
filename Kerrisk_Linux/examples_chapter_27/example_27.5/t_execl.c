#include <stdlib.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	printf("Initial value of USER: %s\n", getenv("USER"));
	if (putenv("USER=britta") != 0)
		errExit("putenv");
	execl("/usr/bin/printenv", "printenv", "USER", "SHELL", (char *) NULL);
	errExit("execl");
}

