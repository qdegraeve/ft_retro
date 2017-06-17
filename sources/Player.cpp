#include "Player.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Player::Player(std::string name) : Entity("Player", 100, 10, 0, 0, 'p', 1)
{
	this->_name = name;
	std::cout << "Player constructor called" << std::endl;
	return ;
}

Player::Player(Player const & src) : Entity(src)
{

	std::cout << "Player Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Player::~Player(void) {
	std::cout << "Player Destructor called" << std::endl;
}

/*************************     OPERATORS OVERLOAD     *************************/

Player &	Player::operator=(Player const & rhs) {

	std::cout << "Assignation operator called for Player" << std::endl;
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
		this->_name = rhs.get_name();
	}
	return (*this);
}

/*************************     GETTERS      ***********************************/

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

std::string	Player::get_name(void) const
{
	return (this->_name);
}

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/

std::ostream &		operator<<(std::ostream & o, Player const & rhs)
{
	o << rhs.get_name() << " " << (Entity)rhs;
	return (o);
}


