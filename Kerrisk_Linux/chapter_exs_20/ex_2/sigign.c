#include <signal.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

int main()
{
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		errExit("sigaction");

	while(1) {
		sleep(1);
		printf("Running\n");
	}

	return 0;
}

