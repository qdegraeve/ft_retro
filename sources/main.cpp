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
	if (COLS < 60 || LINES < 40)
	{
		std::cerr << "Votre Fenetre est trop petite." << std::endl;
		std::cerr << "Merci d'utilise une fenetre d'au moins 60 x 40" << std::endl;
		return (1);
	}
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

	keypad(game._playground.get_win(), TRUE);
	nodelay(game._playground.get_win(), TRUE);
	wrefresh(game._playground.get_win());
	game.start_game();
	endwin();
	return (0);
}
