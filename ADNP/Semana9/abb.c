#include "abb.h"


ABB* ABB_create(int key, ABB* left, ABB* right, ABB* father) {
    ABB* new; 
    new = malloc(sizeof(ABB));
    new->left = left;
    new->right = right; 
    new->father = father;
    new->key = key;

    return new;
}

//percurso pré-ordem    
ABB* ABB_insert(ABB** A, int key){
    ABB_insert_father(A, key, (*A));
}

static ABB* ABB_insert_father(ABB** A, int key, ABB* father) {

    if(!(*A)) { 
        (*A) = ABB_create(key, NULL, NULL, father);
        return NULL;
    }

    if (key < (*A)->key) {
        ABB_insert_father(&(*A)->left, key, (*A));
    }

    else {
        ABB_insert_father(&(*A)->right, key, (*A));
    }
}


ABB* ABB_search(ABB* no, int key) {
    if (!no) { return NULL; }

    if (no->key == key) { return no; }

    ABB* next = (key > no->key) ? no->right : no->left;
    return ABB_search(next, key);
}

void ABB_print(ABB* no, PRINT_TYPE type) {
    if (!no) {return;}

    switch (type) {
    case 1: 
        ABB_print(no->left, type);
        printf("%d\t", no->key);
        ABB_print(no->right, type);
        break;
    case 2: 
        ABB_print_pre_ordem(no, 2);
        break;
    case 3:
        ABB_print(no->left, type);
        ABB_print(no->right, type);
        printf("%d\t", no->key);
        break;  
    default: 
        printf("OPÇÃO INVÁLIDA\n");
    }
}

static void ABB_print_pre_ordem(ABB* no, int num) {
    if (!no) {
        print_No(-404, num);
        return;
    }

    ABB_print_pre_ordem(no->left, num+1);
    ABB_print_pre_ordem(no->right, num+1);
    print_No(no->key, num);
}

static void print_No(int key, int num)  {
    int i;
    for (i = 0; i < num; i++) 
    printf("   ");
    if (key == -404) {
        printf("*\n\n");
    }
    else {
        printf("%d\n\n", key);
        printf(" ");
        
    }
}


int ABB_size(ABB* no) {
    if(!no)  { return 0; }

   return ABB_size(no->left) + ABB_size(no->right) + 1;
}

void ABB_destroy(ABB* no){
    if(!no) return;
   
    ABB_destroy(no->left);
    ABB_destroy(no->right);
    free(no);
}

 int ABB_remove(ABB **no, int key){

    if (!(*no)) return -1;

    ABB* remove = ABB_search((*no), key);
    int control = 1;
 
    if (!remove) {return -1; }

    //no folha
    if (!remove->left & !remove->right) {
        if (remove->key < remove->father->key) {
            remove->father->left = NULL;
        }
        else {
            remove->father->right = NULL;      
            
        }
    }

    //no com um filho
    else if(!remove->left ^ !remove->right) {
        if (ABB_size((*no)) > 2) {
            if (!remove->left) {
                remove->father->right = remove->right;
                remove->right->father = remove->father;
            }
            else {
                remove->father->left = remove->left;
                remove->left->father = remove->father;
            }
        }
        else {
           if (!remove->left) {
               remove->key = remove->right->key; 
               remove->right = NULL;
               free(remove->right);
           }

           else {
               remove->key = remove->left->key;
               remove->left = NULL;
               free(remove->left);
           }
           control = 0;
        }
    }

    //no com dois filhos
    else if (!(!remove->left & !remove->right)) {
       
        ABB* sx = ABB_largest_left(remove);
 
        if (sx == remove->left) {          
            remove->left = sx->left;      
               
        }
        else {
           sx->father->right = NULL;
        }

        control = 0;
        remove->key = sx->key; 
        free(sx); 
    }

    if (control) { free(remove); }

}

ABB* ABB_largest_left(ABB *no){
    if (!no) {return NULL;}

    ABB* aux = no->left; 
    ABB* largest = aux;
    

    while (!!aux) {
        largest = aux;
        aux = aux->right;
    }

    return largest;
}

ABB* ABB_smaller_right(ABB *no){
    if (!no) {return NULL;}

    ABB* aux = no->right; 
    ABB* largest = aux;
    

    while (!!aux) {
        largest = aux;
        aux = aux->left;
    }

    return largest;
}

