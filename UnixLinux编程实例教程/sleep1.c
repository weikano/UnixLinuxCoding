#include <stdio.h>
#include <signal.h>
#include <unistd.h>
main()
{
    void wakeup(int);

    printf("about to sleep for 4 seconds \n");
    signal(SIGALRM, wakeup);
    alarm(4);
    pause();

    printf("Nothing so soon\n");
}

void wakeup(int seconds) {
    #ifndef SHHH
    printf("Alarm received from kernel\n");
    #endif
}