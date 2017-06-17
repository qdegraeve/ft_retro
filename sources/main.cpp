#include <iostream>
#include "Entity.hpp"

int main()
{
	Entity		toto("toto", 10, 1, 0, 0, 't', 1);

	std::cout << toto << std::endl;
	toto.move();
	return (0);
}
