#include <stdio.h>

void nsqueeze(char s1[], char s2[]);

int main()
{
	char str1[] = "hello";
	char str2[] = "world";

	nsqueeze(str1, str2);
	printf("%s\n", str1); // Вывод: "he"
	return 0;
}

void nsqueeze(char s1[], char s2[])
{
	int i, j, k;
	int is_present;

	for (i = j = 0; s1[i] != '\0'; i++) {
	is_present = 0;
		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k]) {
			is_present = 1;
			break;
			}
		}
			if (!is_present) {
			s1[j++] = s1[i];
			}
	}
	s1[j] = '\0';
}
