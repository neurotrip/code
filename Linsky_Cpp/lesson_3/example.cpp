#include <stdio.h>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main() 
{
	int x = 3;
	int y = 4;
	printf("x = %d y = %d x(adr) = %p y(adr) = %p\n",x,y,&x,&y);
	swap(x, y);
	printf("\n");
	
	printf("x = %d y = %d x(adr) = %p y(adr) = %p\n",x,y,&x,&y);

	return 0;
}

