#include <stdio.h>
#include <string.h>
#define ANSWER "Грант"
int main(void)
{
	char try[40];

	puts("Кто похоронен в могиле Гранта?");
	gets(try);
	while (strcmp(try, ANSWER) != 0)
	{
		puts("Нет, неправильно. Попытайся еще раз.");
		gets(try);
	}

	puts("Теперь правильно!");

	return 0;
}

