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

#include "../incl/Entity.hpp"

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
 
int Entity::getXPos()
{
	return (m_xpos);
}
int Entity::getYPos()
{
	return m_ypos;
}
int Entity::getXSize()
{
	return m_xsize;
}
int Entity::getYSize()
{
	return (m_ysize );
}


const char *Entity::getSymbol()
{
	return(m_symbol);
}

void Entity::setXPos(int update_val)
{
	m_xpos = update_val;
	if (m_xpos > m_xmax)
		m_xpos = m_xmax;
	else if (m_xpos < 0)
		m_xpos =0;
}

void Entity::setYPos(int update_val)
{
	m_ypos = update_val;
	if (m_ypos > m_ymax)
		m_ypos = m_ymax;
	else if (m_ypos < 1)
		m_ypos = 1;
}

void Entity::setPos(int new_X, int new_Y)
{
	setXPos(new_X);
	setYPos(new_Y);
}

void Entity::moveUp()
{
	setYPos(m_ypos + 1);
}
void Entity::moveDown()
{
	setYPos(m_ypos - 1);
}


