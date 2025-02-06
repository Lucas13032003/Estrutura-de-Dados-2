#include <stdlib.h>
#include <string.h>

// Estrutura da tabela hash
typedef struct {
    int *tb; // tabela hash
    int M;   // tamanho da tabela hash
    int N;   // total de chaves presentes na tabela
} TH;

// Protótipo da função auxiliar para redimensionar
int aumentaTamanho(int M);

// Função hash modular
int hash(int chave, int M) {
    return chave % M;
}

// Função para redimensionar a tabela hash
void redimensionaTabela(TH *h) {
    int novoTamanho = aumentaTamanho(h->M);
    int *novaTabela = (int *)malloc(novoTamanho * sizeof(int));
    for (int i = 0; i < novoTamanho; i++) {
        novaTabela[i] = -1; // Inicializa com símbolo de vazio
    }

    int tamanhoAntigo = h->M;
    int *tabelaAntiga = h->tb;

    h->tb = novaTabela;
    h->M = novoTamanho;
    h->N = 0;

    for (int i = 0; i < tamanhoAntigo; i++) {
        if (tabelaAntiga[i] != -1) {
            THinsere(h, tabelaAntiga[i]);
        }
    }

    free(tabelaAntiga);
}

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
    if (h->N > h->M / 2) {
        redimensionaTabela(h);
    }

    int idx = hash(ch, h->M);
    while (h->tb[idx] != -1) {
        if (h->tb[idx] == ch) {
            return; // Chave duplicada, não insere
        }
        idx = (idx + 1) % h->M; // Sondagem linear
    }

    h->tb[idx] = ch;
    h->N++;
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
    int idx = hash(ch, h->M);
    while (h->tb[idx] != -1) {
        if (h->tb[idx] == ch) {
            h->tb[idx] = -1;
            h->N--;

            // Reinserção das chaves seguintes
            idx = (idx + 1) % h->M;
            while (h->tb[idx] != -1) {
                int chaveParaReinserir = h->tb[idx];
                h->tb[idx] = -1;
                h->N--;
                THinsere(h, chaveParaReinserir);
                idx = (idx + 1) % h->M;
            }

            return 0; // Chave removida com sucesso
        }
        idx = (idx + 1) % h->M;
    }

    return -1; // Chave não encontrada
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
    int idx = hash(ch, h->M);
    while (h->tb[idx] != -1) {
        if (h->tb[idx] == ch) {
            return 1; // Chave encontrada
        }
        idx = (idx + 1) % h->M;
    }

    return 0; // Chave não encontrada
}
