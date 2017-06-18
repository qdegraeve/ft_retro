#include "Asteroid.hpp"

/*************************     CONSTRUCTORS     *******************************/

Asteroid::Asteroid(unsigned int pos_x,
					Window const &win) : Ennemy(pos_x,
												10000,			/* life */
												10,				/* damage */
												COLOR_PAIR(0),	/* color */
												-1,				/* speed */
												0,				/* shoot frame */
												win)
{
	return ;
}

Asteroid::Asteroid(Asteroid const & src) : Ennemy(src)
{
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Asteroid::~Asteroid()
{
	return ;
}

/*************************     OPERATORS OVERLOAD     *************************/
Asteroid & Asteroid::operator=(Asteroid const & rhs)
{
	(void)rhs;
	return (*this);
}
