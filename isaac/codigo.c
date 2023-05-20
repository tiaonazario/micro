#include <stdio.h>

// Função para troca de valores entre duas variáveis
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Função para ordenar um vetor de inteiros em ordem crescente usando o algoritmo Selection Sort
void selectionSort(int vetor[], int tamanho) {
    int i, j, menor_indice;

    for (i = 0; i < tamanho - 1; i++) {
        menor_indice = i;

        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor_indice]) {
                menor_indice = j;
            }
        }

        if (menor_indice != i) {
            swap(&vetor[i], &vetor[menor_indice]);
        }
    }
}

int main() {
    int tamanho;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho], i;

    for (i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor desordenado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    selectionSort(vetor, tamanho);

    printf("\nVetor ordenado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n\n");

    return 0;
}

