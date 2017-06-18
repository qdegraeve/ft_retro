#ifndef GAME_HPP
# define GAME_HPP

#include "Player.hpp"
#include "Bullet.hpp"
#include "Ennemy.hpp"
#include <iostream>
#include <unistd.h>

# define NB_MAX_PLAYER 1
# define HEIGHT_MENU 10
# define WIN_SPACE 2
# define BEGIN_PG (HEIGHT_MENU + 4)
# define PLAYGROUND_HEIGHT (LINES - BEGIN_PG - WIN_SPACE)
# define MAX_ENEMIES_PER_TURN (PLAYGROUND_HEIGHT / 16)
# define ENNEMY_SLOT_SIZE(x) (PLAYGROUND_HEIGHT / x)
# define TARGET_SLEEP 20

class Game
{
	public:
		Game(unsigned int nb_player);			/* constructor by default */
		Game(Game const & src);					/* constructor by copy */
		~Game();								/* destructor */

		/* Getters */
		unsigned int		get_nb_players(void) const;
		Player&				get_player(unsigned int index) const;
		unsigned int		get_nb_ennemy(void) const;
		Ennemy*				get_ennemy_list(void) const;

		/* Setters */

		/* Ennemy functions */
		void				generate_ennemy(void);

		/* Player functions */
		void				move_player();
		void				player_shoot(Player const & player);

		/* Bullets */
		void				move_bullets(void);

		/* Ennemy */
		void				move_ennemies(void);

		/* Ennemy */
		void				move_player(unsigned int index, int x, int y);
		Entity*				move_entity_list(Entity* list, int const i);

		Window const &	_menu;
		Window const &	_playground;

		/* Play interface */
		int				start_game(void);
		bool			exit_game(int c);
		void			menu_window(void);
		bool			players_alive(void);

		/* Non member functions */
		static void		stock_pos(int &x, int &y, Entity &ref);

	protected:

		bool			meet_ennemies(Entity *entity, int old_x, int old_y);
		bool			meet_player(Entity *entity, int old_x, int old_y);
		bool			meet_bullets(Entity *entity, int old_x, int old_y);

		// checkCollision();
		// Draw();

	private:

		Game(void);								/* constructor by default */
		Game & operator=(Game const & rhs);		/* overload operator = */

		bool				_collision(int const i, Entity *entity, int old_x, int old_y);

		unsigned int		_nb_players;
		Player*				_players[NB_MAX_PLAYER];
		unsigned int		_nb_ennemy;
		Ennemy*				_ennemy_list;
		unsigned int		_nb_bullet;
		Bullet*				_bullet_list;
};
#endif /* GAME_HPP */
