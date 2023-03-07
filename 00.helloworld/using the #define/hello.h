/*
    @ Developer : Azabell1993 Github master  
    @ Created   : 2023-03-07  
    @ fileName  : hello.h
    @ Purpose   : bubble sort c code
*/
#pragma ONCE
#ifndef PRINT_H_
#define PRINT_H_
#include <stdio.h>
#include <stdlib.h>
#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
typedef int (*_cloud)(const int *hello, char *return_contents);
	int return_hello(const int *hello, const char *return_contents);
	int main(int argc, char *argv[]);
#endif
typedef int (*_cloud)(const int *hello, char *return_contents);

#define PARK_HEADER                     \
    int *myhello;                       \
    char *return_contents;              \
    _cloud  update;                     \

#define DECL_PARK(hello, RETURN_FUNCTION) struct {  \
    PARK_HEADER;                                    \
} DEFINE_NAME(NAME, RETURN_FUNCTION)

#define RETURN_FUNCTION(hello, RETURN_CONTENTS) \
DECL_PARK(NAME, RETURN_FUNCTION) = {            \
}

struct CLOUD {
    int *myhello;
    char *return_contents;
    int (*_cloud)(const int *,  char *);
} ;

__cdecl int return_hello(const int *hello, const char *return_contents) {
    struct CLOUD *cloud;
    return_contents = "Hello World";
    if(sizeof(*cloud->myhello) == 4)
        return (printf("%s\n",return_contents));
}
#endif

#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
PARK_HEADER

typedef int (*_main)(int argc, char *argv[]);

#define PRINTF              \
    _main PRINTF            \

#define PRINF_FUNCTION(ARGC, ARGV) struct {   \
    PRINTF;                                   \
} DEFINE_PRINTF(ARGC, ARGV)

#define RETURN_PRINTF(ARGC, ARGV) \
PRINF_FUNCTION(ARGC, ARGV) = {    \
}

/*
	@parm
*/
int __cdecl main(int argc, char *argv[]) {
    return_hello(myhello, return_contents);
    return 0;
}

#ifdef __headerfile
}
#endif
#endif /* PRINT_H_ */