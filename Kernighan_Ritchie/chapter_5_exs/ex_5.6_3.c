#include <stdio.h>
#include <string.h>
void reverse (char s[]);
void itoa (int n, char s[]);

int main() 
{
	int number = -12345;
	char result[20];

	itoa(number, result);

	printf ("String %s\n", result);

	return 0;
}

void itoa(int n, char s[])
{
	int sign;
	char *p = s;
	if ((sign = n) < 0)
		n = -n;

	

	do {
		*p++ = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		*p++ = '-';

	*p = '\0';
	reverse(s);

}

void reverse(char s[])
{
	char * start = s;
	char * end = s + strlen(s) - 1;
	char temp;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		++start;
		--end;
	}
}

