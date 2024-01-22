#include <stdio.h>
#define MAXTITL 40
#define MAXAUTL 40
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
	int index;

	printf("Введите название книги.\n");
	printf("Нажмите [enter] в начале строки для выхода.\n");

	while (count < MAXBKS && gets(library[count].title) != NULL
						  && library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		gets(library[count].author);
		printf("Теперь введите цену книги.\n");
		scanf("%f", &library[count++].value);

		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}

	if (count > 0)
	{
		printf("Каталог ваших книг:\n");
		for (index = 0; index < count; index++)
			printf("%s от %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
	}
	else {
	printf("Вообще нет книг? Очень плохо.\n");
	}
	
	return 0;
}

