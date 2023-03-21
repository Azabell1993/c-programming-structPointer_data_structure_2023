#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LogicLib.h"

int main(int argc, char* argv[]) {

    char* helloworld;

    helloworld = malloc(sizeof(char)*100);
    strcpy(helloworld, "world!!");

#ifdef _WIN64
    Hello hello = new_Hello();
    hello.Hello_day(helloworld);
    hello.get_day(&hello, helloworld);
    free(helloworld);
#endif


printf("\n");
printf("============== [1] sumLogic Test Printf ==============\n");
#ifdef __WIN64__
    int numA = 0;
    int numB = 0;;

    printf("input the first numA and numB value :   ");
    scanf("%d %d", &numA, &numB);

    addFunction add = new_addFunction();
    add.setAdd(&add, numA, numB);
    int result = add.getAdd(&add);
    printf("result : %d", result);
#endif

printf("\n");
printf("============== [2] vector Test Printf ==============\n");
#ifdef __WIN64__
    Vector vec = new_Vector();

    Vector_push_back(&vec, 1);
    Vector_push_back(&vec, 2);
    Vector_push_back(&vec, 3);
    Vector_push_back(&vec, 4);

    printf("Vector size: %zu, capacity: %zu\n", Vector_get_size(&vec), Vector_get_capacity(&vec));

    for (size_t i = 0; i < Vector_get_size(&vec); i++) {
        printf("%d ", Vector_at(&vec, i));
    }

    Vector_clear(&vec);
    Vector_resize(&vec, 2);

    Vector_push_back(&vec, 5);
    Vector_push_back(&vec, 6);

    printf("\nVector size: %zu, capacity: %zu\n", Vector_get_size(&vec), Vector_get_capacity(&vec));

    for (size_t i = 0; i < Vector_get_size(&vec); i++) {
        printf("%d ", Vector_at(&vec, i));
    }

    Vector_free(&vec);
#endif

printf("\n");
printf("============== [3] arrayList Test Printf ==============\n");
#ifdef __WIN64__
    ArrayList list = new_ArrayList();

    // Add some elements to the list
    list.push_back(&list,1);
    list.push_back(&list,2);
    list.push_back(&list,3);

    // Print the list contents
    printf("List contents:\n");
    list.size;
    for (size_t i = 0; i < list.get_size(&list); i++) {
        printf("%d\n", list.at(&list, i));
    }

    // Clear the list
    list.clear(&list);

    // Add some more elements to the list
    list.push_back(&list, 4);
    list.push_back(&list, 5);

    // Print the list contents again
    printf("List contents:\n");
    for (size_t i = 0; i < list.get_size(&list); i++) {
        printf("%d\n", list.at(&list, i));
    }

    // Free the list
    list.free(&list);
#endif

printf("\n");
printf("============== [4] pair Test Printf ==============\n");
#ifdef __WIN64__
    IntPair pair = IntPair_make(list.at(&list, 4), list.at(&list, 5));
    IntPair other_pair = IntPair_make(list.at(&list, 4), list.at(&list, 5));
    bool equal = pair.equals(&pair, &other_pair);
    printf("%d",  pair.equals(&pair, &other_pair));
#endif

    return (0);
}