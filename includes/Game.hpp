#ifndef GAME_HPP
# define GAME_HPP

#include "Player.hpp"
#include "Bullet.hpp"
#include "Ennemy.hpp"
#include <iostream>

#define NB_MAX_PLAYER 1
#define HEIGHT_MENU 10
#define WIN_SPACE 2
#define BEGIN_PG (HEIGHT_MENU - (2 * WIN_SPACE))

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
		void				player_shoot(Player const & player);

		/* Bullets */
		void			move_bullets(void);

		/* Ennemy */
		void			move_ennemy(void);

	protected:

		// checkCollision();
		// Draw();

	private:

		Game(void);								/* constructor by default */
		Game & operator=(Game const & rhs);		/* overload operator = */

		unsigned int		_nb_players;
		Player*				_players[NB_MAX_PLAYER];
		unsigned int		_nb_ennemy;
		Ennemy*				_ennemy_list;
		unsigned int		_nb_bullet;
		Bullet*				_bullet_list;
		Window const &		_menu;
		Window const &		_playground;

};
#endif /* GAME_HPP */
