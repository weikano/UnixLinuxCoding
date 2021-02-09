#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//cc bounce_async.c set_ticker.c -lncurses -o bounce_async.o

#define MESSAGE "hello"
#define BLANK       "          "

int row = 10;
int col = 0;
int dir = 1;
int delay = 200;
int done = 0;

main()
{
    void on_alarm(int);
    void on_input(int);
    void enable_kbd_signals();

    initscr();
    crmode();
    noecho();
    clear();

    signal(SIGIO, on_input);
    enable_kbd_signals();
    signal(SIGALRM, on_alarm);
    set_ticker(delay);
    move(row, col);
    addstr(MESSAGE);

    while(!done) {
        pause();
    }
    endwin();
}

void on_input(int signum) 
{
    char c = getch();
    if(c == 'Q' || c == EOF) {
        done = 1;
    }else if(c == ' ') {
        dir = -dir;
    }
}

void on_alarm(int signum)
{
    signal(SIGALRM, on_alarm);
    mvaddstr(row, col, BLANK);
    col += dir;
    mvaddstr(row, col, MESSAGE);
    refresh();

    if(dir == -1 && col <= 0) {
        dir = 1;
    }else if(dir == 1 && col + strlen(MESSAGE) > COLS)  {
        dir = -1;
    }
}

void enable_kbd_signals()
{
    int fd_flags;
    fcntl(0, F_SETOWN, getpid());
    fd_flags = fcntl(0, F_GETFL);
    fcntl(0, F_SETFL, (fd_flags | O_ASYNC));
}