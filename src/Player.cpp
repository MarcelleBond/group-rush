/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09/01/13 by rhohls          #+#    #+#             */
/*   Updated: 2019/06/09 09/01/13 by rhohls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <iostream>

Player::Player()
{
	std::cout << "Warning default constructor called" << std::endl;
	init(0, 0, 256, 256);
}

Player::Player(int xmax, int ymax)
{
	init(0, 0, xmax, ymax);
}
Player::Player(int xmax, int ymax, int xpos, int ypos)
{
	init(xpos, ypos, xmax, ymax);
}

Player::Player(Player const &src)
{
	*this = src;
}

Player::~Player() {}

Player &Player::operator=(Player const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

bool Player::shoot(Enemy enemy[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (enemy[i].getYPos() == this->m_ypos)
		{
			enemy[i].Die();
			return true;
		}
	}
		return false;
}

void Player::moveUp()
{
	setYPos(this->m_ypos++);
}
void Player::moveDown()
{
	setYPos(this->m_ypos--);
}