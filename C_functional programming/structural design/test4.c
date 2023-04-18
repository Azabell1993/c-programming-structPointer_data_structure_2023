#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lambda(return_type, function_body) ({ \
return_type __fn__ function_body \
__fn__; \
})

typedef struct {
    int (*hello_print)(int);
    char* (*print_example)(char*);
} Example;

int hello_print(int num) {
    char result[10];
    sprintf(result, "%d", num);
    return atoi(result);
}

char* print_example(char* myname, int num) {
    char result[100];
    sprintf(result, "My name is %s and my birthday is on the %dth day!", myname, num);
    return strdup(result);
}

int main() {
    Example* example = malloc(sizeof(Example));
    example->hello_print = hello_print;
    example->print_example = lambda(char*, (char* myname) { 
        return print_example(myname, example->hello_print(19930315)); 
    });
    printf("%s\n", example->print_example("Park Ji Woo"));
    free(example);
    return 0;
}
