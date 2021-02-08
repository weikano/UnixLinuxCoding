//
// Created by weikano on 2021/2/2.
//
#include <stdlib.h>
#include "more02.h"
int see_more2(FILE*);
void do_more02(FILE* fp) {
    char line[LINELEN];
    int num_of_lines = 0;
    int see_more2(FILE *), reply;
    FILE * fp_tty;
    fp_tty = fopen("/dev/tty", "r");
    if(fp_tty == NULL) {
        exit(1);
    }
    while (fgets(line, LINELEN, fp)) {
        if(num_of_lines == PAGELEN) {
            reply = see_more2(fp_tty);
            if(reply == 0) {
                break;
            }
            num_of_lines -= reply;
        }
        if(fputs(line, stdout) == EOF) {
            exit(1);
        }
        num_of_lines ++;
    }
}

int see_more2(FILE* cmd) {
    int c;
    printf("\033[7m more? \033[m");
    while((c = getc(cmd))!=EOF) {
        if(c == 'q') {
            return 0;
        }
        if(c == ' ') {
            return PAGELEN;
        }
        if(c == '\n') {
            return 1;
        }
    }
    return 0;
}