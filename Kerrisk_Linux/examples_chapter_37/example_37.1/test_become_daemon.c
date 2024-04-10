#include "/home/code/Kerrisk_Linux/lib/become_daemon.h"
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
int
main(int argc, char *argv[])
{
    becomeDaemon(0);

    /* Normally a daemon would live forever; we just sleep for a while */

    sleep((argc > 1) ? getInt(argv[1], GN_GT_0, "sleep-time") : 20);

    exit(EXIT_SUCCESS);
}
