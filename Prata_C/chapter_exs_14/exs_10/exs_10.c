#include <stdio.h>

void menu_1();
void menu_2();
void menu_3();
void menu_4();

int main(void)
{
	void (*menu_fun[4])() = { menu_1, menu_2, menu_3, menu_4};
	int choice = 0;

	while(1) {
		printf("Выбер меню 1, 2, 3, 4\n");
		printf("5 - выход\n");
		scanf("%d", &choice);

		if (choice == 5)
			break;

		(*menu_fun[choice-1])();
	}

}

void menu_1() 
{
	printf("Меню 1\n");
}

void menu_2()
{
	printf("Меню 2\n");
}

void menu_3()
{
	printf("Меню 3\n");
}

void menu_4()
{
	printf("Меню 4\n");
}

