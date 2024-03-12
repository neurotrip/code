#include <stdio.h>
#include <unistd.h>

int main() 
{
	int count = 0;
	for(;;) {
		count++;
		sleep(3);
	}
}

