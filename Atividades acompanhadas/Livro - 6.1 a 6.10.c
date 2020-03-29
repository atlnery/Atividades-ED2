#include <stdio.h>
#include <math.h>

    typedef float type; 

                                        /*/////////////////////////////////
                                        /          PROTÓTIPOS             /  
                                        /*/////////////////////////////////

    type power(type b, int exp);
    int plus(int n);
    type plusType(type n);
    int multiplication(int m, int n);
    int divide(int m, int n);
    int evenOrOdd(int n);
    type vPlus(type* v, int n);
    type maxValue(type* v, int first, int last);

                                        /*/////////////////////////////////
                                        /      EXERCÍCIOS E SOLUÇÕES      /  
                                        /*/////////////////////////////////
                                     
//6.1 Crie uma função recursiva para calcular x^n, sendo x != 0 um número real e n um número natural.
    type power(type b, int exp){
        if (exp == 0) return 1;        
        return b * power(b, exp-1);
    }

//6.2 Crie uma função recursiva para calcular a soma 1 + 2 + 3 +...+ n, sendo n um número natural.
    int plus(int n){
        if (n == 1) return 1; 
        return n + plus(n-1);
    }

//6.3 Crie uma função recursiva para calcular a soma 1 + 1/2 + 1/3 +...+ 1/n, sendo n != 0 um número natural.
    type plusType(type n){
        if(n == 0) return n;
        if(n == 1) return 1;
        return (1/n) + plusType(n-1);
    }

//6.4 Usando soma e subtração, crie uma função recursiva para calcular o produto de dois números naturais m e n.
    int multiplication(int m, int n) {
        if ((m == 0) || (n == 0)) return 0; 
        if(m == 1) return n;
        return n + multiplication (m-1, n);
    }

//6.5 Usando soma e subtração, crie uma função recursiva para calcular o quociente da divisão inteira de m por n, sendo m e n Þ 0 números naturais
    int divide(int m, int n) {
        if ((m == 0) || (n == 0)) return 0; 
        if (m < n) return 0;
        return divide(m-n, n) + 1;
    }

//6.6 	Usando subtração, crie uma função recursiva para determinar se um número natural n é par
//retorno da função - se 0, número ímpar. Se 1, valor é par; 
    int evenOrOdd(int n) {
        if (n == 0) return 1; 
        if (n < 0)  return 0;
        return evenOrOdd(n-2);
    }

/*6.7 A função recursiva a seguir calcula o resto da divisão de m por n, sendo m e n Þ 0 dois números naturais. 
 Desenhe o fluxo de execução para a chamada resto(17,5) e mostre que essa função tem recursão de cauda.

    int resto(int m, int n) { 
        if( m<n ) return m; 
        else return resto(m-n,n);
    }
*/

/*6.8 Considerando a função a seguir, desenhe a árvore de decomposição recursiva para a chamada r(2,3) e mostre que a recursão é redundante. 
    int r(int m, int n) { 
        if( m==0 ) return n; 
        if( n==0 ) return m; 
        return r(m-1, n) + r(m, n-1);
        } 
*/

//6.9 Crie uma função recursiva para calcular a soma dos n primeiros itens armazenados num vetor de números inteiros v.
    type vPlus(type* v, int n){
        if(n > sizeof(v)) return 0;
        if (n == 0) return v[0];
        return v[n] + vPlus(v, n-1);
    }

//6.10 Crie a função recursiva maximo(v,i,f), que determina o valor máximo em um vetor v, indexado de i a f. 
    type maxValue(type* v, int first, int last) {
        if (last < first) return -404;
        if (last * first < 0) return -404;
        
        if(last == first) return v[first];
        else {
            int x = maxValue(v, first+1, last); 
            return fmax(x, v[first]);
        }
    }

                                        /*/////////////////////////////////
                                        /              TESTES             /  
                                        /*/////////////////////////////////

void main(){

    type n = power(2,4);
    printf("Exponencial: %.f\n", n);

    n = plus(5);
    printf("Soma: %.f\n", n);

    n = plusType(4);
    printf("Soma de reais: %.2f\n", n);

    n = multiplication(4,2);
    printf("Produto: %.f\n", n);

    n = divide(5,4);
    printf("Quociente: %.f\n", n);

    n = evenOrOdd(5);
    printf("Par ou ímpar: %.f\n", n);

    type v[5] = {0,1,2,3,4};
    n = vPlus(v, 4);
    printf("Soma de vetor: %.f\n", n);

    type v1[10] = {1,2,3,4,10,6,7,20,9,5};
    printf("Valor maximo no vetor: %.f\n", maxValue(v1, 0, 1));
}
