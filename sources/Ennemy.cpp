#include "Ennemy.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Ennemy::Ennemy(void) : Entity("Ennemy", 5,	/* life max */
										10,	/* damage point */
										0,	/* pos x */
										0,	/* pos y */
										'e',	/* character */
										2)		/* speed */
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
