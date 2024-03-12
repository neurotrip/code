#include <sys/types.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	pid_t childPid;

	switch(childPid = fork()) {
	case -1: errExit("fork");
	case 0:
			 sleep(3);
			 pid_t parrentPid = getppid();
			 printf("Parrent PID %ld\n", (long) parrentPid);
			 exit(EXIT_SUCCESS);
	default:
			 exit(EXIT_SUCCESS);
	}
}

