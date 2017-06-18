#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include "Entity.hpp"

class Player : public Entity {

public:

	Player(int color, Window const & win);
	Player(Player const & src);
	virtual ~Player();

	Player &			operator=(Player const & rhs);

	/* Getter */
	std::string	const	get_name(void) const;
	unsigned int		get_level(void) const;
	unsigned int		get_score(void) const;
	unsigned int		get_nb_ennemy_to_shoot(void) const;

	/* Setter */
	void				set_name(std::string const & name);
	void				increase_score(unsigned int amount);
	void				increase_level(unsigned int amount);

	virtual void		move(int x_move, int y_move);

	protected:
		std::string		_name;

	private:
		unsigned int		_level;
		unsigned int		_score;
		unsigned int		_nb_ennemy_to_shoot;

};

std::ostream &		operator<<(std::ostream & o, Player const & rhs);

#endif
