#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

int getint(int *pn);
int getch(void);
void ungetch(int);

int main(void)
{
        int number;

        printf ("Введите целое число: ");
        if (getint(&number))
                printf ("Прочитанное число: %d\n", number);
        else
                printf ("Ошибка ввода\n");

        return 0;

}

int getint(int *pn)
{
        int c, sign;
        while (isspace(c=getch()))
                ;
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);
                return 0;
        }
	


        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-') {
                c = getch();
		if(!isdigit(c))
		{
			ungetch((sign == 1) ? '+' : '-');
            		return 0;
		}
	}
        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        if (c != EOF)
                ungetch(c);
        return c;
}

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c )
{
        if (bufp >= BUFSIZE)
                printf ("ungetch: слишком много символов\n");
        else
                buf[bufp++] = c;
}


