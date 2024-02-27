#include <stdio.h>
#include <unistd.h>

int main(void) 
{
	pid_t mypid;
	mypid = getpid();
	printf("My PID is %ld\n", (long)mypid);
	
	return 0;
}

