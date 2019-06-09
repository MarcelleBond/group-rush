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

#include "Enemy.hpp"
#include <iostream>
#include <stdlib.h>

Enemy::Enemy()
{
	std::cout << "Warning default constructor called" << std::endl;
	init(0, 0, 256, 256, "<");
}

Enemy::Enemy(int xmax, int ymax)
{
	init(0, 0, xmax, ymax, "<");
}
Enemy::Enemy(int xmax, int ymax, int xpos, int ypos)
{
	init(xpos, ypos, xmax, ymax, "<");
}
Enemy::Enemy(int xmax, int ymax, int xpos, int ypos, char *symbol)
{
	init(xpos, ypos, xmax, ymax, symbol);
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

	rand_y = rand() % this->m_ymax;
	setPos(this->m_xmax, rand_y);
}
