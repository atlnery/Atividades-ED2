#include <stdio.h>

#include "radixsort.h"
#include "vector.h"

#include "radixsortBin.h"

#define DEBUG 0

void main() {

    for(int i = 1; i <= 7; i++) {

        int n = pow(10, i);

        if (i == 6) { n = 500000; }

        if (i == 7) { n = 1000000; }

        int max = n * 100;
        int seed = 0;

        printf("\nQUANTIDADE DE ELEMENTOS: %d\n", n);

        //DECIMAL
        int* v = random_vector(n, max, seed);

        clock_t start = clock();
        radixsort(v, n);
        double tempo = (double) (clock() - start) / (CLOCKS_PER_SEC / 1000);

        printf("Tempo de execução decimal: %.3f ms\n", tempo);

        #if DEBUG
            vectorPrint(v,n);
        #endif

        free(v);
    
        //BINÁRIO
        int* vb = random_vector(n, max, seed);

        start = clock();
        radixsortBin(vb, n);
        tempo = (double) (clock() - start) / (CLOCKS_PER_SEC / 1000);

        printf("Tempo de execução binário: %.3f ms\n", tempo);

        #if DEBUG
            vectorPrint(vb, n);
        #endif

        free(vb);
    }

}
