/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/10 15:43:56 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Player.hpp"
#include "./incl/Entity.hpp"
#include "./incl/Enemy.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#define NUM_ENEMY 8
#define NUM_OBJECT 4
#define TOTAL_OBJ (NUM_ENEMY + NUM_OBJECT)
void DisplayEntity(Entity *obj, const char * symbol);
void MoveObjects(Enemy *villain[], int numVil);

int main()
{
    int secondsLeft = 0;
    int seconds = 0;
    int seconds2 = 0;
    std::srand(time(0));
    wborder( initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    int c;
    int x,y;
    int object_index;
    
    getmaxyx(stdscr, y, x);
    Player player = Player(x-1,y-2,2, y/2);

    //objects init
    Enemy *list_objects[TOTAL_OBJ];
    for (int i = 0; i < NUM_OBJECT; i++)
    {
        list_objects[i] = new Enemy(x - 4, y - 3, x-20, (3*i + 2), "*", 2, 2);
        DisplayEntity(list_objects[i], list_objects[i]->getSymbol());
    }
    //enemy init
    for (int i = NUM_OBJECT; i < (TOTAL_OBJ); i++)
    {
        list_objects[i] = new Enemy(x - 2, y - 2, x-5, i + 10, 1);
        DisplayEntity(list_objects[i], list_objects[i]->getSymbol());      
    }

    DisplayEntity(&player, player.getSymbol());
    
    while ((c = getch()) != 27)
    {
        // usleep(1000);
        mvprintw(2,1,"Seconds: %d", seconds);
        mvprintw(3,1,"milli seconds: %d", secondsLeft);
        mvprintw(4,1,"Score: %d", player.score);
        secondsLeft++;
        napms(1);
        if (secondsLeft == 100)
        {
            secondsLeft = 0;
            seconds++;
            seconds2++;
        }
        if (seconds2 == 1)
        {
            MoveObjects(list_objects, TOTAL_OBJ);
            if (player.collision(list_objects, TOTAL_OBJ))
                break;
                    
           seconds2 = 0;
        }
        if (c == 32)
        {
            if ((object_index = player.shoot(list_objects, TOTAL_OBJ)) != -1)
            {
                // remove object from list
                DisplayEntity(list_objects[object_index], " ");
                list_objects[object_index]->Die();
                player.score += list_objects[object_index]->points;
                DisplayEntity(list_objects[object_index], list_objects[object_index]->getSymbol());
            }
        }
        if (c == 258)
        {
            DisplayEntity(&player, " ");
            player.moveUp();
            DisplayEntity(&player, player.getSymbol());
        }
        if (c == 259)
        {
            DisplayEntity(&player, " ");
            player.moveDown();
            DisplayEntity(&player, player.getSymbol());
        }
        refresh(); 
    }
    /////////// END GAME LOOP
    getch();
    refresh();
    endwin();

    std::cout << "GAME OVER" << std::endl;
}


void DisplayEntity(Entity *obj, const char * symbol)
{
    int x = obj->getXPos();
    int y = obj->getYPos();

    int xsize = obj->getXSize();
    int ysize = obj->getYSize();
    
    for (int i=0; i < xsize; i++)
    {
        for (int j=0; j < ysize; j++)
        {
            mvprintw(y + j, x + i, symbol);
        } 
    }
}

void MoveObjects(Enemy *villain[], int numVil)
{
    for (int i = 0; i <= numVil; i++)
    {
        /* code */
        DisplayEntity(villain[i],  " ");
        if ((villain[i]->getXPos() - 1) <= 1)
        {
            // villain[i]->setPos(villain[i]->getXPos() + 10,villain[i]->getYPos());
            villain[i]->Die();
        }
        else
        {
            villain[i]->setPos(villain[i]->getXPos() - 1,villain[i]->getYPos());
        }

        DisplayEntity(villain[i], villain[i]->getSymbol());
    }
}