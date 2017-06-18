#ifndef BULLET_HPP
# define BULLET_HPP

# include <string>
# include "Entity.hpp"

class Bullet : public Entity
{
	public:
		Bullet(bool is_ally, unsigned int pos_x, unsigned int pos_y,
				int speed, int color, Window const & win);
		Bullet(Bullet const & src);
		virtual ~Bullet();

	private:

		Bullet &	operator=(Bullet const & rhs);
		Bullet(void);
};

#endif
