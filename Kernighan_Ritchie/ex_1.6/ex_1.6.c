#include <stdio.h>

main() 
{
int c;
c = (getchar() != EOF);
if (c == 0)
    printf("0");
if (c == 1)
    printf("1");
}