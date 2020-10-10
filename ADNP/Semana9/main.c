#include <stdio.h>
#include "abb.h"

#define DEBUG 0

void main(int argc, char** argv) {
    ABB* abb = NULL;

    int v[] = {30, 50, 40, 47, 15, 20, 25, 17, 19, 4, 7, 0};

    for (int i = 0; i < 12; i++) {
         ABB_insert(&abb, v[i]);
    }

    #if DEBUG
    printf("%d? %p\n",10, ABB_search(abb, 10));
    printf("%d? %p\n",40, ABB_search(abb, 40));
    printf("%d? %p\n",2, ABB_search(abb, 2));
    printf("%d? %p\n\n",5, ABB_search(abb, 5));

    printf("Pai de %d é %d\n\n", 7, ABB_search(abb, 7)->father->key);
    printf ("Quantidade de elems %d\n", ABB_size(abb));
    #endif
    
    ABB_remove(&abb, 0);
    ABB_remove(&abb, 30);
    ABB_remove(&abb, 15);
    ABB_remove(&abb, 20);

    ABB_print(abb, 2);

    ABB_destroy(abb);
}
