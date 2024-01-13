#include <stdio.h>

int main(void)
{
	char mass[26];
	int i;
	for (i = 97; i <= 122; i++) {
		mass[i] = i;
		printf ("%c\n", mass[i]);
	}
	return 0;
}


