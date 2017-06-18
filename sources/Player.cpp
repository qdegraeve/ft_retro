#include "Player.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Player::Player(Window const & win) : Entity("Player",
								100,	/* life max */
								10,		/* damage point */
								(COLONNES / 2),	/* pos x */
								LIGNES,		/* pos y */
								'p',	/* character */
								1,
								win)		/* speed */
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

void				Player::move(int x_move, int y_move)
{
	Entity::move(x_move, y_move);

	if (this->_pos_y < 1)
		this->_pos_y = 1;
	if (this->_pos_x < 1)
		this->_pos_x = 1;
	if (this->_pos_y >= _win.get_lines())
		this->_pos_y = _win.get_lines();
	if (this->_pos_x >= _win.get_cols())
		this->_pos_x = _win.get_cols();
}

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/

std::ostream &		operator<<(std::ostream & o, Player const & rhs)
{
	o << rhs.get_name() << " " << (Entity)rhs;
	return (o);
}


