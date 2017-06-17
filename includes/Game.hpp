/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:01:23 by mressier          #+#    #+#             */
/*   Updated: 2017/06/17 10:03:04 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

};
#endif /* GAME_HPP */
