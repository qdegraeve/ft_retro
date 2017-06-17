#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

int main()
{
	Game		game(1);
	Player&		mathilde = game.get_player(0);

	mathilde.set_name("Mathilde");
	std::cout << mathilde << std::endl;
	game.generate_ennemy();
	game.player_shoot(mathilde);
	for (int i = 0; i < 20; ++i)
	{
		game.move_bullets();
		game.move_ennemy();
	}
	return (0);
}
