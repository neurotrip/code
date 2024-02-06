#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 1000
#define MAXLINES 5000

char *lineptr[MAXLINES];
int ngetline(char *, int); 
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void nqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int rev_numcmp(const char *, const char *);
int revcmp(const char *, const char *);
int frevcmp(const char *, const char *);
int fcmp(const char *, const char *);

void swap(void *v[], int i, int j);


int main(int argc, char *argv[])
{
    	int nlines;
    	int numeric = 0;
	int reverse = 0;
	int fallout = 0;
	for (int i = 1; i < argc; i++) {
        	if (strcmp(argv[i], "-n") == 0) {
            		numeric = 1;
       	 	} else if (strcmp(argv[i], "-r") == 0) {
            		reverse = 1;
        	} else if (strcmp(argv[i], "-f") == 0) {
			fallout = 1;
		}

		
    	}
    	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		printf ("Вывод\n");
		int (*comp)(void *, void *);
        	if (numeric) {
            		comp = (reverse ? rev_numcmp : numcmp);
        	} else {
			if (fallout)
			{
				comp = (reverse ? frevcmp : fcmp);
			}
			else {
            			comp = (reverse ? revcmp : strcmp);
			}

        	}
        	nqsort((void **)lineptr, 0, nlines - 1, comp);
       		writelines(lineptr, nlines);
		return 1;
    	} else {
        	printf ("Введено слишком много строк\n");
        	return 1;
    	}
}


int readlines(char *lineptr[], int maxlines) {
    	int len, nlines;
    	char line[MAXLEN];

    	nlines = 0;
    	while ((len = ngetline(line, MAXLEN)) > 0) {
        	if (nlines >= maxlines) {
            		return -1; // Слишком много строк
        	} else {
            	line[len - 1] = '\0'; // Убираем символ новой строки
            	lineptr[nlines++] = strdup(line);
        	}
    	}

    	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    	for (int i = 0; i < nlines; i++) {
        	printf("%s\n", lineptr[i]);
    	}
}

void nqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    	int i, last;

    	if (left >= right) {
        	return;
   	 }

   	swap(v, left, (left + right) / 2);
    	last = left;

    	for (i = left + 1; i <= right; i++) {
        	if ((*comp)(v[i], v[left]) < 0) {
            	swap(v, ++last, i);
        	}
    	}

    	swap(v, left, last);
    	nqsort(v, left, last - 1, comp);
    	nqsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    	void *temp;
    	temp = v[i];
    	v[i] = v[j];
    	v[j] = temp;
}

int numcmp(const char *s1, const char *s2)
{
    	double v1, v2;

    	v1 = atof(s1);
    	v2 = atof(s2);

    	if (v1 < v2) {
        	return -1;
    	} else if (v1 > v2) {
        	return 1;
    	} else {
        	return 0;
    	}	
}

int ngetline(char *s, int lim)
{
    	int c, i;

    	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        	s[i] = c;
    	}

    	if (c == '\n') {
        	s[i++] = c;
    	}

    	s[i] = '\0';
    	return i;
}
int revcmp(const char *s1, const char *s2) 
{
    return -strcmp(s1, s2);
}
int frevcmp(const char *s1, const char *s2)
{
	return -fcmp(s1, s2);
	
}
int fcmp(const char *str1, const char *str2) 
{
//    	const char *str1 = *(const char **)s1;
//    	const char *str2 = *(const char **)s2;

    	while (tolower((unsigned char)*str1) == tolower((unsigned char)*str2)) {
        	if (*str1 == '\0') {
            		return 0;
        	}
        	str1++;
        	str2++;
    }

    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}
int rev_numcmp(const char *s1, const char *s2)
{
        double v1, v2;

        v1 = atof(s1);
        v2 = atof(s2);

        if (v1 < v2) {
                return 1;
        } else if (v1 > v2) {
                return -1;
        } else {
                return 0;
        }
}


