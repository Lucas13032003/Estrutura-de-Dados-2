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

// Função para espiar o topo da pilha sem removê-lo
no* espia(pilha *topo) {
    if (topo == NULL) return NULL;
    return topo->nodo;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha *topo) {
    return topo == NULL;
}

// Função para o percurso pós-ordem sem recursão
void pos_ordem(no *raiz) {
    if (raiz == NULL) return;

    pilha *p = cria_pilha();
    no *ultimo_visitado = NULL;

    while (!pilha_vazia(p) || raiz != NULL) {
        if (raiz != NULL) {
            empilha(raiz, &p);
            raiz = raiz->esq;
        } else {
            no *nodo_atual = espia(p);
            if (nodo_atual->dir != NULL && ultimo_visitado != nodo_atual->dir) {
                raiz = nodo_atual->dir;
            } else {
                printf("%d ", nodo_atual->dado);
                ultimo_visitado = desempilha(&p);
            }
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
