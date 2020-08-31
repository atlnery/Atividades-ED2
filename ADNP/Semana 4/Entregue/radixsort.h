#ifndef RADIXSORT_H
#define RADIXSORT_H

    #include <math.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    void counting_sort(int* v, int n, int div, int b, int* temp);
    void radixsort(int* v, int n);
    int maxrs(int* v, int n);

#endif /*RADIXSORT_H*/