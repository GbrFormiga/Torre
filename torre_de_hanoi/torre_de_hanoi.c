#include <stdio.h>
#include <stdlib.h>


#define MAX_DISCOS 4 


void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Move disco 1 de %c para %c\n", origem, destino);
    } else {
        hanoi(n - 1, origem, auxiliar, destino); 
        printf("Move disco %d de %c para %c\n", n, origem, destino);  
        hanoi(n - 1, auxiliar, destino, origem);  
    }
}

int main() {
    int num_discos = MAX_DISCOS;

    printf("Resolvendo a Torre de Hanoi com %d discos:\n", num_discos);
    hanoi(num_discos, 'A', 'C', 'B'); 
    return 0;
}
