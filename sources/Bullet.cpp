#include "Bullet.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Bullet::Bullet(void) : Entity("Bullet", /* type */
								1,		/* life max */
								2,		/* damage point */
								0,		/* pos x */
								0,		/* pos y */
								'-',	/* character */
								2)		/* speed */
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Bullet::Bullet(Bullet const & src) : Entity(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Bullet::~Bullet(void)
{
	std::cout << "Destructor called" << std::endl;
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
