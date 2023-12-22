#include <stdio.h>

int binsearch( int x, int v[], int n);

int main()
{
	int xx= 15;
	int vv[10]={ 1, 3, 4, 7, 15, 18, 33, 34, 67, 88 };
	int nn=10;
	int pos;
	pos = binsearch(xx, vv, nn);
	printf ("Значение %d имеет индекс %d\n", xx, pos);
	return 0;
}


int binsearch(int x, int v[], int n)
{
	 int low, high, mid;
	 low = 0;
	 high = n - 1 ;
	 while (low <= high) {
		 mid = (low + high) / 2;
		 if (x < v[mid])
		 	high = mid - 1;
		 else if (x > v[mid])
 			low = mid + 1 ;
		 else /* совпадение найдено */
		 return mid;
	 }
 return -1; /* совпадения нет */
}

