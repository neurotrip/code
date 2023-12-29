#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define ALLOCSIZE 5000
#define MAXLEN 1000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n);
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(char *lineptr[], int left, int right);
int ngetline(char *s, int);
void qsort(char *v[], int left, int right);

int main(void)
{
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		my_qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf ("ошибка: слишком много строк\n");
		return 1;
	}
}

int ngetline(char *s, int lim)
{
	int c;
	int len = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*s = c;
		++s;
		len++;
	}

	if (c == '\n') {
		*s = c;
		++s;
		len++;
	}

	*s = '\0';

	return len;
}

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp -n;
	} else 
		return 0;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;

	while ((len = ngetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)		
		printf ("%s\n", *(lineptr++));
}

void my_qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	int nstrcmp(char *s, char *t);
	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (nstrcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	my_qsort(v, left, last - 1);
	my_qsort(v, last+1, right);
}

int nstrcmp(char *s, char *t)
{
	while (*s == *t) {
		if (*s == '\0')
			return 0;
		s++;
		t++;
	}
	return *s - *t;
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

