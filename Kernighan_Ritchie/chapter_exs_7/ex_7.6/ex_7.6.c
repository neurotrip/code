#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	FILE *fp1;
	FILE *fp2;
	char buffer1[100];
	char buffer2[100];
	
	fp1 = fopen(argv[1], "r");
	if (!fp1) {
		printf("Не удается открыть файл %s\n", argv[1]);
		return 1;
	}
	fp2 = fopen(argv[2], "r");
	if (!fp2) {
		printf("Не удается октрыть файл %s\n", argv[2]);
		return 1;
	}

	while (fgets(buffer1, sizeof(buffer1), fp1) != NULL &&
				fgets(buffer2, sizeof(buffer2), fp2) != NULL) {
		if (strcmp(buffer1, buffer2) != 0) {
			printf("Первая отличающаяся строка: %s\n", buffer1);
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
	}		
	fclose(fp1);
	fclose(fp2);

	printf("Файлы одинкаковы\n");
	return 0;
}
