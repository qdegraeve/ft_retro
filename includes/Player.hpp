#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include "Entity.hpp"

class Player : public Entity {

public:

	Player(void);
	Player(Player const & src);
	virtual ~Player();

	Player &		operator=(Player const & rhs);

	/* Getter */
	std::string	const	get_name(void) const;

	/* Setter */
	void				set_name(std::string const & name);

	protected:
		std::string		_name;

	private:
};

std::ostream &		operator<<(std::ostream & o, Player const & rhs);

#endif
