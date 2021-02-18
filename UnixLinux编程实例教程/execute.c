#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "smsh.h"

int execute(char** arglist)
{
    int pid;
    int child_info = -1;

    if(args[0] == NULL) {
        return 0;
    }
    if((pid == fork()) == -1) {
        perror("fork");
    }else if(pid == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        execv(arglist[0], arglist);
        perror("Cannot execute command");
        exit(1);
    }else {
        if(wait(&child_info) == -1) {
            perror("wait");
        }
        return child_info;
    }
}