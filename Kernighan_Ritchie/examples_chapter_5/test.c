#include <stdio.h>
#include <string.h>
void nstrcpy(char *s, char *t);

int main(void)
{
	char amas[] = "kak dela?";
	char bmas[sizeof(amas)];
	nstrcpy(bmas, amas);
	printf ("%s\n", bmas);
	return 0;
}

void nstrcpy(char *s, char *t)
{
	while (*s++ = *t++) 
		;
}

