#include <stdio.h>

main ()

{
    int space, tab, new_str = 0;
    int c;
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++space;
        if (c == '\t')
            ++tab;
        if (c == '\n')
            ++new_str;
    }
    printf ("\nspace = %d \ntab = %d \nnew_str = %d",space, tab, new_str );
}
