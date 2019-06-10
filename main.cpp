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
void DisplayEntity(Entity *obj, const char *symbol);
void MoveObjects(Enemy *villain[], int numVil);

int main()
{
    int secondsLeft = 0;
    int seconds = 0;
    int seconds2 = 0;
    std::srand(time(0));
    initscr();
    // wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    int c;
    int x, y;
    int object_index;
    getmaxyx(stdscr, y, x);
    for (int i = 0; i < x; i++)
    {
        //top border
        mvaddch(0, i, '#');
        //bottom border
        mvaddch(y - 4, i, '#');
    }
    for (int i = 0; i < y; i++)
    {
        //left border
        mvaddch(i, 0, '#');
        //right border
        mvaddch(i, x - 1, '#');
    }
    Player player = Player(x - 1, y - 5, 2, y / 2);

    //objects init
    Enemy *list_objects[TOTAL_OBJ];
    for (int i = 0; i < NUM_OBJECT; i++)
    {
        list_objects[i] = new Enemy(x - 4, y - 7, x - 20, (3 * i + 2), "*", 2, 2);
        DisplayEntity(list_objects[i], list_objects[i]->getSymbol());
    }
    //enemy init
    for (int i = NUM_OBJECT; i < (TOTAL_OBJ); i++)
    {
        list_objects[i] = new Enemy(x - 2, y - 7, x - 5, i + 10, 1);
        DisplayEntity(list_objects[i], list_objects[i]->getSymbol());
    }
    DisplayEntity(&player, player.getSymbol());

    while ((c = getch()) != 27)
    {
        // usleep(1000);
        mvprintw(y-1, 2, "Seconds: %d", seconds);
        mvprintw(y-2, 2, "milli seconds: %d", secondsLeft);
        mvprintw(y-3, 2, "Score: %d", player.score);
        secondsLeft++;
        napms(1);
        if (secondsLeft == 1000)
        {
            secondsLeft = 0;
            seconds++;
            seconds2++;
        }
        if (secondsLeft == 50)
        {
            mvprintw(player.getYPos(), player.getXPos() + 1, " ");
        }
        if (seconds2 == 1)
        {
            MoveObjects(list_objects, TOTAL_OBJ);
            // MoveBackGround(list_background, NUM_BACKGROUND,player);
            if (player.collision(list_objects, TOTAL_OBJ))
            {

                mvprintw(1, x / 2, "_______  _______  _______  _______        _______           _______  _______ ");
                mvprintw(2, x / 2, "(  ____ \\(  ___  )(       )(  ____ \\      (  ___  )|\\     /|(  ____ \\(  ____ )");
                mvprintw(3, x / 2, "| (    \\/| (   ) || () () || (    \\/      | (   ) || )   ( || (    \\/| (    )|");
                mvprintw(4, x / 2, "| |      | (___) || || || || (__          | |   | || |   | || (__    | (____)|");
                mvprintw(5, x / 2, "| | ____ |  ___  || |(_)| ||  __)         | |   | |( (   ) )|  __)   |     __)");
                mvprintw(6, x / 2, "| | \\_  )| (   ) || |   | || (            | |   | | \\ \\_/ / | (      | (\\ (   ");
                mvprintw(7, x / 2, "| (___) || )   ( || )   ( || (____/\\      | (___) |  \\   /  | (____/\\| ) \\ \\__");
                mvprintw(8, x / 2, "(_______)|/     \\||/     \\|(_______/      (_______)   \\_/   (_______/|/   \\__/");
                refresh();
                sleep(6);
                break;
            }

            seconds2 = 0;
        }
        if (c == 32)
        {     
            attron(COLOR_PAIR(1));
            mvprintw(player.getYPos(), player.getXPos() + 1, "-");
            attroff(COLOR_PAIR(1));
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
            mvprintw(player.getYPos(), player.getXPos() + 1, " ");
            DisplayEntity(&player, " ");
            player.moveUp();
            DisplayEntity(&player, player.getSymbol());
        }
        if (c == 259)
        {
            mvprintw(player.getYPos(), player.getXPos() + 1, " ");
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

void DisplayEntity(Entity *obj, const char *symbol)
{
    int x = obj->getXPos();
    int y = obj->getYPos();

    int xsize = obj->getXSize();
    int ysize = obj->getYSize();

    for (int i = 0; i < xsize; i++)
    {
        for (int j = 0; j < ysize; j++)
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
        DisplayEntity(villain[i], " ");
        if ((villain[i]->getXPos() - 3) <= 1)
        {
            // villain[i]->setPos(villain[i]->getXPos() + 10,villain[i]->getYPos());
            villain[i]->Die();
        }
        else
        {
            villain[i]->setPos(villain[i]->getXPos() - 3, villain[i]->getYPos());
        }

        DisplayEntity(villain[i], villain[i]->getSymbol());
    }
}