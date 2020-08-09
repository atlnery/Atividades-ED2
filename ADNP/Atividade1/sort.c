#include <stdio.h>
#include <stdlib.h>
                                /*/////////////////////////////////
                                /          prototypes             /  
                                /*/////////////////////////////////

//void selectionSort(int* v, int n); 
void selectionSort(int* v, int n, int* ncomp); 
//int maxValue(int* v, int n);
int maxValue(int* v, int n, int* ncomp);

//void bubbleSort(int* v, int n); 
void bubbleSort(int* v, int n, int* ncomp);

//void insertionSort(int* v, int n); 
void insertionSort(int* v, int n, int* ncomp); 
void insertion(int* v, int index); 

int* randomVector(int n, int max, int seed);
void vectorPrint(int* v, int n);
void freeVector(int * v); 
void change(int* v, int pos, int next); 

                                /*/////////////////////////////////
                                /          functions              /  
                                /*/////////////////////////////////


/*                                          SELECTION SORT
   função para ordenação por seleção, nesse caso, elemento com maior valor
 * @param v: ponteiro para o vetor em ordenação.
 * @param n: quantidade de elementos do vetor.
 * @param ncomp: ponteiro para número de comparações realizadas.
 */ 
//void selectionSort(int* v, int n) {
void selectionSort(int* v, int n, int* ncomp) {
    if (v == NULL || n <= 1) { return; }

    while (n-- > 0) {
        int pos = maxValue(v, n, ncomp);
        change(v, pos, n); 
    }
} 

/* função para comparar e encontrar o maior valor entre v[i] e v[i+1]
 * @param v: ponteiro para o vetor em ordenação.
 * @param n: quantidade de elementos do vetor. 
 * @param ncomp: ponteiro para número de comparações realizadas.
 */
//int maxValue(int* v, int n) {
int maxValue(int* v, int n, int* ncomp) {
    int max = v[0]; int pos = 0;

    while (n > 0) {
        *ncomp += 1;
        if (max < v[n]) {
            max = v[n]; 
            pos = n; 
        }
        n--; 
    }
    return pos;
}


/*                                               BUBBLE SORT
    função de ordenação em bolha
 * @param v: ponteiro para o vetor em ordenação.
 * @param n: quantidade de elementos do vetor. 
 * @param ncomp: ponteiro para número de comparações realizadas.
 */             
//void bubbleSort(int* v, int n) {
void bubbleSort(int* v, int n, int* ncomp) {    
    if (v == NULL || n <= 1) { return; }   
   
    int i = 1; 

    while (i < n) {        
        int j = 0, count = 0;

        while (j < (n-i)) {
            *ncomp += 1;
            if (v[j] > v[j+1]) {
                change(v, j, j+1);       
                count++;
            }
            j++;
        }
        i++;
        if (count == 0) { break;  }
    }
}


/*                                              INSERTION SORT
   algoritmo para ordenação por inserção 
 * @param v: ponteiro para o vetor em ordenação.
 * @param n: quantidade de elementos do vetor.
 * @param ncomp: ponteiro para número de comparações realizadas.
 */
//void insertionSort(int* v, int n) { 
void insertionSort(int* v, int n, int* ncomp) {
    if (v == NULL || n <= 1) { return; }

    int index = 1; 
    while (index < n) {
        *ncomp += 1;
        insertion(v, index++);        
    }
}

/* função para inserção de elementos na posição index 
 * @param v: ponteiro para o vetor em ordenação.
 * @param index: posição do último elemento do subvetor em ordenação.  
 */
void insertion(int* v, int index) {
    int value = v[index]; 
   
    while ( index > 0 && v[index] < v[index-1] ) {
        value = v[index];
        v[index] = v[index-1];
        v[index-1] = value; 
        index--;
    }
}


/*                                          FUNÇÕES PARA MANIPULAÇÃO DE VETORES 
   função de criação de vetor randômico
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

