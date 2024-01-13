#include <stdio.h>
int main(void)
{
	char ch;
	int j, k = 0;
	printf ("Введите символы\n");
	
	while((ch = getchar()) != EOF)
	{
		if (ch <= 'Z' && ch >= 'A')
	 		j++;
		if (ch <= 'z' && ch >= 'a')
			k++;
       }
	printf ("\n%d Верхнего регистра, %d нижниге регистра\n", j, k);
	
	return 0;
}

