//cc bounce1d.c set_ticker.c -lncurses -o bounce1d.o

#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <string.h>

#define MESSAGE "hello"
#define BLANK       "           "

int row; //当前行
int col; //当前列
int dir; //方向

int main()
{
    int delay;  //bigger => slower
    int ndelay; // new delay

    int c;  //user input;
    void move_msg(int); //handler for timer

    initscr();
    crmode();
    noecho();
    clear();

    row = 10;
    col = 0;
    dir = 1;
    delay = 200;

    move(row, col);
    addstr(MESSAGE);
    signal(SIGALRM, move_msg);
    set_ticker(delay);

    while(1) {
        ndelay = 0;
        c = getchar();
        if(c == 'Q') break;
        if(c == ' ') dir = -dir;
        if(c == 'f' && delay > 2) {
            ndelay = delay/2;
        }
        if(ndelay > 0) {
            set_ticker(delay = ndelay);
        }
    }

    endwin();
    return 0;
}

void move_msg(int signum)
{
    signal(SIGALRM, move_msg);
    move(row, col);
    addstr(BLANK);
    col += dir;
    move(row, col);
    addstr(MESSAGE);
    refresh();

    if(dir == -1 && col < 0) {
        dir = 1;
    }else if(dir == 1 && col + strlen(MESSAGE) >= COLS) {
        dir = -1;
    }
}
