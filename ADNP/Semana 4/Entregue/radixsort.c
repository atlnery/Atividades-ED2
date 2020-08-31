#include "radixsort.h"


/* Função de ordenação a partir de raiz
 * @param v: ponteiro para vetor
 * @param n: tamanho do vetor
*/
void radixsort(int* v, int n) {
    int k, div = 1;

    k = maxrs(v, n); 
    int * temp = malloc(n * sizeof(int));

    while (k > 0) {
        counting_sort(v, n, div, 10, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}

/* Função de ordenação a partir vetor de contagem
 * @param v: ponteiro para vetor
 * @param n: tamanho do vetor
 * @param div: posição a ser ordenada
 * @param base: valor da base 
 * @param tem: vetor auxiliar para alocação
*/
void counting_sort(int* v, int n, int div, int base, int* temp) {
    //vetor para contagem 
    int c[base]; 
    memset(c, 0, base * sizeof(int)); 

    #define DIGIT(X) (X / div) % base

    //vetor de contagem
    for (int i = 0; i < n; i++) {
        c[DIGIT(v[i])]++;
    }

    //soma de prefixos vetor de contagem
    int acumulado = 0;
    for(int i = 0; i < base; i++) {
        int temp = c[i]; 
        c[i] = acumulado; 
        acumulado += temp;
    }

    //ordenação a partir do vetor de contagem na posição n : div ^ n
    for(int i = 0; i < n; i++) {
        int index = DIGIT(v[i]);
        temp[c[index]] = v[i];
        c[index]++;
    }

    memcpy(v, temp, n * sizeof(int));    
}

/* Função que devolve valor máximo do vetor v
 * @param v: ponteiro para vetor
 * @param n: tamanho do vetor
*/
int maxrs(int* v, int n) {
    int i = 0; 
    int max = v[0];

    while (i++ < n) {
        if(v[i] > max) {
            max = v[i];
        }
        i++;
    }
    return max;
}