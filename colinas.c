#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1048576

typedef struct no {
    int id;
    char comida[11];
    struct no* prox;
} no;

// Função para criar um novo nó
no* criaNo(int id, char* comida) {
    no* newno = (no*)malloc(sizeof(no));
    if (!newno) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    newno->id = id;
    strcpy(newno->comida, comida);
    newno->prox = NULL;
    return newno;
}

// Função hash para calcular o índice
int funcaoHash(int id) {
    return abs(id) % MAX;
}

// Função para inserir um nó na tabela hash
void insertno(no** tabelaHash, int id, char* comida) {
    int index = funcaoHash(id);
    no* current = tabelaHash[index];

    // Verifica se já existe um nó com o mesmo ID e comida
    while (current != NULL) {
        if (current->id == id && strcmp(current->comida, comida) == 0) {
            printf("%d\n", id);
            return;
        }
        current = current->prox;
    }

    // Se não existir, cria um novo nó e o insere no início da lista
    no* newno = criaNo(id, comida);
    newno->prox = tabelaHash[index];
    tabelaHash[index] = newno;
}

// Função para liberar memória da tabela hash
void liberar(no** tabelaHash) {
    for (int i = 0; i < MAX; i++) {
        no* current = tabelaHash[i];
        while (current != NULL) {
            no* temp = current;
            current = current->prox;
            free(temp);
        }
    }
    free(tabelaHash);
}

int main() {
    // Aloca a tabela hash
    no** tabelaHash = (no**)calloc(MAX, sizeof(no*));
    if (!tabelaHash) {
        perror("Erro ao alocar tabela hash");
        return EXIT_FAILURE;
    }

    int id;
    char comida[11];

    // Lê a entrada e insere na tabela hash
    while (scanf("%d %s", &id, comida) != EOF) {
        insertno(tabelaHash, id, comida);
    }

    // Libera memória alocada
    liberar(tabelaHash);

    return 0;
}
