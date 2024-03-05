#include <limits.h>
#include <string.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

#define BUF_SIZE PATH_MAX

char *my_realpath(const char *pathname, char *resolved_path);

int main(int argc, char *argv[])
{
	if (argc != 2) 
		errExit("Usage: %s <pathname>\n", argv[0]);

	char resolved_path[BUF_SIZE];
	if (realpath(argv[1], resolved_path) == NULL) 
		errExit("realpath");

	printf("Resolved path: %s\n", resolved_path);
	
	exit(EXIT_SUCCESS);	
}
char *my_realpath(const char *pathname, char *resolved_path)
{
	static char resolved[BUF_SIZE];

	if (resolved_path == NULL)
		resolved_path = resolved;

	if (pathname[0] == '/') {
		strncpy(resolved_path, pathname, BUF_SIZE);
			resolved_path[BUF_SIZE - 1] == '\0';
	} else {
		if (getcwd(resolved_path, BUF_SIZE) == NULL) 
			errExit("getcwd");
	

	strncat(resolved_path, "/", BUF_SIZE - strlen(resolved_path) -1);
	strncat(resolved_path, pathname, BUF_SIZE - strlen(resolved_path) -1);
	resolved_path[BUF_SIZE - 1] = '\0';
	}

	return resolved_path;
}
