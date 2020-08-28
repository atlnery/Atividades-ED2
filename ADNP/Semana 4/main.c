#include <stdio.h>

#include "countingsort.h"
#include "info.h"

void main() {

    int n = 10;
    int k = 6;

    Info* v = criaInfo(n);
    preencheInfo(v, n, k);
    imprimeInfo(v, n);
    
    countingsort(v, n);
    imprimeInfo(v, n);

    free(v);
}
