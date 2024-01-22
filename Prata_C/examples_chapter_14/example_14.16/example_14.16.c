#include <stdio.h>
#include <string.h>
#include <ctype.h>

char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void)
{
	char line[81];
	char copy[81];
	char choice;
	void (*pfun)(char *);


	puts("Введите строку, пустая - выход");
	while (gets(line) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch(choice)
			{
				case 'u' : pfun = ToUpper; break;
				case 'l' : pfun = ToLower; break;
				case 't' : pfun = Transpose; break;
			 	case 'o' : pfun = Dummy; break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("Введите строку, пустая - выход");
	}
	puts("Всего доброго!");
	return 0;
}

char showmenu(void)
{
	char ans;
	puts("Введите номер выбранного элемента меню:");
	puts("u) верхний регистр 	l) нижний регистр");
	puts("t) перестановка регистров o) исходный регистр");
	puts("n) следующая строка");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while (strchr("ulton", ans) == NULL)
	{
		puts("Пожалуйста, введите a u, l, t, o или n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char *str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{

}

void show(void (*fp)(char *), char *str)
{
	(*fp)(str);
	puts(str);
}

