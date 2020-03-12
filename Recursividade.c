#include <stdio.h>
#include <time.h>


//funções recursivas
int rec_fat(int n);
int rec_mult(int a, int b);
int rec_divide(int a, int b);
int rec_fibo(int p);
int rec_convertebase(int dec, int base); //precisou do return. Pru quê?

//funções iterativas
int it_fat(int n);
int it_mult(int a, int b);
int it_divide(int a, int b);
int it_fibo(int p);
void it_convertebase(int dec, int base);


// conversão apenas de decimal para outras bases. 
int rec_convertebase(int dec, int base){
    
    if (dec < base){         
        printf("%d", dec); 
        return 0;
    }

    rec_convertebase(dec/base, base);
    printf("%d", dec%base);
}


void it_convertebase(int dec, int base){
    
    int convertido[128]; 
    int i = 127; 

    while(dec >= base){
        convertido[i] = dec%base; 
        dec /= base; 
        i--; 
    }

    convertido[i] = dec;
   
    for(; i < 128; i++){
        printf ("%d", convertido[i]);
    }
}


int rec_fibo(int p){
    if (p < 2) {return p;}

    return (rec_fibo(p-1) + rec_fibo(p-2));
}


int it_fibo(int p){
    
    if (p < 2){return p;}

    int f[p]; 
    f[0] = 0;
    f[1] = 1;    
        
    for (int i = 2; i <= p; i++){
        f[i] = f[i-1] + f[i-2];
    }

    int valor = f[p];
    return valor;
}


int it_fat(int n){
    if (n <= 0){ return 1;}

    int fat = 1; 

    while (n > 1){
        fat *= n;
        n -= 1;
    }    

    return fat; 
}


int rec_fat(int n){
    if (n == 0){ return 1;}

    return n * rec_fat(n-1);
}


int rec_mult(int a, int b){
    if ((a && b) == 0) { return 0;}

    if (a == 1) return b;

    return b + rec_mult(a-1, b);
}


int it_mult(int a, int b){
    if ((a && b) == 0) return 0;

    int produto = b;

    for(; a > 1; a--){
        produto += b;
    }
    return produto;
}


int rec_divide(int a, int b){
    if ((a < b) | (a && b) == 0) return 0;

    return rec_divide(a-b, b) + 1;
}


int it_divide(int a, int b){
    int quociente = 0;

    if ((a && b) == 0 || (a < b)) {return 0;}

    while (a >= b){
        a -= b;
        quociente++;
    }
    
    return quociente;
}


void main(){

    clock_t tempo;
    tempo = clock();

    it_convertebase(1500,16);
    printf("\n");

    double exec = (clock() - tempo) / (double) CLOCKS_PER_SEC;
    
    printf("Tempo execucao: %9.f \n", exec);
}
