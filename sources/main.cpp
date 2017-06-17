#include <ncurses.h>
#include <sys/wait.h>
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
	Game		game(1);

	mvwprintw(game._menu.get_win(), game._menu.get_lines() / 2, game._menu.get_cols() / 2 - 10, "BIENVENUE");
	wrefresh(game._menu.get_win());
	keypad(game._playground.get_win(), TRUE);
	nodelay(game._playground.get_win(), TRUE);
//	wrefresh(game._playground.get_win());
	game.start_game();
	endwin();
	game.generate_ennemy();
	return (0);
}
