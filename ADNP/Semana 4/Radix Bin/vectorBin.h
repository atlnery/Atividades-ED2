#ifndef VECTORBIN_H
#define VECTORBIN_H


    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    #define SIZEMAX 1024
    
    char auxConvBase[SIZEMAX];

    char** random_vectorBin(int n, int max, int seed);
    void convertebaseBin(int valor, int n, int* count);
    int convertebin(char* bin, int size);

    void imprimeBin(char** bin, int n);
    char* newVectorChar(int n);
    void freeString(char** bin, int n);
    void reverse(char  ** bin, int n);
    char *strrev(char *str);


#endif /*VECTORBIN_H*/