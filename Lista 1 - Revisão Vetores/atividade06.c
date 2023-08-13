#include <stdio.h>

// Função para calcular o produto escalar entre dois vetores
int calculateDotProduct(int arrayA[], int arrayB[], int size) {
    int i, dotProduct = 0;
    for ( i = 0; i < size; i++) {
        dotProduct += arrayA[i] * arrayB[i];
    }
    return dotProduct;
}

int main() {
    int i, size;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &size);

    int arrayA[size], arrayB[size];
    printf("Digite os elementos do vetor A:\n");
    for ( i = 0; i < size; i++) {
        scanf("%d", &arrayA[i]);
    }

    printf("Digite os elementos do vetor B:\n");
    for ( i = 0; i < size; i++) {
        scanf("%d", &arrayB[i]);
    }

    int dotProduct = calculateDotProduct(arrayA, arrayB, size);
    printf("Produto Escalar: %d\n", dotProduct);

    return 0;
}

