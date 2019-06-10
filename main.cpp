/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/10 08:05:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Player.hpp"
#include "./incl/Entity.hpp"
#include "./incl/Enemy.hpp"
#include <iostream>
#include <ncurses.h>

#define NUM_ENEMY 8

int main()
{
    std::srand(time(0));
    wborder( initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    int c;
    int x,y;
    getmaxyx(stdscr, y, x);
    Player player = Player(x,y,2, y/2);

    Enemy *list_enemies[NUM_ENEMY];
    for (int i = 0; i < NUM_ENEMY; i++)
    {
        std::cout <<"i = " << i <<std::endl;
        list_enemies[i] = new Enemy(x - 2, y - 1, x-5, i + 10);
        mvprintw(list_enemies[i]->getYPos(), list_enemies[i]->getXPos(), list_enemies[i]->getSymbol());
    }

    Enemy *list_objects[NUM_ENEMY];
    for (int i = 0; i < NUM_ENEMY; i++)
    {
        list_objects[i] = new Enemy(x - 2, y - 1, x-10, (i + 10), "*");
        mvprintw(list_objects[i]->getYPos(), list_objects[i]->getXPos(), list_objects[i]->getSymbol());
    }
    mvprintw(player.getYPos(), player.getXPos(), player.getSymbol());
    int object_index;
    while ((c = getch()) != 27)
    {
        if (c == 32)
        {
            if ((object_index = player.shoot(list_objects, NUM_ENEMY)) != -1)
            {
                // remove obect from list
                mvprintw(list_objects[object_index]->getYPos(), list_objects[object_index]->getXPos(), " ");
                list_objects[object_index]->Die();
                mvprintw(list_objects[object_index]->getYPos(), list_objects[object_index]->getXPos(), list_objects[object_index]->getSymbol());
            }
            else if ((object_index = player.shoot(list_enemies, NUM_ENEMY )) != -1)
            {
                //remove enemy
                mvprintw(list_enemies[object_index]->getYPos(), list_enemies[object_index]->getXPos(), " ");
                list_enemies[object_index]->Die();
                mvprintw(list_enemies[object_index]->getYPos(), list_enemies[object_index]->getXPos(), list_enemies[object_index]->getSymbol());
            }
        }
        if (c == 259)
        {
            
            mvprintw(player.getYPos(), player.getXPos(), " ");
            player.moveUp();
            mvprintw(player.getYPos(), player.getXPos(), player.getSymbol());
        }
        if (c == 258)
        {
            mvprintw(player.getYPos(), player.getXPos(), " ");
            player.moveDown();
            mvprintw(player.getYPos(), player.getXPos(), player.getSymbol());
        }
        refresh(); 
    }
    /////////// END GAME LOOP
    getch();
    refresh();
    endwin();

    // std::cout << "the result is " << collision(plyA, plyB) << std::endl;
}
