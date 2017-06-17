#include <ncurses.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"
#include "Window.hpp"

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
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	Window		menu(10, 2);
	Window		playground(LINES - 13, 11);
	Game		game(1);
	Player&		mathilde = game.get_player(0);

	mathilde.set_name("Mathilde");
	mvwprintw(menu.get_win(), menu.get_lines() / 2, menu.get_cols() / 2 - 10, "BIENVENUE");
	wrefresh(menu.get_win());
	int x = 1;
	int y = 1;
	int c = 0;
	char curs = 'O';
	char *str;
	str = (char*)malloc(0);
	keypad(playground.get_win(), TRUE);
	nodelay(playground.get_win(), TRUE);
	wrefresh(playground.get_win());
	while (42) {
		if ((c = wgetch(playground.get_win())) != 27) {
			mvwaddch(playground.get_win(), y, x, ' ');
			switch(c) {
				case KEY_UP:
					y = max(1, y - 1);
					break;
				case KEY_DOWN:
					y = min(playground.get_lines() - 1, y + 1);
					break;
				case KEY_RIGHT:
					x = min(playground.get_cols() - 1, x + 1);
					break;
				case KEY_LEFT:
					x = max(1, x - 1);
					break;
			}
			flushinp();
			mvwaddch(playground.get_win(), y, x, curs);
		}
		if (c == 27)
			break ;
		if (c == KEY_RESIZE) {
			erase();
			std::cout << "Resize is forbidden" << std::endl;
			break ;
		}
		usleep(20000);
	}
	endwin();
	std::cout << mathilde << std::endl;
	game.generate_ennemy();
	game.player_shoot(mathilde);
	return (0);
}
