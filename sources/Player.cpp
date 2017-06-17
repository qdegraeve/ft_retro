#include "Player.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Player::Player(void) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Player::Player(Player const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

/*************************     DESTRUCTORS     ********************************/

Player::~Player(void) {
	std::cout << "Destructor called" << std::endl;
}

/*************************     OPERATORS OVERLOAD     *************************/

Player &	Player::operator=(Player const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->_pos_x = rhs.get_pos_x();
		this->_pos_x = rhs.get_pos_y();
		this->_speed = rhs.get_speed();
		this->_life = rhs.get_life();
	}
	
	return *this;
}

/*************************     GETTERS      ***********************************/

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

std::string	Player::get_name(void) const {
	return (this->_name);
}

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/

std::ostream &		operator<<(std::ostream & o, Player const & rhs) {
	o << rhs.get_name();

	return (o);
}


