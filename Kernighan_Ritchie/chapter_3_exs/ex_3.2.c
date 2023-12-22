#include <stdio.h>
#include <string.h>
#define MAX 1000
void escape(char s[],char t[]);
void escape2(char s[], char t[]);
int main(void)
{
	int i;
	char mass_1[MAX];
	char  mass_2[MAX];
	printf ("Введите первый массив\n");
	for (i = 0; (mass_1[i] = getchar()) != EOF; i++) {
	}
	
   	escape (mass_1, mass_2);
   	printf ("\nВторой массив:\n");
 	for (i = 0; i < strlen(mass_2); i++) 
        	printf ("%c", mass_2[i]);
    	printf ("\n");
   	return 0;
}
void escape2(char s[], char t[]) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        i++;
    }
    t[j] = '\0';
}


void escape(char s[], char t[])
{
	int i, j;

	for (i = 0, j = 0; i < strlen(s); i++, j++)
	{
		switch(s[i])
		{
			case '\t' : 
				t[j] = '\\';			
				t[j+1] = 't';
				j++;
				break;
			case '\n' :
				t[j] = '\\';
				t[j+1] = 'n';
				j++;
				break;
			default :
				t[j] = s[i];
				break;	
		}
	}
	t[j] = '\0';
}
