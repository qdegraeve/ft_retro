#ifndef CRUSADER_HPP
# define CRUSADER_HPP

#include "Ennemy.hpp"

class Crusader : public Ennemy
{
	public:
		Crusader(unsigned int pos_y, Window const &win);	/* constructor by default */
		Crusader(Crusader const & src);						/* constructor by copy */
		~Crusader();										/* destructor */

	private:
		Crusader(void);	/* constructor by default */
		Crusader & operator=(Crusader const & rhs);		/* overload operator = */

};

#endif /* CRUSADER_HPP */