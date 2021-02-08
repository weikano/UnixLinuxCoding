#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SHOWHOST

void show_info(struct utmp*);
void show_time(time_t);
int main()
{
    struct utmp* utbufp, * utmp_next();
    if(utmp_open(UTMP_FILE) == -1) {
        perror(UTMP_FILE);
        exit(1);
    }

    while((utbufp = utmp_next())!=((struct utmp*) NULL)) {
        show_info(utbufp);
    }
    utmp_close();
    return 0;
}

void show_time(time_t timeval)
{
    char * cp;
    cp = ctime(&timeval);
    printf("%12.12s", cp+4);
}

void show_info(struct utmp* utbufp)
{
    if(utbufp->ut_type != USER_PROCESS) {
        return;
    }
    printf("% - 8.8s", utbufp->ut_name);
    printf(" ");
    printf("% -8.8s", utbufp->ut_line);    
    printf(" ");
    show_time(utbufp->ut_time);
    printf(" ");

    #ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
    #endif
    printf("\n");
}