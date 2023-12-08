#include <ncurses.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	initscr();
	move (LINES/2-1, COLS/2-4);
	addstr ("Привет!");
	getch();
	endwin();
	return 0;
}

