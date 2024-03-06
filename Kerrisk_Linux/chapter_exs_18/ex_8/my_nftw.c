#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"


int my_nftw(const char *dirpath, int (*func) (const char *pathname, const struct stat *statbuf));
int size_files(const char *pathname, const struct stat *statbuf);
int main(int argc, char *argv[]) 
{
	const char *dirpath = ".";
	my_nftw(dirpath, size_files);	
	exit(EXIT_SUCCESS);
}
int my_nftw (const char *dirpath, int (*func) (const char *pathname, const struct stat *statbuf)) 
{	
	DIR *dir;
	struct dirent *dirfiles;
	char *files[100];
	struct  stat statbuf;
	char **file_ptr = files;
	if ((dir = (opendir(dirpath))) == NULL) 
		errExit("opendir");
	while ((dirfiles = readdir(dir)) != NULL) {
		if (strcmp(dirfiles->d_name, ".") == 0 || strcmp(dirfiles->d_name, "..") == 0)
			continue;
		*file_ptr = malloc(strlen(dirfiles->d_name) + 1);
		strcpy(*file_ptr, dirfiles->d_name);	
//		printf("%s\n", dirfiles->d_name);
		file_ptr++;
	}
	*file_ptr = NULL;
	file_ptr = files;

	while (*file_ptr != NULL) {
		stat(*file_ptr, &statbuf);
		func(*file_ptr, &statbuf);
		file_ptr++;
	}


	if (closedir(dir) == -1)
		errExit("closedir");

	return 0;
}

int size_files(const char *pathname, const struct stat *statbuf) 
{
	printf("Имя файла: %s, размер %jd\n", pathname, statbuf->st_size);
	return 0;
}
