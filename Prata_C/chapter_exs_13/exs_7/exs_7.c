#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char ch;
	printf("Вывод\n");
	FILE *file1, *file2;

	file1 = fopen(argv[1], "r");
	if (file1 == NULL) {
		exit(EXIT_FAILURE);
	}

	file2 = fopen(argv[2], "r");
	if (file2 == NULL) {
		exit(EXIT_FAILURE);
	}

	fseek(file1, 0, SEEK_END);
    fseek(file2, 0, SEEK_END);
    long size1 = ftell(file1);
    long size2 = ftell(file2);

    // Перемотка файлов обратно в начало
    rewind(file1);
    rewind(file2);


    FILE *largerFile = (size1 > size2) ? file1 : file2;
	char la;
	while ((la = fgetc(largerFile)) != EOF) {
		while ((ch = fgetc(file1)) != EOF) {
			fputc(ch, stdout);
			if (ch == '\n')
				break;
		}
		
		while ((ch = fgetc(file2)) != EOF) {
              fputc(ch, stdout);
              if (ch == '\n')
                  break;
        }
		
		
	}
	fclose(file1);
	fclose(file2);

	return 0;
}

			

