#include <sys/time.h>
#include <unistd.h>

int set_ticker(int n_msecs)
{
    struct itimerval new_timeset;

    long n_sec, n_usec;

    n_sec = n_msecs/ 1000;
    n_usec = (n_msecs % 1000)*1000L;

    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usec;

    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usec;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}