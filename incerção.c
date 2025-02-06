#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *inserir(no *r, int x) {
    if (r == NULL) {
        // Aloca um novo nó se a posição estiver vazia
        no *novo = (no *)malloc(sizeof(no));
        if (novo == NULL) {
            perror("Erro ao alocar memória");
            exit(1);
        }
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (x < r->chave) {
        // Insere na subárvore esquerda
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        // Insere na subárvore direita
        r->dir = inserir(r->dir, x);
    }
    // Se x já existe, não faz nada e retorna o nó atual
    return r;
}

