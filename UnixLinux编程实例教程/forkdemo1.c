#include <stdio.h>
#include <unistd.h>

main()
{
    int ret_from_fork, mypid;
    mypid = getpid();
    printf("Before : my pid is %d \n", mypid);

    ret_from_fork = fork();
    //子进程从fork返回的地方执行，所以会出现两行after代码
    sleep(1);

    printf("After:mypid is %d, fork said %d \n", mypid, ret_from_fork);
}