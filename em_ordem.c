#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Definição da estrutura da pilha para simular recursão
typedef struct pilha {
    no *n;
    struct pilha *prox;
} pilha;

// Função para criar um novo nó na árvore
no* novo_no(int dado) {
    no *n = (no*)malloc(sizeof(no));
    n->dado = dado;
    n->esq = n->dir = NULL;
    return n;
}

// Função para empilhar um nó
void empilhar(pilha **topo, no *n) {
    pilha *novo = (pilha*)malloc(sizeof(pilha));
    novo->n = n;
    novo->prox = *topo;
    *topo = novo;
}

// Função para desempilhar um nó
no* desempilhar(pilha **topo) {
    if (*topo == NULL) return NULL;
    pilha *temp = *topo;
    no *n = temp->n;
    *topo = temp->prox;
    free(temp);
    return n;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha *topo) {
    return topo == NULL;
}

// Função para realizar o percurso em ordem sem recursão
void em_ordem(no *raiz) {
    pilha *topo = NULL;
    no *atual = raiz;

    while (atual != NULL || !pilha_vazia(topo)) {
        // Percorrer para a esquerda até o fim
        while (atual != NULL) {
            empilhar(&topo, atual);
            atual = atual->esq;
        }

        // Processar o nó do topo da pilha
        atual = desempilhar(&topo);
        printf("%d ", atual->dado);

        // Mover para o nó à direita
        atual = atual->dir;
    }
}
