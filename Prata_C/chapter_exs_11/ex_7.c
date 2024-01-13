#include <stdio.h>

char *string_in(char *s1, const char *s2);

int main(void)
{
	char m1[] = "hats";
	char m2[] = "at";
	char *result;

	result = string_in(m1, m2);
	if (result != NULL)
		printf ("Ответ: %p\n", result);
	else
		printf ("Не найдено\n");

	return 0;
}

char *string_in(char *s1, const char *s2)
{
	char *adress;
	char *s1start = s1;
	int count = 0;
	while (*s1 != '\0')
	{
		if (*s1 == *s2) {
			adress = s1;
			break;
		}
		s1++;
	}

	s1 = s1start;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if  (*s1 == *s2) {
		      	count++;
			s2++;
		}
		if (count >= 2)
			return adress;
		s1++;
	}
	return NULL;

}

		
