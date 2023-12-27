#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

double getfloat(double *pn);
int getch(void);
void ungetch(int c);

int main(void)
{
    double number;

    printf("Введите целое число: ");
    if (getfloat(&number))
        printf("Прочитанное число: %lf\n", number);
    else
        printf("Ошибка ввода\n");

    return 0;
}

double getfloat(double *pn)
{
    int c, sign;
    double power = 1.0;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.')
    {
        c = getch();
        for (; isdigit(c); c = getch())
        {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
    }

    *pn *= sign/power;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
	
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}

