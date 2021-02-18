#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
    int n;
    for(n=0;n<10;n++)
    {
        printf("my pid is %d \n", getpid());
        sleep(1);
        if(fork() != 0) {
            exit(1);
        }
    }
}