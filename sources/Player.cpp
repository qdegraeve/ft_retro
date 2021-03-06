#include "Player.hpp"
#include <iostream>

# define PLAYER_LIFE_MAX 30

/*************************     CONSTRUCTORS     *******************************/

Player::Player(int color, Window const & win) : Entity("Player",
								PLAYER_LIFE_MAX,	/* life max */
								10,		/* damage point */
								1,	/* pos x */
								win.get_lines() / 2,		/* pos y */
								'D',	/* character */
								1,		/* speed */
								color,
								true,	/* is ally */
								win)
{
	this->_name = "Player";
	this->_level = 1;
	this->_score = 0;
	this->_nb_ennemy_to_shoot = 5;
	this->_bullet_char = '-';
	this->_bullet_damage = 1;
	return ;
}

Player::Player(Player const & src) : Entity(src)
{

	*this = src;
	return ;
}

/*************************     DESTRUCTORS     ********************************/

Player::~Player(void) {
}

/*************************     OPERATORS OVERLOAD     *************************/

Player &	Player::operator=(Player const & rhs) {

	if (this != &rhs)
	{
		(Entity)(*this) = (Entity)rhs;
		this->_name = rhs.get_name();
		this->_level = rhs.get_level();
		this->_score = rhs.get_score();
		this->_nb_ennemy_to_shoot = rhs.get_nb_ennemy_to_shoot();
		this->_bullet_char = '-';
		this->_bullet_damage = 1;
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

char				Player::get_bullet_char(void) const
{
	return (this->_bullet_char);
}

unsigned int		Player::get_bullet_damage(void) const
{
	return (this->_bullet_damage);
}

/*************************     SETTERS      ***********************************/

void				Player::set_name(std::string const & name)
{
	this->_name = name;
}

void				Player::increase_score(unsigned int amount)
{
	this->_score += amount;
	this->_nb_ennemy_to_shoot -= 1;
	if (this->_nb_ennemy_to_shoot == 0)
	{
		this->increase_level(1);
		if (this->_level == 2)
		{
			this->_bullet_char = '=';
			this->_bullet_damage += 1;
		}
		else if (this->_level == 4)
		{
			this->_bullet_char = ':';
			this->_bullet_damage += 1;

		}
		else if (this->_level == 6)
		{
			this->_bullet_char = '*';
			this->_bullet_damage += 1;
		}
		else if (this->_level == 8)
		{
			this->_bullet_char = '#';
			this->_bullet_damage += 1;
		}
		else if (this->_level % 4 == 0)
			this->_bullet_damage *= 2;
		this->_nb_ennemy_to_shoot = this->_level * 5 + this->_level;
		this->_life += 2;
	}
}

void				Player::increase_level(unsigned int amount)
{
	this->_level += amount;
}

void				Player::reset_player()
{
	this->_life = PLAYER_LIFE_MAX;
	this->_level = 1;
	this->_score = 0;
	this->_nb_ennemy_to_shoot = 5;
	this->_bullet_char = '-';
	this->_bullet_damage = 1;
	this->_pos_x = 1;
	this->_pos_y = this->_win.get_lines() / 2;
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
		this->_pos_y = _win.get_lines() - 1;
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


