#include <stdio.h>
int main(int argc, char *argv[])
{
	int count;

	printf ("В командной строке имеются %d аргументов:\n", argc - 1);

	for (count = 1; count < argc; count++)
		printf ("%d: %s\n", count, argv[count]);
	printf ("\n");

	return 0;
}

