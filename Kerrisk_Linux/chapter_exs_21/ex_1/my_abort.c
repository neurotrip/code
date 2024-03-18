#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

void my_abort(pid_t pid);

int main(int argc, char *argv[])
{
	pid_t pid;
	pid = getpid();

	for (int i = 0; i < 10; i++) {
		printf("Count: %d\n", i);
		sleep(1);
		if (i == 5) 
			my_abort(pid);
	}
	
	exit(EXIT_SUCCESS);
}

void my_abort(pid_t pid) 
{
	if (kill(pid, SIGABRT) == -1)
		errExit("kill");

}

