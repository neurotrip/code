#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINE 100

/* примитивный калькулятор */
//double n_atof(char s[]);
int n_getline (char s[], int lim);
int main()
{
	 double sum;
//	 double sum, atof (char[]);
	 char line[MAXLINE];
//	 int n_getline (char line[], int max);
	 sum = 0;
	 while (n_getline(line, MAXLINE) > 0)
	 printf ("\t%g\n", sum += atof(line));
	 return 0;
}

//double n_atof(char s[])
//{
//	double val, power;
//	int i, sign;
//	for(i = 0; isspace(s[i]); i++)
//		val = 10.0 * val + (s[i] - '0');
//	sign = (s[i] == '-') ? -1 : 1;
//	if (s[i] == '.')
//		i++;
//	for (power = 1.0; isdigit(s[i]); i++) {
//		val = 10.0 *val + (s[i] - '0');
//		power *= 10.0;
//	}
//	double x = sign * val / power;
//	return x;
//}

int n_getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

