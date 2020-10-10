##include "abb.h"

/* função para criação de nó na arvore
 *  @param key: chave para o nó
 *  @param left: nó a esquerda do criado
 *  @param right: nó a direita do criado
 *  @param father: nó pai 
*/
ABB* ABB_create(int key, ABB* left, ABB* right, ABB* father) {
    ABB* new; 
    new = malloc(sizeof(ABB));
    new->left = left;
    new->right = right; 
    new->father = father;
    new->key = key;

    return new;
}

/* função para inserção de nó na arvore
 *  @param key: chave para o nó
*/   
ABB* ABB_insert(ABB** A, int key){
    ABB_insert_father(A, key, (*A));
}


/* função para inserção de nó na arvore com especificação do pai
 *  @param A: ponteiro para o endereço do nó a ser inserido
 *  @param key: chave para o nó
 *  @param father: endereço do pai do nó 
*/ 
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

/* função para busca de nó na arvore
 *  @param no: ponteiro para o nó a ser inserido
 *  @param key: chave a ser buscada
*/ 
ABB* ABB_search(ABB* no, int key) {
    if (!no) { return NULL; }

    if (no->key == key) { return no; }

    ABB* next = (key > no->key) ? no->right : no->left;
    return ABB_search(next, key);
}

/*  função para impressão da arvore. 
 *  @param no: ponteiro para no da arvore
 *  @param type: tipo de impressão a ser realizada
 *  1: lista ordem
 *  2: imprime arvore em pre ordem
 *  3: lista pos ordem 
*/
void ABB_print(ABB* no, PRINT_TYPE type) {
    if (!no) {return;}

    switch (type) {
    case 1: //ORDEM
        ABB_print(no->left, type);
        printf("%d\t", no->key);
        ABB_print(no->right, type);
        break;
    case 2: //PRE ORDEM
        ABB_print_pre_ordem(no, 1, "raiz");
        break;
    case 3: //POS ORDEM
        ABB_print(no->left, type);
        ABB_print(no->right, type);
        printf("%d\t", no->key);
        break;  
    default: 
        printf("OPÇÃO INVÁLIDA\n");
    }
}

/* função impressão da árvore
 *  @param no: ponteiro para a árvore a ser impresso
 *  @param num: controle necessário para impressão 
 *  @param pos: posição que o nó está (esq, dir ou raiz)
*/ 
static void ABB_print_pre_ordem(ABB* no, int num, char* pos) {
    if (!no) {
        print_No(INT_MAX, num, pos);
        return;
    }

    ABB_print_pre_ordem(no->right, num+1, "dir");
    print_No(no->key, num, pos);
    ABB_print_pre_ordem(no->left, num+1, "esq");
}

/* função auxiliar de impressão de nó da árvore
 *  @param key: valor da chave
 *  @param num: controle necessário para impressão 
 *  @param pos: posição que o nó está (esq, dir ou raiz)
*/
static void print_No(int key, int num, char* pos)  {
    int i;
    for (i = 0; i < num; i++) 
        printf("          ");
        if (key == INT_MAX) 
            printf("--(%s)\n", pos);
        else  
            printf("%d(%s)\n", key, pos); 
}

/* retorna quantidade de elementos na árvore
 *  @param no: ponteiro para a árvore
*/
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

/* função remoção de elemento da árvore
 *  @param no: ponteiro para o endereço do nó a ser removido
 *  @param key: chave a ser removida
*/
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
            int lado = 0; 

            if (!remove->left) {
               remove->right->father = remove->father;
            }

            else {
               remove->left->father = remove->father; 
               lado = 1;
            }

            if (remove->key > remove->father->key) {
                remove->father->right = (lado == 1) ? remove->left : remove->right;
            }

            else {
                remove->father->left = (lado == 1) ? remove->left : remove->right;
            }

            control = 1;
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

/* função que retorna o endereço do maior elemento à esquerda do nó
 *  @param no: ponteiro para o nó
 */
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

/* função que retorna o endereço do menor elemento à direita do nó
 *  @param no: ponteiro para o nó
 */
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



