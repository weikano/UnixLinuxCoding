#include <stdio.h>
#include <curses.h>
#include <unistd.h>

void when_exit()
{
    printf("exit");
}

main()
{
    int i;
    initscr();
    clear();
    for(i=0;i<LINES;i++) {
        move(i, i+1);
        if(i % 2 == 1) {
            standout();
        }
        addstr("HelloWorld");
        if(i % 2 == 1) {
            standend();
        }
        sleep(1);
        refresh();
    }
    endwin();
}