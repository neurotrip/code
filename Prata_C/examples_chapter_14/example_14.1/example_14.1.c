#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void) 
{
	struct book library;

	printf("Введите название книги.\n");
	gets(library.title);
	printf("Теперь введите ФИО автора.\n");
	gets(library.author);
	printf("Теперь введите цену.\n");
	scanf("%f", &library.value);
	printf("%s от %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
	printf("Готово.\n");

	return 0;
}


