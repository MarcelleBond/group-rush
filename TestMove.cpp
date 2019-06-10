/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestMove.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/10 13:10:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Player.hpp"
#include "./incl/Entity.hpp"
#include "./incl/Enemy.hpp"
#include <iostream>
#include <ncurses.h>
#include <printf.h>

#define NUM_ENEMY 8


int main()
{
    int xmax=10,ymax=10;
    Player player = Player(xmax, ymax, 3, 4);

    printf("x: %d, y: %d \n", player.getXPos(), player.getYPos());
    player.moveUp();
    printf("x: %d, y: %d \n", player.getXPos(), player.getYPos());
    player.moveDown();
    printf("x: %d, y: %d \n", player.getXPos(), player.getYPos());

    player.setYPos(21);
    printf("x: %d, y: %d \n", player.getXPos(), player.getYPos());

    return 1; 
}
