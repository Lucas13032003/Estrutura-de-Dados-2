#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para encontrar o nó com o valor mínimo na árvore binária de busca
no *minimo(no *r) {
    if (r == NULL) {
        return NULL; // Árvore vazia
    }

    no *atual = r;
    // O menor valor está no extremo esquerdo da árvore
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}
