#include "Ennemy.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Ennemy::Ennemy(unsigned int pos_y, Window const &win) : Entity("Ennemy",
											1,		/* life max */
											1,		/* damage point */
											win.get_cols() - 1,		/* pos x */
											pos_y,	/* pos y */
											'e',	/* character */
											-1,
											win)		/* speed */
{
		fprintf(stderr, "constructeur , pos x == %d\n", this->_pos_x );

	return ;
}

Ennemy::Ennemy(Ennemy const & src) : Entity(src)
{
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Ennemy::~Ennemy(void)
{
		fprintf(stderr, "-- Destructeur , pos x == %d\n", this->_pos_x );
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
