#include <stdio.h>
#include <curses.h>
#include <unistd.h>

#define MSG "HelloWorld"
#define BLANK "                    "

main()
{
    int i;
    initscr();
    for(i=0;i<LINES;i++) {
        move(i, i+1);
        if(i % 2 == 1) {
            standout();
        }
        addstr(MSG);
        if(i % 2 == 1) {
            standend();
        }
        refresh();
        sleep(1);
        move(i, i+1);
        addstr(BLANK);
    }
    endwin();
}