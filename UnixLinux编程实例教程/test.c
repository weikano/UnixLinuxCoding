#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc ,char* args[])
{
    int fd1, fd2;

    fd1 = open(args[1], O_RDONLY);
    fd2 = open(args[1], O_RDONLY);

    printf("fd1 %d, fd2 %d \n", fd1, fd2);

    FILE* f1, *f2;

    f1= fdopen(fd1, "r");
    f2 = fdopen(fd2, "r");

    printf("FILE fd1 %d, FILE fd2 %d", fileno(f1), fileno(f2));

    struct stat fs1, fs2;
    fstat(fd1, &fs1);
    fstat(fd2, &fs2);


    if(fs1.st_ino == fs2.st_ino) {
        printf("same file \n");

        printf("file1 ino %ld, file2 ino %ld\n", fs1.st_ino, fs2.st_ino);

    }
    return 0;
}