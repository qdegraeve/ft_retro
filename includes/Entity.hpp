#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <iostream>

#ifndef LINES
# define LINES 10
#endif
#ifndef COLONNES
# define COLONNES 10
#endif

class Entity
{
	public:
		/* constructors */
		Entity(std::string type,
				unsigned int life_max,
				unsigned int damage_point,
				unsigned int pos_x,
				unsigned int pos_y,
				unsigned char character,
				int speed);								/* constructor by default */
		Entity(Entity const & src);						/* constructor by copy */
		/* destructor */
		virtual ~Entity();								/* destructor */

		/* operator overload */
		Entity & operator=(Entity const & rhs);

		/* Getters */
		std::string	const	get_type() const;
		unsigned int		get_life() const;
		unsigned int		get_max_life() const;
		unsigned int		get_damage_point() const;
		unsigned int		get_pos_x() const;
		unsigned int		get_pos_y() const;
		unsigned char		get_charater() const;
		int					get_speed() const;

		/* Setters */
		void				set_pos_x(unsigned int new_pos_x);
		void				set_pos_y(unsigned int new_pos_y);

		/* Effects */
		void				take_damage(unsigned int amount);
		void				move(int x_move, int y_move);

	protected:

			std::string				_type;
			unsigned int			_life_max;
			unsigned int			_life;
			unsigned int			_damage_point;
			unsigned int			_pos_x;
			unsigned int			_pos_y;
			unsigned char			_character;
			int						_speed;

	private:

};

std::ostream &		operator<<(std::ostream & o, Entity const & rhs);

#endif /* ENTITY_HPP */
