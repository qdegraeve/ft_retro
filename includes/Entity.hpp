/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 09:55:04 by mressier          #+#    #+#             */
/*   Updated: 2017/06/17 11:52:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <iostream>

class Entity
{
	public:
		Entity(std::string type,
				unsigned int life_max,
				unsigned int damage_point,
				unsigned int pos_x,
				unsigned int pos_y,
				int speed);								/* constructor by default */
		Entity(Entity const & src);						/* constructor by copy */
		virtual ~Entity();								/* destructor */

		Entity & operator=(Entity const & rhs);								/* overload operator = */


		void

		void	takeDamage(unsigned int amount) const;
		void	move() const; //TEMP

	protected:

			std::string	const		_type;				//to confirm
			unsigned int			_life_max;
			unsigned int			_life;
			unsigned int			_damage_point;
			unsigned int			_pos_x;
			unsigned int			_pos_y;
			int						_speed;

	private:

};

std::ostream &		operator<<(std::ostream & o, Entity const & rhs);

#endif /* ENTITY_HPP */

test() : Entity("bullet", 54)

test2() : Entity("test2", asdsd)