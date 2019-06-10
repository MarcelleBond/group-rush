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

#include "../incl/Player.hpp"
#include <iostream>
#include <ncurses.h>
Player::Player() 
{
	std::cout << "Warning default constructor called" << std::endl;
	init(0, 0, 256, 256, ">", 1, 1);
}

Player::Player(int xmax, int ymax) 
{
	init(0, 0, xmax, ymax, ">", 1, 1);
}
Player::Player(int xmax, int ymax, int xpos, int ypos)
{
	init(xpos, ypos, xmax, ymax, ">", 1, 1);
}

Player::Player(int xmax, int ymax, int xpos, int ypos, int numlives)
{
	init(xpos, ypos, xmax, ymax, ">", 1, 1);
	m_numLives = numlives;
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

void Player::init(int xpos, int ypos, int xmax, int ymax, const char *symbol, int xsize, int ysize){
	m_xpos = xpos;
	m_ypos = ypos;
	m_xmax = xmax;
	m_ymax = ymax;
	m_symbol = symbol;
	m_xsize = xsize;
	m_ysize = ysize;
	m_numLives = 5;
	score = 0;
}



const char *Player::getPlayerSymbol()
{
	return getSymbol();
}

int Player::shoot(Enemy *enemy[], int length)
{
	int index = -1;
	for (int i = 0; i < length; i++)
	{
		if ((enemy[i]->getYPos() <= this->m_ypos) && 
			((enemy[i]->getYPos() + enemy[i]->getYSize() -1) >= this->m_ypos))
		{
			if ((index = -1) || (enemy[i]->getXPos() < enemy[index]->getXPos()))
				index = i;
		}
	}
	return (index);
}

bool Player::collision(Enemy *enemy[], int length)
{
	for (int i = 0; i < length; i++)
	{
		// printf("int i : %d", i);
		if (this->chk_collision(enemy[i], this))
		{
			return (true);
		}
	}
	return (false);
}

bool Player::chk_collision(Entity *objA, Entity *objB){
	// printf("A- x:%d y:%d s:%d\n", objA->getXPos(),objA->getYPos(), objA->getXSize());
	// printf("B- x:%d y:%d s:%d\n", objB->getXPos(),objB->getYPos(), objB->getXSize());

    if ((objB->getXPos() >= objA->getXPos()) && 
		(objB->getXPos() <= (objA->getXPos() + objA->getXSize() -1)))
    {
        if ((objB->getYPos() >= objA->getYPos()) && 
				(objB->getYPos() <= (objA->getYPos() + objA->getYSize() -1)))
            return (true);
    }
    
    if ((objA->getXPos() >= objB->getXPos()) && 
		(objA->getXPos() <= (objB->getXPos() + objB->getXSize() -1)))
    {
        if ((objA->getYPos() >= objB->getYPos()) && 
				(objA->getYPos() <= (objB->getYPos() + objB->getYSize() -1)))
            return (true);
    }

    return false;  
}



