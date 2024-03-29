#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
#include "/home/code/Kerrisk_Linux/lib/error_functions.c"
#include "/home/code/Kerrisk_Linux/lib/get_num.c"

static void displayProcessTimes(const char *msg)
{
	struct tms t;
	clock_t clockTime;
	static long clockTicks = 0;

	if (msg != NULL)
		printf("%s", msg);

	if (clockTicks == 0) {
		clockTicks = sysconf(_SC_CLK_TCK);
		if (clockTicks == -1)
			errExit("sysconf");
	}

	clockTime = clock();
	if (clockTime == -1)
		errExit("clock");

	printf(" 	clock() returns: %ld clocks-per-sec (%.2f secs)\n",
			(long) clockTime, (double) clockTime / CLOCKS_PER_SEC );
	if (times(&t) == -1)
		errExit("times");
	printf(" 	times() yeilds: user CPU=%.2f; system CPU: %.2f\n",
			(double) t.tms_utime / clockTicks,
			(double) t.tms_stime/ clockTicks);
}

int main(int argc, char *argv[]) 
{
	int numCalls, j;

	printf("CLOCKS_PER_SEC=%ld sysconf(_SC_CLK_TCK)=%ld\n",
			(long) CLOCKS_PER_SEC, sysconf(_SC_CLK_TCK));

	displayProcessTimes("At program start:\n");

	numCalls = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-calls") : 100000000;
	for (j = 0; j < numCalls; j++)
		(void) getppid();

	displayProcessTimes("After getppid() loop:\n");
	fflush(stdin);

	exit(EXIT_SUCCESS);
}
