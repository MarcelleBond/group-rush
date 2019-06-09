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



class Enemy {
	public:
		Enemy();
		Enemy(Enemy const & src);
		~Enemy();
		Enemy & operator=(Enemy const & src);

		void Die();
	private:
	int Xmax;
	int Ymax;
	protected:

};

#endif
