#include "Player.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Player::Player(void) : Entity("Player",
								100,	/* life max */
								10,		/* damage point */
								(COLONNES / 2),	/* pos x */
								LIGNES,		/* pos y */
								'p',	/* character */
								-1)		/* speed */
{
	this->_name = "Player";
	return ;
}

Player::Player(Player const & src) : Entity(src)
{

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

std::string	const	Player::get_name(void) const
{
	return (this->_name);
}

/*************************     SETTERS      ***********************************/

void				Player::set_name(std::string const & name)
{
	this->_name = name;
}

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/

std::ostream &		operator<<(std::ostream & o, Player const & rhs)
{
	o << rhs.get_name() << " " << (Entity)rhs;
	return (o);
}


