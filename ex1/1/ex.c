#include <stdio.h>

int main()
{
    int c;
    int summ_space = 0;
    int summ_tab = 0;
    int summ_ns = 0;
    while ((c = getchar()) != EOF)
    {
    if (c ==' ') ++summ_space;
    if (c =='\t') ++summ_tab;
    if (c =='\n') ++summ_ns;
    }
    printf ("summ_space =%d\nsumm_tab%d\nsumm_ns=%d\n",summ_space,summ_tab,summ_ns );
    return 0;
}