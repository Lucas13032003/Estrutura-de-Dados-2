#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Estrutura da pilha para simular a recursão
typedef struct pilha {
    no *nodo;
    struct pilha *prox;
} pilha;

// Função para criar uma pilha vazia
pilha* cria_pilha() {
    return NULL;
}

// Função para empilhar um nó na pilha
void empilha(no *nodo, pilha **topo) {
    pilha *novo = malloc(sizeof(pilha));
    novo->nodo = nodo;
    novo->prox = *topo;
    *topo = novo;
}

// Função para desempilhar um nó
no* desempilha(pilha **topo) {
    if (*topo == NULL) return NULL;
    pilha *temp = *topo;
    no *nodo = temp->nodo;
    *topo = temp->prox;
    free(temp);
    return nodo;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha *topo) {
    return topo == NULL;
}

// Função para o percurso em ordem sem recursão
void em_ordem(no *raiz) {
    if (raiz == NULL) return;

    pilha *p = cria_pilha();
    no *atual = raiz;

    while (!pilha_vazia(p) || atual != NULL) {
        if (atual != NULL) {
            // Percorre para a esquerda
            empilha(atual, &p);
            atual = atual->esq;
        } else {
            // Visita o nó no topo da pilha e vai para a direita
            atual = desempilha(&p);
            printf("%d ", atual->dado);
            atual = atual->dir;
        }
    }
}

// Função auxiliar para criar um novo nó da árvore
no* cria_no(int dado) {
    no *novo = malloc(sizeof(no));
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    return novo;
}

