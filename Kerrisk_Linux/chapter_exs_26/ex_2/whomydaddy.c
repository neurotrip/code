#include <sys/types.h>
#include <sys/wait.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"
  
int main(int argc, char *argv[])
{
	pid_t childPid, parrentPid, grandparrentPid;
  
   	switch(grandparrentPid = fork()) {
    	case -1: errExit("fork");
       	case 0:
				parrentPid = getpid();
				printf("Parent PID %ld\n", (long) parrentPid);
				switch (parrentPid = fork()) {
					case -1: errExit("fork");
					case 0:
							 sleep(3); 
							 childPid = getppid();
							 printf("Child-parent PID after kill parent %ld\n", (long) childPid);
							 _exit(EXIT_SUCCESS);
					default:
							 _exit(EXIT_SUCCESS);
				}
    	default:
				wait(NULL);
				grandparrentPid = getpid();
				printf("Grand parent pid %ld\n", (long) grandparrentPid);
             	exit(EXIT_SUCCESS);
    }
}
 

