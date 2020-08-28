#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "info.h"
    
    void countingsort(Info* v, int n);
    int max(Info* v, int n);
    void somaPrefix(int* c, int k);


#endif  /*COUNTINGSORT_H*/