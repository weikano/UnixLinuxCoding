#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[])
{
    if(argc < 1) {
        fprintf(stderr, "参数传递错误\n");
        exit(-1);
    }  
    DIR* dir;
    dir = opendir(args[1]);
    if(dir == NULL) {
        perror("路径失败");
        exit(-1);
    }
    struct dirent* ent;
    while((ent = readdir(dir)) != NULL) {
        fprintf(stdout, "%s \n", ent->d_name);
    }
    return 0;
}