#include "radixsortBin.h"
#include "vectorBin.h"

/* Função de ordenação 
 * @param bin: ponteiro para strings de números binários
 * @param n: quantidade de strings 
*/
void radixsortBin(char** bin, int n) {
    
    //obter maior valor (!= de maior chave agora)
    int i = maxLengthBin(bin, n) - 1;
    //obter valor máximo de representação na base 2 
    int k = pow(2, i);
    //inicializar div
    int div = 0;
    //alocar vetor temporário
    char** temp = malloc(n * sizeof(char*));
    for (int j = 0; j < n; j++) {
        temp[j] = calloc(SIZEMAX, SIZEMAX * sizeof(char));
    }

    //executar counting do bit menos significativo ao mais significativo
    while (k > 0) {   
        counting_sortBin(bin, n, div++, 2, temp);
        k /= 2;
    } 

    freeString(temp, n);
}

/* Função para ordenação por contagem
 * @param bin: ponteiro para strings de números binários
 * @param n: quantidade de strings 
 * @param div: posição do bit a ser ordenado
 * @param base: base na qual estão os valores (binária = 2);
 * @param temp: vetor de strings temporário, que será auxiliar na ordenção 
*/
void counting_sortBin(char** bin, int n, int div, int base, char** temp) {

    //vetor para contagem 
    int c[base]; 
    memset(c, 0, base * sizeof(int)); //colocar 0 em todas as pos
        
    #define DIGIT(X) (X >> div) & 1
    
    //vetor com binário convertido para decimal
    int x[n];
    
    for (int i = 0; i < n; i++) {
        //converter binario em decimal
        x[i] = convertebin(bin[i], strlen(bin[i]));
        c[DIGIT(x[i])]++;
    }

    reverse(bin, n);

    //soma de prefixos vetor de contagem
    int acumulado = 0;
    for(int i = 0; i < base; i++) {
        int temp = c[i]; 
        c[i] = acumulado; 
        acumulado += temp;
    }

    //copiar elementos do vetor bin para temp de acordo com a posição em c[0] e c[1]
    for(int i = 0; i < n; i++) {
        int pos = c[DIGIT(x[i])];
    
        strcpy(temp[pos], bin[i]);
        c[DIGIT(x[i])]++;  
    }

    //copiar elementos ordenados de temp para bin
    for (int i = 0; i < n; i++) {
        int tam = strlen(temp[i]) + 1;
        memcpy(bin[i], temp[i], tam * sizeof (char));
    }

    reverse(bin, n);
}

/* Função de ordenação 
 * @param bin: ponteiro para strings de números binários
 * @param n: quantidade de strings 
*/
int maxLengthBin(char** bin, int n) {
    int i = 0; 
    int largest = strlen(bin[0]);

    while (i < n) {
       int next = strlen(bin[i]);
       
       if (largest < next) {
           largest = next;
       }
       i++;
    }

    return largest;
}