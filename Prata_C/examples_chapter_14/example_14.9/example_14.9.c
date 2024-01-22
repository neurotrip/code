#include <stdio.h>
#include <string.h>

struct namect {
	char fname[20];
	char lname[20];
	int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(void)
{
	struct namect person;
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);

	return 0;
	
}

struct namect getinfo(void)
{
	struct namect temp;
	printf("Введите своё имя.\n");
	gets(temp.fname);
	printf("Введите свою фамилию.\n");
	gets(temp.lname);

	return temp;
}

struct namect makeinfo(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, ваше имя и фамилия содержат %d букв.\n", info.fname, info.lname, info.letters);
}

