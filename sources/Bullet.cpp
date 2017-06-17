#include "Bullet.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Bullet::Bullet(unsigned int pos_x, unsigned int pos_y,
				Window & win) : Entity("Bullet", /* type */
											1,		/* life max */
											3,		/* damage point */
											pos_x + 1,	/* pos x */
											pos_y,	/* pos y */
											'-',	/* character */
											2,		/* speed */
											win)		/* speed */
{
	return ;
}

Bullet::Bullet(Bullet const & src) : Entity(src)
{
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Bullet::~Bullet(void)
{
}

/*************************     OPERATORS OVERLOAD     *************************/

Bullet &	Bullet::operator=(Bullet const & rhs)
{
	(void)rhs;
	return *this;
}

/*************************     GETTERS      ***********************************/

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
