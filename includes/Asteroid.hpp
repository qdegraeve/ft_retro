#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "Ennemy.hpp"

class Asteroid : public Ennemy
{
	public:
		Asteroid(unsigned int pos_y, Window const &win);	/* constructor by default */
		Asteroid(Asteroid const & src);					/* constructor by copy */
		~Asteroid();											/* destructor */

	private:
		Asteroid(void);	/* constructor by default */
		Asteroid & operator=(Asteroid const & rhs);		/* overload operator = */

};

#endif /* ASTEROID_HPP */