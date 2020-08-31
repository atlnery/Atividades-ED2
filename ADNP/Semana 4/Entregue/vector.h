#ifndef VECTOR_H
#define VECTOR_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>

    #define SIZEMAX 1024

    char auxConvBase[1024];

    int* random_vector(int n, int max, int seed);
    int* newVector(int n);
    void vectorPrint(int* v, int n);

    void convertebaseBin(int valor, int base, int* count);


#endif /*VECTOR_H*/