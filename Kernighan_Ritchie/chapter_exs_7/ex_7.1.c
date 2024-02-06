#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;
	int toUpper = 0;
	if (strstr(argv[1], "upper") != NULL) {
		toUpper = 1;
	}

	while ((c = getchar()) != EOF) {
		if (toUpper)
			putchar(toupper(c));
		else 
			putchar(c);
	}
	return 0;
}


