 #ifndef INFO_H
 #define INFO_H
 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define INTERVALO 20

    typedef struct {
        int dado;
        int chave;
    }Info;

    Info* criaInfo(int n);
    void preencheInfo(Info* v, int n, int k);
    void imprimeInfo(Info* v, int n);

#endif /*INFO_H*/