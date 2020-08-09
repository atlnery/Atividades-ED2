#include <stdio.h>
#include <time.h>
#include <locale.h>

#include "sort.c"

void results(double timeElapsed, int comparisons);

void results(double timeElapsed, int comparisons) {
    printf("\nTime Elapsed: %.0f ms\n", timeElapsed);
    printf("Comparisons: %d\n", comparisons);
}

void main() {

    setlocale(LC_ALL, "portuguese");
    fflush(stdin);

    /************************************   GERAÇÃO DE VETORES ALEATÓRIOS   ************************************/
    
    int n = 1000;    // quantidade de elementos no vetor
    int max = 1000; // valor máximo dos elementos no vetor
    int seed = 0;   // semente
   
    int* vs = randomVector(n, max, seed);   //vetor Selection Sort
    int* vb = calloc(n, sizeof(int));       //vetor Bubble Sort
    int* vi = calloc(n, sizeof(int));       //vetor Insertion Sort

    //cópia para trabalhar com vetores iguais
    memcpy(vb, vs, n * sizeof(int));
    memcpy(vi, vb, n * sizeof(int));

    printf("\nQuantidade de elementos (n): %d\n", n);


    /************************************   SELECTION SORT  ************************************/
    
    printf("\nSelection Sort");
    int ncomp = 0; // número de comparações Selection

    // cálculo de tempo de execução 
    clock_t start = clock();
    selectionSort(vs, n, &ncomp);
    double timeElapsed = (double) ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

    results(timeElapsed, ncomp);
    //vectorPrint(vs, n);    

    /************************************   BUBBLE SORT   *************************************/
    
    printf("\nBubble Sort");
    ncomp = 0; // número de comparações Bubble

    // cálculo de tempo de execução 
    start = clock(); 
    bubbleSort(vb, n, &ncomp);
    timeElapsed = (double) (clock() - start) / (CLOCKS_PER_SEC / 1000);

    results(timeElapsed, ncomp);
    //vectorPrint(vb, n);

    /************************************   INSERTION SORT   ************************************/
    
    printf("\nInsertion Sort");
    ncomp = 0; // número de comparações Insertion

    // cálculo de tempo de execução 
    start = clock(); 
    insertionSort(vi, n, &ncomp);
    timeElapsed = (double) (clock() - start) / (CLOCKS_PER_SEC / 1000);
    
    results(timeElapsed, ncomp);
    //vectorPrint(vi, n);

    /************************************   DESALOCAÇÃO     *************************************/
    freeVector(vs);
    freeVector(vb);
    freeVector(vi);
}
