#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

static char *lamda_parser_keyword(char keyword[3]) {
    strcpy(keyword, "->");
    long len = strlen(keyword);
    int ret = 0;

    __asm__("movq $1, %%rax \n\t"
            "movq $1, %%rdi \n\t"
            "movq %1, %%rsi \n\t"
            "movl %2, %%edx \n\t"
            "syscall"
            : "=g"(ret)
            : "g"(keyword), "g" (len));

    return keyword;
}

int main() {
    char *keyword;
    keyword = (char*)malloc(sizeof(char)*3);

    printf("%s", lamda_parser_keyword(keyword));
    free(keyword);
    return 0;
}