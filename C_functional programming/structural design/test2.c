#include <stdio.h>

#define lambda(return_type, function_body) ({ \
return_type __fn__ function_body \
__fn__; \
})

int main() {
    int x = 10;

    int (*square)(int) = lambda(int, (int num) { return num * num; });
    printf("Square of %d is %d\n", x, square(x));
    
    return 0;
}
