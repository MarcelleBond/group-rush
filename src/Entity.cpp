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

void Entity::setXPos(int update_val)
{
	this->m_xpos = update_val;
}
void Entity::setYPos(int update_val)
{
	this->m_ypos = update_val;
}
