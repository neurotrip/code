#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ch;
	long count = 0;
	FILE *fp;
	if (argc != 2)
	{
		printf ("Исползование: %s filename\n", argv[0]);
		exit(1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf ("Не удаётся открыть %s\n", argv[1]);
		exit(1);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("Файл %s содержит %ld символов\n", argv[1], count);

	return 0;
}

