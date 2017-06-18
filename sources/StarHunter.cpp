#include "StarHunter.hpp"

/*************************     CONSTRUCTORS     *******************************/

StarHunter::StarHunter(unsigned int pos_x,
						Window const &win) : Ennemy(pos_x,
													1,				/* life */
													1,				/* damage */
													COLOR_PAIR(FT_BLUE),	/* color */
													-1,				/* speed */
													'<',			/* char */
													150,				/* shoot frame */
													win)
{
	return ;
}

StarHunter::StarHunter(StarHunter const & src) : Ennemy(src)
{
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

StarHunter::~StarHunter()
{
	return ;
}

/*************************     OPERATORS OVERLOAD     *************************/
StarHunter & StarHunter::operator=(StarHunter const & rhs)
{
	(void)rhs;
	return (*this);
}
