#include <stdio.h>
#include <string.h>
#include <syscall.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

#define MAX_PATH 1024

void fsize(char *);
void dirwalk(char *, void (*fcn) (char *));

int main(int argc, char *argv[])
{
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);

    return 0;
}

void fsize(char *name)
{
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: нет доступа к %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("Имя файла %s, размер файла %8ld номер inode: %8lu\n",
            name, stbuf.st_size, stbuf.st_ino);

}

void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не могу открыть %s\n", dir);
        return;
    }

    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0
                || strcmp(dp->name, "..") == 0)
            continue;
        if (strlen(dir)+strlen(dp->name) + 2 >sizeof(name))
            fprintf(stderr, "dirwalk: слишком длинное имя %s/%s\n",
                    dir, dp->name);
        else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}






