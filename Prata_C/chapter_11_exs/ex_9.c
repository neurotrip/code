#include <stdio.h>
#include <string.h>
#define SPACE ' '
#define MAX 100
void delspace(char string[]);

int main(void)
{
	char string[MAX];
	printf ("Введите строку или пустую строку для выхода\n");

	while (gets(string))
	{
//		string[strcspn(string, "\n")] = '\0';
		if (strcmp(string, "") == 0)
       			 {
            			break;
        			}
		printf ("Строка с пробелами %s\n", string);
		delspace(string);
		printf ("Строка без пробелов %s\n", string);

		printf ("Введите строку или пустую строку для выхода\n");

	}

	return 0;
}

void delspace(char string[])
{
	int i, j;
	for (i = 0, j = 0; i < strlen(string); i++)
	{
		
		if (string[i] != SPACE)
		{
			string[j] = string[i];
			j++;
			
		}
	}
	string[j] = '\0';

}


