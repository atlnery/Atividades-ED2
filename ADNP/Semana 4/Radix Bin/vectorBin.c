#include "vectorBin.h"

/* Função para geração de vetor de strings com valores binários aleatórios
 * @param n: quantidade de strings 
 * @param max: valor máximo a ser assumido pelos valores aleatórios
 * @param seed: valor inicial
*/
char** random_vectorBin(int n, int max, int seed) {
    int valor;

    srand(time(NULL));

    char** bin = malloc(n * sizeof(char*));
    int count = 0;

    for (int i = 0; i < n; i++) {
        valor = seed + rand() % max;
        convertebaseBin(valor, 2, &count);
        bin[i] = malloc((count + 1) * sizeof(char));
        strcpy(bin[i], auxConvBase);

        strcpy(&auxConvBase[0], "\0");
        count = 0;
    }

    return bin;
}

/* Função para alocação dinâmica de string 
 * @param n: quantidade de espaços na string
*/
char* newVectorChar(int n) {
    if (n < 1) { return NULL; }

    char* v = malloc( (n+1) * sizeof(char));
    return v;
}

/* Função conversão de decimal para outra base. O valor convertido é alocado em uma string
 * @param valor: valor em decimal a ser convertido
 * @param base: valor da base para conversão 
 * @param count: tamanho da string alocada
*/
void convertebaseBin(int valor, int base, int* count) {
    char temp[2];

    if (valor < base){
        sprintf(temp, "%d", valor);
        strncat(auxConvBase, &temp[0], 1);   
        *count++;
        return ;
    }

    convertebaseBin(valor / base, base, count);

    sprintf(temp, "%d", (valor % base));
    strncat(auxConvBase, &temp[0], 1);
    *count++;
}

/* Função para conversão de binário para decimal
 * @param bin: ponteiro para string com valor em binário
 * @param size: tamanho da string
*/
int convertebin(char* bin, int size) {
    if (bin == NULL) { return 0; }

    int x = 0, i = 0; 
    int j = size-1;
    char aux[2];

    while (i < size) {
        strncpy(aux, &bin[i], 1);
        
        if (atoi(aux)) {
            x += pow(2, j);
        }

        i++; j--;
    }

    return x;
}

/* Função para impressão de vetor de strings binárias
 * @param bin: ponteiro para vetor de strings
 * @param n: quantidade de strings
*/
void imprimeBin(char** bin, int n) {
    if (bin == NULL) { return; }

    int i = 0;
    while (i < n) {
        printf("%s ", bin[i++]);
    }
    printf("\n");
}

/* Função para desalocação de vetores dinâmicos
 * @param bin: ponteiro para vetor de strings
 * @param n: quantidade de strings
*/
void freeString(char** bin, int n) {
    if (bin == NULL) { return; }

    for (int i = 0; i < n; i++) {
        free(bin[i]);
    }

    free(bin);
}

/* Função para inverter n strings contidas em um vetor
 * @param bin: ponteiro para vetor de strings
 * @param n: quantidade de strings
*/
void reverse(char ** bin, int n) {
    if (bin == NULL) { return; }

    for(int i = 0; i < n; i++) {
        char * aux = strrev(bin[i]);
        strcpy(bin[i], aux);
    }
}

/* Função para inverter string
 * @param str: ponteiro para string
*/
char* strrev(char *str){
      if (! str || ! *str) { return str; }

      char *s1 = str;
      char *s2 = str + strlen(str) - 1;
          
      for (; s2 > s1; ++s1, --s2) {
            *s1 ^= *s2;
            *s2 ^= *s1;
            *s1 ^= *s2;
      }
      return str;
}