#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"


                                /* BUSCA */

ASCII_TRIE* AT_Buscar(ASCII_TRIE* T, unsigned char* chave) {
    return AT_Buscar_R(T, chave, strlen(chave), 0);
}

/* retorna endereço da busca solicitada
 * @param T: endereço para a chave
 * @param chave: chave a ser buscada;
 * @param n: tamanho da string
 * @param p: profundidade da busca
 */
static ASCII_TRIE* AT_Buscar_R(ASCII_TRIE* T, unsigned char* chave, int n, int p) {
    if (!T) return NULL;

    if (p == n) { return T; }

    //utiliza a chave só porque está trabalhando com tabela ASCII
    AT_Buscar_R(T->filhos[chave[p]], chave, n, p+1);
}

ASCII_TRIE* AT_Buscar_I(ASCII_TRIE* T, uchar* chave) {

    if (!T) return NULL;

    int n = strlen(chave);
    ASCII_TRIE* aux = T;

    for(int p = 0; p < n; p++) {
        aux = aux->filhos[chave[p]]; 
        if (!aux) 
            return NULL;
    }

    return aux;
}
                                /* INSERÇÃO */

static void AT_Inserir_R(ASCII_TRIE** T, uchar* chave, int valor, int n, int p) {

    if (!(*T)) {
        *T = AT_Criar();
    }

    if (p == n) {
        (*T)->valor = valor;
        (*T)->estado = ATE_OCUPADO;
        return;
    }

    AT_Inserir_R(&(*T)->filhos[chave[p]], chave, valor, n, p+1);
}

void AT_Inserir(ASCII_TRIE** T, uchar* chave, int valor) {
    AT_Inserir_R(T, chave, valor, strlen(chave), 0);
}


ASCII_TRIE* AT_Criar() {
    ASCII_TRIE *no;

    no = malloc(sizeof(ASCII_TRIE));
    no->estado = ATE_LIVRE;
    no->valor = 0;

    //inicializar todas as 'letras em ascii'
    for (int i = 0; i < 256; i++) {
        no->filhos[i] = NULL;
    }

    return no;
}

/*    FUNÇÕES ITERATIVAS         */

void AT_Inserir_I(ASCII_TRIE** T, uchar* chave, int valor) {
    if (!(*T)) {
        *T = AT_Criar();
    }
    
    int n = strlen(chave);
    int p; int i;

    ASCII_TRIE** trie = &(*T);

    for (p = 0; p < n; p++) {
        trie = &(*trie)->filhos[chave[p]];
        if (!(*trie))
            (*trie) = AT_Criar();
    }

    (*trie)->valor = valor;
    (*trie)->estado = ATE_OCUPADO;
}    


int prefixo(ASCII_TRIE* T) {
    if (!T) return 0;

    for (int i = 0; i < 256; i++) {
        if (!!T->filhos[i]) 
            return 1;
    }
    return 0;
}    
                                    /* REMOÇÃO */
void AT_Remover_I(ASCII_TRIE** T, uchar* chave) {
    if (!(*T)) return;

    int n = strlen(chave);
       
    ASCII_TRIE** aux[n];
    ASCII_TRIE** trie = &(*T);

    for (int p = 0; p < n; p++) {
        trie = &(*trie)->filhos[chave[p]];
        aux[p] = &(*trie);

        //para chave que não existe
        if (!(*aux[p])) 
            return;
    }

    (*aux[n-1])->estado = ATE_LIVRE;

    for (int p = n-1; p >= 0; p--) {        
        if (prefixo((*aux[p])))
            return;

        free(*aux[p]);
        *aux[p] = NULL;
    }
}

//implementar remoção 'simples'

static void AT_Remover_R(ASCII_TRIE** T, uchar* chave, int n, int p) {
    
    int i;

    if (!(*T)) return;

    if (p == n) {
        (*T)->estado = ATE_LIVRE;
    }
    else {
        AT_Remover_R(&(*T)->filhos[chave[p]], chave, n, p+1);
    }

    if((*T)->estado) { return; }

    //VERIFICAR SE É PREFIXO
    for (int i = 0; i < 256; i++) {
        if (!!(*T)->filhos[i]) 
            return;
    }

    free(*T);
    *T = NULL; //para evitar bug
}

void AT_Remover(ASCII_TRIE** T, uchar* chave) {
    AT_Remover_R(T, chave, strlen(chave), 0);
}


static void dados(ASCII_TRIE* T, int a, int ascii) {

    if (!T) return;
    
    char estado; 

    for(int i = 0; i < a; i++) {  printf("-"); }

    printf("(%c)\t\t", ascii);
    printf("(%d)\t", T->valor);
    estado = (T->estado) ? 'O' : 'L' ;
    printf("%c\n", estado);
}

/* DEMAIS FUNÇÕES */

static void AT_Imprimir_R(ASCII_TRIE* T, int a) {
    if(!T) return; 

    for(int i = 0; i < 256; i++) {
        dados(T->filhos[i], a+1, i);
        AT_Imprimir_R(T->filhos[i], a+1);
    }
}

void AT_Imprimir(ASCII_TRIE* T) {
    if (!T) { return; }

    AT_Imprimir_R(T, 0);
    printf("\n");
}

static void AT_Limpa_R(ASCII_TRIE* T, int n, int* control) {
    if (!T) { return; }

    for(int i = 0; i < 256; i++) {        
        if (T->filhos[i])
            if(T->filhos[i]->estado) {
               *control = 1;
            }
            else {
                if (!prefixo(T->filhos[i]))
                    *control = 0;
            }
        AT_Limpa_R(T->filhos[i], n+1, control);
    }
}

int AT_Limpa(ASCII_TRIE* T) {
    int x = 0;
    AT_Limpa_R(T, 0, &x);
    return x;
}


int AT_Tamanho_R(ASCII_TRIE* T, int* n) {
    if (!T) {       
        return *n;
    }

    for(int i = 0; i < 256; i++) {
        
        if (!!T->filhos[i] && T->filhos[i]->estado) {
            *n = *n+1;
        }
        AT_Tamanho_R(T->filhos[i], n);
    }
}

int AT_Tamanho(ASCII_TRIE* T) {
    int tam = 0;
    return (AT_Tamanho_R(T, &tam));
}



int SubstringCountLenL(char * s, int L) {

    int n = strlen(s); 

    if (!n || L > n) { return 0; }

    ASCII_TRIE* SUB = NULL;

    int limite = 0;
    char string[L+1];

    while (n+1-limite > L) {
        strncpy(string, &s[limite], L);
        string[L] = '\0';
        AT_Inserir(&SUB, string, 10);
        limite++;
    }

    return limite;
}


