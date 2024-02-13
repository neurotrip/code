#include <stdio.h>
#include <string.h>

#define MAX 10
int bintoint(char *);

int main(void)
{
    char bin_str[MAX];
    int number;

    puts("Введите двоичные числа и просмотрите их десятичное представления.");
    while (fgets(bin_str, MAX, stdin) != NULL)
    {
		if (bin_str[strlen(bin_str) - 1] == '\n') {
			bin_str[strlen(bin_str) - 1] = '\0';
		}
        number = bintoint(bin_str);
        printf("%s представляется как ", bin_str);
        printf ("%d в десятичной форме\n" , number);
    }
    puts("Программа завершена.");

    return 0;
}

int bintoint(char * pb)
{
    int i;
	int number = 0;
    int size = strlen(pb);

    for (i = size - 1; i >= 0; i--) {
		if (pb[i] == '1') {
			number += 1 << (size - 1 - i);
		}
	}


    return number;
}




