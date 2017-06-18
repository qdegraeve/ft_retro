#include "Bullet.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Bullet::Bullet(bool is_ally, unsigned int pos_x, unsigned int pos_y,
				int speed, int color, int character, unsigned int bullet_damage,
				Window const & win) : Entity("Bullet", /* type */
											1,		/* life max */
											bullet_damage,		/* damage point */
											pos_x + 1,	/* pos x */
											pos_y,	/* pos y */
											character,	/* character */
											speed,		/* speed */
											color,	/* color */
											is_ally,
											win)
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
