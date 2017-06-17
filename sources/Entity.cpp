#include "Entity.hpp"

/*************************     CONSTRUCTORS     *******************************/

Entity::Entity(std::string type,
				unsigned int life_max,
				unsigned int damage_point,
				unsigned int pos_x,
				unsigned int pos_y,
				unsigned char character,
				int speed) : _type(type),
								_life_max(life_max),
								_life(life_max),
								_damage_point(damage_point),
								_pos_x(pos_x),
								_pos_y(pos_y),
								_character(character),
								_speed(speed)
{
	std::cout << "Entity constructor called" << std::endl;
	return ;
}

Entity::Entity(Entity const & src)
{
	this->_type = src.get_type();
	this->_life_max = src.get_life_max();
	this->_life = src.get_life();
	this->_damage_point = src.get_damage_point();
	this->_pos_x = src.get_pos_x();
	this->_pos_y = src.get_pos_y();
	this->_character = src.get_character();
	this->_speed = src.get_speed();
	// etc..
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Entity::~Entity()
{
	std::cout << "Entity destructor called" << std::endl;
	return ;
}

/*************************     OPERATORS OVERLOAD     *************************/

Entity & 			Entity::operator=(Entity const & rhs)
{
	this->_type = rhs.get_type();
	this->_life_max = rhs.get_life_max();
	this->_life = rhs.get_life();
	this->_damage_point = rhs.get_damage_point();
	this->_pos_x = rhs.get_pos_x();
	this->_pos_y = rhs.get_pos_y();
	this->_character = rhs.get_character();
	this->_speed = rhs.get_speed();
	return (*this);
}

std::ostream &		operator<<(std::ostream & o, Entity const & rhs)
{
	o << "Entity <"
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

unsigned int		Entity::get_pos_x(void) const
{
	return (this->_pos_x);
}

unsigned int		Entity::get_pos_y(void) const
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

/*************************    		 SETTERS	     *************************/

void				Entity::set_pos_x(unsigned int new_pos_x)
{
	this->_pos_x = new_pos_x;
}

void				Entity::set_pos_y(unsigned int new_pos_y)
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

	this->_pos_x = this->_check_move(this->_pos_x, x_move, LINES, 0);
	this->_pos_y = this->_check_move(this->_pos_y, y_move, COLONNES, 0);
}

/*************************    		PRIVATE		     *************************/

unsigned int		Entity::_check_move(unsigned int current_pos, int move,
										int pos_max, int pos_min) const
{
	unsigned int new_pos;

	new_pos = current_pos;
	if ((int)(current_pos + move) > pos_max)
		new_pos = pos_max;
	else if ((int)(current_pos + move) < pos_min)
		new_pos = pos_min;
	else
		new_pos += move;
	return (new_pos);
}
