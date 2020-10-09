#ifndef ABB_H
#define ABB_H

    #include <stdio.h> 
    #include <stdlib.h>

    typedef enum PRINT_TYPE{
        ORDEM = 1, 
        PRE,
        POS
    } PRINT_TYPE;

    typedef struct binary_search_tree{
        struct binary_search_tree* left; 
        struct binary_search_tree* right;
        struct binary_search_tree* father;
        int key;
    }ABB; //Árvore Binária de Busca
    
    ABB* ABB_search(ABB* no, int key);
    ABB* ABB_create(int key, ABB* left, ABB* right, ABB* father);
    ABB* ABB_insert(ABB** A, int key);
    static ABB* ABB_insert_father(ABB** A, int key, ABB* father);

    void ABB_print(ABB* no, PRINT_TYPE type);
    static void ABB_print_pre_ordem(ABB* no, int num);
    static void print_No(int key, int num);

    int ABB_size(ABB* no);
    void ABB_destroy(ABB* no); 
    
    int ABB_remove(ABB **no, int key);
    ABB* ABB_smaller_right(ABB *no);
    ABB* ABB_largest_left(ABB *no);



#endif
