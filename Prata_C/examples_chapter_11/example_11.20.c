#include <stdio.h>
#include <string.h>
#define LISTSIZE 5
int main()
{
	const char * list[LISTSIZE] = 
	{
		"astronomy", "astounding",
		"astrophysics", "ostracize",
		"asterism"
	};
	int count = 0;
	int i;

	for (i = 0; i < LISTSIZE; i++)
		if (strncmp(list[i], "astro", 5) == 0)
		{
			printf ("Найдено: %s\n", list[i]);
			count++;
		}
	printf ("Список содержит %d слов(o,a), начинающихся с astro.\n", count);

	return 0;
}

