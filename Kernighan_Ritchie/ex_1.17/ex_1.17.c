#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000
int main()
{
	char line[MAX_LENGTH];
	int c;
	while ((c= getchar()) != EOF ){

		fgets(line, MAX_LENGTH, stdin);

		if (strlen(line)  > 80){
			printf("Строка больше 80: %s", line);
		}
	}


	return 0;


}
