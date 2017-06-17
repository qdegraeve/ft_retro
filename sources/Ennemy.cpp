#include "Ennemy.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Ennemy::Ennemy(unsigned int pos_x, Window const &win) : Entity("Ennemy",
											5,		/* life max */
											10,		/* damage point */
											pos_x,	/* pos x */
											0,		/* pos y */
											'e',	/* character */
											1,
											win)		/* speed */
{
	std::cout << "Ennemy constructor called" << std::endl;
	return ;
}

Ennemy::Ennemy(Ennemy const & src) : Entity(src)
{
	std::cout << "Ennemy Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Ennemy::~Ennemy(void)
{
	std::cout << "Ennemy Destructor called" << std::endl;
}

/*************************     OPERATORS OVERLOAD     *************************/

Ennemy &	Ennemy::operator=(Ennemy const & rhs)
{
	(void)rhs;
	return (*this);
}

/*************************     GETTERS      ***********************************/

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
