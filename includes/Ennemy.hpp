#ifndef ENNEMY_HPP
# define ENNEMY_HPP

# include <string>
# include "Entity.hpp"

class Ennemy : public Entity
{

	public:

		Ennemy(unsigned int pos_x, Window const & win);
		Ennemy(Ennemy const & src);
		virtual ~Ennemy();

	private:

		Ennemy(void);
		Ennemy &	operator=(Ennemy const & rhs);

};

#endif
