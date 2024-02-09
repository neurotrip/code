#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t n, size_t size);

int main()
{
	int *arr;
	size_t n = 5;

	arr = (int *)my_calloc(n, sizeof(int));

	if (arr != NULL) {
		printf("Выделенная память инициализирована нулями:\n");
		for (size_t i = 0; i < n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		free(arr);
	} else {
		printf("Ошибка при выделении памяти\n");
	}

	return 0;
}

void *my_calloc(size_t n, size_t size)
{
	void *ptr = malloc(n * size);
	
	if (ptr != NULL) 
		memset(ptr, 0, n * size);

	return ptr;
}


	


