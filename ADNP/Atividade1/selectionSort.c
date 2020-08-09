#include <stdio.h>

                                /*/////////////////////////////////
                                /          prototypes             /  
                                /*/////////////////////////////////

//void selectionSort(int* v, int n); 
void selectionSort(int* v, int n, int* ncomp); 
//int maxValue(int* v, int n);
int maxValue(int* v, int n, int* ncomp);

                                /*/////////////////////////////////
                                /          functions              /  
                                /*/////////////////////////////////

/* função para ordenação por seleção, nesse caso, elemento com maior valor
 * @param v: ponteiro para o vetor a ser ordenado
 * @param n: quantidade de elementos do vetor a ser ordenado
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
 * @param v: ponteiro para o vetor em ordenação
 * @param n: quantidade de elementos do vetor 
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
