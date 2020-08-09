#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
 * Arquivo com funções recorrentes usadas pelos arquivos com vetores de ordenação * 
 */
                                /*/////////////////////////////////
                                /          prototypes             /  
                                /*/////////////////////////////////

int* randomVector(int n, int max, int seed);
void vectorPrint(int* v, int n);
void freeVector(int * v); 
void change(int* v, int pos, int next); 


                                /*/////////////////////////////////
                                /          functions              /  
                                /*/////////////////////////////////

/* função de criação de vetor randômico
 * @param n: quantidade de elementos que se deseja no novo vetor a ser criado
 * @param max: valor máximo dos elementos a serem gerados
 * @param seed: semente - define um limite inferior
 */
int* randomVector(int n, int max, int seed) {
    int* v = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        v[i] = seed + rand() % max;
    }

    return v;
}

/* função para troca de posição entre dois elementos do mesmo vetor
 * @param v: endereço do vetor que está sendo ordenado
 * @param pos: posição do elemento maior
 * @param next: posição do próximo elemento, cujo é menor que o que está em v[pos]
 */
void change(int* v, int pos, int n) {
    int temp = v[n]; 
    v[n] = v[pos];
    v[pos] = temp;
}


/* função de impressão do vetor
 * @param v: ponteiro para o endereço do vetor
 * @param n: quantidade de elementos do vetor que se deseja imprimir
 */
void vectorPrint(int* v, int n) {
    if (v == NULL || n <= 0) { return; }

    int i = 0; 
    while (i < n) {
        printf("%d\t", v[i++]);
    }
    printf("\n");
}

/* função para desalocar vetor alocado dinamicamente
 * @param v: ponteiro para o vetor que deseja desalocar da memória  
 */
void freeVector(int* v) {
    free(v);
}
