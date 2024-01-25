#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 100
#define MAXAUTL 100
#define MAXBKS 100
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void delbook(struct book library[],char searchTitle[],FILE *pbooks, int *count);
void editbook(struct book library[], FILE *pbooks, int *index);

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
    else {
        puts("Вообще нет книг? Очень плохо.\n");
	}

    fclose(pbooks);

	
	char choice[10];
	printf ("Хотите отредактировать библиотеку?\n");
	fgets(choice, 10, stdin);
	
	if (choice[0] == 'y')
	{
		int found = 0;
		pbooks = fopen("book.dat", "r+b");
		printf("Напишите название книги\n");
		char searchTitle[MAXTITL];
		fgets(searchTitle, MAXTITL, stdin);
    	searchTitle[strcspn(searchTitle, "\n")] = '\0';

		for (index = 0; index < count; index++) {
        if (strcmp(library[index].title, searchTitle) == 0) {
            printf("Книга найдена: %s\n", library[index].title);
            found = 1;
            break;
            }
        }

		if (found) {
			printf ("1) Удаление  2) Редактирование\n");
			int mode = 0;
			scanf("%d", &mode);
			while (getchar() != '\n') continue;
				if (mode == 1)
					delbook(library, searchTitle, pbooks, &count);
				else if (mode == 2) {
					editbook(library, pbooks, &index);
			}

		}
	}	
	else 
		printf("Конец\n");

    return 0;
}


void delbook(struct book library[],char searchTitle[],FILE *pbooks, int *count)
{
	int index = 0;
    struct book tempLibrary[MAXBKS];
    int tempCount = 0;

        // Копирование всех книг, кроме удаляемой, во временный массив
    for (int i = 0; i < *count; i++) {
		if (i != index) {
			tempLibrary[tempCount++] = library[i];
            }
        }

        // Перезапись файла book.dat данными из временного массива
        freopen("book.dat", "wb", pbooks);
        if (pbooks != NULL) {
            fwrite(tempLibrary, sizeof(struct book), tempCount, pbooks);
            fclose(pbooks);
        }

        // Обновление основного массива и количества книг
        memcpy(library, tempLibrary, sizeof(tempLibrary));
        *count = tempCount;
    

}

void editbook(struct book library[], FILE *pbooks, int *index)
{
	printf("Поменяйте название книги\n");
	fgets(library[*index].title, MAXTITL, stdin);
	library[*index].title[strcspn(library[*index].title, "\n")] = '\0';

	printf("Поменяйте название автора\n");
	fgets(library[*index].author, MAXAUTL, stdin);
	library[*index].author[strcspn(library[*index].author, "\n")] = '\0';

	printf("Поменяйте цену книги\n");
	scanf("%f", &library[*index].value);
	while (getchar() != '\n') continue;

	fseek(pbooks, *index * sizeof(struct book), SEEK_SET);
	fwrite(&library[*index], sizeof(struct book), 1, pbooks);
	fclose(pbooks);
}	
