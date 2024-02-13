#include <stdio.h>

#define YES 1
#define NO 0

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"черный", "красный", "зеленый", "желтый",
						  "синий", "пурпурный", "голубой", "белый"};

struct box_props {
	unsigned int opaque 			: 1;
	unsigned int fill_color 		: 3;
	unsigned int 					: 4;
	unsigned int show_border 		: 1;
	unsigned int border_color 		: 3;
	unsigned int border_style 		: 2;
	unsigned int 					: 2;
};

void show_settings(const struct box_props *pb);

int main(void)
{
	struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};

	printf("Исходные параметры окна:\n");
	show_settings(&box);

	box.opaque = NO;
	box.fill_color = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\nИзмененные параметры окна:\n");
	show_settings(&box);

	return 0;
}

void show_settings(const struct box_props *pb)
{
	printf("Фон %s.\n",
			pb->opaque == YES? "непрозрачный" : "прозрачный");
	printf("Цвет фона %s.\n", colors[pb->fill_color]);
	printf("Рамка %s.\n", 
			pb->show_border == YES? "видимая" : "невидимая");
	printf("Цвет рамки %s.\n", colors[pb->border_color]);
	printf("Стиль линии рамки ");
	switch (pb->border_color) 
	{
		case SOLID : printf("сплошной.\n"); break;
		case DOTTED : printf("пунктирный.\n"); break;
		case DASHED : printf("штриховой.\n"); break;
		default: printf("неизвестный.\n");
	}
}

