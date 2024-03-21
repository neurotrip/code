#define _GNU_SOURCE
#include <signal.h>
#include "/home/code/Kerrisk_Linux/lib/signal_functions.h"
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

static int sigCnt[NSIG];
static volatile sig_atomic_t gotSigint = 0;

static void handler(int sig)
{
    if (sig == SIGINT)
        gotSigint = 1;
    else
        sigCnt[sig]++;
}

int main(int argc, char *argv[])
{
    int n, numSecs;
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
    sigset_t pendingMask, blockingMask, emptyMask;
    printf("%s: PID is %ld\n", argv[0], (long) getpid());

    for (n = 1; n < NSIG; n++)
        sigaction(n, &sa, NULL);

    if (argc > 1) {
        numSecs = getInt(argv[1], GN_GT_0, NULL);

        sigfillset(&blockingMask);
        if (sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1)
            errExit("sigprocmask");
        printf("%s: sleeping for %d seconds\n", argv[0], numSecs);
        sleep(numSecs);

        if (sigpending(&pendingMask) == -1)
            errExit("sigpending");
        printf("%s: pending signals are: \n", argv[0]);
        printSigset(stdout, "\t\t", &pendingMask);
        sigemptyset(&emptyMask);
        if (sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1)
            errExit("sigprocmask");
    }

    while (!gotSigint)
        continue;

    for (n = 1; n < NSIG; n++)
        if (sigCnt[n] != 0)
            printf("%s: signal %d caught %d time%s\n", argv[0], n, sigCnt[n], (sigCnt[n] == 1) ? "" : "s");
    exit(EXIT_SUCCESS);
}
