#include <stdio.h>
#include <stdlib.h>
#define STR 100
#define COL 1000
int main(int argc, char *argv[])
{
	FILE * fp;
	int i = 2;
	char ch;
	char sym = argv[1][0];
	int count = 0;
	char mas[STR][COL];
	int str = 1;
	int b = 0;
	int mas_2[1000];
	if (argc < 3) {
		int j, k;
		printf ("Введите какое-то количество строк\n");
		for (j = 0; fgets(mas[j],COL, stdin) != NULL; j++) {
			for (k = 0; (ch = mas[j][k]) != '\0'; k++)	{
				if (ch == sym)
					count++;
			}
			mas_2[j] = count;
			count = 0;
		}
		while (b < j) {

			printf ("В строке %d символов %c найдено %d штук\n", str, sym, mas_2[b]);
			str++;
			b++;
		}
		
	}
	else {
	

		while (i < argc)
			{
				fp = fopen(argv[i], "r");
				if (fp == NULL) {
					printf ("Не удается открыть файл %s, перехожу к следующему\n", argv[i]);
					i++;
					continue;
				}

				while ((ch = getc(fp)) != EOF) {
					if (ch == sym)
						count++;
				}

				printf ("В файле %s символов %c найдено %d\n", argv[i], sym, count); 
				i++;
				count = 0;
				fclose(fp);
			}
			i = 2;
	}
	printf ("Файлов больше нет, конец\n");	
	
	return 0;
}

	
		
