#include<stdio.h>

int cont = 0;

void hanoi(int n, char origem, char destino, char temp){
        cont++;

    if (n == 1){
        printf("disco %d \t do pino %c ao pino %c\n", n, origem, destino);
        return 0;
    } 

    hanoi(n-1, origem, temp, destino);
    printf("disco %d \t do pino %c ao pino %c\n", n, origem, destino);
    hanoi(n-1, temp, destino, origem);

}

void main(){

    hanoi(2, 'O', 'D', 'T' );
    printf("%d\n\n", cont);
}