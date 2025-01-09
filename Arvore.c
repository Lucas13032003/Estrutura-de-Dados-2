#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* esq;
    struct no* dir;
} no_arv;

/**
 * Insere um novo no  na rvore, com o valor passado como par metro.
 * Se a rvore estiver vazia, criar um novo no com o valor passado e
 * retorna-lo. Caso contr rio, se o valor for menor que o valor da
 * raiz, insere o novo no na esquerda da rvore, e se for maior, na
 * direita. Retorna a raiz da rvore atualizada 
 **/

no_arv* insere_1(no_arv* raiz, int valor) {
    if (raiz == NULL) {
        no_arv* aux = malloc(sizeof(no_arv));
        aux->valor = valor;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    } else {
        if (valor < raiz->valor) {
            raiz->esq = insere_1(raiz->esq, valor);
        } else if (valor > raiz->valor) {
            raiz->dir = insere_1(raiz->dir, valor);
        }
        return raiz;
    }
}
void insere_2(no_arv **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(no_arv));
        if (*raiz == NULL) {
            fprintf(stderr, "Erro de alocação de memória\n");
            exit(EXIT_FAILURE);
        }
        (*raiz)->valor = valor;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        if (valor < (*raiz)->valor) {
            insere_2(&((*raiz)->esq), valor);
        } else {
            insere_2(&((*raiz)->dir), valor);
        }
    }
}

no_arv* insere_3(no_arv *raiz, int valor) {
    if (raiz == NULL) { // Verifica se o nó atual é NULL
        no_arv *aux = malloc(sizeof(no_arv)); // Aloca memória para o novo nó
        if (aux == NULL) { // Verifica se a alocação foi bem-sucedida
            fprintf(stderr, "Erro de alocação de memória\n");
            exit(EXIT_FAILURE);
        }
        aux->esq = aux->dir = NULL; // Inicializa os ponteiros do nó
        aux->dado = valor; // Atribui o valor ao nó
        return aux; // Retorna o novo nó
    }

    if (valor < raiz->dado) { // Valor menor, insere na subárvore esquerda
        raiz->esq = insere_3(raiz->esq, valor);
    } else if (valor > raiz->dado) { // Valor maior, insere na subárvore direita
        raiz->dir = insere_3(raiz->dir, valor);
    }
    return raiz; // Retorna a raiz da subárvore
}

/**
 * Imprime os valores da rvore em pre-ordem, ou seja, a raiz,
 * seguida dos valores da esquerda e da direita.
 * @param raiz a raiz da rvore
 **/
void imprime_1(no_arv* raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->valor);
        imprime_1(raiz->esq);
        imprime_1(raiz->dir);
    }
}

/**
 * Imprime os valores da rvore em ordem, ou seja, os valores da
 * esquerda, a raiz e os valores da direita.
 * @param raiz a raiz da rvore
 **/
void imprime_2(no_arv* raiz) {
    if (raiz != NULL) {
        imprime_2(raiz->esq);
        printf("%d\n", raiz->valor);
        imprime_2(raiz->dir);
    }
}
/**
 * Imprime os valores da rvore em p s-ordem, ou seja, os valores
 * da esquerda, os valores da direita e a raiz.
 * @param raiz a raiz da rvore
 **/
void imprime_3(no_arv* raiz) {
    if (raiz != NULL) {
        imprime_3(raiz->esq);
        imprime_3(raiz->dir);
        printf("%d\n", raiz->valor);
    }
}

/**
 * Retorna a altura da rvore binaria, considerando o nivel da raiz
 * como 1. Se arvore estiver vazia, retorna 0.
 * @param raiz a raiz da rvore
 **/
int altura(no_arv* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int altura_esq = altura(raiz->esq);
    int altura_dir = altura(raiz->dir);
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

/**
 * Programa principal que opera sobre uma rvore binaria.
 * O programa tem as seguintes op es:
 * 1 - Inserir um valor na rvore
 * 2 - Imprimir os valores da rvore em tr s formas diferentes
 * 3 - Calcular a altura da rvore
 * 0 - Sair do programa
 * O programa funciona como um menu interativo, onde o usu rio escolhe
 * a op o desejada e o programa executa a opera o selecionada.
 **/
int main() {
    no_arv* raiz = NULL;
    int opcao = -1, valor;

    do {
        printf("\n1 - Inserir\n2 - Imprimir\n3 - Altura\n0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n Digite um valor: ");
            scanf("%d", &valor);
            //raiz = insere_1(raiz, valor);
            insere_2(&raiz, valor);
            break;
        case 2:
            printf("\n Primeira impressao (pre-ordem): \n");
            imprime_1(raiz);
            printf("\n Segunda impressao (em ordem): \n");
            imprime_2(raiz);
            printf("\n Terceira impressao (pos-ordem): \n");
            imprime_3(raiz);
            break;
        case 3:
            printf("\n Altura da arvore: %d\n", altura(raiz));
            break;
        case 0:
            printf("\n Saindo...\n");
            break;
        default:
            printf("\n Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
