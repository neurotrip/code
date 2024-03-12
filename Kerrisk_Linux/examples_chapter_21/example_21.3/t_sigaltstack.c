#define _GNU_SOURCE
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

static void sigsegvHandler(int sig)
{
	int x;

	printf("Caught signal %d (%s)\n", sig, strsignal(sig));
	printf("Top of handler stack near 	%10p\n", (void *) &x);
	fflush(NULL);

	_exit(EXIT_FAILURE);
}

static void overflowStack(int callNum, FILE *file)
{
	char a[10000];

	printf("Call %4d - top of stack near %10p\n", callNum, &a[0]);
	fprintf(file,"Call %4d - top of stack near %10p\n", callNum, &a[0]);
	overflowStack(callNum+1, file);
}

int main(int argc, char *argv[])
{
	stack_t sigstack;
	struct sigaction sa;
	int j;
	FILE *file;
	char *filename = "text.txt";
	if ((file = fopen(filename, "w")) == NULL) 
		errExit("fopen");
	printf("Top of standart stack is near %10p\n", (void *) &j);
	fprintf(file, "Top of standart stack is near %10p\n", (void *) &j);
	sigstack.ss_sp = malloc(SIGSTKSZ);
	if (sigstack.ss_sp == NULL) 
		errExit("malloc");
	sigstack.ss_size = SIGSTKSZ;
	sigstack.ss_flags = 0;
	if (sigaltstack(&sigstack, NULL) == -1) 
		errExit("sigaltstack");
	printf("Alternate stack is at	%10p-%p\n",
			sigstack.ss_sp, (char *) sbrk(0) - 1);
	fprintf(file, "Alternate stack is at   %10p-%p\n",
              sigstack.ss_sp, (char *) sbrk(0) - 1);
	sa.sa_handler = sigsegvHandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_ONSTACK;
	if (sigaction(SIGSEGV, &sa, NULL) == -1) 
		errExit("sigaction");

	overflowStack(1, file);
}

