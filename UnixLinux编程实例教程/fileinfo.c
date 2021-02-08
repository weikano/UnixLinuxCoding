#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void show_stat_info(const char*, struct stat*);

int main(int ac, char* av[])
{
    struct stat info;
    if(ac > 1) {
        if(stat(av[1], &info) != -1) {
            show_stat_info(av[1],&info);
            return 0;
        }else {
            perror(av[1]);
        }
    }
    return -1;
}

void show_stat_info(const char* name, struct stat* info) {
    printf("    mode: %o \n", info->st_mode);
    printf("    links: %d \n", info->st_nlink);
    printf("    user: %d\n", info->st_uid);
    printf("    group %d \n", info->st_gid);
    printf("    size: %d \n", info->st_size);
    printf("modtime: %d\n", info->st_mtim);
    printf("    name:%s\n", name);
}
