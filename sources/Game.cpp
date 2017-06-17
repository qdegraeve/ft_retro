#include "Game.hpp"

#include <sstream>

Game::Game(unsigned int nb_player) : _nb_players(nb_player > NB_MAX_PLAYER ?
												NB_MAX_PLAYER : nb_player),
									_players(new Player[this->_nb_players]),
									_nb_enemy(0), _enemy_list(NULL),
									_nb_bullet(0), _bullet_list(NULL)

{
	std::cout << "Game constructor called" << std::endl;
	return ;
}

Game::Game(Game const & src)
{
	*this = src;
	return ;
}

Game::~Game()
{
	std::cout << "Game constructor called" << std::endl;
	delete [] this->_players;
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
	return (this->_players[index]);
}

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
