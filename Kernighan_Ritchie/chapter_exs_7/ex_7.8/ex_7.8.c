#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define PAGELEN 40

void print_file(FILE *fp, const char *filename);

int main(int argc, char *argv[])
{
	FILE *fp;

	while (--argc > 0) {
		if ((fp = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "Не удается открыть файл %s", *argv);
			exit(1);
		} else {
			print_file(fp, *argv);
			fclose(fp);
		}
	}

	return 0;

}

void print_file(FILE *fp, const char *filename) 
{
	static int page_number = 1;
	int line_count = 0;
	char line[MAXLINE];
	
	printf("\fЗаголовок %s, Страница: %d\n\n", filename, page_number++);

	while (fgets(line, MAXLINE, fp) != NULL) {
		if (line_count == PAGELEN) {
			printf("\fЗаголовок: %s, Страница %d\n\n", filename, page_number++);
			line_count = 0;
		}
		fputs(line, stdout);
		line_count++;
	}

	if (line_count > 0)
		printf("\f");
}
