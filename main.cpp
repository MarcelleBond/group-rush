/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:02:05 by rhohls            #+#    #+#             */
/*   Updated: 2019/06/09 12:04:32 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "./incl/Player.hpp"
#include "./incl/Entity.hpp"
#include "./incl/Player.hpp" */
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

int main()
{
    std::srand(time(0));
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    noecho();
    nodelay(stdscr, true);
    // keypad(stdscr, true);  
    curs_set(0);
    int c;
    // Player plyA(0, 0);
    while ((c = getch()) != 27)
    {
        if (c == 32)
        {
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
