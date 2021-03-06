#include "Crusader.hpp"

/*************************     CONSTRUCTORS     *******************************/

Crusader::Crusader(unsigned int pos_x,
					Window const &win) : Ennemy(pos_x,
												3,				/* life */
												5,				/* damage */
												COLOR_PAIR(FT_GREEN),	/* color */
												-1,				/* speed */
												'8',			/* char */
												200,			/* shoot frame */
												win)
{
	return ;
}

Crusader::Crusader(Crusader const & src) : Ennemy(src)
{
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Crusader::~Crusader()
{
	return ;
}

/*************************     OPERATORS OVERLOAD     *************************/
Crusader & Crusader::operator=(Crusader const & rhs)
{
	(void)rhs;
	return (*this);
}
