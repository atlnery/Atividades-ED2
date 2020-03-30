#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef int type;
int f[10000000];
int c[10000000];

                                        /*/////////////////////////////////
                                        /          PROTÓTIPOS             /  
                                        /*/////////////////////////////////

    type plus(type a, type b);
    int next(int x);
    int maxValue(int* v, int index);
    int minValue(int* v, int index);     
    int vPlus(int* v, int index);
    int vTimes(int* v, int index);
    float vAverage(int* v, int index);
    int fib(int f0, int f1, int n);
    int fibMemory(int f0, int f1, int n);
    int fibI(int f0, int f1, int n);
    int mdc(int a, int b);
    int mdcI(int a, int b);
    int nCr(int n, int k);
    int nCrMemory(int n, int k);

                                        /*/////////////////////////////////
                                        /      EXERCÍCIOS E SOLUÇÕES      /  
                                        /*/////////////////////////////////
                                        

/////////////////////////////////////////////       Exercício 1 - computar a + b usando função next(int x): 
    type plus(type a, type b) {      
        if ((a < 0) || (b < 0)) { 
            printf ("Invalid parameters\n"); 
            return -1; 
        }        
        if (a == 0) return b;
        return plus(a-1, next(b));         
    }

    int next(int x) { return x+1; }
//

/////////////////////////////////////////////       Exercício 2  - Operações recursivas com vetor de inteiros
// a) Maior elemento do vetor    
    int maxValue(int* v, int index) {
        if (index > sizeof(v)) return 0;
        if (index < 0) return 0;

        if(index == 0) return v[0];
        else {
            int max = maxValue(v, index-1);
            return fmax(max, v[index]);
        }
    }

// b) Menor elemento do vetor  
    int minValue(int* v, int index) {
        if (index > sizeof(v)) return 0;
        if (index < 0) return 0;

        if(index == 0) return v[0];
        else {
            int min = minValue(v, index-1);
            return fmin(min, v[index]);
        }
    }

// c) A soma dos elementos do vetor
    int vPlus(int* v, int index) { 
        if(index == 0) return v[0]; 
        return v[index] + vPlus(v, index-1);
    }

// d) Produto dos elementos do vetor
    int vTimes(int* v, int index) {
        if (index == 0) return v[0]; 
        return v[index] * vTimes(v, index-1);
    }

// e) A média dos elementos do vetor
    float vAverage(int* v, int index) {
         return (float) vPlus(v, index) / (index+1);
    }
//

/////////////////////////////////////////////       Exercício 3 - FIBONACCI
// a) teste de mesa seq G(2,3,4)
// b) Fibonacci recursiva
    int fib(int f0, int f1, int n) {
        if (n == 0) { return f0; }
        else if (n == 1) { return f1; }
        else {
            return fib(f0, f1, n-1) + fib(f0, f1, n-2);
        }
    }

// c) Fibonacci com memoização                                                 
    int fibMemory(int f0, int f1, int n) {
        if (f[n] != NULL) {
            return f[n];
        }
        if (n == 0) { f[n] = f0; }
        else if (n == 1) { f[n] = f1; }
        else {
            f[n] = fibMemory(f0, f1, n-1) + fibMemory(f0, f1, n-2);
        }
        return f[n];
    }

// d) Fibonacci iterativo
    int fibI(int f0, int f1, int n) {
        if (n == 0) { return f0; }
        else if (n == 1) { return f1; }

        int* fb = calloc(n, sizeof(int));

        fb[0] = f0; fb[1] = f1;
        int i = 2;

        while(i <= n) {
            fb[i] = fb[i-1] + fb[i-2];
            i++; 
        }

        int value = fb[n];
        free(fb); 
        return value;
    }
//

/////////////////////////////////////////////       Exercício 4 - MDC
// a) teste de mesa
// b) mdc recursivo
    int mdc(int a, int b) {
        if ((b <= a) && (a%b == 0)) return b;

        if (a < b) { mdc(b, a); }
        else { return mdc(b, a%b); }
    }

// c) mdc iterativo
    int mdcI(int a, int b) {
        int rest = 1;

        while(rest != 0){
            rest = a%b;
            a = b;
            b = rest;
        }
        return a;
    }

//

/////////////////////////////////////////////       Exercício 5 - COEFICIENTE BINOMIAL
// a) teste de mesa
// b) coeficiente binomial recursivo 
    int nCr(int n, int k) {
        if (k > n) { return 0; }
        if (k == 1) { return n; }
        return nCr(n-1, k) + nCr(n-1, k-1);
    }

// c) nCr recursivo com memoização
    int nCrMemory(int n, int k) {
        if (c[n] != NULL){
            return c[n]; 
        }
        if (k > n) { c[n] = 0; }
        else if (k == 1) { c[n] = n; }
        else{ 
            c[n] = nCr(n-1, k) + nCr(n-1, k-1); 
        }
        return c[n];
    }
//


                                        /*/////////////////////////////////
                                        /              TESTES             /  
                                        /*/////////////////////////////////

 void main() {

    //EXERCÍCIO 1
    printf("\nResultado SOMA SUCESSOR: %d\n\n", plus(3, 1));

    //EXERCÍCIO 2
    printf("EXERCÍCIO 2 - VETORES\n");
    int v[10] = {10,9,8,7,6,5,4}; 
    printf("Valor maximo: %d\n", maxValue(v, 4));
    printf("Valor minimo: %d\n", minValue(v, 1));
    printf("Soma de elementos: %d\n", vPlus(v, 6));
    printf("Produto dos elementos: %d\n", vTimes(v, 6));
    printf("Media dos valores: %.2f\n\n", vAverage(v, 6));

    //EXERCÍCIO 3
     printf("EXERCÍCIO 3 - FIBONACCI\n");
    int f0 = 1;
    int f1 = 10; 
    int n = 7;
    printf("Valor do item %d na sequencia Fibonacci recursiva com memória: %d\n", n, fibMemory(f0, f1, n));
    printf("Valor do item %d na sequencia Fibonacci iterativa: %d\n", n, fibI(f0,f1,n) );
    printf("Valor do item %d na sequencia Fibonacci recursiva: %d\n\n", n, fib(f0,f1,n) ); //maior tempo de execução

    // int len = sizeof(f)/sizeof(int);
    // for(int i = 0; i <= n; i++){
    //     printf("%d\t", f[i]);
    // }

    //EXERCÍCIO 4
    printf("EXERCÍCIO 4 - MDC\n");
    printf("MDC recursivo %d\n", mdc(18,9));
    printf("MDC iterativo %d\n\n", mdcI(18,9));

    //EXERCÍCIO 5
    printf("EXERCÍCIO 5 - COEFICIENTE BINOMIAL\n");
    n = 15;
    int k = 10;
    printf("Coeficiente binomial recursivo com mémoria %d\n", nCrMemory(n,k));
    printf("Coeficiente binomial recursivo %d\n\n", nCr(n,k)); //maior tempo de execução


    //EXERCÍCIO 6 - ainda não concluído
    
}   
