#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include "Entity.hpp"

class Player : public Entity {

public:

	Player(std::string name);
	Player(Player const & src);
	virtual ~Player();

	Player &		operator=(Player const & rhs);

	/* Getter */
	std::string		get_name(void) const;

	protected:
		std::string		_name;

	private:
		Player(void);
};

std::ostream &		operator<<(std::ostream & o, Player const & rhs);

#endif
