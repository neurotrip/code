#include <signal.h>
#include <sys/wait.h>
#include <libgen.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

#define CMD_SIZE 200

int main(int argc, char *argv[])
{
	char cmd[CMD_SIZE];
	pid_t childPid;

	setbuf(stdout, NULL);

	printf("parent PID=%ld\n", (long) getpid());

	switch (childPid = fork()) {
	case -1:
		errExit("fork");
	case 0:
		printf("Child (PID=%ld) exiting\n", (long) getpid());
		_exit(EXIT_SUCCESS);

	default:
		sleep(3);
		snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0]));
		system(cmd);

		if (kill(childPid, SIGKILL) == -1)
			errMsg("kill");
		sleep(3);
//		wait(NULL);
		printf("After sending SIGKILL to zombie (PID=%ld):\n",
				(long) childPid);
		system(cmd);

		exit(EXIT_SUCCESS);
	}
}

