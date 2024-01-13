#include <stdio.h>

int main(void)
{
	float duym;
	float sm;
	printf ("Введите рост в дюймах\n");
	scanf ("%f", &duym);
	sm = duym * 2.54;
	printf ("Рост в сантиметрах %f\n", sm);
	return 0;
}

