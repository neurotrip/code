#include <stdio.h>


int bitcount(unsigned x);

int main()
{
    int x;
    
    printf("Enter the number\nx: ");
    scanf("%d", &x);

    printf("%d\n", bitcount(x));
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    
    for(b = 0; x != 0; b++)
        x &=(x-1);
    return b;
}
