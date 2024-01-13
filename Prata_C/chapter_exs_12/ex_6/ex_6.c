#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
        srand((unsigned int)time(NULL));
        int n = 1000;
	int i;
        int mas[n];
        int counts[11] = {0};
        for (i = 0; i < n; i++)
        {
                mas[i] = rand() % 11;
		counts[mas[i]]++;
        }

        printf ("Повторение чисел\n");
        for (i = 0; i < 11; i++)
        {
		if (counts[i] > 1) {
                	printf ("Число %d повторяется %d раз\n", i, counts[i]);
		}

        }

        return 0;
}

