#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void find_pattern(FILE *, const char *, const char *);

int main(int argc, char *argv[])
{
	char *pattern;
	FILE *fp;

	pattern = argv[1];

	if (argc == 2) 
		find_pattern(stdin, "stdin", pattern);
	else {
		for (int i = 2; i < argc; i++) {
			if ((fp = fopen(argv[i], "r")) == NULL) {
				fprintf(stderr, "Не удаётся открыть файл %s\n", argv[i]);
				continue;
			}
			find_pattern(fp, argv[i], pattern);
			fclose(fp);
		}
	}

	return 0;
}

void find_pattern(FILE *stream, const char *filename, const char *pattern)
{
	char line[MAXLINE];
	int found = 0;

	while (fgets(line, MAXLINE, stream) != NULL) {
		if (strstr(line, pattern) != NULL) {
			printf("%s: %s\n", filename, line);
			found = 1;
		}
	}

	if (found) {
		printf("--Найдено в файле-- %s\n", filename);
	}
}

