#include "Game.hpp"
#include "StarHunter.hpp"
#include "Crusader.hpp"
#include "Asteroid.hpp"

#include <sstream>
#include <time.h>

Game::Game(unsigned int nb_player) :_menu(*new Window(HEIGHT_MENU, WIN_SPACE,
													  COLS - (OUTSPACE * 2))),
									_playground(*new Window(LINES - BEGIN_PG - WIN_SPACE,
															BEGIN_PG, COLS - (OUTSPACE * 2))),
									_nb_players(nb_player > NB_MAX_PLAYER ?
												NB_MAX_PLAYER : nb_player),
									_nb_ennemy(0), _ennemy_list(NULL),
									_nb_bullet(0), _bullet_list(NULL)
{
	srand(time(NULL));
	for(unsigned int i=0; i < nb_player; i++)
		this->_players[i] = new Player(i + 1, this->_playground);
	return ;
}

Game::Game(Game const & src) : _menu(*new Window(HEIGHT_MENU, WIN_SPACE,
												COLS - (OUTSPACE * 2))),
								_playground(*new Window(LINES - BEGIN_PG,
														BEGIN_PG, COLS - (OUTSPACE * 2)))
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
	delete &this->_playground;
	delete &this->_menu;
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
	int				ennemies = rand() % MAX_ENEMIES_PER_TURN;
	int				positions[ennemies];

	this->_nb_ennemy += ennemies;
	for (int i = 0; i < ennemies; ++i)
	{
		fprintf(stderr, "nb ennemies == %d\n", this->_nb_ennemy);
		positions[i] = (i * ENNEMY_SLOT_SIZE(ennemies)) + (rand() % ENNEMY_SLOT_SIZE(ennemies));
		new_ennemy = new Crusader(positions[i], this->_playground);
		this->_ennemy_list = (Ennemy *)Entity::set_entity_at_end(this->_ennemy_list, new_ennemy);
	}
}

void				Game::player_shoot(Player const & player)
{
	Bullet*			new_bullet;

	new_bullet = new Bullet(true, player.get_pos_x(), player.get_pos_y(), 2, COLOR_MAGENTA | WA_BOLD, this->_playground);
	this->_bullet_list = (Bullet *)Entity::set_entity_at_end(this->_bullet_list, new_bullet);
}

void				Game::ennemies_shoot(void)
{
	Ennemy			*ptr;
	Bullet*			new_bullet;

	ptr = this->_ennemy_list;
	while (ptr)
	{
		if (ptr->get_shoot_frame() != 0)
		{
			if (ptr->get_nb_shoot() == 0)
			{
				std::cerr << "new bullet" << std::endl;
				new_bullet = new Bullet(false,
										ptr->get_pos_x() - 2,
										ptr->get_pos_y(),
										-2,
										COLOR_MAGENTA | WA_BOLD,
										this->_playground);
				this->_bullet_list = (Bullet *)Entity::set_entity_at_end(this->_bullet_list, new_bullet);
				ptr->set_nb_shoot(ptr->get_shoot_frame());
			}
			else
				ptr->set_nb_shoot(ptr->get_nb_shoot() - 1);
		}
		ptr = (Ennemy *)ptr->get_next();
	}
}

int					Game::start_game(void) {
	int		c = 0;
	float	sleep = 0.0f;
	clock_t	clock;

	while (42) {
		this->menu_window();
		clock = std::clock();
		if (this->players_alive() == false)
		{
			return (this->exit_game(-42));
		}
		if ((c = wgetch(this->_playground.get_win())) != 27) {
			switch(c) {
				case KEY_UP:
					this->move_player(0, 0, -1);
					break;
				case KEY_DOWN:
					this->move_player(0, 0, 1);
					break;
				case KEY_RIGHT:
					this->move_player(0, 1, 0);
					break;
				case KEY_LEFT:
					this->move_player(0, -1, 0);
					break;
				case ERR:
					break;
				default:
					this->player_shoot(*this->_players[0]);
					break;
			}
			flushinp();
		}
		if (this->exit_game(c) == 1)
			break;
		this->generate_ennemy();
		this->move_ennemies();
		this->ennemies_shoot();
		this->move_bullets();
		this->move_player(0, 0, 0);
		clock = std::clock() - clock;
		sleep = 1 / (float)TARGET_SLEEP * 1000000;
		if (sleep > clock)
			usleep(sleep - clock);
	}
	return (0);
}

bool				Game::players_alive(void)
{
	for (unsigned int i = 0; i < this->_nb_players; ++i)
	{
		if (this->_players[i]->get_life() == 0)
			return (false);
	}
	return (true);
}

#define SIZE_MENU sizeof("LEVEL :   , SCORE :         , PLAYER LIFE :    ")

void				Game::menu_window(void)
{
	mvwprintw(this->_menu.get_win(), this->_menu.get_lines() / 2, (this->_menu.get_cols() - sizeof("BIENVENUE")) / 2, "BIENVENUE");
	mvwprintw(this->_menu.get_win(), this->_menu.get_lines() - 1, (this->_menu.get_cols() - SIZE_MENU) / 2, "LEVEL : %2u, PLAYER LIFE : %3u, SCORE : %8u", this->_players[0]->get_level(), this->_players[0]->get_life(), this->_players[0]->get_score());
	wrefresh(this->_menu.get_win());
}

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

void			Game::move_bullets(void)
{
	if (this->_bullet_list)
		this->_bullet_list = (Bullet *)this->move_entity_list(this->_bullet_list, 1);
	return ;
}

void			Game::move_ennemies(void)
{
	if (this->_ennemy_list)
		this->_ennemy_list = (Ennemy *)this->move_entity_list(this->_ennemy_list, 0);
	return ;
}

void			Game::move_player(unsigned int index, int x, int y)
{
	int old_x, old_y = 0;

	(void)old_y;
	(void)old_x;
	Game::stock_pos(old_x, old_y, *this->_players[index]);
	this->_players[index]->move(x, y);
	this->_collision(2, this->_players[index], old_x, old_y);
	// verif de la position
	wattron(this->_playground.get_win(), this->_players[index]->get_color() | WA_BLINK);
	mvwaddch(this->_playground.get_win(), this->_players[index]->get_pos_y(),
			this->_players[index]->get_pos_x(), this->_players[index]->get_character());
	wattroff(this->_playground.get_win(), this->_players[index]->get_color() | WA_BLINK);
}

Entity*			Game::move_entity_list(Entity* list, int const i)
{
	Entity			*ptr = NULL;
	Entity			*next = NULL;
	int				old_x, old_y = 0;


	ptr = list;
	while (ptr)
	{
		Game::stock_pos(old_x, old_y, *ptr);
		mvwaddch(ptr->get_win().get_win(), ptr->get_pos_y(), ptr->get_pos_x(), ' ');
		ptr->move(1, 0);
		if (ptr->current_position_on_board_is_ok() == false || (this->_collision(i, ptr, old_x, old_y) && ptr->get_life() == 0))
		{
			next = ptr->get_next();
			list = Entity::delete_one_entity_on_list(list, ptr);
			ptr = next;
		}
		else
		{
			mvwaddch(ptr->get_win().get_win(), ptr->get_pos_y(), ptr->get_pos_x(), ptr->get_character());
			(void)old_y;
			(void)old_x;
			ptr = ptr->get_next();
		}
	}
	return (list);
}

typedef bool		(Game::*ft_check)(Entity *, int old_x, int old_y);
bool				Game::_collision(int const i, Entity *entity, int old_x, int old_y)
{
	ft_check	tab[] = {&Game::meet_ennemies,
						 &Game::meet_bullets,
						 &Game::meet_player};
	for (int j = 0; j < 3; ++j)
	{
		if (j == i)
			continue;
		if ((this->*tab[j])(entity, old_x, old_y))
			return (true);
	}
	return (false);
}

bool			Game::meet_player(Entity *entity, int old_x, int old_y)
{
	Entity *	ptr = NULL;
	int			min_y, max_y = 0;
	int			min_x, max_x = 0;

	min_x = old_x > entity->get_pos_x() ? entity->get_pos_x() : old_x;
	max_x = min_x != old_x ? old_x : entity->get_pos_x();
	min_y = old_y > entity->get_pos_y() ? entity->get_pos_y() : old_y;
	max_y = min_y != old_y ? old_y : entity->get_pos_y();
	for (unsigned int i = 0; i < this->_nb_players; ++i)
	{
		ptr = this->_players[i];
		if (ptr->get_is_ally() != entity->get_is_ally() &&
			(min_y <= ptr->get_pos_y() && ptr->get_pos_y() <= max_y) &&
			(min_x <= ptr->get_pos_x() && ptr->get_pos_x() <= max_x))
		{
			ptr->take_damage(entity->get_damage_point());
			entity->take_damage(ptr->get_damage_point());

			return (true);
		}
	}
	return (false);
}

bool			Game::meet_bullets(Entity *entity, int old_x, int old_y)
{
	Entity *	ptr = NULL;
	int			min_y, max_y = 0;
	int			min_x, max_x = 0;

	min_x = old_x > entity->get_pos_x() ? entity->get_pos_x() : old_x;
	max_x = min_x != old_x ? old_x : entity->get_pos_x();
	min_y = old_y > entity->get_pos_y() ? entity->get_pos_y() : old_y;
	max_y = min_y != old_y ? old_y : entity->get_pos_y();
	ptr = this->_bullet_list;
	while (ptr)
	{
		if (ptr->get_is_ally() != entity->get_is_ally() &&
			(min_y <= ptr->get_pos_y() && ptr->get_pos_y() <= max_y) &&
			(min_x <= ptr->get_pos_x() && ptr->get_pos_x() <= max_x))
		{
			ptr->take_damage(entity->get_damage_point());
			entity->take_damage(ptr->get_damage_point());
			if (ptr->get_life() == 0)
			{
				mvwaddch(ptr->get_win().get_win(), ptr->get_pos_y(), ptr->get_pos_x(), ' ');
				this->_bullet_list = (Bullet*)Entity::delete_one_entity_on_list(this->_bullet_list, ptr);
			}
			return (true);
		}
		ptr = ptr->get_next();
	}
	return (false);
}

bool			Game::meet_ennemies(Entity *entity, int old_x, int old_y)
{
	Entity *	ptr = NULL;
	int			min_y, max_y = 0;
	int			min_x, max_x = 0;

	min_x = old_x > entity->get_pos_x() ? entity->get_pos_x() : old_x;
	max_x = min_x != old_x ? old_x : entity->get_pos_x();
	min_y = old_y > entity->get_pos_y() ? entity->get_pos_y() : old_y;
	max_y = min_y != old_y ? old_y : entity->get_pos_y();
	ptr = this->_ennemy_list;
	while (ptr)
	{
		if (ptr->get_is_ally() != entity->get_is_ally() &&
			(min_y <= ptr->get_pos_y() && ptr->get_pos_y() <= max_y) &&
			(min_x <= ptr->get_pos_x() && ptr->get_pos_x() <= max_x))
		{
			ptr->take_damage(entity->get_damage_point());
			entity->take_damage(ptr->get_damage_point());
			if (ptr->get_life() == 0)
			{
				mvwaddch(ptr->get_win().get_win(), ptr->get_pos_y(), ptr->get_pos_x(), ' ');
				this->_ennemy_list = (Ennemy*)Entity::delete_one_entity_on_list(this->_ennemy_list, ptr);
			}
			return (true);
		}
		ptr = ptr->get_next();
	}
	return (false);
}

bool		Game::exit_game(int c)
{
	bool	quit = false;
	if (c == 27 || c == KEY_RESIZE || c == -42)
	{
		Window		*pause = new Window(20, LINES / 2 - 20, 50);
		mvwprintw(pause->get_win(), pause->get_lines() / 2, (pause->get_cols() - sizeof("JEU EN PAUSE")) / 2, "JEU EN PAUSE");
		nodelay(pause->get_win(), false);
		keypad(pause->get_win(), TRUE);
		c = wgetch(pause->get_win());
		if (c == 27 || c == KEY_RESIZE)
			quit = true;
		werase(pause->get_win());
		wrefresh(pause->get_win());
		delete(pause);
	}
	return (quit);
}

/*************************     NON MEMBER FUNTIONS     ************************/

void			Game::stock_pos(int &x, int &y, Entity &ref)
{
	x = ref.get_pos_x();
	y = ref.get_pos_y();
	mvwaddch(ref.get_win().get_win(), y, x, ' ');
}

/*************************     EXTERNAL OVERLOADS     *************************/
