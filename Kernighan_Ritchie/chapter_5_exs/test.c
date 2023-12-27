#include <stdio.h>

int main(void)
{
	int a[5]={1,2,3,4,5};
	int *pa;
	pa = a;

	printf ("%d %d %d\n",*pa,*(pa+1), *(pa-1));

	return 0;
}

