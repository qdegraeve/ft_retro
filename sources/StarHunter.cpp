#include "StarHunter.hpp"

StarHunter::StarHunter(unsigned int pos_x,
						Window const &win) : Ennemy(pos_x,
													COLOR_PAIR(2),
													-1,
													50,
													win)
{
	return ;
}

StarHunter::StarHunter(StarHunter const & src) : Ennemy(src)
{
	*this = src;
	return ;
}

StarHunter::~StarHunter()
{
	return ;
}

/*
**  	------------------------------------------------------
**  	|					OVERLOAD OPERATORS				 |
**  	------------------------------------------------------
*/
StarHunter & StarHunter::operator=(StarHunter const & rhs)
{
	(void)rhs;
	return (*this);
}

/*
** Implementation
*/
