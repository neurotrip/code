#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int ngetline(char *line, int max);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c = 0, except = 0, number = 0, found = 0;
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf ("find неверный параметр\n");
				//	argc = 0;
				//	found = -1;
					return 1;
				//	break;
			}

	if (argc != 1)
		printf ("Используйте в find образец\n");
	else
		while (ngetline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except){
				if (number)
					printf ("%ld:", lineno);

				printf ("%s", line);
				found++;
			}
		}


	return found;
}

int ngetline(char *line, int max) {
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *line++ = c;

    if (c == '\n') {
        *line++ = c;
        ++i;
    }

    *line = '\0';

    return i;
}
