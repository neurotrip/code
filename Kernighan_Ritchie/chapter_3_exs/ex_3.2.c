#include <stdio.h>
#include <string.h>
#define MAX 1000
void escape(char s[], char t[]);

int main(void)
{
	int i;
	char mass_1[MAX];
	char  mass_2[MAX];
	printf ("Введите первый массив\n");
	for (i = 0; (mass_1[i] = getchar()) != EOF; i++) {}
//    	mass_1[i] = '\0';
   	escape (mass_1, mass_2);
   	printf ("\nВторой массив:\n");
 	for (i = 0; i < strlen(mass_2); i++) 
        	printf ("%c", mass_2[i]);
    	printf ("\n");
   	return 0;
}

void escape(char s[], char t[])
{
	int i;
	for (i = 0; i < strlen(s); i++)
	{
		switch(s[i])
		{
			case '\t' : 
				t[i] = '\\';
				t[i+1] = 't';
				i++;
				break;
			case '\n' :
				t[i] = '\\';
				t[i+1] = 'n';
				i++;
				break;
			default :
				t[i] = s[i];
				break;	
		}
	}
}
