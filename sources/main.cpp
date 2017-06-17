#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

int main()
{
	Game		game(1);
	Player&		mathilde = game.get_player(0);

	mathilde.set_name("Mathilde");
	game.generate_ennemy();
	return (0);
}
