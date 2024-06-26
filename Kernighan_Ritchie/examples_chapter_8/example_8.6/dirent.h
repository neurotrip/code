#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define NAME_MAX 14
#ifndef DIRSIZ
#define DIRSIZ 14
#endif


typedef struct {
	long ino;
	char name[NAME_MAX+1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} DIR;

struct direct {
	ino_t d_ino;
	char d_name[DIRSIZ];
};

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;
	static Dirent d;

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
			== sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);	
		d.name[DIRSIZ] = '\0';
		return &d;
	}

	return NULL;
}

void closedir(DIR *dp)
{
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

DIR *opendir(char *dirname) 
{
	int fd;
	struct stat stbuf;
	DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
			|| fstat(fd, &stbuf) == -1
			|| (stbuf.st_mode & S_IFMT) != S_IFDIR
			|| (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}

		
