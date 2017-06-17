#include "Game.hpp"

#include <sstream>

Game::Game(unsigned int nb_player) : _nb_players(nb_player > NB_MAX_PLAYER ?
												NB_MAX_PLAYER : nb_player),
									_nb_ennemy(0), _ennemy_list(NULL),
									_nb_bullet(0), _bullet_list(NULL),
									_menu(*new Window(HEIGHT_MENU, WIN_SPACE)),
									_playground(*new Window(LINES - BEGIN_PG, BEGIN_PG))
{
	for(unsigned int i=0; i < nb_player; i++)
		this->_players[i] = new Player(this->_playground);
	return ;
}

Game::Game(Game const & src) : _menu(*new Window(HEIGHT_MENU, WIN_SPACE)),
								_playground(*new Window(LINES - BEGIN_PG, BEGIN_PG))
{
	*this = src;
	return ;
}

Game::~Game()
{
	for(unsigned int i=0; i < this->_nb_players; i++)
		delete this->_players[i];
	Entity::delete_entity_list((Entity *)this->_ennemy_list);
	Entity::delete_entity_list((Entity *)this->_bullet_list);
	return ;
}

/*************************     OVERLOAD OPERATORS	*************************/

Game & Game::operator=(Game const & rhs)
{
	(void)rhs;
	return (*this);
}

/*************************     GETTERS      ***********************************/

unsigned int		Game::get_nb_players(void) const
{
	return (this->_nb_players);
}

Player&				Game::get_player(unsigned int index) const
{
	if (index >= this->_nb_players)
		index = this->_nb_players - 1;
	return (*this->_players[index]);
}

unsigned int		Game::get_nb_ennemy(void) const
{
	return (this->_nb_ennemy);
}

Ennemy*				Game::get_ennemy_list(void) const
{
	return (this->_ennemy_list);
}

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

void				Game::generate_ennemy(void)
{
	Ennemy			*new_ennemy;
	unsigned int	i;

	this->_nb_ennemy = 5;
	for (i = 0; i < this->_nb_ennemy; ++i)
	{
		new_ennemy = new Ennemy(i, this->_playground);
		this->_ennemy_list = (Ennemy *)Entity::set_entity_at_end(this->_ennemy_list, new_ennemy);
	}
}

void				Game::player_shoot(Player const & player)
{
	Bullet*			new_bullet;

	new_bullet = new Bullet(player.get_pos_x(), this->_playground);
	this->_bullet_list = (Bullet *)Entity::set_entity_at_end(this->_bullet_list, new_bullet);
}

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

void			Game::move_bullets(void)
{
	this->_bullet_list = (Bullet *)this->_bullet_list->move_entity_list(this->_bullet_list);
	return ;
}

void			Game::move_ennemy(void)
{
	this->_ennemy_list = (Ennemy *)this->_ennemy_list->move_entity_list(this->_ennemy_list);
	return ;
}

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
