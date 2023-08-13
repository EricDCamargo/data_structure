#include <stdio.h>

// Troca dois elementos de posição
void swap(int *a, int *b) {
    int temp = *a; //variavel auxiliar para armazenar temporariamente o valor de *a
    *a = *b;
    *b = temp;
}

// Ordena o arry de acordo com seus elementos do menor para o maior
void bubbleSort(int array[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

//imprime o array depois de ordenado
void printSortedArray(int array[], int size) {
    int i;
	printf("Vetor Ordenado: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int i, vetor[size];
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &vetor[i]);
    }

    bubbleSort(vetor, size);
    printSortedArray(vetor, size);

    return 0;
}

