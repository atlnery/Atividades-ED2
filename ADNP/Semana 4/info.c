#include "info.h"

/* IMPRIME ESTRUTURA INFO
 * @param v: ponteiro para estrutura
 * @param n: número de valores na estrutura
 */
void imprimeInfo(Info* v, int n) {
    if (v == NULL || n < 1) { return; }

    int i = 0; 
    printf("Dado:\t[ ");
    while (i < n) {
        printf("%d\t", v[i].dado);
        i++;
    }
    printf("]\n");

    i = 0;
    printf("Chave:\t[ ");
    while (i < n) {
        printf("%d\t", v[i].chave); 
        i++;
    }
    printf("]\n\n");
}

/* CRIA ESTRUTURA INFO COM ALOCAÇÃO DE N ESPAÇOS
 * @param n: número de valores que deseja na estrutura
 */
Info* criaInfo(int n) {
    Info* v = malloc (n*sizeof(Info));
    return v;
}

/* PREENCHE ESTRUTURA *JÁ ALOCADA* COM VALORES ALEATÓRIOS
 * @param v: ponteiro para estrutura
 * @param n: número de valores na estrutura
 * @param k: valor de chave máxima desejada
 */
void preencheInfo(Info* v, int n, int k) {
    if (v == NULL || n < 1) { return; }

    for (int i = 0; i < n; i++) {
        v[i].dado = rand() % INTERVALO;
        v[i].chave = rand() % (k+1);
    }
}