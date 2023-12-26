#include <stdio.h>
#define MAX 5
void copy(const int n, int ar1[], int ar2[], int ar3[]);

int main(void)
{
	int mas1[MAX] = {1,2,3,4,5};
	int mas2[MAX] = {1,2,3,4,5};
	int mas3[MAX];
	copy(MAX, mas1, mas2, mas3);

	for(int i = 0; i < MAX; i++)
		printf ("%d ", mas3[i]);
	printf ("\n");
}

void copy(const int n, int ar1[], int ar2[], int ar3[])
{
	for(int i = 0; i < n; i++)
		ar3[i] = ar1[i] + ar2[i];
}

