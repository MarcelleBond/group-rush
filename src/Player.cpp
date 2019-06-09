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

Player::Player() {
	this->m_xpos = 0;
	this->m_ypos = 0;
}

Player::Player(int xpos, int ypos) {
	this->m_xpos = xpos;
	this->m_ypos = ypos;
}

Player::Player(Player const & src) {
	*this = src;	
}

Player::~Player() {}

Player & Player::operator=(Player const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

