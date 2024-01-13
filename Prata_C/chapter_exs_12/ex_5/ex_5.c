#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
void qSort(int arr[], int left, int right);
int main(void)
{
	srand((unsigned int)time(NULL));
	int n = 100;
	int mas[n];
	int i;
	printf ("Произвольный массив\n");
	for (i = 0; i < n; i++)
	{
		mas[i] = rand() % 11;
		printf ("%d\n", mas[i]);
	}
	qSort(mas, 0, n - 1);
	printf ("Отсортированный массив\n");
	for (i = n - 1; i >= 0; i--)
	{
		printf ("%d\n", mas[i]);
	}

	return 0;
}

void swap(int *a, int *b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

void qSort(int arr[], int left, int right)
{
	if(left>right) 
		return;

	int p = arr[(left+right)/2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (arr[i] < p) 
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}

	qSort(arr, left, j);
	qSort(arr, i, right);
}

