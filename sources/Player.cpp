#include "Player.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Player::Player(int color, Window const & win) : Entity("Player",
								10,	/* life max */
								10,		/* damage point */
								(COLONNES / 2),	/* pos x */
								LIGNES,		/* pos y */
								'p',	/* character */
								1,		/* speed */
								color,
								win)
{
	this->_name = "Player";
	this->_level = 1;
	this->_score = 0;
	this->_nb_ennemy_to_shoot = 10;
	return ;
}

Player::Player(Player const & src) : Entity(src)
{

	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Player::~Player(void) {
	std::cerr << "Player Destructor called" << std::endl;
}

/*************************     OPERATORS OVERLOAD     *************************/

Player &	Player::operator=(Player const & rhs) {

	std::cerr << "Assignation operator called for Player" << std::endl;
	if (this != &rhs)
	{
		(Entity)(*this) = (Entity)rhs;
		this->_name = rhs.get_name();
		this->_level = rhs.get_level();
		this->_score = rhs.get_score();
		this->_nb_ennemy_to_shoot = rhs.get_nb_ennemy_to_shoot();
	}
	return (*this);
}

/*************************     GETTERS      ***********************************/

std::string	const	Player::get_name(void) const
{
	return (this->_name);
}
unsigned int		Player::get_level(void) const
{
	return (this->_level);
}

unsigned int		Player::get_score(void) const
{
	return (this->_score);
}

unsigned int		Player::get_nb_ennemy_to_shoot(void) const
{
	return (this->_nb_ennemy_to_shoot);
}

/*************************     SETTERS      ***********************************/

void				Player::set_name(std::string const & name)
{
	this->_name = name;
}

void				Player::increase_score(unsigned int amount)
{
	this->_score += amount;
}

void				Player::increase_level(unsigned int amount)
{
	this->_level += amount;
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


