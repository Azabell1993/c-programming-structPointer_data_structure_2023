/*
    @ Developer : Azabell1993 Github master  
    @ Created   : 2023-03-07  
    @ fileName  : hello.h
    @ Purpose   : bubble sort c code
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

#define say_hello(helloworld, type)                                                                         \
                                                                                                                \
    struct helloworld;                                                                                          \
    typedef struct helloworld helloworld;                                                                       \
                                                                                                                \
    struct helloworld                                                                                           \
    {                                                                                                           \
        size_t age;                                                                                             \
                                                                                                                \
        int (*hello)(const helloworld *, type);                                                                 \
    };                                                                                                          \
                                                                                                                \
    int helloworld##_hello(const helloworld *self, type age)                                            \
    {                                                                                                           \
        return printf("my age : %d\nHello World!!!!!!\n", age);                                                 \
    }                                                                                                           \
                                                                                                                \
    helloworld new_##helloworld(void)                                                                           \
    {                                                                                                           \
        static helloworld temp =                                                                                \
            {                                                                                                   \
                .age = 0,                                                                                       \
                .hello = helloworld##_hello,                                                                    \
            };                                                                                                  \
        return temp;                                                                                            \
    }
#ifdef __headerfile
}
#endif
#endif