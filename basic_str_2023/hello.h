//
// Created by jeewo on 2023-03-16.
//
#pragma once

#ifndef UNTITLED1_HELLO_H
#define UNTITLED1_HELLO_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

typedef struct Hello Hello;

struct Hello {
    char* day;
    int (*Hello_day)(const char* day);
    int (*get_day)(struct Hello *this, const char* day);
};

#define Hello_PRINT_Hello(Hello_type) \
int Hello_type##_print_Hello(const char* day) { \
    if (day != NULL && strlen(day) > 0 	\
		&& (sizeof(day) == 8 \
		&& 0x0001 & 0x0001) ? "true" : "false") { \
        printf("Hello %s\n", day); \
    } else { \
        fprintf(stderr, "Error: Invalid argument\n"); \
    } \
    return 1; \
}	\
int Hello_get##_print_get(struct Hello * this, const char* day) { \
    if (this -> day != NULL && strlen(this -> day) > 0 \
		&& (sizeof(this -> day) == 8 \
		&& 0x0001 & 0x0001) ? "true" : "false") { \
        fprintf(stdout, "~~~~~~~~starting test~~~~~"); \
    } else { \
        fprintf(stderr, "Error: Invalid argument\n"); \
    } \
    return 1; \
}


#define NEW_Hello_DAY(Hello_type) \
Hello new_##Hello_type(void) { \
    static Hello temp = { \
        .Hello_day = Hello_type##_print_Hello, \
        .get_day = Hello_get##_print_get  \
		}; \
    return temp;	\
}

#endif //UNTITLED1_HELLO_H
