#include <stdio.h>
#include <ctype.h>

int htoi(const char s[]);

int main()
{
	char hexString[] = "0xff2a";
	int result = htoi(hexString);
	printf("В десятичной: %d\n", result);
	return 0;
}

int htoi(const char s[])
{
	int i, n;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
	i = 2;
	}
		else {
		i = 0;
		}
	n = 0;
	while (s[i] != '\0') {
		if (isdigit(s[i])) {
		n = 16 * n + (s[i] - '0');
		}
	       	else if (s[i] >= 'a' && s[i] <= 'f') {
		n = 16 * n + 10 + (s[i] - 'a');
		}
	       	else if (s[i] >= 'A' && s[i] <= 'F') {
		n = 16 * n + 10 + (s[i] - 'A');
		}
	       	else {
		break;
		}
		i++;
		}
	return n;
}


