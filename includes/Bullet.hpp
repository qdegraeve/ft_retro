#ifndef BULLET_HPP
# define BULLET_HPP

# include <string>
# include "Entity.hpp"

class Bullet : public Entity {

public:

	Bullet(void);
	Bullet(Bullet const & src);
	virtual ~Bullet();

	Bullet &	operator=(Bullet const & rhs);

};

#endif
