#include <stdio.h>
int max(int ar[], int n);

int main(void)
{
        int array[5] = {1,2,99,1488,3};
        printf ("Разность наибольшего и наименьшего:%d\n", max(array,5));
        return 0;

}

int max(int ar[], int n)
{
        int i;
        int max = ar[0];
	int min = ar[0];
        for(i = 0; i < n; i++) {
                if (ar[i] > max)
                {
                        max = ar[i];
                }
        }
	for(i = 0; i < n; i++) {
		if (ar[i] < min)
		{
			min = ar[i];
		}
	}
	int rz = max - min;
return rz;
}


