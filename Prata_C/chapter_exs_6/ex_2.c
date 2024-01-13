#include <stdio.h>

int main(void)
{
	int count;
	int count2;
	for (count = 0; count < 5; count++) {
		for (count2 = 0; count2 < count+1; count2++) {
			printf ("$\n");
		}
		printf ("\n");
	}

	return 0;
}

