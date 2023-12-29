#include <stdio.h>
#include <string.h>
void fit(char *, unsigned int);

int main(void)
{
	char mesg[] = "Вещи должны быть максимально простыми, "
			"но никак не проще. ";

	puts(mesg);
	fit(mesg, 37);
	puts(mesg);
	puts("Рассмотрим еще несколько строк.");
	puts(mesg + 38);

	return 0;
}

void fit(char *string, unsigned int size)
{
	if (strlen(string) > size)
		*(string + size) = '\0';
}

