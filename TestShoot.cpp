/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestShoot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/10 13:37:18 by rhohls           ###   ########.fr       */
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
    int x = 10;
    int y = 10;
    
    Player player = Player(x,y,2, 2);
    
    Enemy *list_enemies[NUM_ENEMY];
    for (int i = 0; i < NUM_ENEMY; i++)
    {
        list_enemies[i] = new Enemy(x, y, x, i);
        // printf("made enemy- x:%d y:%d size:%d\n", list_enemies[i]->getXPos(), list_enemies[i]->getYPos(), list_enemies[i]->getYSize());
    }

    Enemy *list_objects[NUM_ENEMY];
    for (int i = 0; i < NUM_ENEMY; i++)
    {
        list_objects[i] = new Enemy(x, y, x, (2*i), "*", 2, 2);
    }

    player.setYPos(2);
    int test1 = player.shoot(list_enemies, NUM_ENEMY);
    printf("Output should be 2 -res- |%d|\n", test1 + 1);

    player.setYPos(2);
    int test2 = player.shoot(list_objects, NUM_ENEMY);
    printf("Output should be 1 -res- |%d|\n", test2 + 1);  
    return 1; 
}



