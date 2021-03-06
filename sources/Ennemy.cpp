#include "Ennemy.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Ennemy::Ennemy(unsigned int pos_y, int life_max, int damage_point,
				int color, int speed, char character, unsigned int shoot_frame,
				Window const &win) : Entity("Ennemy",
											life_max,		/* life max */
											damage_point,			/* damage point */
											win.get_cols() - 1,		/* pos x */
											pos_y,	/* pos y */
											character,	/* character */
											speed,	/* speed */
											color | WA_BOLD,	/* color */
											false,	/* is ally */
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
}

/*************************     OPERATORS OVERLOAD     *************************/

Ennemy &	Ennemy::operator=(Ennemy const & rhs)
{
	if (this != &rhs)
	{
		(Entity)(*this) = (Entity)rhs;
		this->_shoot_frame = rhs.get_shoot_frame();
		this->_nb_shoot = rhs.get_nb_shoot();
	}
	return (*this);
}

/*************************     GETTERS      ***********************************/

unsigned int			Ennemy::get_shoot_frame(void) const
{
	return (this->_shoot_frame);
}

unsigned int			Ennemy::get_nb_shoot(void) const
{
	return (this->_nb_shoot);
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
