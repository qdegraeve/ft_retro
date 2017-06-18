#ifndef ENNEMY_HPP
# define ENNEMY_HPP

# include <string>
# include "Entity.hpp"
# include "color.h"

class Ennemy : public Entity
{

	public:

		Ennemy(unsigned int pos_x,
				int life_max,
				int damage_point,
				int color,
				int speed,
				unsigned int shoot_frame,
				Window const & win);
		Ennemy(Ennemy const & src);
		virtual ~Ennemy();

		unsigned int		get_shoot_frame(void) const;
		unsigned int		get_nb_shoot(void) const;

		void				set_nb_shoot(unsigned int nb_shoot);

	protected:
		unsigned int				_shoot_frame;
		unsigned int				_nb_shoot;

	private:

		Ennemy(void);
		Ennemy &	operator=(Ennemy const & rhs);

};

#endif
