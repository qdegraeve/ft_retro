#include "Game.hpp"

#include <sstream>
#include <time.h>

Game::Game(unsigned int nb_player) :_menu(*new Window(HEIGHT_MENU, WIN_SPACE)),
									_playground(*new Window(LINES - BEGIN_PG - WIN_SPACE, BEGIN_PG)),
									_level(1),
									_score(0),
									_nb_enemy_to_shoot(10),

									_nb_players(nb_player > NB_MAX_PLAYER ?
												NB_MAX_PLAYER : nb_player),
									_nb_ennemy(0), _ennemy_list(NULL),
									_nb_bullet(0), _bullet_list(NULL)
{
	srand(time(NULL));
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

	this->_nb_ennemy = rand() % this->_nb_enemy_to_shoot;
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

int					Game::start_game(void) {
	int c = 0;
	while (42) {
		if ((c = wgetch(this->_playground.get_win())) != 27) {
			mvwaddch(this->_playground.get_win(), this->_players[0]->get_pos_y(), this->_players[0]->get_pos_x(), ' ');
			switch(c) {
				case KEY_UP:
					this->_players[0]->move(0, 1);
					break;
				case KEY_DOWN:
					this->_players[0]->move(0, -1);
					break;
				case KEY_RIGHT:
					this->_players[0]->move(-1, 0);
					break;
				case KEY_LEFT:
					this->_players[0]->move(1, 0);
					break;
				case ERR:
					break;
				default:
					this->player_shoot(*this->_players[0]);
					break;
			}
			flushinp();
			mvwaddch(this->_playground.get_win(), this->_players[0]->get_pos_y(), this->_players[0]->get_pos_x(), this->_players[0]->get_character());
			if (this->_bullet_list)
				mvwaddch(this->_playground.get_win(), this->_bullet_list->get_pos_y(), this->_bullet_list->get_pos_x(), this->_bullet_list->get_character());
			this->move_bullets();
		}
		if (c == 27)
			break ;
		if (c == KEY_RESIZE) {
			std::cout << "Resize is forbidden" << std::endl;
			break ;
		}
		usleep(200000);
	}
	return (0);
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
