#include <stdio.h>
#include "curses.h"

//apt install libncurses5-dev
//cc hello1.c -o hello1.o -lncurses
main()
{
    initscr();

    clear();
    move(10,20);
    addstr("Hello World");
    move(LINES-1, 0);
    refresh();
    getch();
    endwin();
}