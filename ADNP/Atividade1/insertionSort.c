#include <stdio.h>

                                /*/////////////////////////////////
                                /          prototypes             /  
                                /*/////////////////////////////////

//void insertionSort(int* v, int n); 
void insertionSort(int* v, int n, int* ncompI); 
void insertion(int* v, int index); 


                                /*/////////////////////////////////
                                /          functions              /  
                                /*/////////////////////////////////

//void insertionSort(int* v, int n) { 
void insertionSort(int* v, int n, int* ncompI) {
    if (v == NULL || n <= 1) { return; }

    int index = 1; 
    while (index < n) {
        *ncompI += 1;
        insertion(v, index++);        
    }
}

void insertion(int* v, int index) {
    int value = v[index]; 
   
    while ( index > 0 && v[index] < v[index-1] ) {
        value = v[index];
        v[index] = v[index-1];
        v[index-1] = value; 
        index--;
    }
}
