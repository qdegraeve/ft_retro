#include "Asteroid.hpp"

/*************************     CONSTRUCTORS     *******************************/

Asteroid::Asteroid(unsigned int pos_x, unsigned int pos_y,
					Window const &win) : Ennemy(pos_y,
												10000,			/* life */
												10,				/* damage */
												COLOR_PAIR(0),	/* color */
												-1,				/* speed */
												'#',				/* character */
												0,				/* shoot frame */
												win)
{
	this->_pos_x -= pos_x;
	std::cerr << "x : " << this->_pos_x << ", pos y : " << this->_pos_y << std::endl;
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
