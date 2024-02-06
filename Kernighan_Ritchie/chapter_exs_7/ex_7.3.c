#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main() 
{
	int n = 16;
	double pi = 3.14159123918;
	char *str = "Hello, world!";
	char sym = 'a';
	minprintf("Int: %d\n", n);
	minprintf("Double %f\n", pi);
	minprintf("String: %s\n", str);
	minprintf("Char: %c\n", sym);
	minprintf("16int: %x\n", n);
	return 0;
}

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	char cval;
	va_start(ap, fmt);

	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			case 'c':
				cval = va_arg(ap, int);
				char charc = (char)cval;
				printf("%c", charc);
				break;
			case 'x':
				ival = va_arg(ap, int);
				printf("%x", ival);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}

		
