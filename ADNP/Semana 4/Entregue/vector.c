#include "vector.h"

/* função de criação de vetor randômico
 * @param n: quantidade de elementos que se deseja no novo vetor a ser criado
 * @param max: valor máximo dos elementos a serem gerados
 * @param seed: semente - define um limite inferior
 */
int* random_vector(int n, int max, int seed) {
    int* v = newVector(n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        v[i] = seed + rand() % max;
    }

    return v;
}

/* função de impressão do vetor
 * @param v: ponteiro para o endereço do vetor
 * @param n: quantidade de elementos do vetor que se deseja imprimir
 */
void vectorPrint(int* v, int n) {
    if (v == NULL || n <= 0) { return; }

    int i = 0; 
    printf("\n[ ");
    while (i < n) {
        printf("%d", v[i++]);
        if (i != n) {
            printf(", ");
        }
    }
    printf(" ]\n\n");
}

int* newVector(int n) {
    int* v = malloc(n * sizeof(int)); 
    return v;
}

/* Função conversão de decimal para outra base. O valor convertido é alocado em uma string
 * @param valor: valor em decimal a ser convertido
 * @param base: valor da base para conversão 
 * @param count: tamanho da string alocada
*/
void convertebaseBin(int valor, int base, int* count) {
    char temp[2];

    if (valor < base){
        sprintf(temp, "%d", valor);
        strncat(auxConvBase, &temp[0], 1);   
        *count++;
        return ;
    }

    convertebaseBin(valor / base, base, count);

    sprintf(temp, "%d", (valor % base));
    strncat(auxConvBase, &temp[0], 1);
    *count++;
}