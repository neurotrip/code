#include <signal.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

void sigint_handler(int sig) {
	printf("SIGINT handler executed.\n");
}
int main()
{
	struct sigaction sa;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESETHAND | SA_NODEFER;


	if (sigaction(SIGINT, &sa, NULL) == -1) 
		errExit("sigaction");
	
	while (1) {
		sleep(1);
	} 

	return 0;
}

