#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int myscanf(const char *fmt, ...);

int main(void)
{
	int n;
	char str[100];

	printf("Введите int, string:");
	int charsRead = myscanf("%d %s", &n, str);

	if (charsRead == 2) {
		printf("Вы ввели: int %d, string %s\n", n, str);
	} else {
		printf("Ошибка ввода");
	}

	return 0;	
}

int myscanf(const char *fmt, ...) 
{
	va_list ap;
	va_start(ap, fmt);
	int ival;
	char *strArg;
	int charsRead = 0;
	const char *p = fmt;

	while (*p) {
		if (*p != '%') {
			putchar(getchar());
			p++;
		}

		p++;

		switch (*p) {
			case 'd':
				{
					ival = va_arg(ap, int);
					if (scanf("%d", &ival) == 1) {
						charsRead++;
					}
				}
				break;
			case 's':
				{
					strArg = va_arg(ap, char *);
					if (scanf("%s", strArg) == 1) {
						charsRead++;
					}
				}
				break;
			default:
				break;
		}
		p++;
	}
	va_end(ap);
	return charsRead;
}

