#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	int i = 1;
	while (i < argc) {
   		if ((fp = fopen(argv[i], "r")) == NULL) {
			printf ("Не удаётся открыть файл %s \n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	
	i = 1;

	while (i < argc) {
		fp = fopen(argv[i], "r");
		printf("Содержимое файла %s\n", argv[i]);
		while ((ch = fgetc(fp)) != EOF) {
			fputc(ch, stdout);
		}
		printf("\n");
		i++;
	}
	i = 1;
	while (i < argc) {
		fp = fopen(argv[i], "r");
		fclose(fp);
		i++;
	}

	return 0;
}

			

