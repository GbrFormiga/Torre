#include <stdio.h>
#include <stdlib.h>

typedef struct Disco {
    int tamanho;
    struct Disco* prox;
} Disco;

typedef struct FilaCircular {
    Disco* frente;
    Disco* tras;
    int tamanho;
} FilaCircular;

void inicializarFila(FilaCircular* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
    fila->tamanho = 0;
}

void enfileirar(FilaCircular* fila, int tamanho) {
    Disco* novo = (Disco*)malloc(sizeof(Disco));
    novo->tamanho = tamanho;
    novo->prox = NULL;
    if (fila->tamanho == 0) {
        fila->frente = novo;
    } else {
        fila->tras->prox = novo;
    }
    fila->tras = novo;
    fila->tamanho++;
}

int desenfileirar(FilaCircular* fila) {
    if (fila->tamanho == 0) {
        return -1;
    }
    Disco* temp = fila->frente;
    int tamanho = temp->tamanho;
    fila->frente = temp->prox;
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    free(temp);
    fila->tamanho--;
    return tamanho;
}
