/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/09 13:53:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Player.hpp"
#include "./incl/Entity.hpp"
#include "./incl/Player.hpp" 
#include <iostream>
#include <ncurses.h>

/* bool collision(Entity &objA, Entity &objB)
{
    // if ((objB.getXPos() >= objA.getXPos()) && ((objB.getXPos() + objB.getXSize()) <= objA.getXPos()))
    // {
    //     if ((objB.getYPos() >= objA.getYPos()) && ((objB.getYPos() + objB.getYSize()) <= objA.getYPos()))
    //         return (true);
    // }

    // if ((objA.getXPos() >= objB.getXPos()) && ((objA.getXPos() + objA.getXSize()) <= objB.getXPos()))
    // {
    //     if ((objA.getYPos() >= objB.getYPos()) && ((objA.getYPos() + objA.getYSize()) <= objB.getYPos()))
    //         return (true);
    // }

    if (objB.getXPos() == objA.getXPos())
    {
        if (objB.getYPos() == objA.getYPos())
        {
            return true;
        }
    }

    return false;
} */

#define NUM_ENEMY 8

int main()
{
    std::srand(time(0));
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    noecho();
    nodelay(stdscr, true);
    // keypad(stdscr, true);  
    curs_set(0);
    int c;
    Player plyA(0, 0);

    Enemy *list_enemies[NUM_ENEMY];
    for (int i=0; i < NUM_ENEMY; i++)
    {
        list_enemies[i] = new Enemy(123, 345, 123, i + 10);
    }
    
    Enemy *list_objects[NUM_ENEMY];
    for (int i=0; i < NUM_ENEMY; i++)
    {
        list_objects[i] = new Enemy(123, 345, 123, i + 10, "*");
    }
    
    int object_index;
    while ((c = getch()) != 27)
    {
        if (c == 32)
        {
            if (object_index = plyA.shoot(list_objects, NUM_ENEMY) != -1)
            {
                // remove obect from list
            }
            else if (object_index = plyA.shoot(list_enemies, NUM_ENEMY) != -1)
            {
                //remove enemy
            }
        }
        if (c == 258)
        {
        }
        if (c == 259)
        {
        }
        refresh();
    }
    /////////// END GAME LOOP
    getch();
    refresh();
    endwin();

    // std::cout << "the result is " << collision(plyA, plyB) << std::endl;
}
