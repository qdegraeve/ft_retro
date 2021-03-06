#include "Entity.hpp"
#include "Game.hpp"

/*************************     CONSTRUCTORS     *******************************/

Entity::Entity(std::string type,
				unsigned int life_max,
				unsigned int damage_point,
				unsigned int pos_x,
				unsigned int pos_y,
				unsigned char character,
				int speed,
				int color,
				bool is_ally,
				Window const & win) : _type(type),
								_life_max(life_max),
								_life(life_max),
								_damage_point(damage_point),
								_pos_x(pos_x),
								_pos_y(pos_y),
								_character(character),
								_speed(speed),
								_color(color),
								_is_ally(is_ally),
								_win(win),
								_next(NULL)
{
	return ;
}

Entity::Entity(Entity const & src) : _win(src.get_win())
{
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Entity::~Entity()
{
	return ;
}

/*************************     OPERATORS OVERLOAD     *************************/

Entity & 			Entity::operator=(Entity const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.get_type();
		this->_life_max = rhs.get_life_max();
		this->_life = rhs.get_life();
		this->_damage_point = rhs.get_damage_point();
		this->_pos_x = rhs.get_pos_x();
		this->_pos_y = rhs.get_pos_y();
		this->_character = rhs.get_character();
		this->_speed = rhs.get_speed();
		this->_next = rhs.get_next();
	}
	return (*this);
}

std::ostream &		operator<<(std::ostream & o, Entity const & rhs)
{
	o << "<"
		<< rhs.get_type()
		<< " (" << rhs.get_life() << "/" <<  rhs.get_life_max() << "PV)"
		<< "[" << rhs.get_pos_x() << "," << rhs.get_pos_y() << "]"
		<< "(" << rhs.get_character() << ")"
		<< ">";
	return (o);
}

/*************************    		 GETTERS	     *************************/

std::string const	Entity::get_type(void) const
{
	return (this->_type);
}

unsigned int		Entity::get_life(void) const
{
	return (this->_life);
}

unsigned int		Entity::get_life_max(void) const
{
	return (this->_life_max);
}

unsigned int		Entity::get_damage_point(void) const
{
	return (this->_damage_point);
}

int					Entity::get_pos_x(void) const
{
	return (this->_pos_x);
}

int					Entity::get_pos_y(void) const
{
	return (this->_pos_y);
}

unsigned char		Entity::get_character() const
{
	return (this->_character);
}

int					Entity::get_speed(void) const
{
	return (this->_speed);
}

int					Entity::get_color(void) const
{
	return (this->_color);
}

bool				Entity::get_is_ally(void) const
{
	return (this->_is_ally);
}

Entity*				Entity::get_next(void) const
{
	return (this->_next);
}

Window const &		Entity::get_win(void) const
{
	return (this->_win);
}

/*************************    		 SETTERS	     *************************/

void				Entity::set_pos_x(int new_pos_x)
{
	this->_pos_x = new_pos_x;
}

void				Entity::set_pos_y(int new_pos_y)
{
	this->_pos_y = new_pos_y;
}

void				Entity::set_speed(int new_speed)
{
	this->_speed = new_speed;
}

void				Entity::set_type(std::string const & new_type)
{
	this->_type = new_type;
}

void				Entity::set_damage_point(unsigned int new_damage_point)
{
	this->_damage_point = new_damage_point;
}

/*************************    	LIST-SETTERS	     *************************/

void				Entity::set_next(Entity *next)
{
	this->_next = next;
}

/*************************    		STATIC		     *************************/

Entity*				Entity::set_entity_at_end(Entity* list, Entity* to_add)
{
	Entity	*ptr = NULL;

	if (list == NULL)
		return (to_add);
	ptr = list;
	while (ptr->get_next() != NULL)
		ptr = ptr->get_next();
	ptr->set_next(to_add);
	to_add->set_next(NULL);
	return (list);
}

Entity*				Entity::get_one_entity(Entity* list, unsigned int index)
{
	Entity*			ptr;

	ptr = list;
	while (index > 0 && ptr != NULL)
	{
		ptr = ptr->get_next();
		index--;
	}
	return (ptr);
}

void				Entity::delete_entity_list(Entity* list)
{
	Entity*			ptr;
	Entity*			next;

	ptr = list;
	while (ptr != NULL)
	{
		next = ptr->get_next();
		delete ptr;
		ptr = next;
	}
}

Entity*				Entity::delete_one_entity_on_list(Entity* list, Entity* to_del)
{
	Entity*		ptr;
	Entity*		prev;

	prev = NULL;
	ptr = list;
	while (ptr != NULL)
	{
		if (ptr == to_del)
		{
			if (prev == NULL)
				list = ptr->get_next();
			else
				prev->set_next(ptr->get_next());
			delete ptr;
			ptr = NULL;
			break ;
		}
		prev = ptr;
		ptr = ptr->get_next();
	}
	return list;
}

/*************************    		OTHERS		     *************************/

void				Entity::take_damage(unsigned int amount)
{
	if (this->_life < amount)
		this->_life = 0;
	else
		this->_life -= amount;
}

void				Entity::move(int x_move, int y_move)
{
	x_move *= this->_speed;
	y_move *= this->_speed;

	this->_pos_x += x_move;
	this->_pos_y += y_move;
}

bool				Entity::current_position_on_board_is_ok(void)
{
	if (this->_pos_y < 1 || this->_pos_x < 1)
		return (false);
	if (this->_pos_y >= _win.get_lines() || this->_pos_x >= _win.get_cols())
		return (false);
	return (true);
}

/*************************    		PRIVATE		     *************************/
