#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
    char* arglist[3];
    arglist[0] = "ls";
    arglist[1] = "-l";
    arglist[2] = 0;

    printf("*** About to execute ls -l \n");
    execvp("ls", arglist);
    //不会在shell中显示出来，因为execvp已经清空当前进程，载入了ls命令，所以后续的代码已经没了
    printf("*** ls is done. bye \n");
}