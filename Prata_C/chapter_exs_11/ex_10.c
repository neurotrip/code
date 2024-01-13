#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGHT 10
#define MAX 100

void menu();
void printOriginalList(char **str);
int main(void)
{
	char *string[LENGHT];
//	char buffer[MAX];
	char **input = string;
	*input= (char*)malloc(MAX);
	printf ("Введите не более 10 строк\n");
	
	while(fgets(*input, MAX, stdin) != NULL)
		*input++;	




//	while (input < string + LENGHT && fgets(buffer, MAX, stdin) != NULL)	
//	{
//	
//		*input++ = strdup(buffer);
//		
//	       	
//	}
//	menu();

	
	printOriginalList(string);

	return 0;	
	
}

void menu()
{
    printf("Выберете одно из предложенных действий\n");
    printf("1. Печать исходного списка строк\n");
    printf("2. Печать строк в виде упорядоченной последовательности\n");
    printf("3. Печать строк в порядке возрастания их длины\n");
    printf("4. Печать строк в порядке возрастания длины первого слова строки\n");
    printf("5. Выход\n");

}
void printOriginalList(char **str)
{
    while (*str != NULL)
    {
        fputs(*str++, stdout);
    }
}

