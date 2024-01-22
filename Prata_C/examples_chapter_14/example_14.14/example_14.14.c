#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 100
#define MAXAUTL 100
#define MAXBKS 100
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
		fputs("Не удается открыть файл book.dat\n", stderr);
		exit(1);
	}

	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
		if (count == 0)
			puts("Текущее содержимое файла book.dat:");
		printf("%s by %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);
		count++;
	}
	
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("Файл book.dat заполнен.",stderr);
		exit(2);
	}

	puts("Введите названия новых книг.");
	puts("Нажмите [enter] в начале строки для выхода из программы.");
	while (count < MAXBKS && gets(library[count].title) != NULL
						  && library[count].title[0] != '\0')
	{
		puts("Теперь введите имя автора.");
		gets(library[count].author);
		puts("Теперь введите цену книги. ");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Введите название следующей книги.");
	}

	if (count > 0)
	{
		puts("Каталог ваших книг:");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else 
		puts("Вообще нет книг? Очень плохо.\n");
	puts("Всего доброго.\n");
	fclose(pbooks);

	return 0;
}

