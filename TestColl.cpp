/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestColl.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/10 15:00:26 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Player.hpp"
#include "./incl/Entity.hpp"
#include "./incl/Enemy.hpp"
#include <iostream>
#include <ncurses.h>
#include <printf.h>

#define NUM_ENEMY 1


int main()
{
    int x = 11;
    int y = 11;
    
    Player player = Player(x,y, x,y);
    
    Enemy *list_objects[NUM_ENEMY];
    for (int i = 0; i < NUM_ENEMY; i++)
    {
        list_objects[i] = new Enemy(x, y, x, y, "*", 2, 2);
    }
    bool test;
    bool test = player.collision(list_objects, NUM_ENEMY);
    printf("Output should be 1 -res- |%d|\n", test ); 
    
    player.setYPos(0);
    test = player.collision(list_objects, NUM_ENEMY);
    printf("Output should be 0 -res- |%d|\n", test );

    player.setYPos(0);
    test = player.collision(list_objects, NUM_ENEMY);
    printf("Output should be 0 -res- |%d|\n", test );
    return 1; 
}



