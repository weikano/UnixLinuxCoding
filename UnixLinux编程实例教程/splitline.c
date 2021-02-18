#include "smsh.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* next_cmd(char* prompt, FILE* fp)
{
    char* buf;
    int bufspace = 0;
    int pos = 0;
    int c;

    printf("%s", prompt);
    while((c = getc(fp))!=EOF) {
        if(pos + 1 >= bufspace) {
            if(bufspace == 0) {
                buf = emalloc(BUFSIZ);
            }else {
                buf = erealloc(buf, bufspace * BUFSIZ);
            }
        }
        if(c == '\n') {
            break;
        }
        buf[pos + 1] = c;
    }
    if(c == EOF && pos == 0) {
        return NULL;
    }
    buf[pos] = '\0';
    return buf;
}