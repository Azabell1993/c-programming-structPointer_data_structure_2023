#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lambda(return_type, function_body) ({ \
return_type __fn__ function_body \
__fn__; \
})

#define SQUARE_FUNC(name, operation) \
int (*name)(int) = lambda(int, (int num) { return operation; });

char* hello_print(int num) {
    char* result = malloc(sizeof(char) * 1);
    sprintf(result, "%d", num * num);
    return (result);
}

char* printexample(char* myname) {
    char* result = malloc(sizeof(char) * 100);
    sprintf(result, "안녕하세요. 저의 이름은 %s입니다. 오늘 우리가 만난 횟수는 %s번!", myname, hello_print(1));
    return (result);
}

int main() {
    char* (*print_example)(char*) = lambda(char*, (char* myname) { return printexample(myname); });
    printf("%s\n", print_example("개발자 박지우"));

    int square_value = 10;
    int (*squretest)(int) = lambda(int, (int num) { return num*num;});
    printf("Square of %d is %d\n", square_value, squretest(square_value));

    int (*squretest2)(int) = lambda(int, (int num) { return num+num;});
    printf("Square of %d is %d\n", square_value, squretest2(square_value));

    square_value = 10;
    SQUARE_FUNC(squretestFunc, num*num);
    SQUARE_FUNC(squretestFunc2, num+num);

    printf("Square of %d is %d\n", square_value, squretestFunc(square_value));
    printf("Square of %d is %d\n", square_value, squretestFunc2(square_value + 1));

    return 0;
}