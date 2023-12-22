#include <stdio.h>
#include <string.h>
#define MAX 1000
int main(void)
{
	char ch[MAX];
	int i;
	printf ("Введите символы\n");
	for(i = 0; (ch[i] = getchar()) != EOF; i++) {
		if (ch[i] == '\n')
			i--;
	}
	for(i = 0; i < strlen(ch); i++)
		printf ("%d  ", ch[i]);
		
	printf ("\nСимволов:%d\n ", i);

	return 0;
}

