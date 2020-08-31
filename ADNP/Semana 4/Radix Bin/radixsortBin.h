#ifndef RADIXSORTBIN_H
#define RADIXSORTBIN_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    void radixsortBin(char** bin, int n);
    void counting_sortBin(char** v, int n, int div, int base, char** temp);
    int maxLengthBin(char** bin, int n);


#endif /*RADIXSORTBIN_H*/