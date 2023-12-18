#include <stdio.h>

int main(void)
{
	int c, i, n_white, n_other, n_digit[10];

	n_white = n_other = 0;
	for (i = 0; i < 10; i++)
		n_digit[i] = 0;
	while ((c = getchar()) != EOF) {
		switch (c) {
			case '0' : case '1' : case '2' : case '3' : case '4' :
			case '5' : case '6' : case '7' : case '8' : case '9' :
				n_digit[c - '0'] ++;
				break;
			case ' ' :
			case '\n' :
			case 't' :
				n_white++;
				break;
			default :
				n_other++;
				break;
		}
	}
	printf ("цифр =");
	for (i = 0; i < 10; i++)
		printf (" %d", n_digit[i]);
	printf (", симв-разд = %d, прочих = %d\n", n_white, n_other);
	return 0;
}

