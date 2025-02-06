#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função auxiliar para encontrar o maior elemento da subárvore esquerda (antecessor)
no *encontrar_antecessor(no *r) {
    no *atual = r;
    while (atual && atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

// Função para remover um nó com chave x da árvore binária de busca
no *remover(no *r, int x) {
    if (r == NULL) {
        // Chave não encontrada, retorna NULL
        return NULL;
    }

    if (x < r->chave) {
        // Procura na subárvore esquerda
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        // Procura na subárvore direita
        r->dir = remover(r->dir, x);
    } else {
        // Nó a ser removido encontrado
        if (r->esq == NULL) {
            // Caso 1: Sem filho esquerdo
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            // Caso 2: Sem filho direito
            no *temp = r->esq;
            free(r);
            return temp;
        }

        // Caso 3: Dois filhos
        no *antecessor = encontrar_antecessor(r->esq);
        r->chave = antecessor->chave;          // Substitui a chave pelo antecessor
        r->esq = remover(r->esq, antecessor->chave); // Remove o antecessor
    }
    return r;
}
