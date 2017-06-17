#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <iostream>
#include "Window.hpp"

#ifndef LIGNES
# define LIGNES 20
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
				int speed,
				Window const & win);								/* constructor by default */
		Entity(Entity const & src);						/* constructor by copy */
		/* destructor */
		virtual ~Entity();								/* destructor */

		/* operator overload */
		Entity & operator=(Entity const & rhs);

		/* Getters */
		std::string	const	get_type() const;
		unsigned int		get_life() const;
		unsigned int		get_life_max() const;
		unsigned int		get_damage_point() const;
		int					get_pos_x() const;
		int					get_pos_y() const;
		unsigned char		get_character() const;
		int					get_speed() const;
		Entity*				get_next() const;
		Window const &		get_win() const;

		/* Setters */
		void				set_damage_point(unsigned int damage_point);
		void				set_pos_x(int new_pos_x);
		void				set_pos_y(int new_pos_y);
		void				set_speed(int new_speed);
		void				set_type(std::string const & new_type);

		/* List - Getters */
		static Entity*		get_one_entity(Entity* list, unsigned int index);

		/* List - Setters */
		void				set_next(Entity* next);
		Entity*				move_entity(Entity* list);

		/* List - Functions */
		static Entity*		set_entity_at_end(Entity* list, Entity* to_add);
		static void			delete_entity_list(Entity* list);
		static Entity*		delete_one_entity_on_list(Entity* list, Entity* to_del);

		/* Others */
		void				take_damage(unsigned int amount);
		void				move(int x_move, int y_move);

	protected:

			std::string				_type;
			unsigned int			_life_max;
			unsigned int			_life;
			unsigned int			_damage_point;
			int						_pos_x;
			int						_pos_y;
			unsigned char			_character;
			int						_speed;

			Window const &			_win;
			Entity*					_next;

	private:

		int							_check_move(int current_pos, int move,
										int pos_max, int pos_min) const;
		bool						_current_position_on_board_is_ok(void);
};

std::ostream &		operator<<(std::ostream & o, Entity const & rhs);

#endif /* ENTITY_HPP */
