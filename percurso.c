#include <stdio.h>
#include <string.h>

// Função para construir o percurso posfixo a partir do prefixo e infixo
void construirPosfixo(char *prefixo, char *infixo, int n, char *posfixo, int *indice) {
    if (n <= 0) return;

    // O primeiro caractere do prefixo é a raiz
    char raiz = prefixo[0];

    // Encontrar a posição da raiz no percurso infixo
    int pos_raiz = strchr(infixo, raiz) - infixo;

    // Construir a subárvore esquerda
    construirPosfixo(prefixo + 1, infixo, pos_raiz, posfixo, indice);

    // Construir a subárvore direita
    construirPosfixo(prefixo + 1 + pos_raiz, infixo + pos_raiz + 1, n - pos_raiz - 1, posfixo, indice);

    // Adicionar a raiz ao percurso posfixo
    posfixo[(*indice)++] = raiz;
}

int main() {
    int c; 
    scanf("%d", &c);

    while (c--) {
        int n; // Número de nós na árvore
        char prefixo[53], infixo[53], posfixo[53];
        scanf("%d %s %s", &n, prefixo, infixo);

        int indice = 0;
        construirPosfixo(prefixo, infixo, n, posfixo, &indice);
        posfixo[indice] = '\0'; // Finalizar a string posfixa

        printf("%s\n", posfixo); // Imprimir o percurso posfixo
    }

    return 0;
}
