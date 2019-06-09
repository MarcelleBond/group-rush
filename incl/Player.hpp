/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09/01/13 by rhohls          #+#    #+#             */
/*   Updated: 2019/06/09 09/01/13 by rhohls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PLAYER_HPP
# define	PLAYER_HPP

#include "Entity.hpp"
#include "Enemy.hpp"

class Player : public Entity{
	public:
		Player();

		Player(int xmax, int ymax);
		Player(int xmax, int ymax, int xpos, int ypos);

		Player(Player const & src);

		int shoot(Enemy enemy[], int length);
		void moveUp();
		void moveDown();
		const char *getPlayerSymbol();

		~Player();
		Player & operator=(Player const & src);
	private:

	protected:

};

#endif
