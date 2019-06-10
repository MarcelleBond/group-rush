/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09/01/13 by rhohls          #+#    #+#             */
/*   Updated: 2019/06/09 09/01/13 by rhohls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ENEMY_HPP
# define	ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity {
	public:
		int points;
		Enemy();

		Enemy(int xmax, int ymax);
		Enemy(int xmax, int ymax, int xpos, int ypos);
		Enemy(int xmax, int ymax, int xpos, int ypos, int in_points);
		Enemy(int xmax, int ymax, int xpos, int ypos, const char *symbol);
		Enemy(int xmax, int ymax, int xpos, int ypos, const char *symbol, int xsize, int ysize);

		Enemy(Enemy const & src);
		~Enemy();
		Enemy & operator=(Enemy const & src);

		void init(int xpos, int ypos, int xmax, int ymax, const char *symbol, int xsize, int ysize);
		void Die();
	private:

	protected:

};

#endif
