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
		Enemy();

		Enemy(int xmax, int ymax);
		Enemy(int xmax, int ymax, int xpos, int ypos);
		Enemy(int xmax, int ymax, int xpos, int ypos, char *symbol);
		Enemy(Enemy const & src);
		~Enemy();
		Enemy & operator=(Enemy const & src);

		void Die();
	private:

	protected:

};

#endif
