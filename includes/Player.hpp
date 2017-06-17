#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include "Entity.hpp"

class Player : public Entity {

public:

	Player(void);
	Player(std::string name, int const n);
	Player(Player const & src);
	~Player();

	Player &	operator=(Player const & rhs);

	std::string	get_name(void) const;

private:
	std::string	_name;

};

std::ostream &		operator<<(std::ostream & o, Player const & rhs);

#endif
