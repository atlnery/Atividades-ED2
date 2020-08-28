#include "countingsort.h"

/* ORDENAÇÃO A PARTIR DE CHAVES 
 * @param v: ponteiro para estrutura
 * @param n: número de valores na estrutura
 */
void countingsort(Info* v, int n) {
    if ( v == NULL || n < 1) { return; }

    
    int k = max(v, n);
    int* c = calloc((k+1), sizeof(int));
    Info* cs = malloc(n * sizeof(Info));

    //computar frequência das chaves
    for(int i = 0; i < n; i++) {
        c[v[i].chave]++;
    }

    //soma de prefixos no vetor da frequencia de chaves.
    somaPrefix(c, k);

    //ordenar de acordo com chaves e ordem de aparição 
    for(int i = 0; i < n; i++) {
        int pos = v[i].chave;
        cs[c[pos]] = v[i];
        c[pos]++;       
    }

    memcpy(v, cs, n * sizeof(Info));
    free(cs);
    free(c);
}


/* RETORNA VALOR MAXIMO ENTRE AS CHAVES
 * @param v: ponteiro para estrutura
 * @param n: número de valores na estrutura
 */
int max(Info* v, int n){
    int max = v[0].chave;
    int i = 1;

    while (i < n) {
        if (v[i].chave > max) {
            max = v[i].chave;
        }
        i++;
    }
    return max;
}

/* SOMA PREFIXOS DO VETOR DE CHAVES
 * @param c: ponteiro para vetor de chaves
 * @param k: valor máximo de chave existente
 */
void somaPrefix(int* c, int k) {
    if (c == NULL) { return; }

    int acumulado = 0;

    for(int i = 0; i <= k; i++) {
        int temp = c[i];
        c[i] = acumulado;
        acumulado += temp;
    }
}