#include <iostream>
#include "Entity.hpp"
#include "Player.hpp"
#include "Ennemy.hpp"
#include "Bullet.hpp"

int main()
{
	Player		mathilde("Mathilde");

	std::cout << mathilde << std::endl;
	for (int i = 0; i < LINES + 1; ++i)
	{
		mathilde.move(0, 1);
		std::cout << mathilde << std::endl;
	}
	return (0);
}
