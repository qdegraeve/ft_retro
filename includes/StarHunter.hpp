#ifndef STAR_HUNTER_HPP
# define STAR_HUNTER_HPP

#include "Ennemy.hpp"

class StarHunter : public Ennemy
{
	public:
		StarHunter(unsigned int pos_y, Window const &win);	/* constructor by default */
		StarHunter(StarHunter const & src);					/* constructor by copy */
		~StarHunter();											/* destructor */

	private:
		StarHunter(void);	/* constructor by default */
		StarHunter & operator=(StarHunter const & rhs);		/* overload operator = */

};

#endif /* STAR_HUNTER_HPP */