#include <stdio.h>

                                /*/////////////////////////////////
                                /          prototypes             /  
                                /*/////////////////////////////////

//void bubbleSort(int* v, int n); 
void bubbleSort(int* v, int n, int* ncompB); 

                                /*/////////////////////////////////
                                /          functions              /  
                                /*/////////////////////////////////

/* função de ordenação em bolha
 * @param v: vetor a ser ordenado
 * @param n: quantidade de elementos em v
 */             
//void bubbleSort(int* v, int n) {
void bubbleSort(int* v, int n, int* ncompB) {    
    if (v == NULL || n <= 1) { return; }   
   
    int i = 1; 

    while (i < n) {        
        int j = 0, count = 0;

        while (j < (n-i)) {
            *ncompB += 1;
            if (v[j] > v[j+1]) {
                change(v, j, j+1);       
                count++;
            }
            j++;
        }
        i++;
        if (count == 0) { break;  }
    }
}
