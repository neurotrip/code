#include <stdio.h>
#include <stdbool.h>
bool fun(char *, char);

int main() 
{
	char string[] = "Privet";
	char ch = 'v';
	bool result = fun(string, ch);
	
	if (result == 0)
		printf ("Символ не найден\n");
	else 
		printf
			("Символ найден\n");

}

bool fun(char *str, char c)
{
	while(*str != '\0')
	{
		if(*str == c)
			return 1;
		str++;
	}

	return 0;
}

