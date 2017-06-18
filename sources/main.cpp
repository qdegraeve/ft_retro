#include <ncurses.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"
#include "Window.hpp"

int main()
{
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);

	Game		game(1);

	mvwprintw(game._menu.get_win(), game._menu.get_lines() / 2, game._menu.get_cols() / 2 - 10, "BIENVENUE");
	wrefresh(game._menu.get_win());
	keypad(game._playground.get_win(), TRUE);
	nodelay(game._playground.get_win(), TRUE);
	wrefresh(game._playground.get_win());
	game.start_game();
	endwin();
	game.generate_ennemy();
	return (0);
}
