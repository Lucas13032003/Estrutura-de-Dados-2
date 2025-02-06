#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Definição da estrutura TH
typedef struct {
    celula *tb; // tabela hash
    int M;      // tamanho da tabela hash
    int N;      // total de chaves presentes na tabela
} TH;

// Função hash modular
int hash(int chave, int M) {
    return chave % M;
}

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
    int idx = hash(ch, h->M);
    celula *atual = h->tb[idx].prox;

    // Verificar se a chave já está na lista
    while (atual != NULL) {
        if (atual->dado == ch) {
            return; // Chave duplicada, não insere
        }
        atual = atual->prox;
    }

    // Inserir a chave no início da lista
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[idx].prox;
    h->tb[idx].prox = nova;
    h->N++;
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
    int idx = hash(ch, h->M);
    celula *atual = &h->tb[idx];

    while (atual->prox != NULL) {
        if (atual->prox->dado == ch) {
            celula *remover = atual->prox;
            atual->prox = remover->prox;
            free(remover);
            h->N--;
            return 0; // Chave encontrada e removida
        }
        atual = atual->prox;
    }

    return -1; // Chave não encontrada
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
    int idx = hash(ch, h->M);
    celula *atual = h->tb[idx].prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            return 1; // Chave encontrada
        }
        atual = atual->prox;
    }

    return 0; // Chave não encontrada
}
