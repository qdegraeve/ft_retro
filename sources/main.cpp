#include <ncurses.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

int	max(int i1, int i2) {
	if (i1 >= i2)
		return (i1);
	return (i2);
}

int	min(int i1, int i2) {
	if (i1 <= i2)
		return (i1);
	return (i2);
}

int main()
{
	Game		game(1);
	Player&		mathilde = game.get_player(0);

	mathilde.set_name("Mathilde");
	int x = 0;
	int y = 0;
	int c = 0;
	char curs = 'O';
	char *str;
	str = (char*)malloc(0);
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	addch(curs);
	printw("enter your name : ");
	echo();
	getstr(str);
	printw("\nyour name is : % s", str);
	nodelay(stdscr, TRUE);
	while (42) {
		if ((c = getch()) != 27) {
			mvaddch(y, x, ' ');
			switch(c) {
				case KEY_UP:
					y = max(0, y - 1);
					break;
				case KEY_DOWN:
					y = min(LINES, y + 1);
					break;
				case KEY_RIGHT:
					x = min(COLS, x + 1);
					break;
				case KEY_LEFT:
					x = max(0, x - 1);
					break;
			}
			flushinp();
			mvaddch(y, x, curs);
		}
		if (c == 27)
			break;
		usleep(100000);
	}
	endwin();
}
