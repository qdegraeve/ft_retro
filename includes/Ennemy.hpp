#ifndef ENNEMY_HPP
# define ENNEMY_HPP

# include <string>
# include "Entity.hpp"

class Ennemy : public Entity {

public:

	Ennemy(void);
	Ennemy(Ennemy const & src);
	virtual ~Ennemy();

	Ennemy &	operator=(Ennemy const & rhs);
};

#endif
