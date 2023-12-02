#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower =0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf ("Таблица\n");
    while (fahr <= upper) 
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf ("%6.1f %6.0f\n", celsius, fahr);
        fahr = fahr + step;
    }
}