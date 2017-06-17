#include "Player.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Player::Player(std::string name) : Entity("Player",
											100,	/* life max */
											10,		/* damage point */
											(COLONNES / 2),	/* pos x */
											LINES,		/* pos y */
											'p',	/* character */
											-1)		/* speed */
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
		(Entity)(*this) = (Entity)rhs;
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


