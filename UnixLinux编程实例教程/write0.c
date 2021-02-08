#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* args[])
{
    int fd;
    char buf[BUFSIZ];
    if(argc != 2) {
        fprintf(stderr, "Usage : write0 ttypname\n");
        exit(1);
    }

    fd = open(args[1], O_WRONLY);
    if(fd == -1) {
        perror(args[1]);
        exit(1);
    }

    while(fgets(buf, BUFSIZ, stdin) != NULL) {
        if(write(fd, buf, strlen(buf)) == -1) {
            break;
        }
    }
    close(fd);
    return 0;
}