#ifndef RADIXSORTBIN_H
#define RADIXSORTBIN_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    void radixsortBin(int* v, int n);
    void counting_sortBin(int* v, int n, int div, int base, int* temp);
    int maxrsBin(int* v, int n);

#endif /*RADIXSORT_H*/