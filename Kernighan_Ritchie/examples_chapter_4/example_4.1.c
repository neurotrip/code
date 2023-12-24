#include <stdio.h>
#define MAXLINE 1000

int n_getline(char line[], int max);
int strindex(char source[], char searhfor[]);
char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;
	while (n_getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf ("%s SUKA", line);
			found++;
		}
	return found;
}

int n_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;

	for(i=0; s[i] != '\0'; i++) {
		for(j = 1, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}


