#ifndef GAME_HPP
# define GAME_HPP

#include "Player.hpp"
#include "Bullet.hpp"
#include "Ennemy.hpp"
#include <iostream>

#define NB_MAX_PLAYER 1

class Game
{
	public:
		Game(unsigned int nb_player);			/* constructor by default */
		Game(Game const & src);					/* constructor by copy */
		~Game();								/* destructor */

		/* Getters */
		unsigned int		get_nb_players(void) const;
		Player&				get_player(unsigned int index) const;

		/* Setters */

	protected:

		// GenerateEnemy();
		// checkCollision();
		// Draw();

	private:
		Game(void);								/* constructor by default */
		Game & operator=(Game const & rhs);		/* overload operator = */


		unsigned int		_nb_players;
		Player*				_players;
		unsigned int		_nb_enemies;
		Ennemy*				_enemy_list;
		unsigned int		_nb_bullet;
		Bullet*				_bullet_list;

};
#endif /* GAME_HPP */
