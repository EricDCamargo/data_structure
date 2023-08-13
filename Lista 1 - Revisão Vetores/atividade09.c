#include <stdio.h>

// Função para rotacionar o array de acordo com a quantidade de rotações recebidas
void rotateArray(int array[], int size, int rotations) {
    int i, temp[size];
    
      // Loop para copiar os elementos para o vetor temporário com a rotação aplicada
    for (i = 0; i < size; i++) {
        temp[(i + rotations) % size] = array[i];
    }
    
    // Loop para copiar os elementos de volta para o arry original
    for (i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

int main() {
    int i, size, rotations;
    
    printf("Digite o tamanho do arry: ");
    scanf("%d", &size);

    int array[size];
    printf("Digite os elementos do vetor:\n");
    for ( i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Digite a quantidade de posições para rotacionar: ");
    scanf("%d", &rotations);

    rotateArray(array, size, rotations);

    printf("Vetor Rotacionado: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

