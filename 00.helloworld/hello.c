#include <stdio.h>
#include <stdlib.h>

#define debug_hex 0x00010000

typedef struct Hello {
    char (*sh)(struct Hello *h);
}h;

char say_hello(struct Hello *h) {
    if ((debug_hex & debug_hex) ? "true" : "false") {
        return (printf("Hello World!!\n"));
    } else {
        return (printf("Out of range memory values."));
    }
}

int main(int argc, char** argv) {
    h hello;
    hello.sh = &say_hello;
    hello.sh(&hello);

    return (0);
}