#include <stdio.h>

int lower(int c);

int main()
{
    int c;
    
    while((c=getchar()) != EOF)
        putchar(lower(c));
    return 0;
}


int lower(int c)
{
    (c>='A' && c<='Z')? c = c + 'a' - 'A' : c;
    return c;
}
