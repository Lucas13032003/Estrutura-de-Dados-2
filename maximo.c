#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para encontrar o nó com o valor máximo na árvore binária de busca
no *maximo(no *r) {
    if (r == NULL) {
        return NULL; // Árvore vazia
    }

    no *atual = r;
    // O maior valor está no extremo direito da árvore
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}
    