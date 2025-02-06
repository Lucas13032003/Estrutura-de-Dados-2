#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função que retorna a altura da árvore binária de busca
int altura(no *r) {
    if (r == NULL) {
        return 0; // Altura de uma árvore vazia é 0
    }
    int he = altura(r->esq); // Altura da subárvore esquerda
    int hd = altura(r->dir); // Altura da subárvore direita
    return (he > hd ? he : hd) + 1; // Maior altura + 1
}
