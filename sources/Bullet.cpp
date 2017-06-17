#include "Bullet.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Bullet::Bullet(unsigned int pos_x) : Entity("Bullet", /* type */
											1,		/* life max */
											3,		/* damage point */
											pos_x,	/* pos x */
											LINES - 1,		/* pos y */
											'-',	/* character */
											2)		/* speed */
{
	std::cout << "Bullet constructor called" << std::endl;
	return ;
}

Bullet::Bullet(Bullet const & src) : Entity(src)
{
	std::cout << "Bullet Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Bullet::~Bullet(void)
{
	std::cout << "Bullet Destructor called" << std::endl;
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
