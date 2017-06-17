/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 09:55:04 by mressier          #+#    #+#             */
/*   Updated: 2017/06/17 10:02:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

class Entity
{
	public:
		Entity();									/* constructor by default */
		Entity(Entity const & src);					/* constructor by copy */
		~Entity();									/* destructor */

		Entity & operator=(Entity const & rhs);		/* overload operator = */

		void	takeDamage(unsigned int amount) const;
		void	move() const; //TEMP

	protected:

			unsigned int		_pos_x;
			unsigned int		_pos_y;
			unsigned int		_life;
			unsigned int		_damage;


	private:

};
#endif /* ENTITY_HPP */
