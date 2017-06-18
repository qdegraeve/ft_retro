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
		this->_players[i] = new Player(COLOR_PAIR(i + 1), this->_playground);
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
typedef void		(Game::*rand_ennemy)(unsigned int);
void				Game::generate_ennemy(void)
{
	rand_ennemy		tab[] = {&Game::new_star_hunter,
						 	&Game::new_crusader,
						 	&Game::new_asteroid};
	int				ennemies = (rand() % MAX_ENEMIES_PER_TURN(this->_players[0]->get_level())) + 1;
	int				positions[ennemies];

	this->_nb_ennemy += ennemies;
	for (int pos_y = 0; pos_y < ennemies; ++pos_y)
	{
		positions[pos_y] = (pos_y * ENNEMY_SLOT_SIZE(ennemies)) + (rand() % ENNEMY_SLOT_SIZE(ennemies));
		(this->*tab[rand() % 3])(positions[pos_y]);
	}
}

void				Game::new_star_hunter(unsigned int pos_y)
{
	Ennemy			*new_ennemy;

	new_ennemy = new StarHunter(pos_y, this->_playground);
	this->_ennemy_list = (Ennemy *)Entity::set_entity_at_end(this->_ennemy_list, new_ennemy);
}


void				Game::new_crusader(unsigned int pos_y)
{
	Ennemy			*new_ennemy;

	new_ennemy = new Crusader(pos_y, this->_playground);
	this->_ennemy_list = (Ennemy *)Entity::set_entity_at_end(this->_ennemy_list, new_ennemy);
}


void				Game::new_asteroid(unsigned int pos_y)
{
	Ennemy			*new_ennemy;

	for (int j = 1; j >= 0; j--)
	{
		for (int x = 1; x >= 0; x--)
		{
			new_ennemy = new Asteroid(x, pos_y - j, this->_playground);
			this->_ennemy_list = (Ennemy *)Entity::set_entity_at_end(this->_ennemy_list, new_ennemy);
		}
	}
}

void				Game::player_shoot(Player const & player)
{
	Bullet*			new_bullet;

	new_bullet = new Bullet(true, player.get_pos_x(), player.get_pos_y(), 2, COLOR_PAIR(FT_YELLOW), this->_playground);
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
				new_bullet = new Bullet(false,
										ptr->get_pos_x() - 2,
										ptr->get_pos_y(),
										-2,
										COLOR_PAIR(FT_MAGENTA),
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
	int		i = 0;
	int		j;

	while (42) {
		this->menu_window();
		clock = std::clock();
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
		if (c == 27 || c == KEY_RESIZE || !this->players_alive())
		{
			if (!this->players_alive())
				this->new_game();
			if (this->pause_menu())
				break;
		}
		j = this->_players[0]->get_level() >= 20 ? 1 : 20 - this->_players[0]->get_level();
		if (i++ % j == 0)
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

#define SIZE_MENU sizeof("LEVEL :   , SCORE :         , TO KILL :    ")
#define SIZE_LIFE sizeof("PLAYER LIFE :    ")

void				Game::menu_window(void)
{
	mvwprintw(this->_menu.get_win(), this->_menu.get_lines() / 2, (this->_menu.get_cols() - sizeof("BIENVENUE")) / 2, "BIENVENUE");
	mvwprintw(this->_menu.get_win(), this->_menu.get_lines() - 2, (this->_menu.get_cols() - SIZE_MENU) / 2, "LEVEL : %2u, , SCORE : %8u, TO KILL : %3u", this->_players[0]->get_level(), this->_players[0]->get_score(), this->_players[0]->get_nb_ennemy_to_shoot());
	wattron(this->_menu.get_win(), this->_players[0]->get_color() | WA_BOLD);
	mvwprintw(this->_menu.get_win(), this->_menu.get_lines() - 1, (this->_menu.get_cols() - SIZE_LIFE) / 2, "PLAYER LIFE : %3u",this->_players[0]->get_life());
	wattroff(this->_menu.get_win(), this->_players[0]->get_color() | WA_BOLD);
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
	wattron(this->_playground.get_win(), this->_players[index]->get_color() | WA_BOLD);
	mvwaddch(this->_playground.get_win(), this->_players[index]->get_pos_y(),
			this->_players[index]->get_pos_x(), this->_players[index]->get_character());
	wattroff(this->_playground.get_win(), this->_players[index]->get_color() | WA_BOLD);
}

Entity*			Game::move_entity_list(Entity* list, int const i)
{
	Entity			*ptr = NULL;
	Entity			*next = NULL;
	int				old_x, old_y = 0;
	int				collision;

	ptr = list;
	while (ptr)
	{
		Game::stock_pos(old_x, old_y, *ptr);
		ptr->move(1, 0);
		collision = false;
		if (ptr->current_position_on_board_is_ok() == false
				|| ((collision = this->_collision(i, ptr, old_x, old_y)) && ptr->get_life() == 0))
		{
			if (ptr->get_is_ally() == false && collision)
				this->_players[0]->increase_score(ptr->get_damage_point());
			next = ptr->get_next();
			list = Entity::delete_one_entity_on_list(list, ptr);
			ptr = next;
		}
		else
		{
			wattron(this->_playground.get_win(), ptr->get_color() | WA_BOLD);
			mvwaddch(ptr->get_win().get_win(), ptr->get_pos_y(), ptr->get_pos_x(), ptr->get_character());
			wattroff(this->_playground.get_win(), ptr->get_color() | WA_BOLD);
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
		if (entity == ptr)
		{
			ptr = ptr->get_next();
			continue;
		}
		if (ptr->get_is_ally() != entity->get_is_ally() &&
			(min_y <= ptr->get_pos_y() && ptr->get_pos_y() <= max_y) &&
			(min_x <= ptr->get_pos_x() && ptr->get_pos_x() <= max_x))
		{
			ptr->take_damage(entity->get_damage_point());
			entity->take_damage(ptr->get_damage_point());
			if (ptr->get_life() == 0)
			{
				if (ptr->get_is_ally() == false)
					this->_players[0]->increase_score(1);
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
				if (ptr->get_is_ally() == false)
					this->_players[0]->increase_score(ptr->get_damage_point());
				mvwaddch(ptr->get_win().get_win(), ptr->get_pos_y(), ptr->get_pos_x(), ' ');
				this->_ennemy_list = (Ennemy*)Entity::delete_one_entity_on_list(this->_ennemy_list, ptr);
			}
			return (true);
		}
		ptr = ptr->get_next();
	}
	return (false);
}

bool		Game::pause_menu(void)
{
	Window		*pause = new Window(20, LINES / 2 - 20, 50);
	bool		quit = false;
	mvwprintw(pause->get_win(), 4, WRITE_CENTER(sizeof("JEU EN PAUSE")),  "JEU EN PAUSE");
	quit = this->send_action(pause->get_win());
	werase(pause->get_win());
	wrefresh(pause->get_win());
	delete(pause);
	box(this->_playground.get_win(), 0, 0);
	wrefresh(this->_playground.get_win());
	box(this->_menu.get_win(), 0, 0);
	wrefresh(this->_menu.get_win());
	return (quit);
}

typedef bool		(Game::*action)(void);
bool				Game::send_action(WINDOW *win)
{
	action			tab[] = {&Game::new_game,
						 &Game::resume,
						 &Game::exit_game};
	std::string		choices[] = {"NEW GAME", "RESUME", "EXIT"};
	int				lines = 6;
	unsigned int	highlight = 0;
	int				c;

	nodelay(win, false);
	keypad(win, TRUE);
	while (42) {
		wattron(win, COLOR_PAIR(FT_BLUE) | WA_BOLD);
		for (unsigned int i = 0; i < 3; ++i)
		{
			if (i == highlight)
				wattron(win, WA_REVERSE);
			mvwprintw(win, lines += 2, WRITE_CENTER(choices[i].length()),  choices[i].c_str());
			wattroff(win, WA_REVERSE);
		}
		wattroff(win, COLOR_PAIR(FT_BLUE) | WA_BOLD);
		lines = 6;
		c = wgetch(win);
		switch(c) {
			case KEY_UP:
				highlight = highlight == 0 ? 2 : highlight - 1;
				break;
			case KEY_DOWN:
				highlight = (highlight + 1) % 3;
				this->move_player(0, 0, 1);
				break;
			case 27:
				return (this->exit_game());
			case KEY_RESIZE:
				return (this->exit_game());
			case 10:
				return ((this->*tab[highlight])());
			case ERR:
				break;
			default:
				break;
		}
	}
}


bool		Game::new_game()
{
	Entity::delete_entity_list(this->_ennemy_list);
	this->_ennemy_list = NULL;
	Entity::delete_entity_list(this->_bullet_list);
	this->_bullet_list = NULL;
	werase(this->_playground.get_win());
	box(this->_playground.get_win(), 0, 0);
	wrefresh(this->_playground.get_win());
	for (unsigned int i = 0; i < this->_nb_players; ++i)
	{
		this->_players[i]->reset_player();
	}
	return (false);
}

bool		Game::resume()
{
	return (false);
}

bool		Game::exit_game()
{
	return (true);
}

/*************************     NON MEMBER FUNTIONS     ************************/

void			Game::stock_pos(int &x, int &y, Entity &ref)
{
	x = ref.get_pos_x();
	y = ref.get_pos_y();
	mvwaddch(ref.get_win().get_win(), y, x, ' ');
}

/*************************     EXTERNAL OVERLOADS     *************************/
