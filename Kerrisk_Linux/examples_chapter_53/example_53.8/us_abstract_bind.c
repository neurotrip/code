#include <stdlib.h>
#include <sys/un.h>
#include <sys/socket.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_un addr;
	char *str;

	memset(&addr, 0, sizeof(struct sockaddr_un));

	addr.sun_family = AF_UNIX;

	strncpy(&addr.sun_path[1], "xyz", sizeof(addr.sun_path) - 2);

	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (sockfd == -1)
		errExit("socket");

	if (bind(sockfd, (struct sockaddr *) &addr, sizeof(sa_family_t) + strlen(str) + 1) == -1)
		errExit("bind");

	sleep(60);
	exit(EXIT_SUCCESS);
}

