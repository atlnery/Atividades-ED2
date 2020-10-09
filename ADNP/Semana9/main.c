#include <stdio.h>
#include "abb.h"


void main(int argc, char** argv) {
    ABB* abb = NULL;

    ABB_insert(&abb, 70);
    ABB_insert(&abb, 39);
    ABB_insert(&abb, 88);
    ABB_insert(&abb, 6);
    ABB_insert(&abb, 7);
    ABB_insert(&abb, 2);
    ABB_insert(&abb, 3);
    ABB_insert(&abb, 1);

    printf("%d? %p\n",10, ABB_search(abb, 10));
    printf("%d? %p\n",40, ABB_search(abb, 40));
    printf("%d? %p\n",2, ABB_search(abb, 2));
    printf("%d? %p\n\n",5, ABB_search(abb, 5));

    printf("Pai de %d é %d\n\n", 7, ABB_search(abb, 7)->father->key);

    printf ("Quantidade de elems %d\n", ABB_size(abb));
    //ABB_remove(&abb, 6);
    printf ("Quantidade de elems após remoção %d\n\n", ABB_size(abb));   

    ABB_print(abb, 2);

    ABB_destroy(abb);
}
