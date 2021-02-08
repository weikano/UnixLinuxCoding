#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    while((c=getchar())!=EOF) {
        if(c == 'z') {
            c = 'a';
        }else {
            c ++;
        }

        putchar(c);
    }

    return 0;
}