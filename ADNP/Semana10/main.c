#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100001

#include "trie.h"


char* openFile(char* file) {
    char caminho[1000] = "./cases/";
    strcat(caminho, file);

    char* string = malloc(SIZE * sizeof(char));

    FILE *arq = fopen(caminho, "r");

    if (!arq) 
        printf("Erro ao abrir o arquivo!\n");
    else 
        fscanf(arq, "%s", string);   

    fclose(arq);
    return string;
}

void main(int argc, char** argv) {

    int L[4] = {3, 10, 30, 50};
    char* caminho = "case_50000.txt";
    char* string = openFile(caminho);
    int i = 3;
    
    printf("%s\n", caminho);
    printf("%d SUBSTRINGS COM L = %d\n\n", SubstringCountLenL(string, L[i]), L[i]);
    free(string);
}