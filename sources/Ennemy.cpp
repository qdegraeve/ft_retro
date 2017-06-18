#include "Ennemy.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Ennemy::Ennemy(unsigned int pos_y, int color,
				int speed, unsigned int shoot_frame,
				Window const &win) : Entity("Ennemy",
											2,		/* life max */
											2,		/* damage point */
											win.get_cols() - 1,		/* pos x */
											pos_y,	/* pos y */
											'e',	/* character */
											speed,	/* speed */
											color,	/* color */
											win)
{
	this->_shoot_frame = shoot_frame;
	this->_nb_shoot = 0;
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

unsigned int			Ennemy::get_shoot_frame(void) const
{
	return (this->_shoot_frame);
}

unsigned int			Ennemy::get_nb_shoot(void) const
{
	return (this->_shoot_frame);
}

/*************************     SETTERS      ***********************************/

void				Ennemy::set_nb_shoot(unsigned int nb_shoot)
{
	if (nb_shoot > this->_shoot_frame)
		this->_nb_shoot = this->_shoot_frame;
	else
		this->_nb_shoot = nb_shoot;
}

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
