/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09/01/13 by rhohls          #+#    #+#             */
/*   Updated: 2019/06/09 09/01/13 by rhohls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity() {}

Entity::Entity(Entity const &src)
{
	*this = src;
}

Entity::~Entity() {}

Entity &Entity::operator=(Entity const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}
 
int const & Entity::getXPos()
{
	return (this->m_xpos);
}
int const & Entity::getYPos()
{
	return (this->m_xpos);
}

char *Entity::getSymbol()
{
	return(this->m_symbol);
}

void Entity::setXPos(int update_val)
{
	this->m_xpos = update_val;
	if (this->m_xpos > this->m_xmax)
		this->m_xpos = this->m_xmax;
	else if (this->m_xpos < 0)
		this->m_xpos =0;
}

void Entity::setYPos(int update_val)
{
	this->m_ypos = update_val;
	if (this->m_ypos > this->m_ymax)
		this->m_ypos = this->m_ymax;
	else if (this->m_ypos < 0)
		this->m_ypos = 0;
}

void Entity::setPos(int new_X, int new_Y)
{
	setXPos(new_X);
	setYPos(new_Y);
}

void Entity::init(int xpos, int ypos, int xmax, int ymax, char *symbol){
	m_xpos = xpos;
	m_ypos = ypos;
	m_xmax = xmax;
	m_ymax = ymax;
	m_symbol = symbol;
}
