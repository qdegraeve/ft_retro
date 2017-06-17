#ifndef GAME_HPP
# define GAME_HPP

class Game
{
	public:
		Game();									/* constructor by default */
		Game(Game const & src);					/* constructor by copy */
		~Game();								/* destructor */

		Game & operator=(Game const & rhs);		/* overload operator = */

	private:

		GenerateEnemy();
		checkCollision();
		Draw();


		Player		*players;
		Enemy		*enemy_list;
		Bullet		*bullet_list;



};
#endif /* GAME_HPP */
