#include "radixsortBin.h"
#include "vector.h"

/* Função de ordenação a partir de raiz
 * @param v: ponteiro para vetor
 * @param n: tamanho do vetor
*/
void radixsortBin(int* v, int n) {
    int k, div = 0;

    //quantidades de bits necessários para representação do maior valor
    k = maxrsBin(v, n); 
    k = pow(2, k);

    int * temp = malloc(n * sizeof(int));

    while (k > 0) {
        counting_sortBin(v, n, div++, 2, temp);
        k /= 2;
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
void counting_sortBin(int* v, int n, int div, int base, int* temp) {
    //vetor para contagem 
    int c[base]; 
    memset(c, 0, base * sizeof(int)); 

    #define DIGIT(X) (X >> div) & 1

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

/* Função que devolve maior valor do vetor v
 * @param v: ponteiro para vetor
 * @param n: tamanho do vetor
*/
int maxrsBin(int* v, int n) {
    int i = 0; 
    int max = v[0];

    while (i++ < n) {
        if(v[i] > max) {
            max = v[i];
        }
    }

    int c = ceil(log(max) / log(2));
    return c;
}