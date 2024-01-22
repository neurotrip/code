#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char *string;
	char *sub = argv[1];
	
	fp  = fopen(argv[2], "r");

	char *pos;
	while (fgets(string, sizeof(string), fp)) {
		pos = strstr(string, sub);
		if (pos != NULL)
		{
			printf ("Найдена подстрока\n");
			printf ("%s", string);
		}
	}

	fclose(fp);
	return 0;
}


