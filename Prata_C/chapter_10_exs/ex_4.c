#include <stdio.h>
int max(int ar[], int n);

int main(void)
{
        int array[5] = {1,2,99,1488,3};
        printf ("Наибольший индекс  массива:%d\n", max(array,5));
        return 0;

}

int max(int ar[], int n)
{
        int i, j;
	int max = ar[0];
        for(i = 0, j = 1; i < n; i++) {
                if (ar[i] > max)
                {
                        max = ar[i];
			j++;
                }
        }
return j;
}


