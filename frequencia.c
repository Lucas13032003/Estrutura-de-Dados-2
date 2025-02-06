#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 130
#define MAX_STR 1010

typedef struct {
    int key;   // Valor ASCII do caractere
    int value; // Frequência do caractere
} Item;

// Função para trocar dois itens
void swapItems(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Função de comparação para ordenar os itens
int isLess(Item a, Item b) {
    return (a.value == b.value) ? (a.key < b.key) : (a.value < b.value);
}

// Algoritmo de ordenação por inserção (usado para pequenos subconjuntos)
void insertionSort(Item* items, int left, int right) {
    for (int i = left + 1, j; i <= right; i++) {
        Item temp = items[i];
        for (j = i; j > 0 && isLess(temp, items[j - 1]); j--)
            items[j] = items[j - 1];
        items[j] = temp;
    }
}

// Particionamento para o quicksort
int partition(Item* items, int left, int right) {
    Item pivot = items[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (isLess(items[j], pivot)) {
            swapItems(&items[j], &items[i]);
            i++;
        }
    }
    swapItems(&items[i], &items[right]);
    return i;
}

// Quicksort híbrido com ordenação por inserção para subconjuntos pequenos
void quicksort(Item* items, int left, int right) {
    if (right - left <= 32) {
        insertionSort(items, left, right);
        return;
    }

    swapItems(&items[(left + right) / 2], &items[right - 1]);
    if (isLess(items[right], items[left])) swapItems(&items[left], &items[right]);
    if (isLess(items[right], items[right - 1])) swapItems(&items[right - 1], &items[right]);
    if (isLess(items[right - 1], items[left])) swapItems(&items[left], &items[right - 1]);

    int mid = partition(items, left, right);
    quicksort(items, left, mid - 1);
    quicksort(items, mid + 1, right);
}

int main() {
    char str[MAX_STR];
    int firstOutput = 1; // Controle para espaçamento entre casos de teste

    while (fgets(str, MAX_STR, stdin)) {
        int frequency[MAX_CHAR] = {0};
        Item items[MAX_CHAR];

        // Contar frequências de cada caractere
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != '\n') // Ignorar nova linha
                frequency[(int)str[i]]++;
        }

        // Montar o array de itens
        int itemCount = 0;
        for (int i = 0; i < MAX_CHAR; i++) {
            if (frequency[i]) {
                items[itemCount++] = (Item){.key = i, .value = frequency[i]};
            }
        }

        // Ordenar os itens por frequência e valor ASCII
        quicksort(items, 0, itemCount - 1);

        // Imprimir resultados
        if (!firstOutput) {
            printf("\n"); // Separador entre casos de teste
        }
        firstOutput = 0;

        for (int i = 0; i < itemCount; i++) {
            printf("%d %d\n", items[i].key, items[i].value);
        }
    }

    return 0;
}
