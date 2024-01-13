#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int * pa;
	int size;
	int value;

	printf ("Введите количество элементов: ");
	scanf("%d", &size);

	while (size > 0)
	{
		printf ("Введите значение для инициализации: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf ("Введите количество элементов (или значение < 1 для выхода из программы): ");
		scanf ("%d", &size);
	}
	printf ("The end\n");

	return 0;
}

int * make_array(int elem, int val)
{
	int *arr = (int*)malloc(elem * sizeof(int));
	int *base = arr;
	while (elem)
	{
		*arr++ = val;
		elem--;
	}
	
	return base;
}

void show_array(const int ar[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		printf (" %d ", ar[i]);
		if ((i + 1) % 8 == 0) {
			printf ("\n");
		}
		
	}
	if (n % 8 != 0) 
		printf ("\n");
}

