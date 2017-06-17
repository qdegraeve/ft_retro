#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

int main()
{
	Game		game(1);
	Player&		mathilde = game.get_player(0);
	Ennemy*		ennemy1;
	Ennemy*		ennemy_list;

	mathilde.set_name("Mathilde");
	game.generate_ennemy();
	ennemy_list = game.get_ennemy_list();
	ennemy1 = (Ennemy *)Entity::get_one_entity(ennemy_list, 1);
	std::cout << *ennemy1 << std::endl;
	ennemy_list = (Ennemy *)Entity::delete_one_entity_on_list(ennemy_list, ennemy1);
	return (0);
}
