#include "Game.hpp"

#include <sstream>

Game::Game(unsigned int nb_player) : _nb_players(nb_player > NB_MAX_PLAYER ?
												NB_MAX_PLAYER : nb_player)
{
	unsigned int			i;
	std::stringstream		new_name;

	for (i = 0; i < this->_nb_players; ++i)
	{
		new_name << "Player" << i;
		this->_players[i] = new Player(new_name.str());
	}
	return ;
}

Game::Game(Game const & src)
{
	*this = src;
	return ;
}

Game::~Game()
{
	unsigned int		i;

	for (i = 0; i < this->_nb_players; ++i)
	{
		delete this->_players[i];
	}
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
	return (*(this->_players[index]));
}

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
