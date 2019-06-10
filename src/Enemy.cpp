/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09/01/13 by rhohls          #+#    #+#             */
/*   Updated: 2019/06/09 09/01/13 by rhohls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Enemy.hpp"
#include <iostream>
#include <stdlib.h>

Enemy::Enemy()
{
	std::cout << "Warning default constructor called" << std::endl;
	init(0, 0, 256, 256, "<", 1, 1);
}

Enemy::Enemy(int xmax, int ymax)
{
	init(0, 0, xmax, ymax, "<", 1, 1);
}
Enemy::Enemy(int xmax, int ymax, int xpos, int ypos)
{
	init(xpos, ypos, xmax, ymax, "<", 1, 1);
}
// Enemy::Enemy(int xmax, int ymax, int xpos, int ypos)
// {
// 	init(xpos, ypos, xmax, ymax, "<", 1, 1);
// }
Enemy::Enemy(int xmax, int ymax, int xpos, int ypos, const char *symbol)
{
	init(xpos, ypos, xmax, ymax, symbol, 1, 1);
}
Enemy::Enemy(int xmax, int ymax, int xpos, int ypos, const char *symbol, int xsize, int ysize)
{
	init(xpos, ypos, xmax, ymax, symbol, xsize, ysize);
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(Enemy const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

void Enemy::Die()
{
	int rand_y;
	int max;

	if (m_ymax == 0)
		max = 10;
	else
		max = m_ymax;
	
	rand_y = rand() % (max) + 1 ;
	// rand_y = 10;
	setPos(this->m_xmax, rand_y);
}