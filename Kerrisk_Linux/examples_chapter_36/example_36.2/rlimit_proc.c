#include <stdlib.h>
#include <sys/resource.h>
#include "/home/code/Kerrisk_Linux/lib/print_rlimit.h"
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	struct rlimit rl;
	int j;
	pid_t childPid;

	if (argc <  2 || argc > 3 ||strcmp(argv[1], "--help") == 0)
		usageErr("%s soft-limit [hard-limit]\n", argv[0]);

	printRlimit("Initial maximum process limits: ", RLIMIT_NPROC);

	rl.rlim_cur = (argv[1][0] == 'i') ? RLIM_INFINITY :
		getInt(argv[1], 0, "soft-limit");
	rl.rlim_max = (argc == 2) ? rl.rlim_cur : 
		(argv[2][0] == 'i') ? RLIM_INFINITY :
		getInt(argv[2], 0, "hard-limit");
	if (setrlimit(RLIMIT_NPROC, &rl) == -1)
		errExit("setrlimit");
	printRlimit("New maximum process limits: 	", RLIMIT_NPROC);

	for (j = 1; ;j++) {
		switch (childPid = fork()) {
			case -1: errExit("fork");

			case 0: _exit(EXIT_SUCCESS);

			default:
					printf("Child %d (PID=%ld) started\n", j, (long) childPid);
					break;
		}
	}
}
