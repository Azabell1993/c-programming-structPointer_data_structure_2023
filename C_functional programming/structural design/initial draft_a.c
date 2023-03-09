/*
    @ Developer : Azabell1993 Github master  
    @ Created   : 2023-03-07 9
    @ fileName  : initial draft.c
    @ Purpose   : C style Lamda first initial draft skecth
*/

#pragma ONCE
#ifndef HELLO_H
#define HELLO_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

#define public static __attribute__((visibility("default")))
#define private static __attribute__((visibility("hidden")))

#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
#define NORETERN _attribute_ ((_noreturn_))
    int helloworld##_hello(helloworld *self, int age);
    helloworld new_##helloworld(void);
#endif

#define say_hello(Calculator, type)                             \
                                                                \
    struct Calculator;                                          \
    typedef struct Calculator helloworld;                       \
                                                                \
    typedef struct Calculator {                                 \
        double a;                                               \
        double b;                                               \
                                                                \
        char (*cal_func)(Calculator *h, double a, double b);    \
    } Calculator;                                               \
                                                                \
    int Calculator##calcu(const helloworld *self, type age)     \
    {                                                           \
        return 
    }                                                           \
                                                                \
    helloworld new_##helloworld(void)                           \
    {                                                           \
        static helloworld temp =                                \
            {                                                   \
                .cal_func = Calculator##calcu,                  \
            };                                                  \
        return temp;                                            \
    }
#ifdef __headerfile
}
#endif
#endif


/* Function<Calculator, Double> func */
/* <Calculator, Double> func

typedef enum _token_type
{
    struct_pointer_function_nickname_a,     // Calculator
    macro_type,                             // Double
    function_pointer_function_name,         // func
    struct_pointer_function_nickname_b
}



/*
static class Calculator {
    double a, b;

    Calculator(double a, double b) {
        this.a = a;
        this.b = b;
    }
}
*/
typedef struct Calculator {
    double a;
    double b;

    char (*h)(Calculator *h, double a, double b);
} Calculator;

/*
static double calculator(Calculator calculator, Function<Calculator, Double> func) {
    return func.apply(calculator);
}
*/
static double calculator(Calculator calculator, 
    /* parser */ Function<Calculator, Double> func) {
    return func.apply(calculator);
}

typedef struct func {
    /* Function<Calculator, Double> */
    int (*apply)(Calculator calculator);
} func;

static int Calculator##apply_func(Calculator calculator) {
    /* */
}



#define say_hello(Calculator, type)
/* create new macro 'Function' */
/* ( -> <   input the token of parser*/
        Function<Calculator, Double>
        
static calculator(Struct Calculator)

calculator(calculator, (h) -> h.a + h.b)

calculator(calculator, (?) -> ?.argc + ?.argc)

calculator(calculator, (?) -> /* parser */)
calculator(calculator, (?) ->##function)
calculator(parserFunction##function)

az_printf(calculator(calculator, (h) -> h.a + h.b))

/* parser token*/
/***************/
/* calculator */
/* ( */
/* calculator,*/
/* ( */ 
/*  h */
/*  ) */ 
/* -> */
/***************/

/* new create function */
/* va_list */
/* variable factor */
az_printf(
    /* first token*/
    calculator(calculator, (?) ->
    /* second token*/
    ?.argc 
    /* charator token*/
    + | - | / | *
    /* end token*/
    ?.argc
)

int main(int argc, char** argv) {
    /* Calculator calculator = new Calculator(10.0, 5.0); */
    Calculator calculator = new_Calculator(10.0, 5.0);
    
    az_printf(calculator(calculator, (h) -> h.a + h.b)); // 15.0
    az_printf(calculator(calculator, (h) -> h.a - h.b)); // 5.0
    az_printf(calculator(calculator, (h) -> h.a * h.b)); // 50.0
    az_printf(calculator(calculator, (h) -> h.a / h.b)); // 2.0
}

