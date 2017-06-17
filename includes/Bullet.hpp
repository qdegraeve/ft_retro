#ifndef BULLET_HPP
# define BULLET_HPP

# include <string>
# include "Entity.hpp"

class Bullet : public Entity
{
	public:
		Bullet(unsigned int pos_x);
		Bullet(Bullet const & src);
		virtual ~Bullet();

	private:
		Bullet &	operator=(Bullet const & rhs);
		Bullet(void);
};

#endif
