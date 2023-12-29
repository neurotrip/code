#include <stdio.h>

int atoi(char s[]);

int main(void)
{
	char input[] = "12345";
	int result = atoi(input);

	printf ("Int: %d\n", result);

	return 0;
}

int atoi(char s[]) 
{
	int n = 0;
	while (*s >= '0' && *s <= '9') {
		n = 10 * n + (*s - '0');
		++s;
	}

	return n;
}

		
