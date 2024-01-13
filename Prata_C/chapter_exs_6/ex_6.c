#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[100];
	printf ("Введите слово\n");
	scanf ("%s", word);
	int i;
	int len;
	len = strlen(word);
	printf ("Слово наоборот\n");
	for (i = len - 1; i >= 0; i--){
		printf ("%c", word[i]);
	}
	printf ("\n");
	return 0;
}
