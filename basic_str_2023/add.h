//
// Created by jeewo on 2023-03-16.
//
#pragma once

#ifndef UNTITLED1_ADD_H
#define UNTITLED1_ADD_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

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
		/* 함수 전방 선언 */
		extern public void addFunction##_set_Add(addFunction *, type, type);
		extern public int addFunction##_get_Add(const addFunction *);

		/* 비멤버 생성자 전방 선언 */
		addFunction new_##addFunction(void);
#endif

#define say_add(addFunction, int)   \
    \
struct addFunction;  \
typedef struct addFunction addFunction;  \
    \
struct addFunction   \
{   \
    int num1;   \
    int num2;   \
    \
    void (*setAdd)(addFunction *, int, int);    \
    int (*getAdd)(const addFunction *); \
};  \
    \
static void addFunction##_set_Add(addFunction *this, int num1, int num2)    \
{   \
    this -> num1 = num1;    \
    this -> num2 = num2;    \
}   \
    \
static int addFunction##_get_Add(const addFunction *this)   \
{   \
    int result = 0; \
    result = this->num1 + this->num2;   \
    return result;  \
}   \
    \
addFunction new_##addFunction(void) \
{   \
    static addFunction temp =   \
            {   \
                    .num1 = 0,  \
                    .num2 = 0,  \
                    .setAdd = addFunction##_set_Add,    \
            .getAdd = addFunction##_get_Add,    \
            };  \
    return temp;    \
}
#ifdef __cplusplus
}
#endif //__cplusplus
#endif //UNTITLED1_ADD_H


