//
// Created by jeewo on 2023-03-16.
//
#pragma once

#ifndef UNTITLED1_LOGICLIB_H
#define UNTITLED1_LOGICLIB_H

#include "hello.h"

#include "add.h"
#include "vector.h"
#include "arraylist.h"
#include "pair.h"

#ifdef __WIN64__
    Hello_PRINT_Hello(Hello)
    NEW_Hello_DAY(Hello)

    say_add(addFunction , int)
    DECLARE_VECTOR(Vector, int)
    DECLARE_ARRAY_LIST(ArrayList, int)
    DECLARE_PAIR(IntPair, int, int)
    DEFINE_PAIR(IntPair, int, int)
#endif

#endif