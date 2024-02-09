#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0666
#define BUFSIZE 1024
#define OPEN_MAX 20

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} fILE;

enum flags { _rEAD = 01, _wRITE = 02, _uNBUF = 04, _eOF = 010, _eRR = 020 };

fILE _iob[OPEN_MAX] = { { 0, (char *) 0, (char *) 0, _rEAD, 0 },
                        { 0, (char *) 0, (char *) 0, _wRITE, 1 },
                        { 0, (char *) 0, (char *) 0, _wRITE | _uNBUF, 2 } };

fILE *fOpen(char *name, char *mode);
int _fillbuf(fILE *fp);
int fClose(fILE *fp);
int main()
{
	fILE *fp = fOpen("test.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "Не могу открыть файл\n");
		exit(EXIT_FAILURE);
	}

	int c;

	while ((c = _fillbuf(fp)) != EOF) {
		putchar(c);
	}

	fClose(fp);

	return 0;
}

fILE *fOpen(char *name, char *mode)
{
	int fd;
	fILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a') 
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_rEAD | _wRITE)) == 0)
			break;

	if (fp >= _iob + OPEN_MAX)
		return NULL;

	if (*mode == 'w') 
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else 
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return NULL;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _rEAD : _wRITE;
	return fp;
}

int _fillbuf(fILE *fp) 
{
	int bufsize;

    if ((fp->flag&(_rEAD | _eOF | _eRR)) != _rEAD)
        return EOF;
    bufsize = (fp->flag & _uNBUF) ? 1 : BUFSIZE;
    if (fp->base == NULL)
        if ((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _eOF;
        else
            fp->flag |= _eRR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char)*fp->ptr++;
}

int fClose(fILE *fp)
{
	if (fp == NULL)
		return EOF;
	if (fp->flag & _wRITE) {
		if (fp->ptr != NULL) {
			write(fp->fd, fp->base, fp->ptr - fp->base);
		}
	}

	close(fp->fd);
	free(fp->base);
	fp->cnt = 0;
	fp->ptr = NULL;
	fp->base = NULL;
	fp->flag = 0;
	fp->fd = 0;

	return 0;
}

