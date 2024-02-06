#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80

int main(void)
{
	int c;
	int line_length = 0;

	while ((c = getchar()) != EOF) {
		if (iscntrl(c) && c != '\n') {
			printf("\\%o", c);
			line_length += 4;
		} else {
			putchar(c);
			line_length++;
		}

		if (line_length >= MAX_LINE_LENGTH) {
			putchar('\n');
			line_length = 0;
		}
	}

	return 0;
}


