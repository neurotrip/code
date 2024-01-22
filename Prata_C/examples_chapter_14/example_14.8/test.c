#include <stdio.h>
#include <stdlib.h>

#define len 10
#define max 20

int main(void)
{
	
	char **array = (char **)malloc(len * sizeof(char *));
	char **ptr;
	array[0] = "Privet mir\n";
    array[1] = "Eto massiv ukazateley na stroki\n";
    array[2] = "Мы можем хранить здесь разные строки.\n";
    array[3] = "А это уже четвертая строка.\n";
    array[4] = "И последняя, пятая строка.\n";
	ptr = array;

	while (*ptr) {
		printf ("%s", *ptr);
		ptr++;
	}
	printf ("%c\n", array[0][2]);	
	free(array);

	return 0;
}

